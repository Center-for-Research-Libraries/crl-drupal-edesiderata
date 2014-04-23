<?php


/**
 * @file
 * Includes logic to automatically update/expire activity status values on cron
 * runs based on their crl_status and related date-range values.
 */


class CrlActivityStatusSync {
  // Dynamic variables set by object methods.
  protected $statusChanges = array();
  protected $nodesToModify = array();

  /**
   * Check and execute a set of status updates.
   */
  public function runSync() {
    // First run calculations about what needs to be synced. This will populate
    // the $statusChanges and $nodesToModify properties.
    $this->calculateSync();
    // Loop though our status_changes array and apply the status changes.
    foreach($this->statusChanges as $nid => $types) {
      $node = &$this->nodesToModify[$nid];
      foreach ($types as $type_key => $statuses) {
        foreach ($statuses as $status_key => $status) {
          // When removing AND adding we unset the status if it's already set.
          // If adding a status, and for some reason the EFQ that got us to this
          // point is incorrect, we could end up adding a new status value each
          // time this is run... which would be bad as it would lead to
          // accumulating corrupt status values.
          $entity_wrapper = entity_metadata_wrapper('node', $node);
          $statuses_active = isset($entity_wrapper->field_activity_crl_status) ? $entity_wrapper->field_activity_crl_status->value() : array();
          if (!empty($statuses_active)) {
            foreach ($statuses_active as $key => $status_active) {
              if ($status_active == $status) {
                unset($node->field_activity_crl_status[$node->language][$key]);
              }
            }
          }
          if ($type_key == 'add') {
            $node->field_activity_crl_status[$node->language][] = array('value' => $status);
          }
        }
      }
      // Save the changes and be sure we also generate a new revision.
      $node->revision = TRUE;
      node_save_action($node);
    }
  }

  /**
   * Calculate which resources need status updates of various types and build
   * an array that captures all the specifics for later processing.
   */
  protected function calculateSync() {
    // Check which offers need an expiration.
    $offer_nodes_to_expire = $this->getNeedsExpiration('activity', 'field_activity_offer_duration', 'field_activity_crl_status', 'license_available');
    $this->nodesToModify += $offer_nodes_to_expire;
    foreach ($offer_nodes_to_expire as $nid => $node) {
      $this->statusChanges[$nid]['remove'][] = 'license_available';
      $this->statusChanges[$nid]['remove'][] = 'license_renewal_available';
      $this->statusChanges[$nid]['add'][] = 'past_license_offer';
    }
    // Check which trials need an expiration.
    $trial_nodes_to_expire = $this->getNeedsExpiration('activity', 'field_activity_trial_duration', 'field_activity_crl_status', 'trial_access_available');
    $this->nodesToModify += $trial_nodes_to_expire;
    foreach ($trial_nodes_to_expire as $nid => $node) {
      $this->statusChanges[$nid]['remove'][] = 'trial_access_available';
    }
    return $this;
  }

  /**
   * Get a set of nodes that need to have a certain status value expired.
   *
   * @param string $node_type
   *   The content type to check.
   * @param string $field_duration
   *   The date field that contains duration information for a status.
   * @param string $field_status
   *   The field that may contain the status value we want to check.
   * @param string $status_to_check
   *   The status value to check that can be set in $field_status and is
   *   controlled by $field_duration.
   * @return array
   *   Returns an indexed list of nodes, keyed by nid, that should have the
   *   $status_to_check status value removed because the related expiration
   *   data has passed.
   */
  protected function getNeedsExpiration($node_type, $field_duration, $field_status, $status_to_check) {
    $nids_past_end_date = $nodes_to_expire = array();
    // First, do an EFQ to fetch a list of nids that have our target status and
    // an associated end date which is in the past.
    $today = date('Y-m-d 00:00:00'); // Ensure matching format to value/value2
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $node_type)
      ->fieldCondition($field_status, 'value', $status_to_check, '=')
      ->fieldCondition($field_duration, 'value2', $today, '<')
      // Force query to run without access checks. This is safe as this is
      // just maintenance logic that's only called via cron.
      ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');
    $entities = $query->execute();
    if (!empty($entities['node'])) {
      $nids_past_end_date = array_keys($entities['node']);
    }
    // Second, we need to bulk load all our nodes that have a past end date so
    // that we can further compare this end date to the start date. The date
    // module will set both start and end dates equal when no end date is
    // collected (e.g. never expires), so we need to filter out these cases.
    // Unfortunatly it does not look like there is any way to incldue this type
    // of check directly in the EFQ above.
    $nodes_past_end_date = node_load_multiple($nids_past_end_date);
    foreach ($nodes_past_end_date as $node) {
      $duration = field_get_items('node', $node, $field_duration);
      // If value == value2 then it's a case where the end date is not collected
      // and we should NOT expire, so only mark value != value2 cases.
      if ($duration[0]['value'] != $duration[0]['value2']) {
        $nodes_to_expire[$node->nid] = $node;
      }
    }
    return $nodes_to_expire;
  }
}
