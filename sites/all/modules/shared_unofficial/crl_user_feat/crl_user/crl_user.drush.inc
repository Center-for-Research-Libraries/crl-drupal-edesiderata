<?php

/**
 * Implements hook_drush_command().
 */
function crl_user_drush_command() {
  $items['crowd-user-sync'] = array(
    'description' => 'Bulk sync User data from Crowd to Drupal.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array('crowd'),
    'arguments' => array(
      'group' => 'Group',
      'limit' => 'Query Limit',
    ),
    'examples' => array(
      'drush crowd-user-sync liaison' => 'Sync user data for all users of the the Crowd liaison group to Drupal.',
    ),
  );
  $items['crowd-set-authmap'] = array(
    'description' => 'Set Crowd authmap value for all users.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array('crowd'),
    'arguments' => array(),
    'examples' => array(
      'drush crowd-set-authmap' => 'Write crowd authmap value for all Drupal users that have a matching entry in Crowd.',
    ),
  );
  $items['crowd-test-connection'] = array(
    'description' => 'Verify the crowd and ldap connection.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array('crowd'),
    'arguments' => array(),
    'examples' => array(
      'drush crowd-test-connection' => 'Check that crowd and ldap are working end-to-end.',
    ),
  );
  $items['ldap-write-misc'] = array(
    'description' => 'Write misc user profile values from Drupal to the encoded description attribute in LDAP.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'arguments' => array(
      'real' => 'Real',
    ),
    'examples' => array(
      'drush ldap-write-misc' => 'Write misc user profile values from Drupal to the encoded description attribute in LDAP.',
    ),
  );
  $items['ldap-write-hosts'] = array(
    'description' => 'Write specific host value in LDAP for all users.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array('crowd'),
    'arguments' => array(
      'host' => 'host',
    ),
    'examples' => array(
      'drush ldap-write-host www.crl.edu' => 'Write a www.crl.edu hosts entry in LDAP for all users.',
    ),
  );
  $items['check-user-dups'] = array(
    'description' => 'Check for duplicate names across local usernames, emails and authnames.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array('entity'),
    'arguments' => array(),
    'examples' => array(
      'drush sf-check-dups' => 'Check for duplicate names across local usernames, emails and authnames.',
    ),
  );
    $items['resave-crowd-users'] = array(
    'description' => 'Resave Crowd users after LDAP pull.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array('entity'),
    'arguments' => array(),
  );
  return $items;
}


/**
 * Callback for crowd-user-sync Drush command.
 */
