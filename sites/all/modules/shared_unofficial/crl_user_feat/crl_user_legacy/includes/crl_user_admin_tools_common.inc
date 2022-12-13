<?php


/**
 * @file
 * Common logic for CRL user admin tools
 */


define('CRL_USER_CROWD_USER_BASE_URL', 'http://crowd.crl.edu/console/secure/user/view!default.action?directoryID=655361&name=');


/**
 * Utility to get remote user details (in CUD) for a user.
 *
 * The values are fetched remotely via Crowd and are formatted for display
 * purposes only. This is used mainly by batch user lookup processes).
 *
 * @param string $username
 *   The username to fetch details for remotely.
 * @param array $fields
 *   Optional. A list of specific fields to limit the returned list to, and to
 *   return in the designated order.
 * @return array
 *   An associated array of fetched user data, sanitized for immediate display,
 *   including (and keyed by):
 *   - email
 *   - first: first name
 *   - last: last name
 *   - inst: institution name
 *   - active: yes/no label designating active status in Crowd
 *   - alert: yes/no label designating if the user is currently in the
 *     member-alert group
 *   - last_login: A printable date value of the last time the user logged-in
 *     to a Crowd-authenticated application.
 *   - crowd_link: A html link to a page in Crowd where the user dertails can
 *     be edited by an admin.
 */
function crl_user_get_remote_data($username, $fields = array()) {
  // Static values that should only need to be fetch on a new request. Note that
  // crowd_client_connect() and crl_user_ldap_connect() use thier own static
  // cache.
  static $alert_users = NULL;
  static $inst_list = NULL;
  try {
    $crowd = crowd_client_connect();
    if (is_null($alert_users)) {
      $alert_users = $crowd->getGroupMembers('member-alert');
      $inst_list = crl_user_inst_list_builder();
    }
    $crowd_user_data = $crowd->getUserFromName($username);
  }
  catch (CrowdException $e) {
    $e->logResponse();
    drupal_set_message('Some user data could not be fetched due to an error in the Crowd connection.', 'error', FALSE);
    return array();
  }
  if (!empty($crowd_user_data)) {
    $data['email'] = !empty($crowd_user_data['email']) ? $crowd_user_data['email'] : '';
    $data['first'] = !empty($crowd_user_data['first-name']) ? $crowd_user_data['first-name'] : '';
    $data['last'] = !empty($crowd_user_data['last-name']) ? $crowd_user_data['last-name'] : '';
    // Get the inst value via LDAP.
    $data['inst'] = '';
    try {
      $ldap = crl_user_ldap_connect();
      $inst_id = $ldap->getInst($username);
      if (!empty($inst_id) && !empty($inst_list[$inst_id])) {
        $data['inst'] = $inst_list[$inst_id];
      }
    }
    catch (Exception $e) {
      watchdog_exception('crl user', $e);
      drupal_set_message('Some user data could not be fetched due to an error in the LDAP connection.', 'error', FALSE);
    }
    $data['active'] = !empty($crowd_user_data['active']) && $crowd_user_data['active'] == TRUE ? 'yes' : 'no';
    $data['alert'] = array_search($username, $alert_users) !== FALSE ? 'yes' : 'no';
    // Try to find a last login attribute.
    $data['last_login'] = '';
    if (!empty($crowd_user_data['attributes']['attributes'])) {
      foreach ($crowd_user_data['attributes']['attributes'] as $attribute) {
        if (!empty($attribute['MultiValuedAttributeEntity']['name']) && $attribute['MultiValuedAttributeEntity']['name'] == 'lastAuthenticated') {
          $data['last_login'] = date(DATE_RSS, $attribute['MultiValuedAttributeEntity']['values'][0] / 1000);
        }
      }
    }
    // Sanitize all plain-string data.
    foreach ($data as &$value) {
      $value = check_plain($value);
    }
    // Add a link to edit the user in Crowd.
    $data['crowd_link'] = l(t('edit'), CRL_USER_CROWD_USER_BASE_URL . urlencode($username), array('attributes' => array('target'=>'_blank')));
    // If a specific field list is defined filter and sort the output as needed.
    if ($fields) {
      $data_select = array();
      foreach ($fields as $field_name) {
        if (isset($data[$field_name])) {
          $data_select[$field_name] = $data[$field_name];
        }
      }
      return $data_select;
    }
    // Otherwise return all data.
    else {
      return $data;
    }
  }
  return array();
}