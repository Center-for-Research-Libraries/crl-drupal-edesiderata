<?php


/**
 * @file
 * Form definition and batch processing logic for the CRL user group validation
 * tool.
 */


define('CRL_USER_ADMIN_TOOLS_PROCESS_ONCE', 10);


// Include common admin methods.
require_once dirname(__FILE__) . '/crl_user_admin_tools_common.inc';


/**
 * Form callback for the bulk user group validation check.
 */
function crl_user_admin_group_validate($form, &$form_state) {
  $menu = menu_get_item(current_path());
  $description = !empty($menu['description']) ? $menu['description'] : '';
  $form['intro'] = array(
    '#prefix' => '<p>',
    '#suffix' => '</p>',
    '#markup' => $description,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Fetch Data')
  );
  $results = cache_get('crl_user_user_group_validate_data');
  if (!empty($results->data) && $results->expire >= time()) {
    $header = array(t('Username / Email'), t('First Name'), t('Last Name'), t('Institution'), t('Active'), t('Member Alert'), t('Last Login'), t('Edit in Crowd'));
    $flag_text = array(
      'switch_mem' => array(
        'title' => t('Members-non that should be switched to members-crl'),
        'description' => t('These users are in the <em>member-non</em> group, but thier current institution affiliation indicates they should be in the <em>member-crl</em> group instead.'),
      ),
      'switch_nonmem' => array(
        'title' => t('Members-crl that should be switched to members-non'),
        'description' => t('These users are in the <em>member-crl</em> group, but thier current institution affiliation (or lack thereof) indicates they should be in the <em>member-non</em> group instead.', array('!fix_link' => url('admin/people/crl/group_validate/process/switch_nonmem'))),
      ),
      'add_mem' => array(
        'title' => t('Ungrouped users that should be members-crl'),
        'description' => t('These users are not in any group signifying membership, but thier current institution affiliation indicates that they should be in the <em>member-crl</em> group.'),
      ),
      'add_nonmem' => array(
        'title' => t('Ungrouped users that should be members-non'),
        'description' => t('These users are not in any group signifying membership, but thier current institution affiliation (or lack thereof) indicates that they should be in the <em>member-non</em> group.'),
      ),
    );
    $form['stamp'] = array(
      '#markup' => '<p>' . t('This data was fetched on %time. <strong>Any remote changes made since that time are not yet reflected here.<br/></strong> Click the "Fetch Data" button above to refresh.', array('%time' => format_date($results->data['metadata']['finished']))) . '</p>',
    );
    foreach ($results->data['flagged'] as $group => $users) {
      if (!empty($users)) {
        $fix_link = '<p><strong>' . l(t('Bulk fix these users'), 'admin/people/crl/group_validate/process/' . $group) . '.</strong></p>';
        $form[$group] = array(
          '#type' => 'fieldset',
          '#collapsible' => TRUE,
          '#collapsed' => TRUE,
          '#title' => $flag_text[$group]['title'] . ' (' . count($users) . ')',
          '#description' => '<p>' . $flag_text[$group]['description'] . '</p>' . $fix_link,
        );
        $form[$group]['table'] = array(
          '#markup' => theme('table', array('header' => $header, 'rows' => $users)) . $fix_link,
        );
      }
    }
  }
  return $form;
}


/**
 * Submit handler for the bulk user check.
 */
function crl_user_admin_group_validate_submit($form, &$form_state) {
  // Setup the batch operation that will fetch user data from Crowd and stash
  // it for later rendering in our form.
  $batch = array(
    'operations' => array(
      array('crl_user_admin_group_validate_set_context', array()),
      array('crl_user_admin_group_validate_query_groups', array(array('member-crl', 'member-non', 'member-alert'))),
      array('crl_user_admin_group_validate_calc', array()),
      array('crl_user_admin_group_validate_get_user_details', array()),
    ),
    'finished' => 'crl_user_admin_group_validate_batch_finished',
    'title' => t('Processing Bulk User Checks'),
    'init_message' => t('Starting ... initializing data.'),
    'progress_message' => t('Completed step @current of @total.'),
    'error_message' => t('The batch process has encountered an error.'),
    'file' => drupal_get_path('module', 'crl_user_legacy') . '/includes/crl_user_admin_tools_group_validate.inc',
  );
  batch_set($batch);
  // Ensure that the form is rebuilt, with sumitted values attached, after
  // submit and batch processing.
  $form_state['rebuild'] = TRUE;
}


/**
 * Batch operation to establish some base context variables that should be
 * available through the whole process.
 *
 * @param array $context
 *   Contextual information as provided through the batch API.
 */
function crl_user_admin_group_validate_set_context(&$context) {
  // Refresh the inst lists from salesforce.
  module_load_include('inc', 'crl_user', 'includes/crl_user_sf');
  crl_user_sf_sync_inst();
  $context['message'] = t('Fetching group data from LDAP and calculating which users need attention.');
}


