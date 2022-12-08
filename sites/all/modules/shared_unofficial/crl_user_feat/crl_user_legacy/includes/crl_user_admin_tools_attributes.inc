<?php


/**
 * @file
 * Form definition and processing logic for the CRL set attributes (user inst)
 * tool.
 */


// Include common admin methods.
require_once dirname(__FILE__) . '/crl_user_admin_tools_common.inc';


/**
 * Form callback for the admin institution change widget.
 */
function crl_user_admin_attributes($form, &$form_state) {
  // Setup conditional variables.
  $username = '';
  $inst_current = '';
  $user_message = '';
  if (!empty($form_state['values']['username'])) {
    $username = $form_state['values']['username'];
    // Connect to crowd and see if we have data for this user.
    try {
      $crowd = crowd_client_connect();
      $crowd_data = $crowd->getUserFromName($username);
    }
    catch (CrowdException $e) {
      $e->logResponse();
      drupal_set_message('User data could not be fetched due to an error in the Crowd connection.', 'error', FALSE);
    }
    if (!empty($crowd_data)) {
      // Set the confirmed username to persist across additional ajax rebuilds
      // and get the user's inst details.
      $form_state['crl_confirmed_user'] = $username;
      try {
        $inst_current = crl_user_ldap_connect()->getInst($username);
      }
      catch (Exception $e) {
        watchdog_exception('crl user', $e);
        drupal_set_message('Institution data could not be fetched due to an error in the LDAP connection.', 'error', FALSE);
      }
      $user_message = t('User %user was found in Crowd. You may now update this user\'s institution value.', array('%user' => $username));
    }
    else {
      $user_message = t('User %user could not be found in Crowd.', array('%user' => $username));
    }
  }
  // Build the form.
  $menu = menu_get_item(current_path());
  $description = !empty($menu['description']) ? $menu['description'] : '';
  $form['intro'] = array(
    '#prefix' => '<p>',
    '#suffix' => '</p>',
    '#markup' => $description,
  );
  $form['inst_change_fieldset'] = array(
    '#prefix' => '<div id="inst-change-wrap-div"',
    '#suffix' => '</div>',
    '#type' => 'fieldset',
  );
  if (!empty($user_message)) {
    $form['inst_change_fieldset']['user_notes'] = array(
      '#markup' => '<p><strong> ' . $user_message . '</strong></p>',
    );
  }
  // If we don't yet have confirmed crowd data for the submitted user we can
  // continue to accept a username to lookup.
  if (empty($crowd_data)) {
    $form['inst_change_fieldset']['username'] = array(
      '#type' => 'textfield',
      '#title' => t('Username'),
      '#default_value' => $username,
      '#description' => t('Enter the username for which you want to check/edit the institution setting.'),
    );
    $form['inst_change_fieldset']['check_user'] = array(
      '#type' => 'button',
      '#value' => t('Check User'),
      '#ajax' => array(
        'callback' => 'crl_user_change_inst_ajax_callback',
        'wrapper' => 'inst-change-wrap-div',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    );
  }
  // If we have confirmed crowd data we can build form inputs for the
  // institution value and formal submit button.
  else {
    $inst_list = crl_user_inst_list_builder(TRUE, TRUE, TRUE);
    $form['inst_change_fieldset']['inst'] = array(
      '#type' => 'select',
      '#title' => t('Institution'),
      '#options' => $inst_list,
      '#default_value' => $inst_current,
      '#empty_option' => 'Select',
    );
    $form['inst_change_fieldset']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Update Institution')
    );
    $form['inst_change_fieldset']['reset'] = array(
      '#markup' => l('Start Over', 'admin/crowd/attributes'),
    );
  }
  return $form;
}


/**
 * Ajax callback for admin institution change widget.
 *
 * @see crl_user_admin_attributes
 */
function crl_user_change_inst_ajax_callback($form, &$form_state) {
  // Just return the form to be rebuilt.
  return $form;
}


/**
 * Submit handler for admin institution change widget.
 *
 * @see crl_user_admin_attributes
 */
function crl_user_admin_attributes_submit($form, &$form_state) {
  $inst_list = crl_user_inst_list_builder();
  if (!empty($form_state['crl_confirmed_user']) && !empty($form_state['values']['inst'])) {
    try {
      $ldap = crl_user_ldap_connect();
      $updated = $ldap->setInst($form_state['crl_confirmed_user'], $form_state['values']['inst']);
      if ($updated) {
        // Force a change of the updated timestamp.
        crl_user_legacy_update_crowd_timestamp($form_state['crl_confirmed_user']);
        drupal_set_message(t('Successfully updated %user to institution %inst', array('%user' => $form_state['crl_confirmed_user'], '%inst' => $inst_list[$form_state['values']['inst']])));
      }
      else {
        // By this point the user is know to exist, so any problem related to
        // setting their inst value is an Exception.
        throw new Exception('A known user could not be updated in LDAP');
      }
    }
    catch (Exception $e) {
      watchdog_exception('crl user', $e);
      drupal_set_message(t('There was an error updating %user', array('%user' => $form_state['crl_confirmed_user'])), 'error');
    }
  }
}
