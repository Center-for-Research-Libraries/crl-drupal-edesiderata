<?php


/*****************************************************************************/
/*      Object to manage status sync tasks 
/*****************************************************************************/
class CrlResourceStatusSync {
  // Define Drupal object and field machine names centrally.
  public $a_node_type = 'activity';
  public $a_field_offer_duration = 'field_activity_offer_duration';
  public $a_field_trial_duration = 'field_activity_trial_duration';
  public $a_field_status = 'field_activity_crl_status';
  public $r_node_type = 'resource'; 
  // Dynamic variables set by object methods.
  public $lite = FALSE;
  public $status_changes = array();
  
  
  // Constructor
  public function __construct($lite = FALSE) {
    $this->lite = $lite;
  }  
 
  
  // Calculate which resources need status updates of various types and build
  // an array that captures all the specifics for later processing.
  public function calculate_sync() {
    // See what activity entities are marked as "licesne available" and compare
    // to which ones have an offer expiration date that's still in the future.
    $license_available_marked = $this->get_resources_by_active_status($this->a_node_type, $this->a_field_status, 'license_available');
    $license_available_not_expired = $this->get_resources_by_t_range($this->a_node_type, $this->a_field_offer_duration, date('Y-m-d'));
    foreach (array_diff($license_available_marked, $license_available_not_expired) as $nid) {
      $this->status_changes[$nid]['remove'][] = 'license_available';
      $this->status_changes[$nid]['remove'][] = 'license_renewal_available';
    }
    // See what activity entities are marked as "trial access available" and
    // compare to which ones have an offer expiration date that's still in the
    // future.
    $trial_available_marked = $this->get_resources_by_active_status($this->a_node_type, $this->a_field_status, 'trial_access_available');
    $trial_available_not_expired = $this->get_resources_by_t_range($this->a_node_type, $this->a_field_trial_duration, date('Y-m-d'));
    foreach (array_diff($trial_available_marked, $trial_available_not_expired) as $nid) {
      $this->status_changes[$nid]['remove'][] = 'trial_access_available';
    }
    return $this;   
  }
 
  
  // Execute a set of status updates by loading all the nodes that need an
  // update all at once, and then applying each status update one-by-one.
  public function run_sync() {
    // Load nodes that will be changed.
    $nodes_to_edit = node_load_multiple(array_keys($this->status_changes));  
    // Loop though our status_changes array and apply the status changes.
    foreach($this->status_changes as $nid => $types) {
      $node = &$nodes_to_edit[$nid];
      foreach ($types as $type_key => $statuses) {
        foreach ($statuses as $status_key => $status) {        
          // When removing AND adding we unset the status if it's already set.
          // If adding a status, and for some reason the EFQ that got us to this
          // point is incorrect, we could end up adding a new status value each
          // time this is run... which would be bad as it would lead to
          // accumulating corrupt status values.
          $statuses_active = field_get_items('node', $node, $this->a_field_status);
          if (!empty($statuses_active)) {
            foreach ($statuses_active as $key => $status_active) {
              if ($status_active['value'] == $status) {
                unset($node->{$this->a_field_status}[$node->language][$key]);
              }
            }
          }
          if ($type_key == 'add') {
            $node->{$this->a_field_status}[$node->language][] = array('value' => $status);
          }
        }
      }
      node_save_action($node);
    }
  }

  
  // Get a set of resource ids that SHOULD have a status based on a time range
  // on the related offer.
  public function get_resources_by_t_range($node_type, $field_duration, $date) {
    // Get the active offers
    $nids_active = array();
    $query = new EntityFieldQuery();
    $entities = $query->entityCondition('entity_type', 'node')
                      ->entityCondition('bundle', $node_type)
                      ->fieldCondition($field_duration, 'value2', $date, '>=')
                      ->execute();
    if (!empty($entities['node'])) {
      $nids_active = array_keys($entities['node']);
    }
    return $nids_active;
  }
  
  
  // Get a set of resoruce ids that DO have a status.
  public function get_resources_by_active_status($node_type, $field_status, $status) {    
    $nids_active = array();
    $query = new EntityFieldQuery();
    $entities = $query->entityCondition('entity_type', 'node')
                      ->entityCondition('bundle', $node_type)
                      ->fieldCondition($field_status, 'value', $status, '=')
                      ->execute();
    if (!empty($entities['node'])) {
      $nids_active = array_keys($entities['node']);
    }
    return $nids_active;  
  }
}



/*****************************************************************************/
/*        Additions to manage CRL Status Metadata on Resource
/*****************************************************************************/


/**
 * Implements hook_entity_property_info_alter().
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


// Callback function to calculate backreferenced properties.
function crl_helpers_resource_backref_properties_get($entity, array $options, $name, $type, $info) {
  // First calculate the backreferences. We store these in a static cache so
  // that this getter callback can be called multiple times, for multiple
  // properties that use backreferences, in one page load efficiently.
  static $backrefs = array();
  if (!isset($backrefs[$entity->nid])) {
    $backrefs[$entity->nid] = array();
    list($id) = entity_extract_ids($type, $entity);
    // Get the entities that reference this resource through the
    // field_resource_reference field.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node', '=')
          ->entityCondition('bundle', 'activity')
          ->fieldCondition('field_resource_reference', 'target_id', $id, '=');
    $result = $query->execute();
    if (!empty($result['node'])) {
      $backrefs[$entity->nid] = array_keys($result['node']);
    }
  }
  // Now load the full backreferenced nodes (node_load_multiple has its own
  // static cache so it does not have to be part of the static caching above.
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
      $now = date('Y-m-d');
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
            // See if this activity entity contains an offer that's now expired,
            // and if so set the "Past (expired) offer" setting.
            $offer_duration = field_get_items('node', $node, 'field_activity_offer_duration');
            if (isset($offer_duration[0]['value2'])) {
              if ($offer_duration[0]['value2'] < $now && !in_array('past_license_offer', $computed_status)) {
                $computed_status[] = 'past_license_offer';
              }
            }
          }
        }
      }
      // Also see if this resource has a source status that indicates it's a
      // full CRL review.
      $source_status = crl_helpers_get_single_node_field($entity, 'field_resource_source_status');
      if ($source_status == 'crl_review' && !in_array('crl_review_available', $computed_status)) {
        $computed_status[] = 'crl_review_available';
      }
      return $computed_status;
      
  }
}


// Callback to centrally define the key|value pairs used for the various
// CRL status options. This may be called via multiple contexts.
function crl_helpers_activity_status_property_oplist($arg1 = NULL) {
  // Define fields set be editors on activity entity.
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


function crl_helpers_activity_status_property_sort(array $a, array $b) {
  $weights = array(
    'crl_desiderata' => 10,
    'license_under_consideration' => 20,
    'license_available' => 30,
    'license_renewal_available' => 40,
    'trial_access_available' => 50,
    'past_license_offer' => 60,
    'crl_review_available' => 70,
  );
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


// Helper function to actually check and mark resource entries as "dirty" when
// a related activity entry is added/changed/removed.
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
