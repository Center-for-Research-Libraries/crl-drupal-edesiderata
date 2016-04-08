<?php


/**
 * @file
 * Admin panel forms.
 */


/**
 * Menu callback function to generate the module configuration form.
 */
function crowd_admin_settings($form, $form_state) {
  global $is_https;
  // Run a quick check to see if the connection is working with the current
  // configuration.
  if (empty($form_state['input'])) {
    if (crowd_client_connect()->validateConnection()) {
      drupal_set_message(t('The connection to your Crowd server application appears to be functioning correctly.'));
    }
    else {
      drupal_set_message(t('Unable to connect to your Crowd server application. Please check your connection settings.'), 'error');
    }
  }
  //Server settings
  $form['server'] = array(
    '#type' => 'fieldset',
    '#title' => t('Crowd server settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['server']['crowd_server'] = array(
    '#type' => 'textfield',
    '#title' => t('Crowd REST server'),
    '#default_value' => variable_get('crowd_server', ''),
    '#size' => 30,
    '#maxlength' => 55,
    '#description' => t('Location of Atlassian Crowd authentication service (e.g., https://crowd.mydomain.com).'),
    '#element_validate' => array('crowd_validate_url'),
  );

  $form['server']['crowd_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Crowd REST server port'),
    '#default_value' => variable_get('crowd_port', '443'),
    '#size' => 30,
    '#maxlength' => 8,
    '#description' => t('443 is the standard ssl port. 8443 is the standard non-root port for Tomcat.'),
  );

  $form['server']['crowd_uri'] = array(
    '#type' => 'textfield',
    '#title' => t('Crowd REST API path'),
    '#default_value' => variable_get('crowd_uri', 'rest/usermanagement/latest'),
    '#size' => 30,
    '#description' => t('The path to the Crowd REST API, including context if applicable (e.g., context/rest/usermanagement/latest).'),
  );

  $form['server']['crowd_application'] = array(
    '#type' => 'textfield',
    '#title' => t('Crowd application name'),
    '#default_value' => variable_get('crowd_application', ''),
    '#size' => 30,
    '#description' => t('Applications need to be registered with Crowd in order to provide SSO services.  Enter the name of your registered application here.'),
  );
  $password = variable_get('crowd_application_password', '');
  $form['server']['crowd_application_password'] = array(
    '#type' => 'password',
    '#title' => t('Crowd application password'),
    '#default_value' => $password,
    '#size' => 30,
    '#description' => t('Enter the password used by your application to authenticate with Crowd. Please note that Drupal stores this password in plain text within the database and it is transmitted to Crowd using HTTP Basic Authentication.'),
    // The Drupal Form API "password" type does not properly respect the default
    // value setting, so this field is always blank each time the form is
    // re-loaded and the value is not maintained when the form is again
    // submitted. The following line is a workaround for this. We are already
    // storing passwords in plain-text, so forcing the default value to work
    // on an admin-only form should be alright.
    '#attributes' => array('value' => $password),
  );
  //Cookie Settings
  $form['cookie_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('SSO cookie options'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['cookie_options']['crowd_cookie_sso_domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Crowd cookie SSO domain'),
    '#default_value' => variable_get('crowd_cookie_sso_domain', ''),
    '#size' => 30,
    '#description' => t('The domain that SSO cookies should be generated for (such as .mydomain.com).'),
  );

  $crowd_secure_sso_cookie_disabled = !$is_https && !variable_get('crowd_secure_sso_cookie', FALSE);
  $crowd_secure_sso_cookie_disabled_message = $crowd_secure_sso_cookie_disabled ? '<strong>' . t('This option can only be enabled over a secure connection.') . '</strong>' : '';
  $form['cookie_options']['crowd_secure_sso_cookie'] = array(
    '#type' => 'checkbox',
    '#title' => t('Secure SSO cookie'),
    '#default_value' => variable_get('crowd_secure_sso_cookie', FALSE),
    '#disabled' => $crowd_secure_sso_cookie_disabled,
    '#description' => t('If enabled, the "Secure" flag will be set on the SSO cookie when a session is initiated by Drupal, and any insecure SSO cookies set by other applications will be ignored. This will break SSO for any applications not using a secure connection (SSL/TLS), including Drupal. Additionally, users will not be able to log in to Drupal with Crowd credentails over an insecure connection when this option is active.') . ' ' . $crowd_secure_sso_cookie_disabled_message,
  );

  $form['cookie_options']['crowd_logout_no_cookie'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log out if cookie is deleted or changed'),
    '#default_value' => variable_get('crowd_logout_no_cookie', FALSE),
    '#description' => t('If enabled, this option will automatically log the current user out of Drupal if the Crowd SSO cookie has been deleted or has changed during an active Drupal session. This does not remotely re-validate the session but still offers an inexpensive check that can be safely run on each page request. User 1 is exempted from this check.'),
  );
  $form['cookie_options']['advanced_cookie_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced cookie options'),
    '#collapsible' => TRUE,
    // Make sure this fieldset is open whenever the crowd_validate_token is
    // active. Having that option checked is dangerous for performance, so we
    // want the admin to be very aware of that setting when it's active.
    '#collapsed' => !variable_get('crowd_validate_token', FALSE),
  );
  $form['cookie_options']['advanced_cookie_options']['crowd_cookie_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Crowd cookie name'),
    '#default_value' => variable_get('crowd_cookie_name', 'crowd.token_key'),
    '#size' => 30,
    '#description' => t('The cookie name used in this SSO group. This should only be changed if you maintain multiple Crowd SSO groups.'),
  );
  $form['cookie_options']['advanced_cookie_options']['crowd_cookie_duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Crowd cookie duration'),
    '#default_value' => variable_get('crowd_cookie_duration', 0),
    '#size' => 30,
    '#description' => t("The cookie duration, in minutes, that should be set when a Crowd session is initiated through Drupal (i.e. a user logs-in to Crowd through Drupal's login screen). Set this to 0 if you wish to expire the cookie at the end of each browser session. Please note that the cookie duration set here may not be respected by all Atlassian applications and that this duration only applies to the cookie itself, not the SSO session."),
  );
  $form['cookie_options']['advanced_cookie_options']['crowd_validate_token'] = array(
    '#type' => 'checkbox',
    '#title' => t('Validate the SSO cookie on each request'),
    '#default_value' => variable_get('crowd_validate_token', FALSE),
    '#description' => t('If enabled, this option will validate the SSO auth token against Crowd on every page load. <strong>WARNING:</strong> enabling this option may negatively impact performance of your web server and Crowd server significantly. Use with caution!'),
  );

  // Crowd to Drupal mapped groups
  $form['groups'] = array(
    '#type' => 'fieldset',
    '#title' => t('Current group maps'),
    '#description' => '<p>' . t('These are the currently mapped Crowd groups to Drupal roles. <strong><a href="!link">Configue mappings</a></strong>.', array('!link' => url('admin/config/crowd/group-mapping'))) . '</p>',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $group_map = variable_get('crowd_groups', array());
  $site_roles = user_roles();
  $form['groups']['key'] = array(
    '#prefix' => '<div id="group-map-key">',
    '#markup' => t('<strong>[Crowd Group] => Drupal Role</strong>'),
    '#suffix' => '</div>',
    );
  if (!empty ($group_map)) {
    foreach ($group_map as $key => $value) {
      if ($value != 0) {
        $form['groups'][$key] = array(
          '#prefix' => '<div id="group-map-' . $key . '">',
          '#markup' => '[' . $key . '] => ' . $site_roles[$value],
          '#suffix' => '</div>'
        );
      }
    }
  }
  $form['groups']['groups_page_link'] = array(
    '#prefix' => '<div id="link-to-crowd-groups-page">',
    '#value' => '<br/>' . l(t('Crowd Group Mapping Page'), 'admin/settings/crowd/group-mapping', array('attributes' => array('rel' => '_blank'))),
    '#suffix' => '</div>',
  );

  // Additional options
  $form['other_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Other Crowd Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['other_settings']['crowd_allow_local_logins'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow local logins if Crowd fails'),
    '#default_value' => variable_get('crowd_allow_local_logins', TRUE)
  );
  $form['other_settings']['crowd_allow_local_block'] = array(
    '#type' => 'checkbox',
    '#title' => t("Allow users' local blocked status to override Crowd active status"),
    '#default_value' => variable_get('crowd_allow_local_block', TRUE),
    '#description' => t('If enabled a user can be blocked based on their Drupal user status independent of thier Crowd active status. If unchecked each user\'s Crowd active status will be synced to Drupal and will uniquely determine whether-or-not the user is allowed to authenticate locally.'),
  );
  $form['other_settings']['crowd_handle_username_collision'] = array(
    '#type' => 'select',
    '#title' => t('How to handle username collisions'),
    '#options' => array(
      'abort' => 'Abort login and show error',
      'merge' => 'Allow login and silently link accounts',
    ),
    '#default_value' => variable_get('crowd_handle_username_collision', 'abort'),
    '#description' => t("What to do when a user is accessing Drupal for the first time based on Crowd credentials and they already have a local account with a matching username. Note that the option to allow the login and link accounts should only be used in controlled circumstances when you are certain that all accounts with matching usernames (across Crowd and Drupal) represent the same individual users."),
  );
  $form['other_settings']['redirects'] = array(
    '#type' => 'fieldset',
    '#title' => t('Optional Page Redirects'),
    '#description' => t('The Crowd module does not natively provide Drupal-to-Crowd integration for "self-service" user account management and password reset requests. However, you can redirect users from the Drupal-based forms that handle these actions to alternative locations (such as the Crowd Console web application).'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['other_settings']['redirects']['crowd_redirect_user_edit_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect URL for account settings page'),
    '#default_value' => variable_get('crowd_redirect_user_edit_url', ''),
    '#description' => t('Provide a URL redirect for the Drupal "Account Settings" (user/*/edit) page, such as the URL to the "My Profile" page of the Crowd Console. This redirect will only happen for users that have been authenticated through Crowd. Enter as a Drupal path or absolute URL, or leave blank for no redirect.'),
    '#element_validate' => array('crowd_validate_url'),
  );
  $form['other_settings']['redirects']['crowd_redirect_pass_reset_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect URL for password reset page'),
    '#default_value' => variable_get('crowd_redirect_pass_reset_url', ''),
    '#description' => t('Provide a URL redirect for the Drupal "Request New Password" (user/password) page, such as the URL to the "Forgot Login" page of the Crowd Console. Enter as a Drupal path or absolute URL, or leave blank for no redirect.'),
    '#element_validate' => array('crowd_validate_url'),
  );
  return system_settings_form($form);
}


