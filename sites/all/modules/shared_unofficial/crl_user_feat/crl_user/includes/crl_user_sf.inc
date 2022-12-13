<?php


/**
 * @file
 * Logic only used in cron/bulk operations.
 */


/**
 * Helper to fetch the institution picklist from Salesforce.
 *
 * @see: crl_user_cron().
 */
function crl_user_sf_sync_inst() {
  if (module_exists('salesforce')) {
    $sf = salesforce_get_api();
    if ($sf->isAuthorized()) {
      // Run the base queries that we'll need.
      $query_full = "SELECT Display_Name__c, Id, Member_ID__c From Account WHERE Parent_Member_Type__c = NULL ORDER BY Name_for_sorting__c ASC";
      $query_mem = "SELECT Display_Name__c, Id, Member_ID__c From Account WHERE (Active__c = TRUE) AND (Member_Type__c = 'Voting' OR Member_Type__c = 'Group' OR Member_Type__c = 'Global') ORDER BY Name_for_sorting__c ASC";
      // We use the apiCall method directly (as opposed to building a
      // SalesforceSelectQuery object) as some of our queries use nested
      // conditions that may not be possible to represent otherwise.
      $sf_records_full_raw = $sf->apiCall('query?q=' . urlencode($query_full));
      $sf_records_mem_raw = $sf->apiCall('query?q=' . urlencode($query_mem));
      $sf_records_full = isset($sf_records_full_raw['records']) ? $sf_records_full_raw['records'] : array();
      $sf_records_mem = isset($sf_records_mem_raw['records']) ? $sf_records_mem_raw['records'] : array();
    }
    // Sort-out details for FULL institution list.
    if (!empty($sf_records_full)) {
      $institutions_array_sfid = array();
      $institutions_array_id = array();
      $institutions_array_id_map = array();
      foreach ($sf_records_full as $record) {
        if (isset($record['Id']) && isset($record['Display_Name__c'])) {
          $display_name = $record['Display_Name__c'];
          $institutions_array_sfid[$record['Id']] = $display_name;
          if (isset($record['Member_ID__c'])) {
            // Store name keyed by crlid and an id map.
            $institutions_array_id[$record['Member_ID__c']] = $record['Display_Name__c'];
            $institutions_array_id_map[$record['Member_ID__c']] = $record['Id'];
          }
        }
      }
      // Store results.
      variable_set('crl_sf_sync_institutions_array_sfid', $institutions_array_sfid);
      variable_set('crl_sf_sync_institutions_array_crlid', $institutions_array_id);
      variable_set('crl_sf_sync_institutions_array_id_map', $institutions_array_id_map);
    }
    // Sort-out details for MEMBER institution list.
    if (!empty($sf_records_mem)) {
      $institutions_array_sfid_mem = array();
      $no_id_array = array();
      foreach ($sf_records_mem as $record) {
        if (isset($record['Id']) && isset($record['Display_Name__c'])) {
          // Store name keyed by sfid.
          $institutions_array_sfid_mem[$record['Id']] = $record['Display_Name__c'];
          // All mem institutions should have a CRL ID, so flag any cases that
          // do not
          if (empty($record['Member_ID__c'])) {
            $no_id_array[$record['Id']] = $record['Display_Name__c'];
          }
        }
      }
      // Report cases where CRL ID is missing from the member list.
      if (!empty($no_id_array)) {
        $institutions_sans_id = '';
        foreach($no_id_array as $value) {
          $institutions_sans_id .= $value . ", ";
        }
        watchdog('crl user', 'The following member institutions have no CRL id in Salesforce: @institutions_sans_id', array('@institutions_sans_id' => $institutions_sans_id), WATCHDOG_WARNING);
      }
      // If we found changes to our member list queue run checks for all local
      // affiliated users.
      $current_mem_array = variable_get('crl_sf_sync_institutions_array_sfid_mem');
      // Diff both ways to get ALL changes.
      $changes = array_merge(array_diff($current_mem_array, $institutions_array_sfid_mem), array_diff($institutions_array_sfid_mem, $current_mem_array));
      if ($changes) {
        $queue = DrupalQueue::get('crl_user_update_mem_roles');
        $added = 0;
        foreach ($changes as $sfid => $inst) {
          $added += (int) $queue->createItem($sfid);
        }
        watchdog('crowd user', 'Detected a CRL member status change in %count institutions. The users affiliated with these institutions have been queued for an update to correctly set their local member role details.', array('%count' => count($changes)));
      }
      // Store results.
      variable_set('crl_sf_sync_institutions_array_sfid_mem', $institutions_array_sfid_mem);
      variable_set('crl_sf_sync_institutions_array', $institutions_array_sfid_mem);
    }
  }
}
