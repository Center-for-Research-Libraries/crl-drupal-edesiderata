<?php

/**
 * @file
 * Theme related functions for processing output related to crl_message_feat.
 */


/**
 * Custom theme function for rows in message digest to add the timestamp.
 */
function crl_message_feat_message_digest_row($vars) {
  array_push($vars['rows'], ' ('. format_date($vars['message']->timestamp, 'custom', 'F j, Y : g:i a T').')');
  return implode($vars['rows']);
}
 
/**
 * Custom theme function for message digest to add it to a list.
 */
function crl_message_feat_message_digest($vars) {
  $digest = '<p>' . t('The folowing activity digest has been generated for you from the Center for Research Libraries !main website. The activity shown below is based on the watchlist items you specified in !mydes.', array('!main' => l('eDesiderata', '<front>'), '!mydes' => l('My eDesiderata', 'my'))) . '</p>';
  $digest .= theme_item_list(array('items' => $vars['messages'], 'title' => NULL, 'type' => 'ul', 'attributes' => array()));
  return $digest;
}


function crl_message_feat_preprocess_mimemail_message($vars) {
  // Placeholder for prepecessing logic on the mimemail template.
}