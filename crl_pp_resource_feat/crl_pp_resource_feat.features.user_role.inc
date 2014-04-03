<?php
/**
 * @file
 * crl_pp_resource_feat.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function crl_pp_resource_feat_user_default_roles() {
  $roles = array();

  // Exported role: collection-development.
  $roles['collection-development'] = array(
    'name' => 'collection-development',
    'weight' => 21,
  );

  // Exported role: pp-main.
  $roles['pp-main'] = array(
    'name' => 'pp-main',
    'weight' => 6,
  );

  return $roles;
}
