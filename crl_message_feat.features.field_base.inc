<?php
/**
 * @file
 * crl_message_feat.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function crl_message_feat_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_message_cat'
  $field_bases['field_message_cat'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_message_cat',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'major' => 'Major',
        'minor' => 'Minor',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
