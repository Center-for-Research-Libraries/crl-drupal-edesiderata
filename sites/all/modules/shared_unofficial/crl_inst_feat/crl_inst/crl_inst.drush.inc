<?php

/**
 * Implements hook_drush_command().
 */
function crl_inst_drush_command() {
  $items['sf-refresh-inst'] = array(
    'description' => 'Mark all existing inst records as outdated such that their data will be re-pulled from Salesforce.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array(),
    'arguments' => array(),
    'examples' => array(
      'drush sf-refresh-users' => 'Mark all existing user records as outdated such that their data will be re-pulled from Salesforce.',
    ),
  );
  return $items;
}


/**
 * Callback for sf-refresh-inst Drush command.
 */
function drush_crl_inst_sf_refresh_inst() {
  if (drush_confirm(dt('This will mark all institution records that are linked to Salesfoce as outdated. Are you sure you want to continue?'))) {
    // Mark user entities and related linked data entities as outdated.
    foreach (array('node', 'sf_net_affiliation') as $type) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', $type);
      if ($type == 'node') {
        $query->entityCondition('bundle', 'institution');
      }
      $result = $query->execute();
      $ids = !empty($result[$type]) ? $result[$type] : array();
      $total = count($ids);
      $processed = 0;
      $reported_percent = 0;
      drush_log(dt('Marking @num @type records as outdated...', array('@num' => $total, '@type' => $type)), 'status');
      foreach ($ids as $id => $data) {
        $map = salesforce_mapping_object_load_by_drupal($type, $id);
        if ($map) {
          // Reset the timestamp and add some details that will make the mapping
          // revision history appear logical.
          $map->entity_updated = 1;
          $map->last_sync_message = t('Dummy entry to force refresh by resetting timestamp');
          $map->last_sync_status = SALESFORCE_MAPPING_STATUS_SUCCESS;
          $map->save();
        }
        $processed++;
        $percent = $processed / $total * 100;
        if ($percent > $reported_percent + 10) {
          drush_log(dt('@percent% of @type records processed (@processed/@total)', array('@percent' => floor($percent), '@type' => $type, '@processed' => $processed, '@total' => $total)), 'status');
          $reported_percent = $percent;
        }
      }
    }
    // Reset timestamps for last sync so SF queries will treat all related
    // remote records as new.
    variable_del('salesforce_pull_last');
    variable_del('salesforce_pull_last_sync_Account');
    variable_del('salesforce_pull_last_sync_Network_Affiliation__c');
    drush_log(dt('Institution records have been marked outdated. Please allow for several cron runs to compelete before refreshed data is fully pulled from Salesforce.'), 'success');
  }
}