function drush_crl_user_crowd_user_sync($group = NULL, $limit = 1000) {
	drush_log(dt('This process will sync data from all users in Crowd group "@group" to Drupal.', array('@group' => $group)), 'ok');
  // Get base member data from Crowd.
  $crowd_client = crowd_client_connect();
  $members = $crowd_client->getGroupMembers($group, 0, $limit);
  $members_not_in_drupal = $members_synced = $members_created = array();
  if (!empty($members)) {
    // See how many members were detected in Crowd. The default limit for most
    // API calls is 1000 records, so put up a warning if we might be going over
    // that. This script would need to be modified to split the query up if we
    // want to support more that 1000 records.
    if (count($members) >= $limit) {
      $continue_prompt = dt('There appear to be more than !limit users in Crowd group "@group". This script will only process the first @limit. Do you want to continue anyway?', array('@group' => $group, '@limit' => $limit));
    }
    else {
      $continue_prompt = dt('Detected @count users in Crowd group "@group", continue with the sync process?', array('@count' => count($members), '@group' => $group));
    }
    if (!drush_confirm($continue_prompt)) {
      drush_die(dt('Aborting.'), 'ok');
    }
    drush_print('');
    // Run the sync on members that already exist in both Crowd and Drupal.
    foreach ($members as $member) {
      $drupal_user = user_load_by_name($member);
      $crowd_user = $crowd_client->getUserFromName($member);
      if ($drupal_user) {
        crowd_pull_user_data($drupal_user, $crowd_user);
        $members_synced[$member] = $crowd_user;
        drush_log(dt('Synced user @user', array('@user' => $member)), 'notice');
      }
      else {
        $members_not_in_drupal[$member] = $crowd_user;
        drush_log(dt('Cound not find matching Drupal user for Crowd user @user', array('@user' => $member)), 'warning');
      }
    }
    drush_print('');
    drush_log(dt('@members_synced group members were synced to Drupal, @members_not_in_drupal group members were not synced because no matching Drupal account was found.', array('@members_synced' => count($members_synced), '@members_not_in_drupal' => count($members_not_in_drupal))), 'ok');
    // Optionally loop through the members that don't yet exist in Drupal and
    // offer to create them.
    if (!empty($members_not_in_drupal) && drush_confirm(dt('Would you like to create local accounts for the @members_not_in_drupal users that do not yet exist in Drupal?', array('@members_not_in_drupal' => count($members_not_in_drupal))))) {
      foreach ($members_not_in_drupal as $member_to_create => $crowd_user_data) {
        // This create logic is straight from user_external_login_register().
        $account = user_external_load($member_to_create);
        if (!$account) {
          // Register this new user.
          $userinfo = array(
            'name' => $member_to_create,
            'pass' => user_password(),
            'init' => $member_to_create,
            'status' => 1,
            'access' => REQUEST_TIME,
          );
          $account = user_save(drupal_anonymous_user(), $userinfo);
          // Terminate if an error occurred during user_save().
          if (!$account) {
            drush_set_error(dt('Error saving user account for username @name', array('@name' => $member_to_create)));
            continue;
          }
          user_set_authmaps($account, array("authname_crowd" => $member_to_create));
          // Also sync to Crowd.
          crowd_pull_user_data($account, $crowd_user_data);
          $members_created[] = $member_to_create;
          drush_log(dt('Created and synced user @user', array('@user' => $member_to_create)), 'notice');
        }
        else {
          drush_set_error(dt('Something is wrong. User @name does not have a Drupal account but they do have a record in the Drupal authmap table', array('@name' => $member_to_create)));
        }
      }
      drush_log(dt('@members_created Drupal accounts were created and synced with Crowd from group "@group"', array('@members_created' => count($members_created), '@group' => $group)), 'ok');
    }
  }
  else {
    drush_log(dt('Nothing to do. Please verify that you have specified a valid group.'), 'ok');
  }
}


/**
 * Callback for crowd-set-authmap Drush command.
 */
function drush_crl_user_crowd_set_authmap() {
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'user');
  $result = $query->execute();
  $uids = !empty($result['user']) ? $result['user'] : array();
  if (drush_confirm(dt('This will check all @count users on the site for a matching Crowd entry, and if one is found it will set a local authmap value. Are you sure you want to continue?', array('@count' => count($uids))))) {
    $users = user_load_multiple(array_keys($uids));
    try {
      $crowd = crowd_client_connect();
      foreach ($users as $user) {
        $crowd_user = $crowd->getUserFromName($user->name);
        if ($crowd_user && mb_strtolower($crowd_user['name']) == mb_strtolower($user->name)) {
          user_set_authmaps($user, array('authname_crowd' => $crowd_user['name']));
          drush_log(dt('Added authmap value for @user', array('@user' => $user->name)), 'notice');
        }
        else {
          $c_username = isset($crowd_user['name']) ? $crowd_user['name'] : 'unknown';
          drush_log(dt('Did not add the authmap value for user @user, they probably do not have a Crowd account or something else is wrong. Crowd username was @c_user', array('@user' => $user->name, '@c_user' => $c_username)), 'warning');
        }
      }
    }
    catch (Exception $e) {
      watchdog_exception('crl user', $e);
    }
  }
}

/**
 * Callback for crowd-set-authmap Drush command.
 */
function drush_crl_user_crowd_test_connection() {
  // Test Crowd
  $date = date(DATE_RSS);
  $crowd_fail = FALSE;
  try {
    $crowd = crowd_client_connect();
    // Use known test credentials to do an end-to-end authentication test.
    if ($crowd->authorize('member@crl.edu', 'Crl14user')) {
      drush_log(dt('@date, End-to-end Crowd connection is working.', array('@date' => $date)), 'ok');
    }
    else {
      $crowd_fail = TRUE;
    }
  }
  catch (\Exception $ex) {
    $crowd_fail = TRUE;
  }
  if ($crowd_fail) {
    drush_log(dt('@date, Crowd authentication test failed.', array('@date' => $date)), 'error');
    // Test direct LDAP link.
    $ldap_fail = FALSE;
    try {
      $ldap = crl_user_ldap_connect();
      if ($ldap->getInfo('member@crl.edu')) {
        drush_log(dt('@date, Direct LDAP connection is working.', array('@date' => $date)), 'ok');
      }
      else {
        $ldap_fail = TRUE;
      }
    }
    catch (Exception $ex) {
      $ldap_fail = TRUE;
    }
    if ($ldap_fail) {
      drush_log(dt('@date, Direct LDAP connection failed.', array('@date' => $date)), 'error');
    }
  }
}

