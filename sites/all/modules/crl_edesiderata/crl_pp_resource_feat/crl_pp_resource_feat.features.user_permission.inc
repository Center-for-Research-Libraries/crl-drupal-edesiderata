<?php
/**
 * @file
 * crl_pp_resource_feat.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crl_pp_resource_feat_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_pp_related'.
  $permissions['create field_pp_related'] = array(
    'name' => 'create field_pp_related',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pp_related'.
  $permissions['edit field_pp_related'] = array(
    'name' => 'edit field_pp_related',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pp_related'.
  $permissions['edit own field_pp_related'] = array(
    'name' => 'edit own field_pp_related',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'flag entityform_pp_convert'.
  $permissions['flag entityform_pp_convert'] = array(
    'name' => 'flag entityform_pp_convert',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag entityform_pp_convert'.
  $permissions['unflag entityform_pp_convert'] = array(
    'name' => 'unflag entityform_pp_convert',
    'roles' => array(),
    'module' => 'flag',
  );

  // Exported permission: 'view field_pp_related'.
  $permissions['view field_pp_related'] = array(
    'name' => 'view field_pp_related',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pp_related'.
  $permissions['view own field_pp_related'] = array(
    'name' => 'view own field_pp_related',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
