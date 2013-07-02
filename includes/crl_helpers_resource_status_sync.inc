<?php


/**
 * @file
 * Includes logic to automatically update/expire activity status values on cron
 * runs based on their crl_status and related date-range values. 
 */


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
      $this->status_changes[$nid]['add'][] = 'past_license_offer';
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

  // Get a set of node ids that SHOULD have a status based on a time range
  // on the node's date field.
  public function get_resources_by_t_range($node_type, $field_duration, $date) {
    // Get the active offers
    $nids_active = array();
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', $node_type)
          ->fieldCondition($field_duration, 'value2', $date, '>=')
          // Force query to run without access checks. This is safe as this is
          // just maintenance logic that's only called via cron.
          ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');
    $entities = $query->execute();
    if (!empty($entities['node'])) {
      $nids_active = array_keys($entities['node']);
    }
    return $nids_active;
  }
  
  // Get a set of node ids that DO have a specific status.
  public function get_resources_by_active_status($node_type, $field_status, $status) {    
    $nids_active = array();
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', $node_type)
          ->fieldCondition($field_status, 'value', $status, '=')
          // Force query to run without access checks. This is safe as this is
          // just maintenance logic that's only called via cron.
          ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');
    $entities = $query->execute();
    if (!empty($entities['node'])) {
      $nids_active = array_keys($entities['node']);
    }
    return $nids_active;  
  }
}
