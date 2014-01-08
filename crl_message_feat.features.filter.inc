<?php
/**
 * @file
 * crl_message_feat.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function crl_message_feat_filter_default_formats() {
  $formats = array();

  // Exported format: Literal.
  $formats['literal'] = array(
    'format' => 'literal',
    'name' => 'Literal',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  return $formats;
}
