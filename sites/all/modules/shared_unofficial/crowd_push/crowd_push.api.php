<?php

/**
 * @file
 * Describe hooks provided by the Crowd Provisioning module.
 */


/**
 * Implement custom logic, or alter data that will be used during a Crowd Push.
 * Providioning, before a new user is provisioned in crowd *
 * @param array $data
 *   An associative array of user data to be sent to Crowd when creating the new
 *   user remotely. Contains:
 *   - 'name': Username.
 *   - 'first-name': First name.
 *   - 'last-name': Last name.
 *   - 'email': email address
 *   - 'password': user password
 *   - 'display-name' (optional): Display name.
 *   - 'active' (optional): Whether to set user as active (true/false)
 * @param object $account
 *   The Drupal user account that is being pushed to Crowd, available for
 *   context.
 */
function hook_crowd_push_user_data_alter(&$data, $account) {
  // Set the first and last name values from custom profile form fields.
  if (!empty($account->field_first_name) && !empty($account->field_last_name)) {
    // Set the first and last name info in the $data array.
    $data['first-name'] = $account->field_first_name[field_language('user', $account, 'field_first_name')][0]['value'];
    $data['last-name'] = $account->field_last_name[field_language('user', $account, 'field_last_name')][0]['value'];
  }
}
