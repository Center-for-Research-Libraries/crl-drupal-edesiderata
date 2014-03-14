<?php

/**
 * @file
 * Theme related functions for processing output related to crl_message_feat.
 */


/**
 * Custom theme function for rows in message digest to add the timestamp.
 */
function crl_message_feat_message_digest_row($vars) {
  array_push($vars['rows'], ' ('. format_date($vars['message']->timestamp, 'medium').')');
  return implode($vars['rows']);
}
 
/**
 * Custom theme function for message digest to add it to a list.
 */
function crl_message_feat_message_digest($vars) {
  $digest = '<p>' . t('The following activity digest has been generated for you from the Center for Research Libraries eDesiderata website, based on the watchlist items you specified in !mydes.', array('!mydes' => l('meDesiderata', 'me'))) . '</p>';
  $digest .= theme_item_list(array('items' => $vars['messages'], 'title' => NULL, 'type' => 'ul', 'attributes' => array()));
  $digest .= '<p>' . t('You can add or remove items from your watchlist by logging-in to !mydes', array('!mydes' => l('meDesiderata', 'me'))) . '</p>';
  return $digest;
}
