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
    $license_available_marked = $this->get_resources_by_active_status($this->a_node_type, $this->a_field_status, 'a30_license_available');
    $license_available_not_expired = $this->get_resources_by_t_range($this->a_node_type, $this->a_field_offer_duration, date('Y-m-d'));
    foreach (array_diff($license_available_marked, $license_available_not_expired) as $nid) {
      $this->status_changes[$nid]['remove'][] = 'a30_license_available';
      $this->status_changes[$nid]['remove'][] = 'a40_license_renewal_available';
    }
    // See what activity entities are marked as "trial access available" and
    // compare to which ones have an offer expiration date that's still in the
    // future.
    $trial_available_marked = $this->get_resources_by_active_status($this->a_node_type, $this->a_field_status, 'a50_trial_access_available');
    $trial_available_not_expired = $this->get_resources_by_t_range($this->a_node_type, $this->a_field_trial_duration, date('Y-m-d'));
    foreach (array_diff($trial_available_marked, $trial_available_not_expired) as $nid) {
      $this->status_changes[$nid]['remove'][] = 'a50_trial_access_available';
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
          // When removing AND adding we check that the given status is not 
          // already set. If adding a status, and for some reason the EFQ that 
          // got us to this point is incorrect, we could end up adding a new 
          // status value each time this is run... which would be bad as it 
          // would lead to accumulating corrupt status values.
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
 * 
 * Add a new entity property that will be used to define the formal CRL status
 * associated with any given resource.
 */
function crl_helpers_entity_property_info_alter(&$info) {
  $properties = &$info['node']['properties'];
  $properties['crl_activity_backref'] = array(
    'label' => t("CRL Actvity Status Through Backreference"),
    'type' => 'list<text>',
    'description' => t("Gets CRL Actvity Status Through Backreference."),
    'getter callback' => 'crl_helpers_activity_status_property_get',
    'options list' => 'crl_helpers_activity_status_property_oplist',
  );
}


// Callback function to actaully calculate the status associated with a
// resource. This function queires numerous places and aggregates the results
// into this one entity property.
function crl_helpers_activity_status_property_get($entity, array $options, $name, $type, $info) {
  $now = date('Y-m-d');
  $computed_status = array();
  list($id) = entity_extract_ids($type, $entity);
  // Get the activity entries that reference this resource.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node', '=')
        ->entityCondition('bundle', 'activity')
        ->fieldCondition('field_resource_reference', 'target_id', $id, '=');
  $result = $query->execute();
  // Load the related activity entities and get the status set on them.
  if (!empty($result['node'])) {
    $backref_nids = array_keys($result['node']);
    // Consider revisting to fetch one field instead of full node_load, see:
    // http://btmash.com/article/2012-04-13/i-just-want-one-field-using-fieldattachload
    $backref_nodes = node_load_multiple($backref_nids);
    foreach ($backref_nodes as $nid => $node) {
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
      // See if this activity entity contains an offer that's now expired, and
      // if so set the "Past (expired) offer" setting.
      $offer_duration = field_get_items('node', $node, 'field_activity_offer_duration');
      if (isset($offer_duration[0]['value2'])) {
        if ($offer_duration[0]['value2'] < $now && !in_array('a60_past_license_offer', $computed_status)) {
          $computed_status[] = 'a60_past_license_offer';
        }
      }
    }
  }
  // Also see if this resource has a source status that indicates it's a full
  // CRL review.
  $source_status = crl_helpers_get_single_node_field($entity, 'field_resource_source_status');
  if ($source_status == 'crl_review' && !in_array('a70_crl_review_available', $computed_status)) {
    $computed_status[] = 'a70_crl_review_available';
  }
  return $computed_status;
}


// Callback to centrally define the key|value pairs used for the various
// CRL status options. This may be called via multiple contexts.
function crl_helpers_activity_status_property_oplist($arg1 = NULL) {
  // Define fields set be editors on activity entity.
  $options = array(
    'a10_crl_desiderata' => t('CRL Desiderata'),
    'a20_license_under_consideration' => t('License terms under consideration'),
    'a30_license_available' => t('License offer available'),
    'a40_license_renewal_available' => t('License renewal available'),
    'a50_trial_access_available' => t('Trial access available'),
  );
  // If $arg1['id'] is set this is probably being called while a node is being
  // edited. In this case we do NOT want to add the following system-managed
  // fields to the options array.
  if (1) {
    $options_sys = array(
      'a60_past_license_offer' => t('Past (expired) license offer'),
      'a70_crl_review_available' => t('CRL Review available'),
    );
    $options = array_merge($options, $options_sys); 
  }
  return $options;
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


/**
 * Implements hook_form_BASE_FORM_ID_alter().
 * 
 * When updating an activity entity enforce some custom validation rules on
 * the CRL status settings.
 */
function crl_helpers_form_activity_node_form_alter(&$form, &$form_state, $form_id) {
  $form['#validate'][] = 'crl_helpers_activity_node_form_validate';
}


// Validation callback for activity_node_form
function crl_helpers_activity_node_form_validate(&$form, &$form_state) {
  $set_status = array();
  $language = $form['language']['#value'];
  if (!empty($form_state['values']['field_activity_crl_status'][$language])) {
    foreach($form_state['values']['field_activity_crl_status'][$language] as $item) {
      if (!empty($item['value'])) {
        $set_status[] = $item['value'];
      }
    }
  }
  // Handle case where an offer is set while another status is set that is
  // mutually exclusive.
  $dissallow_with_offer = array_intersect($set_status, array('a10_crl_desiderata', 'a20_license_under_consideration'));
  if (in_array('a30_license_available', $set_status) && !empty($dissallow_with_offer)) {
    form_set_error('field_activity_crl_status', t('"License Offer Available" cannot be set while "CRL Desiderata" or "License terms under consideration" are also set.'));
  }
  // Handle case where "License renewal available" is set without "License
  // available"
  if (in_array('a40_license_renewal_available', $set_status) && !in_array('a30_license_available', $set_status)) {
    form_set_error('field_activity_crl_status', t('"License Renewal Available" should only be set if "License Available" is also set.'));
  }
  $now = date('Y-m-d');
  // If the offer end date is not in the future the offer status should not
  // be set.
  if (in_array('a30_license_available', $set_status)) {
    if ($form_state['values']['field_activity_offer_duration'][$language][0]['value2'] < $now) {
      form_set_error('field_activity_offer_duration', t('"License Offer Available" cannot be set while the offer expiration date is either not set or is in the past.'));
    }
  }
  // If the trial end date is not in the future the "Trial Access Available"
  // status should not be set.
  if (in_array('a50_trial_access_available', $set_status)) {
    if ($form_state['values']['field_activity_trial_duration'][$language][0]['value2'] < $now) {
      form_set_error('field_activity_trial_duration', t('"Trial Access Available" cannot be set while the trial expiration date is either not set or is in the past.'));
    }
  }
}
