<?php
/**
 * @file
 * crl_mydes_feat.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crl_mydes_feat_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'mydes_lists';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'My eDesiderata Lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My eDesiderata';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'crl_resource_alert' => 'crl_resource_alert',
    'title' => 'title',
    'timestamp' => 'timestamp',
    'timestamp_1' => 'timestamp_1',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'crl_resource_alert' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Flags: mydes */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'mydes';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_resource_reference_node']['id'] = 'reverse_field_resource_reference_node';
  $handler->display->display_options['relationships']['reverse_field_resource_reference_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_resource_reference_node']['field'] = 'reverse_field_resource_reference_node';
  /* Field: Content: CRL Resource Alert */
  $handler->display->display_options['fields']['crl_resource_alert']['id'] = 'crl_resource_alert';
  $handler->display->display_options['fields']['crl_resource_alert']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['crl_resource_alert']['field'] = 'crl_resource_alert';
  $handler->display->display_options['fields']['crl_resource_alert']['label'] = '';
  $handler->display->display_options['fields']['crl_resource_alert']['exclude'] = TRUE;
  $handler->display->display_options['fields']['crl_resource_alert']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['crl_resource_alert']['type'] = 'custom';
  $handler->display->display_options['fields']['crl_resource_alert']['type_custom_true'] = '<span class="crl-tag alert">alert</span>';
  $handler->display->display_options['fields']['crl_resource_alert']['not'] = 0;
  $handler->display->display_options['fields']['crl_resource_alert']['link_to_entity'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] [crl_resource_alert]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Title display (rewrite) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Title display (rewrite)';
  $handler->display->display_options['fields']['nid']['label'] = 'Resource';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[title] [crl_resource_alert]';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Provider */
  $handler->display->display_options['fields']['field_provider']['id'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['table'] = 'field_data_field_provider';
  $handler->display->display_options['fields']['field_provider']['field'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: CRL Status */
  $handler->display->display_options['fields']['field_activity_crl_status']['id'] = 'field_activity_crl_status';
  $handler->display->display_options['fields']['field_activity_crl_status']['table'] = 'field_data_field_activity_crl_status';
  $handler->display->display_options['fields']['field_activity_crl_status']['field'] = 'field_activity_crl_status';
  $handler->display->display_options['fields']['field_activity_crl_status']['relationship'] = 'reverse_field_resource_reference_node';
  $handler->display->display_options['fields']['field_activity_crl_status']['delta_offset'] = '0';
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Updated since last view';
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '[timestamp]';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['empty'] = 'no';
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['fields']['timestamp_1']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp_1']['relationship'] = 'reverse_field_resource_reference_node';
  $handler->display->display_options['fields']['timestamp_1']['label'] = 'Offer updated since last view';
  $handler->display->display_options['fields']['timestamp_1']['alter']['text'] = '[timestamp_1] (activity)';
  $handler->display->display_options['fields']['timestamp_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp_1']['empty'] = 'no';
  $handler->display->display_options['fields']['timestamp_1']['hide_alter_empty'] = FALSE;
  /* Field: Print Link */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['ui_name'] = 'Print Link';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['text'] = '<a href="/print/[nid_1]">Print</a>';
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['link_type'] = 'normal';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resource' => 'resource',
  );
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '1';
  /* Filter criterion: Content: CRL Status (field_activity_crl_status) */
  $handler->display->display_options['filters']['field_activity_crl_status_value']['id'] = 'field_activity_crl_status_value';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['table'] = 'field_data_field_activity_crl_status';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['field'] = 'field_activity_crl_status_value';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['relationship'] = 'reverse_field_resource_reference_node';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['value'] = array(
    'all' => 'all',
    'crl_desiderata' => 'crl_desiderata',
    'license_under_consideration' => 'license_under_consideration',
    'license_available' => 'license_available',
    'trial_access_available' => 'trial_access_available',
    'license_renewal_available' => 'license_renewal_available',
    'past_license_offer' => 'past_license_offer',
    'inactive_declined' => 'inactive_declined',
  );
  $handler->display->display_options['filters']['field_activity_crl_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_crl_status_value']['expose']['operator_id'] = 'field_activity_crl_status_value_op';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['expose']['label'] = 'Filter by CRL Status';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['expose']['operator'] = 'field_activity_crl_status_value_op';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['expose']['identifier'] = 'field_activity_crl_status_value';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    23 => 0,
  );
  $handler->display->display_options['filters']['field_activity_crl_status_value']['expose']['reduce'] = TRUE;

  /* Display: List */
  $handler = $view->new_display('page', 'List', 'page');
  $handler->display->display_options['path'] = 'my';
  $export['mydes_lists'] = $view;

  return $export;
}
