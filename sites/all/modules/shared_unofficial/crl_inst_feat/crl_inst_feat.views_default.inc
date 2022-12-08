<?php
/**
 * @file
 * crl_inst_feat.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crl_inst_feat_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'institution_admin_lists';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Institution Admin Lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CRL Members';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_inst_sort_name' => 'field_inst_sort_name',
    'field_inst_member_type' => 'field_inst_member_type',
    'field_inst_start_fy' => 'field_inst_start_fy',
    'field_inst_active' => 'field_inst_active',
    'status' => 'status',
    'crl_inst_new' => 'crl_inst_new',
    'field_inst_founding_member' => 'field_inst_founding_member',
    'field_inst_rep' => 'field_inst_rep',
    'field_inst_mem_id' => 'field_inst_mem_id',
    'field_inst_net_affiliations' => 'field_inst_net_affiliations',
    'field_inst_wna_latin_america' => 'field_inst_wna_latin_america',
    'field_inst_wna_latin_america_2' => 'field_inst_wna_latin_america_2',
    'field_inst_wna_africa' => 'field_inst_wna_africa',
    'field_inst_wna_south_asia' => 'field_inst_wna_south_asia',
    'nid' => 'nid',
    'field_inst_crkn_1' => 'field_inst_crkn_1',
    'field_inst_ohiolink' => 'field_inst_ohiolink',
    'field_inst_fte' => 'field_inst_fte',
    'last_sync' => 'last_sync',
    'last_sync_message' => 'last_sync_message',
  );
  $handler->display->display_options['style_options']['default'] = 'last_sync';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inst_sort_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inst_member_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inst_start_fy' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inst_active' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'crl_inst_new' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inst_founding_member' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inst_rep' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inst_mem_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inst_net_affiliations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inst_wna_latin_america' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inst_wna_latin_america_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inst_wna_africa' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inst_wna_south_asia' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'field_inst_crkn_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inst_ohiolink' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inst_fte' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_sync' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_sync_message' => array(
      'sortable' => 1,
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
  $handler->display->display_options['header']['area']['content'] = 'This is an administrative list to verify synced data from Salesforce.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '</br></br>
Listing @total institutions ';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '</hr>
Listing @total active members ';
  /* Relationship: Salesforce Mapping Object: Salesforce Mapping */
  $handler->display->display_options['relationships']['salesforce_mapping_object']['id'] = 'salesforce_mapping_object';
  $handler->display->display_options['relationships']['salesforce_mapping_object']['table'] = 'node';
  $handler->display->display_options['relationships']['salesforce_mapping_object']['field'] = 'salesforce_mapping_object';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Sort Name */
  $handler->display->display_options['fields']['field_inst_sort_name']['id'] = 'field_inst_sort_name';
  $handler->display->display_options['fields']['field_inst_sort_name']['table'] = 'field_data_field_inst_sort_name';
  $handler->display->display_options['fields']['field_inst_sort_name']['field'] = 'field_inst_sort_name';
  /* Field: Content: Member Type */
  $handler->display->display_options['fields']['field_inst_member_type']['id'] = 'field_inst_member_type';
  $handler->display->display_options['fields']['field_inst_member_type']['table'] = 'field_data_field_inst_member_type';
  $handler->display->display_options['fields']['field_inst_member_type']['field'] = 'field_inst_member_type';
  $handler->display->display_options['fields']['field_inst_member_type']['element_label_colon'] = FALSE;
  /* Field: Content: Starting FY */
  $handler->display->display_options['fields']['field_inst_start_fy']['id'] = 'field_inst_start_fy';
  $handler->display->display_options['fields']['field_inst_start_fy']['table'] = 'field_data_field_inst_start_fy';
  $handler->display->display_options['fields']['field_inst_start_fy']['field'] = 'field_inst_start_fy';
  /* Field: Content: Active Status */
  $handler->display->display_options['fields']['field_inst_active']['id'] = 'field_inst_active';
  $handler->display->display_options['fields']['field_inst_active']['table'] = 'field_data_field_inst_active';
  $handler->display->display_options['fields']['field_inst_active']['field'] = 'field_inst_active';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: CRL Institution New */
  $handler->display->display_options['fields']['crl_inst_new']['id'] = 'crl_inst_new';
  $handler->display->display_options['fields']['crl_inst_new']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['crl_inst_new']['field'] = 'crl_inst_new';
  $handler->display->display_options['fields']['crl_inst_new']['label'] = 'Is New';
  $handler->display->display_options['fields']['crl_inst_new']['element_label_colon'] = FALSE;
  /* Field: Content: Founding Member */
  $handler->display->display_options['fields']['field_inst_founding_member']['id'] = 'field_inst_founding_member';
  $handler->display->display_options['fields']['field_inst_founding_member']['table'] = 'field_data_field_inst_founding_member';
  $handler->display->display_options['fields']['field_inst_founding_member']['field'] = 'field_inst_founding_member';
  /* Field: Content: Member Liaison */
  $handler->display->display_options['fields']['field_inst_rep']['id'] = 'field_inst_rep';
  $handler->display->display_options['fields']['field_inst_rep']['table'] = 'field_data_field_inst_rep';
  $handler->display->display_options['fields']['field_inst_rep']['field'] = 'field_inst_rep';
  /* Field: Content: Member ID */
  $handler->display->display_options['fields']['field_inst_mem_id']['id'] = 'field_inst_mem_id';
  $handler->display->display_options['fields']['field_inst_mem_id']['table'] = 'field_data_field_inst_mem_id';
  $handler->display->display_options['fields']['field_inst_mem_id']['field'] = 'field_inst_mem_id';
  /* Field: Content: Network Affiliations */
  $handler->display->display_options['fields']['field_inst_net_affiliations']['id'] = 'field_inst_net_affiliations';
  $handler->display->display_options['fields']['field_inst_net_affiliations']['table'] = 'field_data_field_inst_net_affiliations';
  $handler->display->display_options['fields']['field_inst_net_affiliations']['field'] = 'field_inst_net_affiliations';
  $handler->display->display_options['fields']['field_inst_net_affiliations']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_inst_net_affiliations']['delta_offset'] = '0';
  /* Field: Content: WNA-Latin America: Part I */
  $handler->display->display_options['fields']['field_inst_wna_latin_america']['id'] = 'field_inst_wna_latin_america';
  $handler->display->display_options['fields']['field_inst_wna_latin_america']['table'] = 'field_data_field_inst_wna_latin_america';
  $handler->display->display_options['fields']['field_inst_wna_latin_america']['field'] = 'field_inst_wna_latin_america';
  $handler->display->display_options['fields']['field_inst_wna_latin_america']['exclude'] = TRUE;
  /* Field: Content: WNA-Latin America: Part II */
  $handler->display->display_options['fields']['field_inst_wna_latin_america_2']['id'] = 'field_inst_wna_latin_america_2';
  $handler->display->display_options['fields']['field_inst_wna_latin_america_2']['table'] = 'field_data_field_inst_wna_latin_america_2';
  $handler->display->display_options['fields']['field_inst_wna_latin_america_2']['field'] = 'field_inst_wna_latin_america_2';
  $handler->display->display_options['fields']['field_inst_wna_latin_america_2']['exclude'] = TRUE;
  /* Field: Content: WNA-Africa */
  $handler->display->display_options['fields']['field_inst_wna_africa']['id'] = 'field_inst_wna_africa';
  $handler->display->display_options['fields']['field_inst_wna_africa']['table'] = 'field_data_field_inst_wna_africa';
  $handler->display->display_options['fields']['field_inst_wna_africa']['field'] = 'field_inst_wna_africa';
  $handler->display->display_options['fields']['field_inst_wna_africa']['exclude'] = TRUE;
  /* Field: Content: WNA-South Asia */
  $handler->display->display_options['fields']['field_inst_wna_south_asia']['id'] = 'field_inst_wna_south_asia';
  $handler->display->display_options['fields']['field_inst_wna_south_asia']['table'] = 'field_data_field_inst_wna_south_asia';
  $handler->display->display_options['fields']['field_inst_wna_south_asia']['field'] = 'field_inst_wna_south_asia';
  $handler->display->display_options['fields']['field_inst_wna_south_asia']['exclude'] = TRUE;
  /* Field: Merged WNA status */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Merged WNA status';
  $handler->display->display_options['fields']['nid']['label'] = 'WNA Affiliations';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[field_inst_wna_latin_america]
