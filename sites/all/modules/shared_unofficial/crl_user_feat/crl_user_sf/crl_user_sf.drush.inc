<?php

/**
 * Implements hook_drush_command().
 */
function crl_user_sf_drush_command() {
  $items['sf-link-users'] = array(
    'description' => 'Bulk link existing users to existing Salesforce contacts.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array('crowd'),
    'arguments' => array(),
    'examples' => array(
      'drush sf-link-users' => 'Follow prompts to link existing users to existing Salesforce contacts.',
    ),
  );
  $items['sf-check-liaisons'] = array(
    'description' => 'Check SF liaison values against Crowd values.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array('crl_user_sf', 'crowd'),
    'arguments' => array(),
    'examples' => array(
      'drush sf-check-liaison' => 'Check SF liaison values against Crowd values.',
    ),
  );
  $items['sf-refresh-users'] = array(
    'description' => 'Mark all existing user records as outdated such that their data will be re-pulled from Salesforce.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array('crl_user_sf', 'crowd'),
    'arguments' => array(),
    'examples' => array(
      'drush sf-refresh-users' => 'Mark all existing user records as outdated such that their data will be re-pulled from Salesforce.',
    ),
  );
  $items['sf-clear-cron'] = array(
    'description' => 'Run cron enough times to ensure crowd_batch_pull and salesforce_pull queues are clear.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array('crl_user_sf', 'crowd'),
    'arguments' => array(),
    'examples' => array(
      'drush sf-refresh-users' => 'Run cron enough times to ensure crowd_batch_pull and salesforce_pull queues are clear.',
    ),
  );
  return $items;
}


/**
 * Callback for sf-link-users command.
 */
function drush_crl_user_sf_sf_link_users() {
  // Query full list of SF users.
  $sfapi = salesforce_get_api();
  $version_path = parse_url($sfapi->getApiEndPoint(), PHP_URL_PATH);
  $query = "SELECT FirstName, LastName, Email, AccountId FROM Contact ORDER BY Email ASC";
  if ($sfapi->isAuthorized()) {
    $results = $sfapi->apiCall('query?q=' . urlencode($query));
    $sf_contacts = array();
    $sf_contacts_no_email = array();
    if (!empty($results['records'])) {
      foreach ($results['records'] as $result) {
        if (empty($result['Email'])) {
          $sf_contacts_no_email[] = $result;
        }
        else {
          $sf_contacts[mb_strtolower($result['Email'])] = $result;
        }
      }
      // Handle requests larger than the batch limit (usually 2000).
      $next_records_url = isset($results['nextRecordsUrl']) ? str_replace($version_path, '', $results['nextRecordsUrl']) : FALSE;
      while ($next_records_url) {
        $new_result = $sfapi->apiCall($next_records_url);
        if (!isset($new_result['errorCode'])) {
          foreach ($new_result['records'] as $result) {
            if (empty($result['Email'])) {
              $sf_contacts_no_email[] = $result;
            }
            else {
              $sf_contacts[mb_strtolower($result['Email'])] = $result;
            }
          }
        }
        $next_records_url = isset($new_result['nextRecordsUrl']) ?
          str_replace($version_path, '', $new_result['nextRecordsUrl']) : FALSE;
      }
    }
    // Query full list of Crowd users. We get this based on which Drupal users
    // are linked to Crowd in the authmap table, assuming we have a recent sync
    // of the remore Crowd directory.
    $query = "SELECT u.uid, u.name, u.mail FROM {users} AS u INNER JOIN {authmap} AS a ON u.uid = a.uid WHERE a.module = :authgroup ORDER BY u.mail ASC";
    $d_results = db_query($query, array(':authgroup' => 'crowd'))->fetchAllKeyed(1);
    $drupal_users = array();
    foreach ($d_results as $email => $d_result) {
      $drupal_users[mb_strtolower($email)] = $d_result;
    }
    drush_log(dt('Detected @sf_count SF users, @drupal_count Crowd users.', array('@sf_count' => count($sf_contacts), '@drupal_count' => count($drupal_users))), 'ok');
    // See what direct matches exist.
    $matched = array_intersect_key($sf_contacts, $drupal_users);
    $unmatched = array_diff_key($sf_contacts, $drupal_users);
    drush_log(dt('@matched_count SF users can be directly linked to existing Crowd users based on matching email.', array('@matched_count' => count($matched))), 'ok');
    // Look for potential matches based on first and last name.
    $potential_matches = array();
    $potential_match_details_path = file_default_scheme() . '://potential_matches.csv';
    $fp = fopen($potential_match_details_path, "w+");
    foreach ($unmatched as $unmatched_mail => $sf_record) {
      if (!empty($sf_record['LastName']) && !empty($sf_record['FirstName'])) {
        $query = new EntityFieldQuery;
        $query
          ->entityCondition('entity_type', 'user')
          ->fieldCondition('field_last_name', 'value', $sf_record['LastName'], '=')
          ->fieldCondition('field_first_name', 'value', $sf_record['FirstName'], '=');
        $results = $query->execute();
        if (!empty($results['user'])) {
          $i = 0;
          foreach ($results['user'] as $id => $data) {
            $user = user_load($id);
            if (!isset($matched[$user->name])) {
              $potential_matches[$unmatched_mail][] = $user;
              $csv_values = $i ? array('"', '"', '"', '"', $user->name, $user->status, crl_user_get_institution($user->uid)) : array($unmatched_mail, $sf_record['FirstName'], $sf_record['LastName'], crl_user_get_institution(NULL, $sf_record['AccountId']), $user->name, $user->status, crl_user_get_institution($user->uid));
              fputcsv($fp, $csv_values);
            }
            $i++;
          }
        }
      }
    }
    drush_log(dt('@potential_match_count SF users without matching email still have at least one potential Crowd user match based on first and last names.', array('@potential_match_count' => count($potential_matches))), 'ok');
    drush_log(dt('Potential match details have been written to @path', array('@path' => $potential_match_details_path)), 'ok');
  }
}


