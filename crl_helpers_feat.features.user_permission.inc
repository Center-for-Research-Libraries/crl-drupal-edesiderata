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

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'crl-staff' => 'crl-staff',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
      'grn-cifnal' => 'grn-cifnal',
      'grn-gnarp' => 'grn-gnarp',
      'member-crl' => 'member-crl',
      'member-ip' => 'member-ip',
      'mydes-temp' => 'mydes-temp',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
      'editor power' => 'editor power',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'crl access member features'.
  $permissions['crl access member features'] = array(
    'name' => 'crl access member features',
    'roles' => array(
      'administrator' => 'administrator',
      'crl-staff' => 'crl-staff',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
      'grn-cifnal' => 'grn-cifnal',
      'grn-gnarp' => 'grn-gnarp',
      'member-crl' => 'member-crl',
    ),
    'module' => 'crl_helpers',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
      'crl-staff' => 'crl-staff',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
      'grn-cifnal' => 'grn-cifnal',
      'grn-gnarp' => 'grn-gnarp',
      'member-crl' => 'member-crl',
      'mydes-temp' => 'mydes-temp',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'crl-staff' => 'crl-staff',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
      'grn-cifnal' => 'grn-cifnal',
      'grn-gnarp' => 'grn-gnarp',
      'member-crl' => 'member-crl',
      'mydes-temp' => 'mydes-temp',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'crl-staff' => 'crl-staff',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
      'grn-cifnal' => 'grn-cifnal',
      'grn-gnarp' => 'grn-gnarp',
      'member-crl' => 'member-crl',
      'mydes-temp' => 'mydes-temp',
    ),
    'module' => 'comment',
  );

  return $permissions;
}