/**
 * Callback for ldap-write-misc Drush command.
 */
function drush_crl_user_ldap_write_misc($real = 'not real') {
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'user');
  $result = $query->execute();
  $uids = !empty($result['user']) ? $result['user'] : array();
  $updated = 0;
  if (drush_confirm(dt('This will write misc user profile values from Drupal to the encoded description attribute in LDAP for all @count users on the site. Are you sure you want to continue? (@real)', array('@count' => count($uids), '@real' => $real)))) {
    $users = user_load_multiple(array_keys($uids));
    try {
      $ldap = crl_user_ldap_connect();
      foreach ($users as $user) {
        $authmaps = user_get_authmaps($user->name);
        $title = entity_metadata_wrapper('user', $user)->field_profile_title->value();
        // See if we have a Crowd user who also has misc required profile fields
        // filled-in (from provisioning).
        if (is_array($authmaps) && array_key_exists('crowd', $authmaps) && !empty($title)) {
          $current_ldap_info = $ldap->getInfo($user->name);
          // If the user already has the misc fields populated in LDAP this may
          // be strange given that they could not have been provisioned in two
          // places.
          if (!empty($current_ldap_info['field_profile_title'])) {
            drush_log(dt('User @user has misc attributes set both locally and in Crowd already. This may need additional confirmation.', array('@user' => $user->name)), 'warning');
          }
          // Qrite the values to LDAP.
          $success = ($real === 'real') ? $ldap->updateLdapFromUser(crowd_user_authmap_name($user->name), $user) : TRUE;
          $success = TRUE;
          if ($success) {
            drush_log(dt('LDAP values set for @user.', array('@user' => $user->name)), 'ok');
            $updated++;
          }
          else {
            drush_log(dt('There was a problem setting LDAP values for @user.', array('@user' => $user->name)), 'error');
          }
        }
      }
    }
    catch (Exception $e) {
      watchdog_exception('crl user', $e);
    }
    drush_log(dt('Updated LDAP values set for @count users.', array('@count' => $updated)), 'ok');
  }
}

/**
 * Callback for resave-crowd-users Drush command.
 */
function drush_crl_user_resave_crowd_users() {
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'user');
  $result = $query->execute();
  $uids = !empty($result['user']) ? $result['user'] : array();
  $updated = 0;
  if (drush_confirm(dt('This will resave @count users on the site. Are you sure you want to continue?', array('@count' => count($uids))))) {
    $users = user_load_multiple(array_keys($uids));
    try {
      $ldap = crl_user_ldap_connect();
      $count = 0;
      foreach ($users as $user) {
        $authmaps = user_get_authmaps($user->name);
        if (is_array($authmaps) && array_key_exists('crowd', $authmaps)) {
          // Update from current LDAP data and trigger save directly.
          //$success = $ldap->updateUserFromLdap(crowd_user_authmap_name($user->name), $user, TRUE);
          $success = user_save($user);
          if ($success) {
            drush_log(dt('User @user saved.', array('@user' => $user->name)), 'ok');
            $updated++;
          }
          else {
            drush_log(dt('There was an error updating user @user.', array('@user' => $user->name)), 'error');
          }
        }
        $count++;
      }
    }
    catch (Exception $e) {
      watchdog_exception('crl user', $e);
    }
    drush_log(dt('@count users re-saved.', array('@count' => $updated)), 'ok');
  }
}


/**
 * Callback for ldap-write-hosts Drush command.
 */
