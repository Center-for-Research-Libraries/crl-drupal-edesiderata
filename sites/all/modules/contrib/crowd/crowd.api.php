<?php

/**
 * @file
 * Describe hooks provided by the Crowd module.
 */


/**
 * Implement sync tasks, or alter data that will be used by the native Crowd
 * sync tasks, when Crowd data is synced to Drupal.
 *
 * @param array $crowd_user
 *   An associative array of crowd user data that was fetched from Crowd.
 * @param object $account
 *   A Drupal user object representing the local user to be synced to.
 */
function hook_crowd_presync_user_data(&$crowd_user, $account) {
  // Sync first and last name data with custom profile fields.
  $edit = array();
  // Make sure all the fields are loaded on the account.
  $account = user_load($account->uid);
  $edit['field_first_name'][LANGUAGE_NONE][0]['value'] = $crowd_user['first-name'];
  $edit['field_last_name'][LANGUAGE_NONE][0]['value'] = $crowd_user['last-name'];
  user_save($account, $edit);
}


/**
 * React to or alter a redirect that Crowd enforces on an account edit or reset
 * password link.
 *
 * @param string $redirect
 *   The redirect URL that the user is about to be sent to.
 */
function hook_crowd_redirect(&$redirect) {
  // Set a cookie to tell an external system something about this refferal (such
  // as a return path).
  global $base_url;
  $remote_destination_url = $base_url;
  // If this is a password reset we should set the return destination to be the
  // login page.
  if (drupal_match_path($_GET['q'], 'user/password')) {
    $remote_destination_url = url('user', array('absolute' => TRUE));
  }
  setcookie('mysite-remote-destination-url', $remote_destination_url, NULL, '/', variable_get('crowd_cookie_sso_domain', ''), FALSE);
}


/**
 * Alter the connection class used to talk to Crowd via REST.
 *
 * @param string $connection_class
 *   The connection class name that will be used when a connection is
 *   instantiated.
 */
function hook_crowd_client_connect_class_alter(&$connection_class) {
  // Don't alter if something else already is.
  if ($connection_class == 'CrowdRestClient') {
    $connection_class = 'MyExtendedCrowdRestClass';
  }
}
