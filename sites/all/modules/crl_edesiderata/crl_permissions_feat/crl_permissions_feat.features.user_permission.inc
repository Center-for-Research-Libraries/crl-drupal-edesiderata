<?php

/**
 * @file
 * crl_permissions_feat.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crl_permissions_feat_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'administrator' => 'administrator',
      'editor power' => 'editor power',
    ),
    'module' => 'webform',
  );

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

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'administrator' => 'administrator',
      'crl-staff' => 'crl-staff',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access library reports'.
  $permissions['access library reports'] = array(
    'name' => 'access library reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'libraries',
  );

  // Exported permission: 'access mail logger'.
  $permissions['access mail logger'] = array(
    'name' => 'access mail logger',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mail_logger',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access print'.
  $permissions['access print'] = array(
    'name' => 'access print',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'crowd admin' => 'crowd admin',
      'editor power' => 'editor power',
      'pp-main' => 'pp-main',
    ),
    'module' => 'print',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access send by email'.
  $permissions['access send by email'] = array(
    'name' => 'access send by email',
    'roles' => array(
      'administrator' => 'administrator',
      'crowd admin' => 'crowd admin',
      'editor power' => 'editor power',
      'pp-main' => 'pp-main',
    ),
    'module' => 'print_mail',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access statistics'.
  $permissions['access statistics'] = array(
    'name' => 'access statistics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'add JS snippets for google analytics'.
  $permissions['add JS snippets for google analytics'] = array(
    'name' => 'add JS snippets for google analytics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'administer CAPTCHA settings'.
  $permissions['administer CAPTCHA settings'] = array(
    'name' => 'administer CAPTCHA settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer boxes'.
  $permissions['administer boxes'] = array(
    'name' => 'administer boxes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'boxes',
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

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer contexts'.
  $permissions['administer contexts'] = array(
    'name' => 'administer contexts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'administer crowd'.
  $permissions['administer crowd'] = array(
    'name' => 'administer crowd',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'crowd',
  );

  // Exported permission: 'administer crowd group memberships'.
  $permissions['administer crowd group memberships'] = array(
    'name' => 'administer crowd group memberships',
    'roles' => array(
      'administrator' => 'administrator',
      'crowd admin' => 'crowd admin',
    ),
    'module' => 'crowd_push',
  );

  // Exported permission: 'administer delta'.
  $permissions['administer delta'] = array(
    'name' => 'administer delta',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'delta_ui',
  );

  // Exported permission: 'administer delta blocks'.
  $permissions['administer delta blocks'] = array(
    'name' => 'administer delta blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'delta_blocks',
  );

  // Exported permission: 'administer entityform types'.
  $permissions['administer entityform types'] = array(
    'name' => 'administer entityform types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer feeds'.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'administer feeds_tamper'.
  $permissions['administer feeds_tamper'] = array(
    'name' => 'administer feeds_tamper',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer fields'.
  $permissions['administer fields'] = array(
    'name' => 'administer fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer google analytics'.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'administer honeypot'.
  $permissions['administer honeypot'] = array(
    'name' => 'administer honeypot',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'honeypot',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'imce',
  );

  // Exported permission: 'administer mailsystem'.
  $permissions['administer mailsystem'] = array(
    'name' => 'administer mailsystem',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mailsystem',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer message subscribe'.
  $permissions['administer message subscribe'] = array(
    'name' => 'administer message subscribe',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_subscribe',
  );

  // Exported permission: 'administer message types'.
  $permissions['administer message types'] = array(
    'name' => 'administer message types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'editor power' => 'editor power',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer print'.
  $permissions['administer print'] = array(
    'name' => 'administer print',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'print',
  );

  // Exported permission: 'administer realname'.
  $permissions['administer realname'] = array(
    'name' => 'administer realname',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'realname',
  );

  // Exported permission: 'administer recaptcha'.
  $permissions['administer recaptcha'] = array(
    'name' => 'administer recaptcha',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'recaptcha',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'redirect',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
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

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'administer search_api_saved_searches'.
  $permissions['administer search_api_saved_searches'] = array(
    'name' => 'administer search_api_saved_searches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api_saved_searches',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer statistics'.
  $permissions['administer statistics'] = array(
    'name' => 'administer statistics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'administer string overrides'.
  $permissions['administer string overrides'] = array(
    'name' => 'administer string overrides',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'stringoverrides',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer taxonomy display'.
  $permissions['administer taxonomy display'] = array(
    'name' => 'administer taxonomy display',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_display',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer uniqueness'.
  $permissions['administer uniqueness'] = array(
    'name' => 'administer uniqueness',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'uniqueness',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer voting api'.
  $permissions['administer voting api'] = array(
    'name' => 'administer voting api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'votingapi',
  );

  // Exported permission: 'always use additional datasources'.
  $permissions['always use additional datasources'] = array(
    'name' => 'always use additional datasources',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'tablefield',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass honeypot protection'.
  $permissions['bypass honeypot protection'] = array(
    'name' => 'bypass honeypot protection',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'honeypot',
  );

  // Exported permission: 'bypass message access control'.
  $permissions['bypass message access control'] = array(
    'name' => 'bypass message access control',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
      'editor power' => 'editor power',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'clear jisc_publisher_data feeds'.
  $permissions['clear jisc_publisher_data feeds'] = array(
    'name' => 'clear jisc_publisher_data feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear jisc_resource_data feeds'.
  $permissions['clear jisc_resource_data feeds'] = array(
    'name' => 'clear jisc_resource_data feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'configure tablefield'.
  $permissions['configure tablefield'] = array(
    'name' => 'configure tablefield',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'tablefield',
  );

  // Exported permission: 'context ajax block access'.
  $permissions['context ajax block access'] = array(
    'name' => 'context ajax block access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'create a resource_expires_soon message instance'.
  $permissions['create a resource_expires_soon message instance'] = array(
    'name' => 'create a resource_expires_soon message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'create a resource_new message instance'.
  $permissions['create a resource_new message instance'] = array(
    'name' => 'create a resource_new message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'create a resource_new_alert message instance'.
  $permissions['create a resource_new_alert message instance'] = array(
    'name' => 'create a resource_new_alert message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'create a resource_new_comment message instance'.
  $permissions['create a resource_new_comment message instance'] = array(
    'name' => 'create a resource_new_comment message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'create a resource_new_review message instance'.
  $permissions['create a resource_new_review message instance'] = array(
    'name' => 'create a resource_new_review message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'create a resource_status_update message instance'.
  $permissions['create a resource_status_update message instance'] = array(
    'name' => 'create a resource_status_update message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'create a resource_suggested message instance'.
  $permissions['create a resource_suggested message instance'] = array(
    'name' => 'create a resource_suggested message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'create a resource_update message instance'.
  $permissions['create a resource_update message instance'] = array(
    'name' => 'create a resource_update message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'create activity content'.
  $permissions['create activity content'] = array(
    'name' => 'create activity content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create any message instance'.
  $permissions['create any message instance'] = array(
    'name' => 'create any message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
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

  // Exported permission: 'create institution content'.
  $permissions['create institution content'] = array(
    'name' => 'create institution content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create messages'.
  $permissions['create messages'] = array(
    'name' => 'create messages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create pp_resource content'.
  $permissions['create pp_resource content'] = array(
    'name' => 'create pp_resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create provider content'.
  $permissions['create provider content'] = array(
    'name' => 'create provider content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create resource content'.
  $permissions['create resource content'] = array(
    'name' => 'create resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create salesforce mapping object'.
  $permissions['create salesforce mapping object'] = array(
    'name' => 'create salesforce mapping object',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'salesforce_mapping',
  );

  // Exported permission: 'create spp_resource content'.
  $permissions['create spp_resource content'] = array(
    'name' => 'create spp_resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
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

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete a resource_expires_soon message instance'.
  $permissions['delete a resource_expires_soon message instance'] = array(
    'name' => 'delete a resource_expires_soon message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'delete a resource_new message instance'.
  $permissions['delete a resource_new message instance'] = array(
    'name' => 'delete a resource_new message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'delete a resource_new_alert message instance'.
  $permissions['delete a resource_new_alert message instance'] = array(
    'name' => 'delete a resource_new_alert message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'delete a resource_new_comment message instance'.
  $permissions['delete a resource_new_comment message instance'] = array(
    'name' => 'delete a resource_new_comment message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'delete a resource_new_review message instance'.
  $permissions['delete a resource_new_review message instance'] = array(
    'name' => 'delete a resource_new_review message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'delete a resource_status_update message instance'.
  $permissions['delete a resource_status_update message instance'] = array(
    'name' => 'delete a resource_status_update message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'delete a resource_suggested message instance'.
  $permissions['delete a resource_suggested message instance'] = array(
    'name' => 'delete a resource_suggested message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'delete a resource_update message instance'.
  $permissions['delete a resource_update message instance'] = array(
    'name' => 'delete a resource_update message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any activity content'.
  $permissions['delete any activity content'] = array(
    'name' => 'delete any activity content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
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

  // Exported permission: 'delete any institution content'.
  $permissions['delete any institution content'] = array(
    'name' => 'delete any institution content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any message instance'.
  $permissions['delete any message instance'] = array(
    'name' => 'delete any message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any pp_resource content'.
  $permissions['delete any pp_resource content'] = array(
    'name' => 'delete any pp_resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any provider content'.
  $permissions['delete any provider content'] = array(
    'name' => 'delete any provider content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any resource content'.
  $permissions['delete any resource content'] = array(
    'name' => 'delete any resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any spp_resource content'.
  $permissions['delete any spp_resource content'] = array(
    'name' => 'delete any spp_resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own activity content'.
  $permissions['delete own activity content'] = array(
    'name' => 'delete own activity content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
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

  // Exported permission: 'delete own institution content'.
  $permissions['delete own institution content'] = array(
    'name' => 'delete own institution content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own pp_resource content'.
  $permissions['delete own pp_resource content'] = array(
    'name' => 'delete own pp_resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own provider content'.
  $permissions['delete own provider content'] = array(
    'name' => 'delete own provider content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own resource content'.
  $permissions['delete own resource content'] = array(
    'name' => 'delete own resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own spp_resource content'.
  $permissions['delete own spp_resource content'] = array(
    'name' => 'delete own spp_resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'editor power' => 'editor power',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete salesforce mapping object'.
  $permissions['delete salesforce mapping object'] = array(
    'name' => 'delete salesforce mapping object',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'salesforce_mapping',
  );

  // Exported permission: 'delete terms in facets'.
  $permissions['delete terms in facets'] = array(
    'name' => 'delete terms in facets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in fy'.
  $permissions['delete terms in fy'] = array(
    'name' => 'delete terms in fy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in grouping'.
  $permissions['delete terms in grouping'] = array(
    'name' => 'delete terms in grouping',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in provider_publisher_type'.
  $permissions['delete terms in provider_publisher_type'] = array(
    'name' => 'delete terms in provider_publisher_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in provider_type'.
  $permissions['delete terms in provider_type'] = array(
    'name' => 'delete terms in provider_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in resource_languages'.
  $permissions['delete terms in resource_languages'] = array(
    'name' => 'delete terms in resource_languages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in resource_type'.
  $permissions['delete terms in resource_type'] = array(
    'name' => 'delete terms in resource_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in title_type'.
  $permissions['delete terms in title_type'] = array(
    'name' => 'delete terms in title_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'diff view changes'.
  $permissions['diff view changes'] = array(
    'name' => 'diff view changes',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'diff',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit a resource_expires_soon message instance'.
  $permissions['edit a resource_expires_soon message instance'] = array(
    'name' => 'edit a resource_expires_soon message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'edit a resource_new message instance'.
  $permissions['edit a resource_new message instance'] = array(
    'name' => 'edit a resource_new message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'edit a resource_new_alert message instance'.
  $permissions['edit a resource_new_alert message instance'] = array(
    'name' => 'edit a resource_new_alert message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'edit a resource_new_comment message instance'.
  $permissions['edit a resource_new_comment message instance'] = array(
    'name' => 'edit a resource_new_comment message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'edit a resource_new_review message instance'.
  $permissions['edit a resource_new_review message instance'] = array(
    'name' => 'edit a resource_new_review message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'edit a resource_status_update message instance'.
  $permissions['edit a resource_status_update message instance'] = array(
    'name' => 'edit a resource_status_update message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'edit a resource_suggested message instance'.
  $permissions['edit a resource_suggested message instance'] = array(
    'name' => 'edit a resource_suggested message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'edit a resource_update message instance'.
  $permissions['edit a resource_update message instance'] = array(
    'name' => 'edit a resource_update message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any activity content'.
  $permissions['edit any activity content'] = array(
    'name' => 'edit any activity content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
    ),
    'module' => 'node',
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

  // Exported permission: 'edit any institution content'.
  $permissions['edit any institution content'] = array(
    'name' => 'edit any institution content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any message instance'.
  $permissions['edit any message instance'] = array(
    'name' => 'edit any message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any pp_resource content'.
  $permissions['edit any pp_resource content'] = array(
    'name' => 'edit any pp_resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any provider content'.
  $permissions['edit any provider content'] = array(
    'name' => 'edit any provider content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any resource content'.
  $permissions['edit any resource content'] = array(
    'name' => 'edit any resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any spp_resource content'.
  $permissions['edit any spp_resource content'] = array(
    'name' => 'edit any spp_resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit boxes'.
  $permissions['edit boxes'] = array(
    'name' => 'edit boxes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'boxes',
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

  // Exported permission: 'edit mimemail user settings'.
  $permissions['edit mimemail user settings'] = array(
    'name' => 'edit mimemail user settings',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'edit own activity content'.
  $permissions['edit own activity content'] = array(
    'name' => 'edit own activity content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
    ),
    'module' => 'node',
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

  // Exported permission: 'edit own institution content'.
  $permissions['edit own institution content'] = array(
    'name' => 'edit own institution content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own pp_resource content'.
  $permissions['edit own pp_resource content'] = array(
    'name' => 'edit own pp_resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own provider content'.
  $permissions['edit own provider content'] = array(
    'name' => 'edit own provider content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own resource content'.
  $permissions['edit own resource content'] = array(
    'name' => 'edit own resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own spp_resource content'.
  $permissions['edit own spp_resource content'] = array(
    'name' => 'edit own spp_resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit salesforce mapping object'.
  $permissions['edit salesforce mapping object'] = array(
    'name' => 'edit salesforce mapping object',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'salesforce_mapping',
  );

  // Exported permission: 'edit terms in facets'.
  $permissions['edit terms in facets'] = array(
    'name' => 'edit terms in facets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in fy'.
  $permissions['edit terms in fy'] = array(
    'name' => 'edit terms in fy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in grouping'.
  $permissions['edit terms in grouping'] = array(
    'name' => 'edit terms in grouping',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in provider_publisher_type'.
  $permissions['edit terms in provider_publisher_type'] = array(
    'name' => 'edit terms in provider_publisher_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in provider_type'.
  $permissions['edit terms in provider_type'] = array(
    'name' => 'edit terms in provider_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in resource_languages'.
  $permissions['edit terms in resource_languages'] = array(
    'name' => 'edit terms in resource_languages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in resource_type'.
  $permissions['edit terms in resource_type'] = array(
    'name' => 'edit terms in resource_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in title_type'.
  $permissions['edit terms in title_type'] = array(
    'name' => 'edit terms in title_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
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

  // Exported permission: 'flag base_node_watch'.
  $permissions['flag base_node_watch'] = array(
    'name' => 'flag base_node_watch',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag email_node_watch'.
  $permissions['flag email_node_watch'] = array(
    'name' => 'flag email_node_watch',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
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

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'grant content access'.
  $permissions['grant content access'] = array(
    'name' => 'grant content access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'content_access',
  );

  // Exported permission: 'grant own content access'.
  $permissions['grant own content access'] = array(
    'name' => 'grant own content access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'content_access',
  );

  // Exported permission: 'import jisc_publisher_data feeds'.
  $permissions['import jisc_publisher_data feeds'] = array(
    'name' => 'import jisc_publisher_data feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import jisc_resource_data feeds'.
  $permissions['import jisc_resource_data feeds'] = array(
    'name' => 'import jisc_resource_data feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'node-specific print configuration'.
  $permissions['node-specific print configuration'] = array(
    'name' => 'node-specific print configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'print_ui',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
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

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'editor power' => 'editor power',
    ),
    'module' => 'node',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'send arbitrary files'.
  $permissions['send arbitrary files'] = array(
    'name' => 'send arbitrary files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'send message notify'.
  $permissions['send message notify'] = array(
    'name' => 'send message notify',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_notify_ui',
  );

  // Exported permission: 'send unlimited emails'.
  $permissions['send unlimited emails'] = array(
    'name' => 'send unlimited emails',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'print_mail',
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

  // Exported permission: 'skip CAPTCHA'.
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'member-ip' => 'member-ip',
    ),
    'module' => 'captcha',
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

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'tamper jisc_publisher_data'.
  $permissions['tamper jisc_publisher_data'] = array(
    'name' => 'tamper jisc_publisher_data',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper jisc_resource_data'.
  $permissions['tamper jisc_resource_data'] = array(
    'name' => 'tamper jisc_resource_data',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'unflag base_node_watch'.
  $permissions['unflag base_node_watch'] = array(
    'name' => 'unflag base_node_watch',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag email_node_watch'.
  $permissions['unflag email_node_watch'] = array(
    'name' => 'unflag email_node_watch',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag entityform_pp_convert'.
  $permissions['unflag entityform_pp_convert'] = array(
    'name' => 'unflag entityform_pp_convert',
    'roles' => array(),
    'module' => 'flag',
  );

  // Exported permission: 'unflag resource_suggestion_process'.
  $permissions['unflag resource_suggestion_process'] = array(
    'name' => 'unflag resource_suggestion_process',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unlock jisc_publisher_data feeds'.
  $permissions['unlock jisc_publisher_data feeds'] = array(
    'name' => 'unlock jisc_publisher_data feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock jisc_resource_data feeds'.
  $permissions['unlock jisc_resource_data feeds'] = array(
    'name' => 'unlock jisc_resource_data feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'update tokens'.
  $permissions['update tokens'] = array(
    'name' => 'update tokens',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
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

  // Exported permission: 'use text format external_display'.
  $permissions['use text format external_display'] = array(
    'name' => 'use text format external_display',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format literal'.
  $permissions['use text format literal'] = array(
    'name' => 'use text format literal',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
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

  // Exported permission: 'view a resource_expires_soon message instance'.
  $permissions['view a resource_expires_soon message instance'] = array(
    'name' => 'view a resource_expires_soon message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'view a resource_new message instance'.
  $permissions['view a resource_new message instance'] = array(
    'name' => 'view a resource_new message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'view a resource_new_alert message instance'.
  $permissions['view a resource_new_alert message instance'] = array(
    'name' => 'view a resource_new_alert message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'view a resource_new_comment message instance'.
  $permissions['view a resource_new_comment message instance'] = array(
    'name' => 'view a resource_new_comment message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'view a resource_new_review message instance'.
  $permissions['view a resource_new_review message instance'] = array(
    'name' => 'view a resource_new_review message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'view a resource_status_update message instance'.
  $permissions['view a resource_status_update message instance'] = array(
    'name' => 'view a resource_status_update message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'view a resource_suggested message instance'.
  $permissions['view a resource_suggested message instance'] = array(
    'name' => 'view a resource_suggested message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'view a resource_update message instance'.
  $permissions['view a resource_update message instance'] = array(
    'name' => 'view a resource_update message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
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

  // Exported permission: 'view any message instance'.
  $permissions['view any message instance'] = array(
    'name' => 'view any message instance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'message_ui',
  );

  // Exported permission: 'view any unpublished activity content'.
  $permissions['view any unpublished activity content'] = array(
    'name' => 'view any unpublished activity content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished content'.
  $permissions['view any unpublished content'] = array(
    'name' => 'view any unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished institution content'.
  $permissions['view any unpublished institution content'] = array(
    'name' => 'view any unpublished institution content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished page content'.
  $permissions['view any unpublished page content'] = array(
    'name' => 'view any unpublished page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished pp_resource content'.
  $permissions['view any unpublished pp_resource content'] = array(
    'name' => 'view any unpublished pp_resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished provider content'.
  $permissions['view any unpublished provider content'] = array(
    'name' => 'view any unpublished provider content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished resource content'.
  $permissions['view any unpublished resource content'] = array(
    'name' => 'view any unpublished resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished spp_resource content'.
  $permissions['view any unpublished spp_resource content'] = array(
    'name' => 'view any unpublished spp_resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished webform content'.
  $permissions['view any unpublished webform content'] = array(
    'name' => 'view any unpublished webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
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

  // Exported permission: 'view mimemail user settings'.
  $permissions['view mimemail user settings'] = array(
    'name' => 'view mimemail user settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mimemail',
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

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view post access counter'.
  $permissions['view post access counter'] = array(
    'name' => 'view post access counter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'view rate results page'.
  $permissions['view rate results page'] = array(
    'name' => 'view rate results page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rate',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view salesforce mapping object'.
  $permissions['view salesforce mapping object'] = array(
    'name' => 'view salesforce mapping object',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'salesforce_mapping',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
      'crl-staff' => 'crl-staff',
      'crowd admin' => 'crowd admin',
      'editor basic' => 'editor basic',
      'editor power' => 'editor power',
    ),
    'module' => 'system',
  );

  return $permissions;
}
