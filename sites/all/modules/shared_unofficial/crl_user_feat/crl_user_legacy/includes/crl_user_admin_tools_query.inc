<?php


/**
 * @file
 * Form definition and batch processing logic for CRL user admin query tools.
 * This file handles both the history and inst query cases.
 */


// Include common admin methods.
require_once dirname(__FILE__) . '/crl_user_admin_tools_common.inc';


/**
 * Form callback for the admin crowd user history widget.
 */
function crl_user_admin_query($form, &$form_state, $type) {
  // Initialize some variables.
  global $user;
  $have_data = FALSE;
  $hide_inactive = isset($form_state['values']['hide_inactive']) ? $form_state['values']['hide_inactive'] : FALSE;
  $hide_alert = isset($form_state['values']['hide_alert']) ? $form_state['values']['hide_alert'] : FALSE;
  $hide_match = isset($form_state['values']['hide_match']) ? $form_state['values']['hide_match'] : FALSE;
  $history_start = isset($form_state['values']['history_start']) ? $form_state['values']['history_start'] : 7;
  // Some init variables are specific to the query type.
  if ($type == 'history') {
    $results = cache_get('crl_user_query_data_history_' . $user->uid);
  }
  else {
    $inst_list = crl_user_inst_list_builder(TRUE, TRUE, TRUE);
    $inst_current = isset($form_state['input']['inst']) ? $form_state['input']['inst'] : NULL;
    $results = cache_get('crl_user_query_data_inst_' . $inst_current);
  }
  // Init some variables that are only needed when we have data.
  if (!empty($results->data) && $results->expire >= time()) {
    $have_data = TRUE;
    // The history start data, if applicable, should be carried over from the
    // cached metadata when we have data.
    $history_start = isset($results->data['metadata']['history_start']) ? $results->data['metadata']['history_start'] : $history_start;
    $header = array(t('Username'), t('Email'), t('First Name'), t('Last Name'), t('Institution'), t('Active'), t('Member Alert'), t('Last Login'), t('Edit in Crowd'), t('Created this period'));
    $rows = $results->data['rows'];
    $rows_count = count($rows);
    // Process any filters that are set via the form.
    $rows_hidden = 0;
    foreach ($rows as $key => $row) {
      if ($hide_inactive && $row['active'] == 'no') {
        unset($rows[$key]);
        $rows_hidden++;
        continue;
      }
      if ($hide_alert && $row['alert'] == 'no') {
        unset($rows[$key]);
        $rows_hidden++;
        continue;
      }
      if ($hide_match && $row['username'] == $row['email']) {
        unset($rows[$key]);
        $rows_hidden++;
      }
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
  // Some form structures are specific to the query type.
  if ($type == 'history') {
    $form['history_start'] = array(
      '#type' => 'textfield',
      '#title' => t('Days of History'),
      '#default_value' => $history_start,
      '#description' => t('The number of days of change history to display. Decimals are allowed (0.1 = approx 2.5 hours).'),
    );
    $form['#submit'] = array('crl_user_admin_query_history_submit');
  }
  if ($type == 'inst') {
    $form['inst'] = array(
      '#type' => 'select',
      '#title' => t('Institution'),
      '#required' => TRUE,
      '#options' => $inst_list,
      '#default_value' => $inst_current,
      '#empty_option' => 'Select',
    );
    $form['#submit'] = array('crl_user_admin_query_inst_submit');
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Fetch Data')
  );
  // We only render ajax filters and the results table if we have data to work
  // with.
  if ($have_data) {
    $form['hide_inactive'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide inactive users'),
      '#default_value' => $hide_inactive,
        '#ajax' => array(
          'callback' => 'crl_user_admin_query_ajax',
          'wrapper' => 'crowd-query-wrap-div',
          'method' => 'replace',
          'effect' => 'fade',
        ),
    );
    $form['hide_alert'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide users that are <strong>not</strong> in member alert status'),
      '#default_value' => $hide_match,
        '#ajax' => array(
          'callback' => 'crl_user_admin_query_ajax',
          'wrapper' => 'crowd-query-wrap-div',
          'method' => 'replace',
          'effect' => 'fade',
        ),
    );
    $form['hide_match'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide users where username matches email'),
      '#default_value' => $hide_match,
        '#ajax' => array(
          'callback' => 'crl_user_admin_query_ajax',
          'wrapper' => 'crowd-query-wrap-div',
          'method' => 'replace',
          'effect' => 'fade',
        ),
    );
    $form['crowd_query_fieldset'] = array(
      '#prefix' => '<div id="crowd-query-wrap-div"',
      '#suffix' => '</div>',
      '#type' => 'fieldset',
    );
    $form['crowd_query_fieldset']['stats'] = array(
      '#markup' => '<p><strong>' . t('Found @count users that match this query criteria. @hidden are currently hidden by filters.', array('@count' => $rows_count, '@hidden' => $rows_hidden)) . '</strong></p>',
    );
    $form['crowd_query_fieldset']['stamp'] = array(
      '#markup' => '<p>' . t('This data was fetched on %time. <strong>Any remote changes made since that time are not yet reflected here.<br/></strong> Click the "Fetch Data" button above to refresh.', array('%time' => format_date($results->data['metadata']['finished']))) . '</p>',
    );
    $form['crowd_query_fieldset']['results'] = array(
      '#markup' => theme('table', array('header' => $header, 'rows' => $rows)),
    );
  }
  return $form;
}


/**
 * Ajax callback for the admin user query form.
 */
function crl_user_admin_query_ajax($form, &$form_state) {
  // No processing needed here, just return the form.
  return $form['crowd_query_fieldset'];
}


/**
 * Submit handler for an admin crowd user HISTORY query.
 */
function crl_user_admin_query_history_submit($form, &$form_state) {
  // Convert history to unix timestamp and then into the (strict) format that
  // Crowd understands.
  $history_start_crowd = time() - 60 * 60 * 24 * $form_state['values']['history_start'];
  $history_start_crowd = date('Y-m-d', $history_start_crowd) . 'T' .  date('G:i', $history_start_crowd);
  // Setup the batch operation that will fetch user data from Crowd and stash
  // it for later rendering in our form.
  $batch = array(
    'operations' => array(
      array('crl_user_admin_query_history_batch_set_context', array($form_state['values']['history_start'])),
      array('crl_user_admin_query_history_batch_query', array('updated', 'user', 'updatedDate > ' . $history_start_crowd)),
      array('crl_user_admin_query_history_batch_query', array('created', 'user', 'createdDate > ' . $history_start_crowd)),
      array('crl_user_admin_query_batch_fetch', array('updated')),
    ),
    'finished' => 'crl_user_admin_query_history_batch_finished',
    'title' => t('Processing history-based query'),
    'init_message' => t('Starting ... Fetching user lists from Crowd.'),
    'progress_message' => t('Completed step @current of @total.'),
    'error_message' => t('The batch process has encountered an error.'),
    'file' => drupal_get_path('module', 'crl_user_legacy') . '/includes/crl_user_admin_tools_query.inc',
  );
  batch_set($batch);
  // Ensure that the form is rebuilt, with sumitted values attached, after
  // submit and batch processing.
  $form_state['rebuild'] = TRUE;
}


/**
 * Submit handler for an admin crowd user INST query.
 */
function crl_user_admin_query_inst_submit($form, &$form_state) {
  // Setup the batch operation that will fetch user data from Crowd and stash
  // it for later rendering in our form.
  $batch = array(
    'operations' => array(
      array('crl_user_admin_query_inst_batch_query', array($form_state['input']['inst'])),
      array('crl_user_admin_query_batch_fetch', array('users')),
    ),
    'finished' => 'crl_user_admin_query_inst_batch_finished',
    'title' => t('Processing institution-based query'),
    'init_message' => t('Starting ... Fetching user list.'),
    'progress_message' => t('Completed step @current of @total.'),
    'error_message' => t('The batch process has encountered an error.'),
    'file' => drupal_get_path('module', 'crl_user_legacy') . '/includes/crl_user_admin_tools_query.inc',
  );
  batch_set($batch);
  // Ensure that the form is rebuilt, with sumitted values attached, after
  // submit and batch processing.
  $form_state['rebuild'] = TRUE;
}


/**
 * Batch operation to establish some base context variables for a history-based
 * query.
 *
 * @param string $history_start
 *   The days of history value as input in the form. Used for context.
 * @param array $context
 *   Contextual information as provided through the batch API.
 */
function crl_user_admin_query_history_batch_set_context($history_start, &$context) {
  $context['results']['metadata']['history_start'] = $history_start;
}


/**
 * Batch operation to query a list of users based on a history filter.
 *
 * This query uses Crowd directly and the "Crowd Query Language".
 *
 * @param string $label
 *   A label for this query which also designates how the results will be keyed
 *   inside $context['results'].
 * @param string $type
 *   The type of data to search in Crowd (e.g. 'user').
 * @param string $restriction
 *   The "Crowd Query Language" filter to apply.
 * @param array $context
 *   Contextual information as provided through the batch API.
 */
function crl_user_admin_query_history_batch_query($label, $type, $restriction, &$context) {
  if (!isset($context['results'][$label])) {
    $context['results'][$label] = array();
    $context['sandbox']['offset'] = 0;
  }
  $results_per_query = 900;
  try {
    $results = crowd_client_connect()->searchCql($type, $restriction, $context['sandbox']['offset'], $results_per_query);
  }
  catch (CrowdException $e) {
    $e->logResponse();
    drupal_set_message('User data could not be fetched due to an error in the Crowd connection.', 'error', FALSE);
  }
  if (!empty($results)) {
    $context['results'][$label] = array_merge($context['results'][$label], $results);
  }
  // Prep for next iteration.
  $context['message'] = t('Querying Crowd for base data.');
  $context['sandbox']['offset'] = $context['sandbox']['offset'] + $results_per_query;
  $context['finished'] = empty($results) ? 1 : 0;
}


/**
 * Batch operation to query a list of users based on an institution filter.
 *
 * This query uses LDAP directly.
 *
 * @param string $inst
 *   The sfid for an institution to use as a filter in the query.
 * @param array $context
 *   Contextual information as provided through the batch API.
 */
function crl_user_admin_query_inst_batch_query($inst, &$context) {
  // Get the users for the selected institution.
  try {
    $context['results']['users'] = array_keys(crl_user_ldap_connect()->getInstUsers($inst));
    $context['results']['inst'] = $inst;
  }
  catch (Exception $e) {
    watchdog_exception('crl user', $e);
    // Re-throw the exception to kill the batch process if needed.
    throw new Exception('User data cannot be reliably processed due to issues with the LDAP connection.');
  }
}


/**
 * Batch operation to fetch the full user details for usernames stored in
 * in $context['results'].
 *
 * @param string $source
 *   The key in $context['results'] where a list of users to lookup can be
 *   found. The resulting list must be a numerically indexed array of usernames.
 * @param array $context
 *   Contextual information as provided through the batch API.
 */
function crl_user_admin_query_batch_fetch($source, &$context) {
  // Prep context.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['total'] = count($context['results'][$source]);
    if ($context['sandbox']['total'] == 0) {
      return;
    }
  }
  $progress = $context['sandbox']['progress'];
  $username = $context['results'][$source][$progress];
  // Fetch full user data.
  $data = crl_user_get_remote_data($username);
  if ($data) {
    // Add the username to the beginning of the data.
    $data = array('username' => $username) + $data;
    // Add a note about if the user was created during this history period and
    // a crowd edit link (applies only to histoy-based queries).
    if (isset($context['results']['created'])) {
      $data['created_this_period'] = array_search($username, $context['results']['created']) !== FALSE ? t('yes') : t('no');
    }
    else {
      $data['created_this_period'] = t('n/a');
    }
    $context['results']['rows'][$username] = $data;
  }
  // Prep for next iteration.
  $context['message'] = t('Fetching full data for user @current of @total', array('@current' => $context['sandbox']['progress'], '@total' => $context['sandbox']['total']));
  $context['sandbox']['progress']++;
  $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['total'];
}


/**
 * Callback for the completion of the HISTORY query batch operation.
 */
function crl_user_admin_query_history_batch_finished($success, $results, $operations) {
  if ($success) {
    global $user;
    $results['metadata']['finished'] = time();
    cache_set('crl_user_query_data_history_' . $user->uid, array('metadata' => $results['metadata'], 'rows' => $results['rows']), 'cache', time() + 60 * 30);
  }
  else {
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }
}


/**
 * Callback for the completion of the INST query batch operation.
 */
function crl_user_admin_query_inst_batch_finished($success, $results, $operations) {
  if ($success) {
    $results['metadata']['finished'] = time();
    // Stash our results for later access and listing.
    cache_set('crl_user_query_data_inst_' . $results['inst'], array('metadata' => $results['metadata'], 'rows' => $results['rows']), 'cache', time() + 60 * 30);
  }
  else {
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }
}