function drush_crl_user_ldap_write_hosts($host = '') {
  if (empty($host)) {
    drush_set_error(dt('A host argument is required'));
    return;
  }
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'user');
  $result = $query->execute();
  $uids = !empty($result['user']) ? $result['user'] : array();
  if (drush_confirm(dt('This will add a "host" value in LDAP of @host for all @count users on the site. Are you sure you want to continue?', array('@host' => $host, '@count' => count($uids))))) {
    $users = user_load_multiple(array_keys($uids));
    try {
      $ldap = crl_user_ldap_connect();
      foreach ($users as $user) {
        if ($ldap->updateHosts($user->name, $host)) {
          drush_log(dt('Added host value for @user', array('@user' => $user->name)), 'notice');
        }
        else {
          drush_log(dt('Did not add the host value in LDAP for user @user, they probably do not have an account in LDAP or they already contain this host.', array('@user' => $user->name)), 'warning');
        }
      }
    }
    catch (Exception $e) {
      watchdog_exception('crl user', $e);
    }
  }
}


/**
 * Callback for crl-user-check-dups Drush command.
 */
function drush_crl_user_check_user_dups() {
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'user');
  $result = $query->execute();
  $uids = !empty($result['user']) ? $result['user'] : array();
  if (drush_confirm(dt('Begin dup check for @count users? This may take a while.', array('@count' => count($uids))))) {
    $found_count = 0;
    $in_dup = $in_dup_combo = array();
    foreach ($uids as $uid => $data) {
      $user = user_load($uid);
      $user_wrapper = entity_metadata_wrapper('user', $user);
      // Check for duplicate values across all local usernames, emails and authnames.
      if (!in_array($uid, $in_dup)) {
        $query = "SELECT u.uid, u.name, u.mail FROM {users} AS u INNER JOIN {authmap} AS a ON u.uid = a.uid WHERE (u.name = :name OR u.mail = :name OR u.name = :mail OR u.mail = :mail) AND a.module = :authgroup";
        $results = db_query($query, array(':name' => $user->name, 'mail' => $user->mail, 'authgroup' => 'crowd'))->fetchAllKeyed();
        if (count($results) > 1) {
          $found_count++;
          drush_log(dt('Name @name and/or email @mail appears to be used across multiple Drupal users.', array('@name' => $user->name, '@mail' => $user->mail)), 'warning');
          foreach ($results as $uid => $data) {
            $in_dup[] = $uid;
            $user_dup = user_load($uid);
            $authname = crowd_user_authmap_name($user_dup->name);
            drush_log(dt('User: @uid, Status: @status, Name: @name, Email: @mail, Authname: @authname', array('@uid' => $user_dup->uid, '@name' => $user_dup->name, '@mail' => $user_dup->mail, '@authname' => $authname, '@status' => $user_dup->status)), 'warning');
          }
        }
      }
      // Then check for any other users that have the same name and inst combo.
      if (!in_array($uid, $in_dup_combo)) {
        $query_dup_combo = new EntityFieldQuery;
        $query_dup_combo->entityCondition('entity_type', 'user')
          ->propertyCondition('status', 1)
          ->fieldCondition('field_first_name', 'value', $user_wrapper->field_first_name->value(), '=')
          ->fieldCondition('field_last_name', 'value', $user_wrapper->field_last_name->value(), '=')
          ->fieldCondition('field_institution', 'value', $user_wrapper->field_institution->value(), '=');
        $result_dup_combo = $query_dup_combo->execute();
        $uids_dup_combo = !empty($result_dup_combo['user']) ? $result_dup_combo['user'] : array();
        if (count($uids_dup_combo) > 1) {
          $found_count++;
          drush_log(dt('More than one users share the same first name "@fname" last name "@lname" and inst "@inst" combination.', array('@fname' => $user_wrapper->field_first_name->value(), '@lname' => $user_wrapper->field_last_name->value(), '@inst' => crl_user_get_institution($uid))), 'warning');
          foreach ($uids_dup_combo as $uid_dup_combo => $data) {
            $in_dup_combo[] = $uid_dup_combo;
            $user_dup_combo = user_load($uid_dup_combo);
            drush_log(dt('User: @uid, Status: @status, Name: @name', array('@uid' => $user_dup_combo->uid, '@name' => $user_dup_combo->name, '@status' => $user_dup_combo->status)), 'warning');
          }
        }
      }
      entity_get_controller('user')->resetCache();
    }
    drush_log(dt('Found @found_count potential duplicate cases.', array('@found_count' => $found_count)), 'ok');
  }

}
