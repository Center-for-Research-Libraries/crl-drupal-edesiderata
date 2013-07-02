<?php


/**
 * @file
 * Custom relationship logic between resource and activity entities.
 */


/**
 * Get a summary of backref relationships between a resource and activity.
 * 
 * The various functions that are called through this function implement static
 * caching whenever DB queries are needed, so it should be safe to call this
 * multiple times on the same page load (e.g. if backref info must be requested
 * from different contexts for the same resource entitity). We don't do static
 * caching in this function directly as it would be redundant to static caching
 * within its later called functions (such as entity_load). This avoids using up
 * unnecessary memory.
 * 
 * @param object $entity
 *   A resoruce entity.
 * @return array
 *   An associative array of backref information for this resource.
 */
function crl_helpers_get_backref_summary($entity) {
  $nid = $entity->nid;
  $summary = array();
  $wrapper = entity_metadata_wrapper('node', $entity);
  
  // Get general backref info through Entity API.
  $summary['backref_entities'] = $wrapper->crl_resource_backref->raw();
  
  // Get status values through Entity API. This also calculated through a
  // backref.
  $crl_statuses = $wrapper->crl_resource_status_backref->raw();
  foreach ($crl_statuses as $status) {
    if (!empty($status)) {
      $summary['status'][] = $status;
    }
  }
  return $summary;
}


/**
 * Implements hook_entity_property_info_alter().
 * 
 * This is where we define our status values through backrefrences (activites
 * that point to resources).
 */
function crl_helpers_entity_property_info_alter(&$info) {
  $properties = &$info['node']['properties'];
  // Add a new entity property that will be used to fetch the general details
  // for all entities that point to a resource entity through a
  // field_resource_reference field.
  $properties['crl_resource_backref'] = array(
    'label' => t("CRL resource backreference"),
    'type' => 'list<text>',
    'description' => t("Gets entities through resource backreference."),
    'getter callback' => 'crl_helpers_resource_backref_properties_get',
  );
  // Add a new entity property that will be used to define the formal CRL status
  // associated with any given resource (based on activity values linked to a
  // resource entity through a field_resource_reference field.
  $properties['crl_resource_status_backref'] = array(
    'label' => t("CRL resource status backreference"),
    'type' => 'list<text>',
    'description' => t("Gets CRL resource status through backreference."),
    'getter callback' => 'crl_helpers_resource_backref_properties_get',
    'options list' => 'crl_helpers_activity_status_property_oplist',
  );
}


/**
 * Properties getter callback: calculate backreferenced properties.
 * 
 * Note that this getter callback is called from multiple contexts. It is called
 * upon the display of a resource to dynamically calculate resource data based
 * on related activity (when loading/display pages). It is also called via the
 * Search API when content is indexed in order to dynamically calculate resource
 * status data that will be indexed (and used in facets).
 * 
 * @see crl_helpers_entity_property_info_alter().
 */
function crl_helpers_resource_backref_properties_get($entity, array $options, $name, $type, $info) {
  // The logic below may fail in strange ways if we are not dealing with a node.
  if (empty($entity->nid)) {
    return FALSE;
  }
  // First calculate the backreferences. We store these in a static cache so
  // that this getter callback can be called multiple times, for multiple
  // properties that use backreferences, in one page load efficiently.
  static $backrefs = array();
  if (!isset($backrefs[$entity->nid])) {
    $backrefs[$entity->nid] = array();
    // Get the entities that reference this resource through the
    // field_resource_reference field.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node', '=')
          ->entityCondition('bundle', 'activity')
          ->fieldCondition('field_resource_reference', 'target_id', $entity->nid, '='); 
    // Force query to run without access checks. If we remove the tag below then
    // status values will reflect the current user's access permissions (status
    // values will not appear for activity entries they do not have access to)
    // which could be a very good thing. However, this will cause problems when
    // this code is called though cron when resoruce content is being indexed.
    // This is because cron can only run as one user (anon by default) so the
    // indexed (facet) data can't be user-specific. For now, we just override
    // access control for all cases but may need to think more about how to deal
    // with this.
    $query->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');
    $result = $query->execute();
    if (!empty($result['node'])) {
      $backrefs[$entity->nid] = array_keys($result['node']);
    }
  }
  // Now load the full backreferenced nodes (node_load_multiple has its own
  // static cache so it does not have to be part of the static caching above).
  $backref_nodes = node_load_multiple($backrefs[$entity->nid]);
  // Once we have the backreference details we can continue with
  // property-specific logic that uses this info.
  switch ($info['name']) {    
    // A request for the basic crl_resource_backref propery should just return
    // the raw backrefrenced nodes.
    case 'crl_resource_backref':
      return $backref_nodes;      
    // A request for the crl_resource_status_backref property requires
    // additional calculation to get the status specifics (based on the
    // referencing activity status details).
    case 'crl_resource_status_backref':
      $computed_status = array();
      if (!empty($backref_nodes)) {
        foreach ($backref_nodes as $nid => $node) {
          if ($node->type = 'activity')  {
            // Get the raw status values set on the activity entity and aggregate
            // them directly into our computed result.
            $statuses = field_get_items('node', $node, 'field_activity_crl_status');
            if (!empty($statuses)) {
              foreach ($statuses as $status) {
                if (!in_array($status['value'], $computed_status)) {
                  $computed_status[] = $status['value'];
                }
              }
            }
          }
        }
      }
      // Also see if this resource has a source status that indicates it's a
      // full CRL review (that status value is always calculated dynamically).
      $source_status = crl_helpers_get_single_node_field($entity, 'field_resource_source_status');
      if ($source_status == 'crl_review' && !in_array('crl_review_available', $computed_status)) {
        $computed_status[] = 'crl_review_available';
      }
      return $computed_status;
  }
}


