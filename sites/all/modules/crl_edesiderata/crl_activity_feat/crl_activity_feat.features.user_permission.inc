<?php
/**
 * @file
 * crl_activity_feat.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crl_activity_feat_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_resource_reference'.
  $permissions['create field_resource_reference'] = array(
    'name' => 'create field_resource_reference',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_resource_reference'.
  $permissions['edit field_resource_reference'] = array(
    'name' => 'edit field_resource_reference',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_resource_reference'.
  $permissions['edit own field_resource_reference'] = array(
    'name' => 'edit own field_resource_reference',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_resource_reference'.
  $permissions['view field_resource_reference'] = array(
    'name' => 'view field_resource_reference',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_resource_reference'.
  $permissions['view own field_resource_reference'] = array(
    'name' => 'view own field_resource_reference',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