[field_inst_wna_latin_america_2]
[field_inst_wna_africa]
[field_inst_wna_south_asia]';
  /* Field: Content: CRKN Member Status */
  $handler->display->display_options['fields']['field_inst_crkn_1']['id'] = 'field_inst_crkn_1';
  $handler->display->display_options['fields']['field_inst_crkn_1']['table'] = 'field_data_field_inst_crkn';
  $handler->display->display_options['fields']['field_inst_crkn_1']['field'] = 'field_inst_crkn';
  /* Field: Content: OhioLink Status */
  $handler->display->display_options['fields']['field_inst_ohiolink']['id'] = 'field_inst_ohiolink';
  $handler->display->display_options['fields']['field_inst_ohiolink']['table'] = 'field_data_field_inst_ohiolink';
  $handler->display->display_options['fields']['field_inst_ohiolink']['field'] = 'field_inst_ohiolink';
  /* Field: Content: FTE */
  $handler->display->display_options['fields']['field_inst_fte']['id'] = 'field_inst_fte';
  $handler->display->display_options['fields']['field_inst_fte']['table'] = 'field_data_field_inst_fte';
  $handler->display->display_options['fields']['field_inst_fte']['field'] = 'field_inst_fte';
  /* Field: Salesforce Object Mapping: Last sync */
  $handler->display->display_options['fields']['last_sync']['id'] = 'last_sync';
  $handler->display->display_options['fields']['last_sync']['table'] = 'salesforce_mapping_object';
  $handler->display->display_options['fields']['last_sync']['field'] = 'last_sync';
  $handler->display->display_options['fields']['last_sync']['relationship'] = 'salesforce_mapping_object';
  $handler->display->display_options['fields']['last_sync']['date_format'] = 'long';
  $handler->display->display_options['fields']['last_sync']['second_date_format'] = 'long';
  /* Field: Salesforce Object Mapping: Last sync message */
  $handler->display->display_options['fields']['last_sync_message']['id'] = 'last_sync_message';
  $handler->display->display_options['fields']['last_sync_message']['table'] = 'salesforce_mapping_object';
  $handler->display->display_options['fields']['last_sync_message']['field'] = 'last_sync_message';
  /* Sort criterion: Content: Sort Name (field_inst_sort_name) */
  $handler->display->display_options['sorts']['field_inst_sort_name_value']['id'] = 'field_inst_sort_name_value';
  $handler->display->display_options['sorts']['field_inst_sort_name_value']['table'] = 'field_data_field_inst_sort_name';
  $handler->display->display_options['sorts']['field_inst_sort_name_value']['field'] = 'field_inst_sort_name_value';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'institution' => 'institution',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Active Status (field_inst_active) */
  $handler->display->display_options['filters']['field_inst_active_value']['id'] = 'field_inst_active_value';
  $handler->display->display_options['filters']['field_inst_active_value']['table'] = 'field_data_field_inst_active';
  $handler->display->display_options['filters']['field_inst_active_value']['field'] = 'field_inst_active_value';
  $handler->display->display_options['filters']['field_inst_active_value']['group'] = 1;
  $handler->display->display_options['filters']['field_inst_active_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_inst_active_value']['expose']['operator_id'] = 'field_inst_active_value_op';
  $handler->display->display_options['filters']['field_inst_active_value']['expose']['label'] = 'Active Status';
  $handler->display->display_options['filters']['field_inst_active_value']['expose']['operator'] = 'field_inst_active_value_op';
  $handler->display->display_options['filters']['field_inst_active_value']['expose']['identifier'] = 'field_inst_active_value';
  $handler->display->display_options['filters']['field_inst_active_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Member Type (field_inst_member_type) */
  $handler->display->display_options['filters']['field_inst_member_type_value_1']['id'] = 'field_inst_member_type_value_1';
  $handler->display->display_options['filters']['field_inst_member_type_value_1']['table'] = 'field_data_field_inst_member_type';
  $handler->display->display_options['filters']['field_inst_member_type_value_1']['field'] = 'field_inst_member_type_value';
  $handler->display->display_options['filters']['field_inst_member_type_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_inst_member_type_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_inst_member_type_value_1']['expose']['operator_id'] = 'field_inst_member_type_value_1_op';
  $handler->display->display_options['filters']['field_inst_member_type_value_1']['expose']['label'] = 'Member Type';
  $handler->display->display_options['filters']['field_inst_member_type_value_1']['expose']['operator'] = 'field_inst_member_type_value_1_op';
  $handler->display->display_options['filters']['field_inst_member_type_value_1']['expose']['identifier'] = 'field_inst_member_type_value_1';
  $handler->display->display_options['filters']['field_inst_member_type_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Network Affiliations (field_inst_net_affiliations) */
  $handler->display->display_options['filters']['field_inst_net_affiliations_value']['id'] = 'field_inst_net_affiliations_value';
  $handler->display->display_options['filters']['field_inst_net_affiliations_value']['table'] = 'field_data_field_inst_net_affiliations';
  $handler->display->display_options['filters']['field_inst_net_affiliations_value']['field'] = 'field_inst_net_affiliations_value';
  $handler->display->display_options['filters']['field_inst_net_affiliations_value']['group'] = 1;
  $handler->display->display_options['filters']['field_inst_net_affiliations_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_inst_net_affiliations_value']['expose']['operator_id'] = 'field_inst_net_affiliations_value_op';
  $handler->display->display_options['filters']['field_inst_net_affiliations_value']['expose']['label'] = 'Network Affiliations';
  $handler->display->display_options['filters']['field_inst_net_affiliations_value']['expose']['operator'] = 'field_inst_net_affiliations_value_op';
  $handler->display->display_options['filters']['field_inst_net_affiliations_value']['expose']['identifier'] = 'field_inst_net_affiliations_value';
  $handler->display->display_options['filters']['field_inst_net_affiliations_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['field_inst_net_affiliations_value']['group_info']['label'] = 'Network Affiliations (field_inst_net_affiliations)';
  $handler->display->display_options['filters']['field_inst_net_affiliations_value']['group_info']['identifier'] = 'field_inst_net_affiliations_value';
  $handler->display->display_options['filters']['field_inst_net_affiliations_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_inst_net_affiliations_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Keyword Search';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );

  /* Display: Admin Table */
  $handler = $view->new_display('page', 'Admin Table', 'page_3');
  $handler->display->display_options['path'] = 'admin/inst-list';
  $translatables['institution_admin_lists'] = array(
    t('Master'),
    t('CRL Members'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('This is an administrative list to verify synced data from Salesforce.'),
    t('</br></br>
Listing @total institutions '),
    t('</hr>
Listing @total active members '),
    t('Salesforce Object'),
    t('Title'),
    t('Sort Name'),
    t('Member Type'),
    t('Starting FY'),
    t('Active Status'),
    t('Published'),
    t('Is New'),
    t('Founding Member'),
    t('Member Liaison'),
    t('Member ID'),
    t('Network Affiliations'),
    t('WNA-Latin America: Part I'),
    t('WNA-Latin America: Part II'),
    t('WNA-Africa'),
    t('WNA-South Asia'),
    t('WNA Affiliations'),
    t('[field_inst_wna_latin_america]
[field_inst_wna_latin_america_2]
[field_inst_wna_africa]
[field_inst_wna_south_asia]'),
    t('CRKN Member Status'),
    t('OhioLink Status'),
    t('FTE'),
    t('Last sync'),
    t('Last sync message'),
    t('Network Affiliations (field_inst_net_affiliations)'),
    t('Keyword Search'),
    t('Admin Table'),
  );
  $export['institution_admin_lists'] = $view;

  return $export;
}