/**
 * Callback for sf-check-liaisons Drush command.
 */
function drush_crl_user_sf_sf_check_liaisons() {
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'user');
  $result = $query->execute();
  $uids = !empty($result['user']) ? $result['user'] : array();
  if (drush_confirm(dt('This will check all @count users on the site for liaison setting accuracy by comparing Salesforce and Crowd data. Are you sure you want to continue?', array('@count' => count($uids))))) {
    $users = user_load_multiple(array_keys($uids));
    foreach ($users as $user) {
      $sf_roles = _crl_user_sf_get_contact_roles($user);
      $crowd_groups = crowd_client_connect()->getUserGroups(crowd_user_authmap_name($user->name));
      $sf_liaison = isset($sf_roles['Liaison']);
      $crowd_liaison = (array_search('liaison', $crowd_groups) !== FALSE);
      if ($sf_liaison !== $crowd_liaison) {
        drush_log(dt('Liaison value mismatch for @name: SF Value = @sf_liaison, Crowd Value = @crowd_liaison', array('@name' => $user->name, '@sf_liaison' => $sf_liaison, '@crowd_liaison' => $crowd_liaison)), 'warning');
      }
    }
  }
}


/**
 * Callback for sf-refresh-users Drush command.
 */
function drush_crl_user_sf_refresh_users() {
  if (drush_confirm(dt('This will mark all user records that are linked to Salesfoce as outdated and then trigger the maintenance tasks to refresh them. THIS MUST BE RUN INSIDE A LOCAL DRUPAL ROOT and not via a Drush alias. Are you sure you want to continue?'))) {
    // Start by ensuring there is nothing in the queues already.
    crl_user_sf_clear_cron();
    // Mark user entities and related linked data entities as outdated.
    foreach (array('user', 'sf_contact_role') as $type) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', $type);
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
    // remote records as new. We do this last so that any cron runs that may be
    // automatically triggered during the processes above do not start syncing
    // data for partially processed records.
    variable_del('salesforce_pull_last');
    variable_del('salesforce_pull_last_sync_Contact');
    variable_del('salesforce_pull_last_sync_Role__c');
    // Sleep for a couple min to allow for time offsets and variances in remote
    // timestamps that are used in update calculations.
    drush_log(dt('Sleeping for 2 min to account for timestamp variances and offsets across systems...'), 'status');
    sleep(120);
    // Do the refresh via cron.
    crl_user_sf_clear_cron(4, 120);
  }
}


/**
 * Callback for sf-clear-cron Drush command.
 */
function drush_crl_user_sf_clear_cron() {
  crl_user_sf_clear_cron();
}


/**
 * Run cron enough times to ensure crowd_batch_pull and salesforce_pull queues
 * are clear.
 *
 * @param int $reps
 *   The number os sequential cron runs that must pass wihthout any items in the
 *   queue before completion.
 * @param int dealy
 *   The number of seconds to pause between each cron run
 */
function crl_user_sf_clear_cron($reps = 2, $delay = 20) {
  $crowd_queue = DrupalQueue::get('crowd_batch_pull');
  $sf_queue = DrupalQueue::get('salesforce_pull');
  $passed = 0;
  while ($passed < $reps) {
    drush_log(dt('Running Cron to process pending Salesforce and Crowd pull items...'), 'status');
    // Trigger cron. Note that we can't use drupal_cron_run() for this directly
    // as we need each cron run to be started with a new REQUEST_TIME. This
    // ensures that timestamp comparisons and offsets used by pull detection
    // logic work as expected.
    $start_time = time();
    drush_shell_exec('drush cron');
    $output = drush_shell_exec_output();
    if (strpos($output[0], 'Cron run successful') !== FALSE) {
      $sf_items = $sf_queue->numberOfItems();
      $crowd_items = $crowd_queue->numberOfItems();
      if ($sf_items || $crowd_items) {
        drush_log(dt('There are still items in the queue (Salesforce Pull: @sf_num, Crowd Pull: @crowd_num).', array('@sf_num' => $sf_items, '@crowd_num' => $crowd_items)), 'status');
        $passed = 0;
      }
      else {
        $passed++;
      }
      // Sleep as needed to accomodate $delay
      if (time() - $start_time < $delay) {
        sleep($delay - (time() - $start_time));
      }
    }
    else {
      drush_log($output[0], 'warning');
      drush_log(dt('Cron could not be run properly. Please run cron manually as needed to clear the pull queues. Quitting.'), 'warning');
      break;
    }
  }
}
