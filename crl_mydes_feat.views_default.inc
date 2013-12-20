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
  $handler->display->display_options['title'] = 'My Watched Items';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'crl_resource_alert' => 'crl_resource_alert',
    'title' => 'title',
    'timestamp' => 'timestamp',
    'timestamp_1' => 'timestamp_1',
    'title_1' => 'title_1',
    'field_provider' => 'field_provider',
    'field_activity_crl_status' => 'field_activity_crl_status',
    'timestamp_2' => 'timestamp_2',
    'ops' => 'ops',
    'nid_1' => 'nid_1',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp_2';
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
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_provider' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_crl_status' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p>You watched items are appear below. The activity related to these items will be aggregated into your personal activity feed.</p><p>To add a new item to your watch list simply click the "Watch" option that appears next to each item while browsing the resource listings.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p><strong>No watched items found.</strong></p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
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
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '[timestamp]';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['fields']['timestamp_1']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp_1']['relationship'] = 'reverse_field_resource_reference_node';
  $handler->display->display_options['fields']['timestamp_1']['label'] = '';
  $handler->display->display_options['fields']['timestamp_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp_1']['alter']['text'] = '[timestamp_1] (activity)';
  $handler->display->display_options['fields']['timestamp_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp_1']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[title] [crl_resource_alert]&nbsp;&nbsp;[timestamp]&nbsp;&nbsp;[timestamp_1]';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Provider */
  $handler->display->display_options['fields']['field_provider']['id'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['table'] = 'field_data_field_provider';
  $handler->display->display_options['fields']['field_provider']['field'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: CRL Status Old */
  $handler->display->display_options['fields']['field_activity_crl_status']['id'] = 'field_activity_crl_status';
  $handler->display->display_options['fields']['field_activity_crl_status']['table'] = 'field_data_field_activity_crl_status';
  $handler->display->display_options['fields']['field_activity_crl_status']['field'] = 'field_activity_crl_status';
  $handler->display->display_options['fields']['field_activity_crl_status']['relationship'] = 'reverse_field_resource_reference_node';
  $handler->display->display_options['fields']['field_activity_crl_status']['label'] = 'CRL Status';
  $handler->display->display_options['fields']['field_activity_crl_status']['delta_offset'] = '0';
  /* Field: Flags: Flagged time */
  $handler->display->display_options['fields']['timestamp_2']['id'] = 'timestamp_2';
  $handler->display->display_options['fields']['timestamp_2']['table'] = 'flagging';
  $handler->display->display_options['fields']['timestamp_2']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp_2']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['timestamp_2']['label'] = 'Watched since';
  $handler->display->display_options['fields']['timestamp_2']['date_format'] = 'medium_no_time';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['link_type'] = 'normal';
  /* Field: Print Link */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['ui_name'] = 'Print Link';
  $handler->display->display_options['fields']['nid_1']['label'] = 'Operations';
  $handler->display->display_options['fields']['nid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['text'] = '<a href="/print/[nid_1]">Print</a>&nbsp;&nbsp;[ops]';
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Field: CRL Status Old (field_activity_crl_status) */
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $export['mydes_lists'] = $view;

  return $export;
}