/**
 * Batch operation to fetch various group lists from LDAP and store the results
 * in the batch $context.
 *
 * @param array $groupnames
 *   An indexed array of groupnames to use when fetching user lists. Each pass
 *   of this operation will lookup users for ONE group and store the results in
 *   $context['results']['$groupname'].
 * @param array $context
 *   Contextual information as provided through the batch API.
 */
function crl_user_admin_group_validate_query_groups($groupnames, &$context) {
  if (!isset($context['sandbox']['offset'])) {
    $context['sandbox']['offset'] = 0;
  }
  $groupname = $groupnames[$context['sandbox']['offset']];
  // We need to re-init the LDAP resource on each pass as it looks like it can't
  // be stored in the context across requests.
  try {
    $context['results'][$groupname] = array_map('strtolower', crl_user_ldap_connect()->getGroupUsers($groupname));
  }
  catch (Exception $e) {
    watchdog_exception('crl user', $e);
    // Re-throw the exception to kill the batch process if needed.
    throw new Exception('Group data cannot be reliably processed due to issues with the LDAP connection.');
  }
  $context['message'] = t('Querying LDAP for user data.');
  // Prep for next iteration.
  $context['message'] = t('Fetching group data from LDAP and calculating which users need attention.');
  $context['sandbox']['offset'] = $context['sandbox']['offset'] + 1;
  $context['finished'] = $context['sandbox']['offset'] >= count($groupnames) ? 1 : 0;
}


/**
 * Batch operation to calculate which users have incorrect group associations
 * and flag them appropriately.
 *
 * @param array $context
 *   Contextual information as provided through the batch API.
 */
function crl_user_admin_group_validate_calc(&$context) {
  $members_correct = $nonmembers_correct = $crl_users = array();
  // Get ALL user inst details and loop over them to calculate the CORRECT
  // member and nonmember lists.
  try {
    $users_inst_all = crl_user_ldap_connect()->getInstUsers();
    $inst_list_mem = crl_user_inst_list_builder(FALSE);
    foreach ($users_inst_all as $username => $sfid) {
      // If the user has an inst set that's in the member inst list, they should
      // be listed as a member.
      if (array_key_exists($sfid, $inst_list_mem)) {
        $members_correct[] = strtolower($username);
      }
      // Otherwise they should be listed as a nonmember.
      else {
        $nonmembers_correct[] = strtolower($username);
      }
    }
  }
  catch (Exception $e) {
    watchdog_exception('crl user', $e);
    // Re-throw the exception to kill the batch process if needed.
    throw new Exception('User data cannot be reliably processed due to issues with the LDAP connection.');
  }
  // Find the currently incompatible combinations (that need switching).
  $context['results']['flagged']['switch_mem'] = array_intersect($members_correct, $context['results']['member-non']);
  $context['results']['flagged']['switch_nonmem'] = array_intersect($nonmembers_correct, $context['results']['member-crl']);
  // Then find the missing cases (that need group additions) which aren't
  // already captured in switch cases.
  $context['results']['flagged']['add_mem'] = array_diff($members_correct, $context['results']['member-crl'], $context['results']['flagged']['switch_mem']);
  $context['results']['flagged']['add_nonmem'] = array_diff($nonmembers_correct, $context['results']['member-non'], $context['results']['flagged']['switch_nonmem']);
  $context['results']['needs_details'] = array();
  // Do some final cleanup and organization.
  foreach ($context['results']['flagged'] as $group => &$set) {
    // Gather-up a nicely indexed "flat" list of usernames that can be used
    // when fetching the full details in Crowd.
    foreach ($set as $username) {
      $context['results']['needs_details'][] = array('username' => $username, 'group' => $group);
    }
    // Flip the usernames into the keys and sort.
    $set = array_flip($set);
    ksort($set);
  }
  // Prep for next iteration.
  $context['message'] = t('Fetching group data from LDAP and calculating which users need attention.');
}


/**
 * Batch operation to fetch full user details from Crowd for each user that's
 * flagged as needing attention.
 *
 * @param array $context
 *   Contextual information as provided through the batch API.
 */
function crl_user_admin_group_validate_get_user_details(&$context) {
  // Prep context.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['total'] = count($context['results']['needs_details']);
    if ($context['sandbox']['total'] == 0) {
      return;
    }
  }
  $progress = $context['sandbox']['progress'];
  $username = $context['results']['needs_details'][$progress]['username'];
  $group = $context['results']['needs_details'][$progress]['group'];
  // Fetch full user data.
  $context['results']['flagged'][$group][$username] = crl_user_get_remote_data($username);
  $context['message'] = t('Fetching full data from Crowd for user @current of @total', array('@current' => $context['sandbox']['progress'], '@total' => $context['sandbox']['total']));
  // Prep for next iteration.
  $context['sandbox']['progress']++;
  $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['total'];
}


/**
 * Callback for the completion of the batch operation.
 */
function crl_user_admin_group_validate_batch_finished($success, $results, $operations) {
  if ($success) {
    $results['metadata']['finished'] = time();
    // Stash our results for later access and listing.
    cache_set('crl_user_user_group_validate_data', array('metadata' => $results['metadata'], 'flagged' => $results['flagged']), 'cache', time() + 60 * 60);
  }
  else {
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }
}


