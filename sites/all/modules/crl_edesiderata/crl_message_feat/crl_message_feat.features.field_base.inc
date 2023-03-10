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

  // Exported field_base: 'message_subscribe_email'.
  $field_bases['message_subscribe_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'user',
    ),
    'field_name' => 'message_subscribe_email',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Don\'t email',
        1 => 'Email',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'message_subscribe_email_freq'.
  $field_bases['message_subscribe_email_freq'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'user',
    ),
    'field_name' => 'message_subscribe_email_freq',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'message_subscribe_email_frequency_allowed_values',
      'allowed_values_php' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
