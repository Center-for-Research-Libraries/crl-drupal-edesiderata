<?php
// $Id$

/**
 * @file
 *   Implementation of a node body search and replace drush command. 
 */

/**
 * Implementation of hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and 
 * description.
 *
 * Notice how this structure closely resembles how 
 * you define menu hooks.
 * 
 * @See drush_parse_command() for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function replace_drush_command() {
  $items = array();

  // the key in the $items array is the name of the command.
  $items['replace'] = array(
    // the name of the function implementing your command.
    'callback' => 'replace_callback',
    // a short description of your command
    'description' => "Find and replace text in a node's body using regular expressions.",
    'examples' => array(

      "drush replace jstor-titles/philosophy-titles \"/feminist-women's-studies-titles/\" \"feminist-womens-studies-titles\"" => "Replaces all instances of \"feminist-women's-studies-titles\" with \"feminist-womens-studies-titles\" in the body of the node with path alias \"jstor-titles/philosophy-titles\"."
    ),
    'arguments' => array(
      'path' => "Path to a node.  This can either be the node's path alias or node/NID path.",
      'pattern' => 'Pattern to search for.  This should be specified in the same way as the pattern argument to the PHP function preg_replace.',
      'replacement' => 'Replacement pattern.  This should be specified in the same way as the replacement argument to the PHP function preg_replace.',
      'log_message' => '(optional) Revision log message for the replacement.',
    ),
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function replace_drush_help($section) {
  switch ($section) {
    case 'drush:replace':
      return dt("Replaces text in a particular node's body using regular expressions.");
  }
}

/**
 * Example drush command callback.
 *
 * This is where the action takes place.
 *
 * In this function, all of Drupals API is (usually) available, including
 * any functions you have added in your own modules/themes.
 *
 * To print something to the terminal window, use drush_print().
 *
 */
function replace_callback() {
  // Perform this action as the administrative user.
  global $user;
  $user = user_load(array('uid' => 1));

  $commands = func_get_args();

  $num_args = func_num_args();

  if ($num_args == 3 ||
      $num_args == 4) {
    $path = $commands[0];
    $pattern = $commands[1];
    $replacement = $commands[2];
 
    if ($num_args == 4) {
      $log_message = $commands[3];
    }
    else {
      $log_message = "Updated using drush replace $pattern $replacement";
    }

    $nid = NULL;
    $path_parts = preg_split('/\//', $path);
    if (count($path_parts) == 2 && $path_parts[0] == 'node') {
      // Path specified is of form node/NID
      $nid = $path_parts[1];
    }
    else {
      $system_url = drupal_lookup_path('source', $path);
      $system_url_parts = preg_split('/\//', $system_url);
      if ($system_url_parts[0] == 'node') {
        $nid = $system_url_parts[1];
      }
      else {
        return drush_set_error('DRUSH_REPLACE_NOT_NODE', dt('!path is not a node.', array('!path' => $path)));
      }
    }

    if (!is_null($nid)) {
      $node = node_load($nid);
      if ($node) {
        $replacement_count = 0;
        $limit = -1; // Unlimited replacements
        $body = $node->body;
        $new_body = preg_replace($pattern, $replacement, $body, $limit, $replacement_count);
        // BEGIN DEBUG
        //drush_print($body);
        //drush_print('+++---');
        //drush_print($new_body);
        //drush_print('+++---');
        //drush_print($log_message);
        // END DEBUG
        $node->body = $new_body;
        $node->log = $log_message;
        node_save($node);
        drush_print(dt('Replaced !count instances.', array('!count' => $replacement_count)));
      }
      else {
        return drush_set_error('DRUSH_REPLACE_NODE_LOAD_FAILED', dt('Could not load node with path !path.', array('!path' => $path)));
      }
    }
    else {
      return drush_set_error('DRUSH_REPLACE_NODE_LOAD_FAILED', dt('Could not load node with path !path.', array('!path' => $path)));
    }
  }
  else {
    return drush_set_error('DRUSH_REPLACE_COMMAND_SYNTAX', dt("Incorrect command syntax. Please type 'drush help replace' to see how to use this command."));
  }
}