/**
 * Form callback for group validation processing.
 */
function crl_user_admin_group_validate_process($form, &$form_state, $case = NULL) {
  // Get the cached data that was most recently fetched regarding the group
  // memberships.
  $data = cache_get('crl_user_user_group_validate_data');
  // Map some text descriptions to the groups that may be addressing.
  $groups = array(
    'switch_mem' => t('These users are in the <em>member-non</em> group, but thier current institution affiliation indicates they should be in the <em>member-crl</em> group instead.'),
    'switch_nonmem' => t('These users are in the <em>member-crl</em> group, but thier current institution affiliation (or lack thereof) indicates they should be in the <em>member-non</em> group instead.'),
    'add_mem' => t('These users are not in any group signifying membership, but thier current institution affiliation indicates that they should be in the <em>member-crl</em> group.'),
    'add_nonmem' => t('These users are not in any group signifying membership, but thier current institution affiliation (or lack thereof) indicates that they should be in the <em>member-non</em> group.'),
  );
  if (!empty($data->data['flagged'][$case]) && $data->expire >= time() && array_key_exists($case, $groups)) {
    $form_state['crowd_users_to_process'] = array_keys($data->data['flagged'][$case]);
    // Stash the subset of users to process, along with the group info, onto the
    // form state for access in the submit handler.
    $form_state['crowd_users_to_process_case'] = $case;
    $users_remaining = array_splice($form_state['crowd_users_to_process'], CRL_USER_ADMIN_TOOLS_PROCESS_ONCE);
    // Build our intro message.
    $intro = t('Automated corrections will be run for the @count users listed below.', array('@count' => count($form_state['crowd_users_to_process'])));
    $intro .= ' ' . $groups[$case];
    if ($users_remaining) {
      $intro .= '<br/><br/>' . t('<strong>Important note:</strong> Only a maxiumum of @num users can be processed at once with this tool. You will need to submit this form multiple times to process the remaining @count users that have been targeted for correction.', array('@num' => CRL_USER_ADMIN_TOOLS_PROCESS_ONCE, '@count' => count($users_remaining)));
    }
    $intro .= theme('item_list', array('items' => $form_state['crowd_users_to_process']));
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Update groups for these @count users', array('@count' => count($form_state['crowd_users_to_process']))),
    );
  }
  else {
    $intro = t('No users can be identified for processing. You may need to re-fetch user data from the group validation tool.');
  }
  $form['intro'] = array(
    '#prefix' => '<p>',
    '#suffix' => '</p>',
    '#markup' => $intro,
    '#weight' => -1,
  );
  $form['return'] = array(
    '#prefix' => '<p>',
    '#suffix' => '</p>',
    '#markup' => l(t('Return to the group validation tool'), 'admin/people/crl/group_validate'),
  );
  return $form;
}


/**
 * Submit handler for for group validation processing.
 */
function crl_user_admin_group_validate_process_submit($form, &$form_state, $case = NULL) {
  $data = cache_get('crl_user_user_group_validate_data');
  $case = $form_state['crowd_users_to_process_case'];
  $users_to_process = $form_state['crowd_users_to_process'];
  $processed = 0;
  // Reconfirm that we have valid data.
  if (!empty($data->data['flagged'][$case]) && $data->expire >= time()) {
    // Process the group changes based on the type of action needed.
    try {
      $crowd = crowd_client_connect();
      foreach ($form_state['crowd_users_to_process'] as $user) {
        if (array_key_exists($user, $data->data['flagged'][$case])) {
          // The user group adjustments depend on the case.
          $to_add = $to_remove = $to_remove_soft = '';
          switch ($case) {
            case 'switch_mem':
              $to_remove = 'member-non';
            case 'add_mem':
              $to_add = 'member-crl';
              break;
            case 'switch_nonmem':
              $to_remove = 'member-crl';
            case 'add_nonmem':
              $to_add = 'member-non';
              // Both cases above justify the removal of the "member-alert"
              // group if if exists.
              $to_remove_soft = 'member-alert';
          }
          // Process changes.
          if ($to_add && $crowd->addUserToGroup($user, $to_add)) {
            $to_add = '';
          }
          if ($to_remove && $crowd->removeUserFromGroup($user, $to_remove)) {
            $to_remove = '';
          }
          // A soft removal is just an attempt to remove the group if it exists.
          // Any errors should be ignored.
          if ($to_remove_soft) {
            $crowd->removeUserFromGroup($user, $to_remove_soft);
          }
          // Verify additions and removals were successful.
          if (empty($to_add) && empty($to_remove)) {
            $processed++;
            unset($data->data['flagged'][$case][$user]);
          }
        }
      }
    }
    catch (CrowdException $e) {
      $e->logResponse();
      drupal_set_message(t('The was an error processing users.'), 'error');
      return;
    }
  }
  drupal_set_message(t('Processed @processed users.', array('@processed' => $processed)));
  // If we made changes update the cached records for later passes.
  if ($processed) {
    cache_set('crl_user_user_group_validate_data', $data->data, 'cache', $data->expire);
  }
}
