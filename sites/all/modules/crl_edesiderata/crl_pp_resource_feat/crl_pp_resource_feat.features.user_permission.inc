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

  return $permissions;
}