/**
 * Properties callback: centrally define the key|value pairs used for the
 * various CRL status options.
 * 
 * @see crl_helpers_entity_property_info_alter().
 */
function crl_helpers_activity_status_property_oplist() {
  $options = array(
    'crl_desiderata' => t('CRL Desiderata'),
    'license_under_consideration' => t('License terms under consideration'),
    'license_available' => t('License offer available'),
    'license_renewal_available' => t('License renewal available'),
    'trial_access_available' => t('Trial access available'),
    'past_license_offer' => t('Past (expired) license offer'),
    'crl_review_available' => t('CRL Review available'),
  );
  return $options;
}


/**
 * Implements hook_facetapi_sort_info().
 */
function crl_helpers_facetapi_sort_info() {
  $sorts = array();
  $sorts['crl_status_sort'] = array(
    'label' => t('Custom CRL Status Sort'),
    'callback' => 'crl_helpers_activity_status_property_sort',
    'description' => t('Custom sort order that only applies to CRL status values.'),
    'weight' => -50,
  );
  return $sorts;
}


/**
 * Facet API sort callback: set actual sort order for CRL status facet.
 * 
 * @see crl_helpers_facetapi_sort_info().
 */
function crl_helpers_activity_status_property_sort(array $a, array $b) {
  // The ordering we want should be taken straight from the hard-coded ordering
  // of the initial CRL status options array.
  $options = crl_helpers_activity_status_property_oplist();
  $weights = array();
  $i = 0;
  foreach ($options as $op_key => $op_value) {
    $i++;
    $weights[$op_key] = $i;
  }
  $a_weight = 0;
  if (isset($a['#indexed_value'])) {
    if (!empty($weights[$a['#indexed_value']])) {
      $a_weight = $weights[$a['#indexed_value']];
    }
  }
  $b_weight = 0;
  if (isset($b['#indexed_value'])) {
    if (!empty($weights[$b['#indexed_value']])) {
      $b_weight = $weights[$b['#indexed_value']];
    }
  }
  return ($a_weight < $b_weight) ? -1 : 1;
}


/**
 * Implements hook_entity_presave().
 * 
 * Whenever we save a change to an activity entity, we also want to be sure
 * to mark any related resource entities as "dirty". This ensures that the
 * related resource will be re-indexed with updated CRL status metadata.
 */
function crl_helpers_entity_presave($entity, $type) {
  crl_helpers_check_set_dirty($entity, $type);
}


/**
 * Implements hook_entity_delete().
 * 
 * Whenever we delete an activity entity, we also want to be sure
 * to mark any related resource entities as "dirty". This ensures that the
 * related resource will be re-indexed with updated CRL status metadata.
 */
function crl_helpers_entity_delete($entity, $type) {
  crl_helpers_check_set_dirty($entity, $type);
}


/**
 * Helper function to actually check and mark resource entries as "dirty" when
 * a related activity entry is added/changed/removed.
 * 
 * @see: crl_helpers_entity_presave().
 * @see: crl_helpers_entity_delete().
 */
function crl_helpers_check_set_dirty($entity, $type) {
  if ($type == 'node' && isset($entity->type)) {
    $dirty_ids = array();
    if ($entity->type == 'activity') {
      $refs = field_get_items('node', $entity, 'field_resource_reference');
      foreach ($refs as $ref) {
        $dirty_ids[] = $ref['target_id'];
      }
    }
    if (!empty($dirty_ids)) {
      search_api_track_item_change('node', $dirty_ids);
    }
  }
}
