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

  // Exported permission: 'configure tablefield'.
  $permissions['configure tablefield'] = array(
    'name' => 'configure tablefield',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'tablefield',
  );

  // Exported permission: 'export tablefield'.
  $permissions['export tablefield'] = array(
    'name' => 'export tablefield',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'tablefield',
  );

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

  // Exported permission: 'rebuild tablefield'.
  $permissions['rebuild tablefield'] = array(
    'name' => 'rebuild tablefield',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'tablefield',
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
