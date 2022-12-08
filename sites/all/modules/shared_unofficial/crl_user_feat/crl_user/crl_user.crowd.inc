<?php


/**
 * @file
 * Hook implementations specific to Crowd.
 */


/**
 * Implements hook_crowd_push_user_data_alter().
 */
function crl_user_crowd_push_user_data_alter(&$data, &$groups, $account) {
  $username = !empty($data['name']) ? $data['name'] : $data['authname'];
  $wrapper = entity_metadata_wrapper('user', $account);
  // First and last name values come from the local profile fields.
  $data['first-name'] = $wrapper->field_first_name->value();
  $data['last-name'] = $wrapper->field_last_name->value();
  // Trigger some attribute updates to the user entry, such as the addition of
  // an institution value (which is taken from the profile).
  try {
    // As of Dec 2022 we manage attributes on Crowd directly instead of LDAP
    crl_user_update_crowd_attributes_from_user($username, $account);
    // Keep pushing to LDAP for additional testing purposes.
    $ldap = crl_user_ldap_connect();
    $success = $ldap->updateLdapFromUser($username, $account);
    if (!$success) {
      watchdog('crl user', 'There was an error setting the LDAP user attribute values for @user during push.', array('@user' => $account->name), WATCHDOG_ERROR);
    } 
  }
  catch (Exception $e) {
    watchdog_exception('crl user', $e);
  }
}


/**
 * Implements hook_crowd_pull_user_data_alter().
 */
function crl_user_crowd_pull_user_data_alter(&$edit, $crowd_user, $account) {
  // We only want to extract some values from the account object and want to be
  // sure that we don't make any alterations to it during the process.
  $account_working = clone $account;
  $wrapper = entity_metadata_wrapper('user', $account_working);
  // Some of our field values come directly from attribites.
  try {
    // As of Dec 2022 we manage attributes on Crowd directly instead of LDAP
    $edit += crl_user_update_user_from_crowd_attributes($crowd_user['name'], $wrapper, FALSE);
    //$ldap = crl_user_ldap_connect();
    // Get the updates from LDAP but don't trigger a save on the entity. We
    // instead extract that updates to populate an $edit array that can later be
    // used in a user_save() operation.
    //$edit += $ldap->updateUserFromLdap($crowd_user['name'], $wrapper, FALSE);
  }
  catch (Exception $e) {
    watchdog_exception('crl user', $e);
  }
  // First and last name values come directly from Crowd.
  $map = array(
    'field_first_name' => 'first-name',
    'field_last_name' => 'last-name'
  );
  foreach ($map as $field_name => $crowd_data_key) {
    if (isset($wrapper->{$field_name}) && isset($crowd_user[$crowd_data_key])) {
      $wrapper->{$field_name}->set($crowd_user[$crowd_data_key]);
      $edit[$field_name] = $wrapper->value()->{$field_name};
    }
  }
}


/**
 * Implements hook_crowd_batch_pull_detector_class_alter().
 */
function crl_user_crowd_batch_pull_detector_class_alter(&$detector_class) {
  // Use our own custom detector class.
  $detector_class = 'CrlUserBatchPullDetector';
}


/**
 * Implements hook_crowd_client_connect_class_alter().
 */
function crl_user_crowd_client_connect_class_alter(&$connection_class) {
  $connection_class = 'CrlUserCrowdRestClient';
}


/**
 * Helper to update crowd attribites from Drupal user.
 * 
 * This is meant to be a direct replacement for the old LDAP
 * updateLdapFromUser() method.
 */
function crl_user_update_crowd_attributes_from_user($username, $account) {
  // We can work with either a wrapped or unwrapped $account object.
  $wrapper = get_class($account) == 'EntityDrupalWrapper' ? $account : entity_metadata_wrapper('user', $account);
  $info_fields = array('field_institution', 'field_profile_inst_other', 'field_phone', 'field_profile_title');
  $info_values = array();
  foreach ($info_fields as $field_name) {
    $info_values[$field_name] = substr($wrapper->{$field_name}->value(), 0, 250);
  }
  crowd_client_connect()->updateUserAttributes($username, $info_values);
}

/**
 * Helper to update Drupal user from Crowd attributes.
 * 
 * This is meant to be a direct replacement for the old LDAP
 * updateUserFromLdap() method.
 */
function crl_user_update_user_from_crowd_attributes($username, $account, $save = FALSE) {
  // We can work with either a wrapped or unwrapped $account object.
  $wrapper = get_class($account) == 'EntityDrupalWrapper' ? $account : entity_metadata_wrapper('user', $account);
  $attributes = crowd_client_connect()->getAttributesFromName($username);
  $info_fields = array('field_institution', 'field_profile_inst_other', 'field_phone', 'field_profile_title');
  $set_values = array();
  foreach ($attributes as $field_name => $value) {
    if (in_array($field_name, $info_fields)) {
      $current_value = $wrapper->{$field_name}->value();
      if (isset($wrapper->{$field_name}) && $current_value != $value) {
        try {
          $wrapper->{$field_name}->set($value);
          $set_values[$field_name] = $wrapper->value()->{$field_name};
        }
        catch (EntityMetadataWrapperException $e) {
          // See if the exception is because we are nullifying a required value.
          // If so we do our own more detailed logging.
          $field_info = $wrapper->{$field_name}->info();
          if (empty($value) && !empty($field_info['required'])) {
            watchdog('crl user', 'Cannot nullify required field %field for user %user.', array('%field' => $field_name, '%user' => $wrapper->value()->name), WATCHDOG_WARNING);
          }
          else {
            throw $e; // Re-throw.
          }
        }
      }
    }
  }
  if ($save && $set_values) {
    $wrapper->save();
  }
  return $set_values;
}