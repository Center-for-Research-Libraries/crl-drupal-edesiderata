<?php


/**
 * @file
 * Form handlers and stubbed form logic for Crowd Push module.
 */


/**
 * Add the Crowd group picklist to a user form (e.g. registration or profile).
 * This only has an effect for users with sufficient permission.
 *
 * @param array $form
 *   The Drupal form to add the picklist to.
 * @param array $form_state
 *   The current form state.
 * @param string $toggle_visibility_element
 *   An optional checkbox element from the parent form to use as a visibility
 *   toggle for the picklist.
 */
function _crowd_push_form_add_group_picklist(&$form, &$form_state, $toggle_visibility_element = NULL) {
  // Add Crowd group controls.
  try {
    $crowd = crowd_client_connect();
    $current_groups = array();
    if (!empty($form['#user']->name)) {
      $authname = crowd_user_authmap_name($form['#user']->name);
      $current_groups = !empty($authname) ? $crowd->getUserGroups($authname) : array();
    }
    $all_groups = $crowd->getAllGroups();
    $all_groups = array_combine($all_groups, $all_groups); // Match keys and values.
    natcasesort($all_groups);
  }
  catch (CrowdException $e) {
    $e->logResponse();
    drupal_set_message(t('There is currently a problem with user registration system, please try again later.'), 'error');
    return;
  }
  $group_map = variable_get('crowd_groups', array());
  $site_roles = user_roles();
  // Add a fieldset for Crowd groups.
  $form['account']['crowd_groups_set'] = array(
    '#type' => 'fieldset',
    '#title' => t('Crowd Groups'),
    '#description' => t(''),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#access' => user_access('administer crowd group memberships'),
  );
  if (isset($toggle_visibility_element)) {
    $form['account']['crowd_groups_set']['#states'] = array(
      'visible' => array(
        ':input[name="' . $toggle_visibility_element . '"]' => array('checked' => TRUE),
      ),
    );
  }
  $form['account']['crowd_groups_set']['crowd_groups'] = array(
    '#type' => 'checkboxes',
    '#options' => $all_groups,
    '#default_value' => $current_groups,
    '#title' => '',
  );
  // Mark the groups that are mapped to Drupal.
  foreach ($form['account']['crowd_groups_set']['crowd_groups']['#options'] as $key => &$group) {
    // Find the role that this group is mapped to, if any.
    if (isset($group_map[$group])) {
      $group .= ' ' . t('(also enables Drupal role <strong>@role</strong>)', array('@role' => $site_roles[$group_map[$group]]));
    }
  }
  // Add logic to calculate roles from groups during save.
  array_unshift($form['#submit'], '_crowd_push_user_calculate_missing_roles');
}


/**
 * Validation handler for registration.
 */
function _crowd_push_user_register_validate($form, &$form_state) {
  if ($form_state['values']['crowd_push_enabled']) {
    // Validate that the user's name and email are free in Crowd. These REST
    // checks also verify that the Crowd API is operational which is also very
    // important to confirm before we get to our submit handler and start
    // writing data locally and remotely.
    try {
      $crowd = crowd_client_connect();
      if (!empty($form_state['values']['name'])) {
        $results_name = $crowd->searchCql('user', 'name=' . $form_state['values']['name']);
        if (!empty($results_name)) {
          form_set_error('name', t('The name %name is already taken (CROWD).', array('%name' => $form_state['values']['name'])));
        }
      }
      if (!empty($form_state['values']['mail'])) {
        $results_mail = $crowd->searchCql('user', 'email=' . $form_state['values']['mail']);
        if (!empty($results_mail)) {
          form_set_error('mail', t('The e-mail address %email is already registered (CROWD). <a href="@password">Have you forgotten your password?</a>', array('%email' => $form_state['values']['mail'], '@password' => url('user/password'))));
        }
      }
    }
    catch (CrowdException $e) {
      $e->logResponse();
      form_set_error('', t('There is currently a problem with user registration system, please try again later.'));
    }
  }
}


/**
 * Validation handler for profile form current password input.
 */
