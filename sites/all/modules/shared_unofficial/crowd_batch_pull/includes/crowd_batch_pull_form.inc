<?php


/**
 * @file
 * Crowd batch pull settings and tools form.
 */


/**
 * Form builder for the Crowd batch pull form.
 */
function crowd_batch_pull_form($form, $form_state) {
  $queue = DrupalQueue::get('crowd_batch_pull');
  $to_delete = isset($form_state['values']['crowd_batch_pull_to_delete']) ? $form_state['values']['crowd_batch_pull_to_delete'] : NULL;
  $delete_markup = '<p>' . t('Detection of remotly deleted users has not been run yet.') . '</p>';
  // Some build logic depends on which AJAX button was pressed.
  if (isset($form_state['triggering_element']['#name'])) {
    switch ($form_state['triggering_element']['#name']) {
      case 'delete_detect':
        $to_delete = crowd_batch_pull_get_detector()->detectDeleted();
        if ($queue->numberOfItems()) {
          drupal_set_message(t('The pull queue is currently not empty. Delete detection may be unreliable until the pull queue has been fully processed.'), 'warning');
        }
        break;
      case 'delete_reset':
        $to_delete = NULL;
        break;
      case 'queue_all':
        $added = 0;
        foreach (crowd_batch_pull_get_detector()->getAllCrowdUsers() as $name) {
          $added += (int) $queue->createItem($name);
        }
        drupal_set_message(t('Added @added Crowd users to the pull queue.', array('@added' => $added)));
        break;
      case 'queue_clear':
        db_query('DELETE FROM queue WHERE name=:queue_name', array(':queue_name' => 'crowd_batch_pull'));
        drupal_set_message(t('The pull queue has been cleared.'));
        break;
      case 'default':
    }
  }
  // Build the settings fieldset and button.
  $form['crowd_batch_pull_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Batch Pull Options'),
    '#description' => t(''),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['crowd_batch_pull_settings']['crowd_batch_pull_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto detect and pull remote user changes during cron'),
    '#default_value' => variable_get('crowd_batch_pull_enabled', FALSE),
    '#description' => t('Enable automatic detection of remote Crowd user changes and additions during cron. If disabled the sync management tools below can still be used for manually syncing.'),
  );
  $form['crowd_batch_pull_settings']['crowd_batch_pull_auto_deletions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Also auto sync Crowd user deletions (experimental)'),
    '#default_value' => variable_get('crowd_batch_pull_auto_deletions', FALSE),
    '#description' => t('Detect and sync Crowd user <em>deletions</em> with Drupal automatically (in addition to changes and additions). If disabled you can still process deletions manually below.'),
    '#states' => array(
      // Hide the settings when the translate option is disabled.
      'invisible' => array(
        ':input[name="crowd_batch_pull_enabled"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['crowd_batch_pull_settings']['save'] = array(
    '#type' => 'submit',
    '#name' => 'settings_submit',
    '#value' => t('Save settings'),
  );
  // Build the queue fieldset and buttons.
  $queue_items_count = $queue->numberOfItems();
  $queue_intro = '<p>' . t('Pull/sync tasks for each remotely updated user are managed in a local queue. If many remote user pulls are queued at once it can take multiple cron runs for this queue to finish processing. Additionally, a full user refresh can be forced at any time by adding all Crowd users to the pull queue manually.') . '</p>';
  $queue_intro .= '<p>' . t('There are currently <strong>@count</strong> users in the queue pending synchronization. The queue will be processed automatically during cron runs.', array('@count' => $queue_items_count)) . '</p>';
  $form['crowd_batch_pull_form_ajax_queue'] = array(
    '#type' => 'fieldset',
    '#title' => t('Manual pull queue management'),
    '#description' => $queue_intro,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#prefix' => '<div id="crowd_batch_pull_form_ajax_queue">',
    '#suffix' => '</div>',
  );
  $form['crowd_batch_pull_form_ajax_queue']['queue_all'] = array(
    '#type' => 'button',
    '#name' => 'queue_all',
    '#value' => t('Queue all users for pull'),
    '#ajax'  => array(
      'callback' => 'crowd_batch_pull_form_ajax_queue',
      'wrapper' => 'crowd_batch_pull_form_ajax_queue',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );
  if ($queue_items_count) {
    $form['crowd_batch_pull_form_ajax_queue']['queue_clear'] = array(
      '#type' => 'button',
      '#name' => 'queue_clear',
      '#value' => t('Clear queue'),
      '#ajax'  => array(
        'callback' => 'crowd_batch_pull_form_ajax_queue',
        'wrapper' => 'crowd_batch_pull_form_ajax_queue',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    );
  }
  // Build the deletion tools fieldset and buttons.
  $form['crowd_batch_pull_form_ajax_delete'] = array(
    '#type' => 'fieldset',
    '#title' => t('Manual deletion management'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#prefix' => '<div id="crowd_batch_pull_form_ajax_delete">',
    '#suffix' => '</div>',
  );
  if (isset($to_delete)) {
    $message = empty($to_delete) ? '<p>' . t('No users detected for deletion.' . '</p>') :
      '<p>' . t('The following users exist locally (are linked to Crowd) but do not exist in the remote Crowd directory:') . '</p></p>' . theme('item_list', array('items' => $to_delete)) . '</p><p>' . t('If you choose to delete these users they will be processed in batch and their content will be assigned to the %anonymous-name user.', array('%anonymous-name' => variable_get('anonymous', t('Anonymous')))) . '</p>';
    $form['crowd_batch_pull_form_ajax_delete']['results'] = array(
      '#markup' => $message,
    );
    if (!empty($to_delete)) {
      $form['crowd_batch_pull_form_ajax_delete']['delete_submit'] = array(
        '#type' => 'submit',
        '#name' => 'delete_submit',
        '#value' => t('Delete these users'),
      );
    }
    $form['crowd_batch_pull_form_ajax_delete']['delete_reset'] = array(
      '#type'  => 'button',
      '#name' => 'delete_reset',
      '#value' => t('Reset'),
      '#ajax'  => array(
        'callback' => 'crowd_batch_pull_form_ajax_delete',
        'wrapper' => 'crowd_batch_pull_form_ajax_delete',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    );
  }
  else {
    $form['crowd_batch_pull_form_ajax_delete']['results'] = array(
      '#markup' => '<p>' . t('Detection of remotly deleted users has not been run yet.') . '</p>',
    );
    $form['crowd_batch_pull_form_ajax_delete']['delete_detect'] = array(
      '#type' => 'button',
      '#name' => 'delete_detect',
      '#value' => t('Detect remotely deleted users'),
      '#ajax'  => array(
        'callback' => 'crowd_batch_pull_form_ajax_delete',
        'wrapper' => 'crowd_batch_pull_form_ajax_delete',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    );
  }
  // Stash calculated "to delete" details in a place that can later be accessed
  // but submit handlers.
  $form['crowd_batch_pull_to_delete'] = array(
    '#type' => 'value',
    '#value' => $to_delete,
  );
  return $form;
}


/**
 * Ajax callback for the batch pull queue form processing.
 */
function crowd_batch_pull_form_ajax_queue($form, $form_state) {
  // Ensure that we capture any drupal messages that are set during form
  // processing.
  $messages = array(
    'messages' => array(
      '#markup' => theme('status_messages'),
    ),
  );
  return $messages + $form['crowd_batch_pull_form_ajax_queue'];
}


/**
 * Ajax callback for the batch pull delete form detection.
 */
function crowd_batch_pull_form_ajax_delete($form, $form_state) {
  // Ensure that we capture any drupal messages that are set during form
  // processing.
  $messages = array(
    'messages' => array(
      '#markup' => theme('status_messages'),
    ),
  );
  return $messages + $form['crowd_batch_pull_form_ajax_delete'];
}


/**
 * Submit callback for the batch pull admin form.
 */
function crowd_batch_pull_form_submit($form, $form_state) {
  // Specific submit logic depends on which button was pressed.
  if (isset($form_state['triggering_element']['#name'])) {
    switch ($form_state['triggering_element']['#name']) {
      // Save settings.
      case 'settings_submit':
        $orig_enabled_setting = variable_get('crowd_batch_pull_enabled', FALSE);
        $new_enabled_setting = $form_state['values']['crowd_batch_pull_enabled'];
        if ($new_enabled_setting && $orig_enabled_setting != $new_enabled_setting) {
          drupal_set_message(t('You have enabled the "auto detect and pull" feature. Please note that it may take several cron runs to complete the initial pull of all remote user data and establish a syncronzied state between the Crowd and Drupal directories.'));
          // Reset that last pull timestamp so that all users will be queued
          // during the next cron run. This will ensure an in-sync starting
          // point.
          variable_set('crowd_batch_pull_last_timestamp', 0);
        }
        variable_set('crowd_batch_pull_enabled', $form_state['values']['crowd_batch_pull_enabled']);
        variable_set('crowd_batch_pull_auto_deletions', $form_state['values']['crowd_batch_pull_auto_deletions']);
        drupal_set_message(t('Settings saved'));
        break;
      // Process deletions.
      case 'delete_submit':
        // Batch delete the users that were detected as remotely deleted.
        foreach ($form_state['values']['crowd_batch_pull_to_delete'] as $uid => $username) {
          $user = user_load($uid);
          if ($user) {
            // Set a flag that we are in the middle of a pull operation that
            // will persist throughout the delete process.
            $user->crowd_user_pull = TRUE; // Depends on static entity cache.
            user_cancel(array(), $uid, 'user_cancel_reassign');
          }
        }
    }
  }
}
