<?php
/**
 * @file
 * crl_mydes_feat.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crl_mydes_feat_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use search_api_saved_searches'.
  $permissions['use search_api_saved_searches'] = array(
    'name' => 'use search_api_saved_searches',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_saved_searches',
  );

  return $permissions;
}