function _crowd_push_user_validate_current_pass($form, &$form_state) {
  // This is essentially a duplicate of user_validate_current_pass() with the
  // password validation check run remotly against Crowd instead of Drupal.
  $account = $form['#user'];
  $authname = crowd_user_authmap_name($account->name);
  foreach ($form_state['values']['current_pass_required_values'] as $key => $name) {
    if ((strlen(trim($form_state['values'][$key])) > 0) && ($form_state['values'][$key] != $account->$key)) {
      try {
        $crowd = crowd_client_connect();
        // The Crowd API does not offer any way to directly validate a password
        // so we have to attmept to authenticate a new session and check for
        // success. This works fine, but it is unfortunate that we need to
        // spin-off extra unneeded sessions just to get this check done.
        $auth = $crowd->authorize($authname, $form_state['values']['current_pass']);
        $current_pass_failed = empty($form_state['values']['current_pass']) || empty($auth);
      }
      catch (Exception $e) {
        $e->logResponse();
        form_set_error('', t('There is currently a problem with user management system, please try again later.'));
      }
      if ($current_pass_failed) {
        form_set_error('current_pass', t("Your current password is missing or incorrect; it's required to change the %name.", array('%name' => $name)));
        form_set_error($key);
      }
      // We only need to check the password once.
      break;
    }
  }
}


/**
 * Submit handler for the user profile and registration form to preserve Crowd
 * password details. This is intended to be run BEFORE core save handlers.
 */
function _crowd_push_user_crowd_pass($form, &$form_state) {
  // If this is the regsitration form some special checks are needed.
  if ($form['#form_id'] == 'user_register_form') {
    // This handler may be triggered before we know if a push action is enabled.
    // (for registrations the form state matters in addition to whether-or-not
    // this handler is run), so we need to abort here if not pushing.
    if (empty($form_state['values']['crowd_push_enabled'])) {
      return;
    }
    // For a pushed registration we MUST send a pass value to Crowd. So in the
    // case that the user was unable to input their password directly (e.g.
    // email validation required) we simply make a random temp Crowd pass just
    // like Drupal does in user_register_submit().
    if (empty($form_state['values']['pass'])) {
      $form_state['values']['crowd_pass'] = user_password();
    }
  }
  // Grab the current pass value from the form (if entered) and preserve it in
  // our own variable for later processing independent of other core submit
  // workflows.
  if (!empty($form_state['values']['pass'])) {
    $form_state['values']['crowd_pass'] = $form_state['values']['pass'];
    // Additionally, if the local password randomization option is set we
    // randomize the Drupal password that will be saved locally.
    if (variable_get('crowd_push_random_local_pass', FALSE)) {
      $form_state['values']['pass'] = user_password();
    }
  }
}


/**
 * Submit handler for the user profile form to fill-in missing role details
 * based on current crowd Group information. This is intended to be run BEFORE
 * core save handlers.
 *
 * This is run to ensure all Crowd group mappings are respected even when the
 * Crowd groups are assigned within Drupal during a push operation.
 */
function _crowd_push_user_calculate_missing_roles($form, &$form_state) {
  $groups = $form_state['values']['crowd_groups'];
  // Ensure that our role list is filtered to only show applied roles.
  $form_state['values']['roles'] = array_filter($form_state['values']['roles']);
  crowd_update_roles_from_groups($form_state['values']['roles'], $groups);
}


/**
 * Submit handler for registration. This is intended to be run AFTER core save
 * handlers.
 */
function _crowd_push_user_register_submit($form, &$form_state) {
  // The newly generated local account details can be extracted from the form
  // state now that the core submit handler has run. This represents a
  // freshly-saved user object which should be totally up-to-date and
  // therefore not necessarially linked by reference, or in-sync with, the
  // global $user object.
  $account = $form_state['user'];
  $authname = crowd_user_authmap_name($account->name, TRUE);
  global $user;
  // Authenticate the user in Crowd if they are already logged-in locally
  // (i.e. this was a self registration, no email validation rules are active,
  // etc.).
  if ($user->uid && $user->uid == $account->uid && $authname) {
    $crowd_user = crowd_login_remote($authname, $form_state['values']['crowd_pass'], FALSE);
    if ($crowd_user) {
      // Make sure that the global user object is up-to-date as the save and
      // push processes (and hooks) may have modified the user data.
      $user = user_load($user->uid, TRUE);
    }
  }
}
