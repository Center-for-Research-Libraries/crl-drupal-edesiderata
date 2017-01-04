<?php
/**
 * @file
 * crl_local_helpers_feat.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crl_local_helpers_feat_user_default_permissions() {
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

  // Exported permission: 'administer uniqueness'.
  $permissions['administer uniqueness'] = array(
    'name' => 'administer uniqueness',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'uniqueness',
  );

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

  // Exported permission: 'create field_voting_results'.
  $permissions['create field_voting_results'] = array(
    'name' => 'create field_voting_results',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
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

  // Exported permission: 'edit field_voting_results'.
  $permissions['edit field_voting_results'] = array(
    'name' => 'edit field_voting_results',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
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

  // Exported permission: 'edit own field_voting_results'.
  $permissions['edit own field_voting_results'] = array(
    'name' => 'edit own field_voting_results',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit salesforce mapping object'.
  $permissions['edit salesforce mapping object'] = array(
    'name' => 'edit salesforce mapping object',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'salesforce_mapping',
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

  // Exported permission: 'show text format dropdown'.
  $permissions['show text format dropdown'] = array(
    'name' => 'show text format dropdown',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'hide_formats',
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

  // Exported permission: 'unflag entityform_pp_convert'.
  $permissions['unflag entityform_pp_convert'] = array(
    'name' => 'unflag entityform_pp_convert',
    'roles' => array(),
    'module' => 'flag',
  );

  // Exported permission: 'use search_api_saved_searches'.
  $permissions['use search_api_saved_searches'] = array(
    'name' => 'use search_api_saved_searches',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_saved_searches',
  );

  // Exported permission: 'use uniqueness widget'.
  $permissions['use uniqueness widget'] = array(
    'name' => 'use uniqueness widget',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'uniqueness',
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

  // Exported permission: 'view field_resource_reference'.
  $permissions['view field_resource_reference'] = array(
    'name' => 'view field_resource_reference',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_voting_results'.
  $permissions['view field_voting_results'] = array(
    'name' => 'view field_voting_results',
    'roles' => array(
      'administrator' => 'administrator',
      'crl-staff' => 'crl-staff',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
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

  // Exported permission: 'view own field_pp_related'.
  $permissions['view own field_pp_related'] = array(
    'name' => 'view own field_pp_related',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
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
      'authenticated user' => 'authenticated user',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_voting_results'.
  $permissions['view own field_voting_results'] = array(
    'name' => 'view own field_voting_results',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view salesforce mapping object'.
  $permissions['view salesforce mapping object'] = array(
    'name' => 'view salesforce mapping object',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'salesforce_mapping',
  );
  
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

  // Exported permission: 'flag resource_suggestion_process'.
  $permissions['flag resource_suggestion_process'] = array(
    'name' => 'flag resource_suggestion_process',
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

  // Exported permission: 'unflag resource_suggestion_process'.
  $permissions['unflag resource_suggestion_process'] = array(
    'name' => 'unflag resource_suggestion_process',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
