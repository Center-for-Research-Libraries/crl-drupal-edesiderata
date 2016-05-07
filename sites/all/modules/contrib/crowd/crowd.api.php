<?php

/**
 * @file
 * Describe hooks provided by the Crowd module.
 */


/**
 * Alter data that will be saved in a Drupal user account during a Crowd pull.
 * This is invoked AFTER native pull caculations have been made but before they
 * are comitted.
 *
 * @param array $edit
 *   An array of custom fields and values to save locally as part of the user
 *   account, and as expected by user_save(). This can be altered as needed to
 *   enforce custom save logic. It is preferred to pass user object changes
 *   through this variable as opposed to modifying $account directly.
 * @param array $crowd_user
 *   An associative array of crowd user data that was fetched from Crowd.
 * @param object $account
 *   A Drupal user object representing the local user to pull updates to.
 */
function hook_crowd_pull_user_data_alter(&$edit, $crowd_user, $account) {
  // Ensure that first and last name data contained in custom profile fields is
  // also part of the pull.
  $field_languages = field_language('user', $account);
  $edit['field_first_name'][$field_languages['field_first_name']][0]['value'] = $crowd_user['first-name'];
  $edit['field_last_name'][$field_languages['field_last_name']][0]['value'] = $crowd_user['last-name'];
}


/**
 * Implement pull tasks, or alter data that will be used by the native Crowd
 * pull tasks, when Crowd data is pulled to Drupal. This is invoked BEFORE
 * native pull caculations have been made.
 *
 * This hook is availalbe for legacy purposes. For most custom sync/pull
 * operations hook_crowd_pull_user_data_alter() is recommended.
 *
 * @param array $crowd_user
 *   An associative array of crowd user data that was fetched from Crowd.
 * @param object $account
 *   A Drupal user object representing the local user to pull updates to.
 */
function hook_crowd_presync_user_data(&$crowd_user, $account) {
  // Ensure that first and last name data contained in custom profile fields is
  // also part of the pull.
  $field_languages = field_language('user', $account);
  $edit['field_first_name'][$field_languages['field_first_name']][0]['value'] = $crowd_user['first-name'];
  $edit['field_last_name'][$field_languages['field_last_name']][0]['value'] = $crowd_user['last-name'];
  // This save is redundant to the one that the invoking method will make, and
  // is the reason that hook_crowd_pull_user_data_alter() is preferred for this
  // kind of custom operation.
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
 * This hook has limited utility as only one module can realistically make use
 * of it at any given time. hook_crowd_client_connect_object_alter() may be a
 * more robust choice for global modifications.
 *
 * @param string $connection_class
 *   The connection class name that will be used when a connection is
 *   instantiated.
 */
function hook_crowd_client_connect_class_alter(&$connection_class) {
  $connection_class = 'MyExtendedCrowdRestClass';
}


/**
 * Decorate a connection object used to talk to Crowd via REST.
 *
 * @param CrowdServiceInterface $connection
 *   A freshly instantiated crowd connection.
 */
function hook_crowd_client_connect_object_alter($connection) {
  // Decorate the connection with custom functionality via the
  // MyDecoratedCrowdConnection class.
  $connection = new MyDecoratedCrowdConnection($connection);
}
