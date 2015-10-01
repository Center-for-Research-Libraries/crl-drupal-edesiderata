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

  // Exported permission: 'administer entityform types'.
  $permissions['administer entityform types'] = array(
    'name' => 'administer entityform types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'administer salesforce'.
  $permissions['administer salesforce'] = array(
    'name' => 'administer salesforce',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'salesforce',
  );

  // Exported permission: 'administer salesforce mapping'.
  $permissions['administer salesforce mapping'] = array(
    'name' => 'administer salesforce mapping',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'salesforce_mapping',
  );

  // Exported permission: 'create salesforce mapping object'.
  $permissions['create salesforce mapping object'] = array(
    'name' => 'create salesforce mapping object',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'salesforce_mapping',
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

  // Exported permission: 'delete any entityform'.
  $permissions['delete any entityform'] = array(
    'name' => 'delete any entityform',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'delete own entityform'.
  $permissions['delete own entityform'] = array(
    'name' => 'delete own entityform',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'delete salesforce mapping object'.
  $permissions['delete salesforce mapping object'] = array(
    'name' => 'delete salesforce mapping object',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'salesforce_mapping',
  );

  // Exported permission: 'edit any entityform'.
  $permissions['edit any entityform'] = array(
    'name' => 'edit any entityform',
    'roles' => array(
      'administrator' => 'administrator',
      'editor power' => 'editor power',
    ),
    'module' => 'entityform',
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
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own entityform'.
  $permissions['edit own entityform'] = array(
    'name' => 'edit own entityform',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'edit salesforce mapping object'.
  $permissions['edit salesforce mapping object'] = array(
    'name' => 'edit salesforce mapping object',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'salesforce_mapping',
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
    ),
    'module' => 'comment',
  );

  // Exported permission: 'rate content'.
  $permissions['rate content'] = array(
    'name' => 'rate content',
    'roles' => array(
      'administrator' => 'administrator',
      'crl-staff' => 'crl-staff',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
      'grn-cifnal' => 'grn-cifnal',
      'grn-gnarp' => 'grn-gnarp',
      'member-crl' => 'member-crl',
    ),
    'module' => 'fivestar',
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
    ),
    'module' => 'comment',
  );

  // Exported permission: 'view any entityform'.
  $permissions['view any entityform'] = array(
    'name' => 'view any entityform',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'view own entityform'.
  $permissions['view own entityform'] = array(
    'name' => 'view own entityform',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
      'member-crl' => 'member-crl',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'view salesforce mapping object'.
  $permissions['view salesforce mapping object'] = array(
    'name' => 'view salesforce mapping object',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'salesforce_mapping',
  );

  return $permissions;
}
