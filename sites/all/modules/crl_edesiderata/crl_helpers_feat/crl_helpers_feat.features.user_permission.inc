<?php
/**
 * @file
 * crl_helpers_feat.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crl_helpers_feat_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_internal_notes'.
  $permissions['create field_internal_notes'] = array(
    'name' => 'create field_internal_notes',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_internal_notes'.
  $permissions['edit field_internal_notes'] = array(
    'name' => 'edit field_internal_notes',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_internal_notes'.
  $permissions['edit own field_internal_notes'] = array(
    'name' => 'edit own field_internal_notes',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_internal_notes'.
  $permissions['view field_internal_notes'] = array(
    'name' => 'view field_internal_notes',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_internal_notes'.
  $permissions['view own field_internal_notes'] = array(
    'name' => 'view own field_internal_notes',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
