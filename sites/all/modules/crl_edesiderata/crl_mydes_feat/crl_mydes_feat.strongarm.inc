<?php
/**
 * @file
 * crl_mydes_feat.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function crl_mydes_feat_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'message_base_node_watch';
  $strongarm->value = 'mydes_saved_searches:block';
  $export['message_base_node_watch'] = $strongarm;

  return $export;
}
