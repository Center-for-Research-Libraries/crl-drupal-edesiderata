<?php

/**
 * Implements hook_drush_command().
 */
function crowd_batch_pull_drush_command() {
  $items['crowd-batch-pull-queue-all'] = array(
    'description' => 'Queue all users for pull.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array('crowd'),
    'arguments' => array(),
    'examples' => array(
      'drush crowd-batch-pull-queue-all' => 'Queue all users for pull.',
    ),
  );
  return $items;
}


/**
 * Callback for crowd-batch-pull-queue-all Drush command.
 */
function drush_crowd_batch_pull_queue_all() {
  drush_print(dt('Fetching full remote user list...'));
  $to_queue = crowd_batch_pull_get_detector()->getAllCrowdUsers();
  if (drush_confirm(dt('This will queue @count Crowd users for a pull. Are you sure you want to continue?', array('@count' => count($to_queue))))) {
    $queue = DrupalQueue::get('crowd_batch_pull');
    $added = 0;
    foreach ($to_queue as $name) {
      $added += (int) $queue->createItem($name);
    }
    if ($added == count($to_queue)) {
      drush_log(dt('@count users added to the pull queue', array('@count' => $added)), 'ok');
    }
    else {
      drush_log(dt('There was a problem adding users to the pull queue'), 'error');
    }
  }
}