/**
 * Menu callback function to generate the group mapping form.
 */
function crowd_group_mapping() {
  // Get group and role data.
  try {
    $groups = crowd_client_connect()->getAllGroups();
  }
  catch (CrowdException $e) {
    $e->logResponse();
    drupal_set_message(t('Unable to connect to your Crowd server application. Please check your connection settings.'), 'error');
    return array('error' => array('#markup' => t('No mapping sources could be detected.')));
  }
  $roles = user_roles(TRUE);
  if (empty($groups)) {
    return array('no_data' => array('#markup' => t('No Crowd groups could be detected for mapping.')));
  }
  if (empty($roles)) {
    return array('no_data' => array('#markup' => t('No Drupal roles could be found for mapping.')));
  }
  foreach ($roles as $key => $role) {
    $options[$key] = $role;
  }
  $defaults = variable_get('crowd_groups', array());
  // Build the form.
  $form['groups'] = array(
    '#type' => 'fieldset',
    '#title' => t('Crowd group mappings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('Use these options to map individual Crowd groups to Drupal roles. For each active mapping the linked Drupal role will be added if the user is a member of the associated Crowd group, and removed if not. <strong>Please note that removing a mapping will not remove any Drupal roles that were previously assigned through the mapping unless the "Flush Drupal roles on each update" setting is enabled below.</strong>'),
  );
  $form['groups']['crowd_groups'] = array(
    '#tree' => TRUE
  );
  foreach ($groups as $key => $value) {
    $form['groups']['crowd_groups'][$value] = array(
      '#type' => 'select',
      '#title' => $value,
      '#options' => $options,
      '#default_value' => (isset($defaults[$value])) ? $defaults[$value] : NULL,
      '#empty_option' => t('Not Mapped'),
    );
  }
  $form['other_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Other group mapping options'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['other_options']['crowd_flush_roles_on_update'] = array(
    '#type' => 'checkbox',
    '#title' => t('Flush Drupal roles on each update'),
    '#default_value' => variable_get('crowd_flush_roles_on_update', FALSE),
    '#description' => t('If enabled all Drupal roles will be removed during each user update just before the group mappings above are applied. This can be useful if you want to strictly ensure that Crowd-authenticated users can only gain roles through Crowd. However, this will also make it impossible to manually maintain any local Drupal roles assignments for Crowd users. This setting only applies to Crowd-authenticated users.'),
  );
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save configuration'
  );
  $form['#theme'] = 'system_settings_form';
  return $form;
}


/**
 * Submit handler for the group mapping form.
 */
function crowd_group_mapping_submit($form, $form_state) {
  // No need to save empty mappings.
  $group_map = $form_state['values']['crowd_groups'];
  foreach ($group_map as $group => $rid) {
    if (empty($rid)) {
      unset($group_map[$group]);
    }
  }
  variable_set('crowd_groups', $group_map);
  variable_set('crowd_flush_roles_on_update', $form_state['values']['crowd_flush_roles_on_update']);
  drupal_set_message(t('Configuration options saved'));
}


/**
 * Form validation callback to provide loose validation for URLs.
 *
 * @see: crowd_admin_settings()
 */
function crowd_validate_url($element, &$form_state, $form) {
  if (!empty($element['#value']) && !valid_url($element['#value'])) {
    form_error($element, t('The URL entered in "@field" does not appear to be valid.', array('@field' => $element['#title'])));
  }
}
