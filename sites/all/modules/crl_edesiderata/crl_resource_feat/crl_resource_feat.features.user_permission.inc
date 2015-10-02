<?php
/**
 * @file
 * crl_resource_feat.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crl_resource_feat_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'flag resource_suggestion_convert'.
  $permissions['flag resource_suggestion_convert'] = array(
    'name' => 'flag resource_suggestion_convert',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag resource_suggestion_convert'.
  $permissions['unflag resource_suggestion_convert'] = array(
    'name' => 'unflag resource_suggestion_convert',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
