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
  $handler->display->display_options['title'] = 'My Watchlist';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'crl access member features';
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
    'title_1' => 'title_1',
    'field_provider' => 'field_provider',
    'crl_resource_status_backref' => 'crl_resource_status_backref',
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
    'crl_resource_status_backref' => array(
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
  $handler->display->display_options['header']['area']['content'] = '<p>You can select individual resources of interest and track the updates, changes to CRL license status and community comments that apply to them. View updates to your watchlist with the activity report or through automated email notifications.</p>
<p><a class="button" href="/resources/main" onclick="return window.confirm(\'You will be directed to the A-Z resource listings. To add a new item to your watchlist, simply click the \\\'Watch\\\' option that appears next to a resource while browsing.\');"></span><b>+</b>&nbsp;&nbsp;Add to Watchlist</a>&nbsp;&nbsp;<a class="button" href="/me/activity"><span class="crl-icon-small pulse-icon"></span>Watchlist Activity Report</a>&nbsp;&nbsp;<a class="button" href="/me/watchlist/download"><span class="crl-icon-small download-icon"></span>Download Watchlist</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'literal';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p><strong>No watched items found.</strong></p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Flags: base_node_watch */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'base_node_watch';
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[title] [crl_resource_alert]';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Provider */
  $handler->display->display_options['fields']['field_provider']['id'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['table'] = 'field_data_field_provider';
  $handler->display->display_options['fields']['field_provider']['field'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: CRL Resource Status Backreference */
  $handler->display->display_options['fields']['crl_resource_status_backref']['id'] = 'crl_resource_status_backref';
  $handler->display->display_options['fields']['crl_resource_status_backref']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['crl_resource_status_backref']['field'] = 'crl_resource_status_backref';
  $handler->display->display_options['fields']['crl_resource_status_backref']['label'] = 'CRL Status';
  $handler->display->display_options['fields']['crl_resource_status_backref']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['crl_resource_status_backref']['format_name'] = 1;
  /* Field: Flags: Flagged time */
  $handler->display->display_options['fields']['timestamp_2']['id'] = 'timestamp_2';
  $handler->display->display_options['fields']['timestamp_2']['table'] = 'flagging';
  $handler->display->display_options['fields']['timestamp_2']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp_2']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['timestamp_2']['label'] = 'Watched since';
  $handler->display->display_options['fields']['timestamp_2']['date_format'] = 'short';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['link_type'] = 'normal';
  /* Field: Print Link */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['ui_name'] = 'Print Link';
  $handler->display->display_options['fields']['nid_1']['label'] = 'Operations';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['text'] = '<a href="/print/[nid_1]">Print</a>&nbsp;&nbsp;[ops]';
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Sort criterion: Flags: Flagged time */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<p>Interested in a resource that you don\'t see listed in the eDesiderata <a href="/resources/main">A-Z index</a>? Please <a href="/submit-suggested-resources"><strong>submit a suggestion</strong></a> for inclusion.</p>';
  $handler->display->display_options['footer']['area']['format'] = 'literal';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'my_edesiderata_watchlist_%timestamp-full.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Resource';
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[title] [crl_resource_alert]&nbsp;&nbsp;[timestamp]&nbsp;&nbsp;[timestamp_1]';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'eDesiderata URL';
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Provider */
  $handler->display->display_options['fields']['field_provider']['id'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['table'] = 'field_data_field_provider';
  $handler->display->display_options['fields']['field_provider']['field'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Subject Areas */
  $handler->display->display_options['fields']['field_subject_area']['id'] = 'field_subject_area';
  $handler->display->display_options['fields']['field_subject_area']['table'] = 'field_data_field_subject_area';
  $handler->display->display_options['fields']['field_subject_area']['field'] = 'field_subject_area';
  $handler->display->display_options['fields']['field_subject_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_subject_area']['delta_offset'] = '0';
  /* Field: Field: Resource Types */
  $handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_resource_type']['delta_offset'] = '0';
  /* Field: Content: Major Languages */
  $handler->display->display_options['fields']['field_resource_languages']['id'] = 'field_resource_languages';
  $handler->display->display_options['fields']['field_resource_languages']['table'] = 'field_data_field_resource_languages';
  $handler->display->display_options['fields']['field_resource_languages']['field'] = 'field_resource_languages';
  $handler->display->display_options['fields']['field_resource_languages']['delta_offset'] = '0';
  /* Field: Content: CRL Resource Status Backreference */
  $handler->display->display_options['fields']['crl_resource_status_backref']['id'] = 'crl_resource_status_backref';
  $handler->display->display_options['fields']['crl_resource_status_backref']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['crl_resource_status_backref']['field'] = 'crl_resource_status_backref';
  $handler->display->display_options['fields']['crl_resource_status_backref']['label'] = 'CRL Status';
  $handler->display->display_options['fields']['crl_resource_status_backref']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['crl_resource_status_backref']['format_name'] = 1;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created date';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium_no_time';
  /* Field: Content: CRL Resource Master Update Timestamp */
  $handler->display->display_options['fields']['crl_resource_master_update_timestamp']['id'] = 'crl_resource_master_update_timestamp';
  $handler->display->display_options['fields']['crl_resource_master_update_timestamp']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['crl_resource_master_update_timestamp']['field'] = 'crl_resource_master_update_timestamp';
  $handler->display->display_options['fields']['crl_resource_master_update_timestamp']['label'] = 'Updated Date';
  $handler->display->display_options['fields']['crl_resource_master_update_timestamp']['date_format'] = 'medium_no_time';
  $handler->display->display_options['fields']['crl_resource_master_update_timestamp']['link_to_entity'] = 0;
  $handler->display->display_options['path'] = 'me/watchlist/download';
  $export['mydes_lists'] = $view;

  $view = new view();
  $view->name = 'mydes_saved_searches';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_saved_search';
  $view->human_name = 'My Saved Searches';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Watchsets';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'crl access member features';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'uid' => 'uid',
    'delete_link' => 'delete_link',
    'name' => 'name',
    'notify_interval' => 'notify_interval',
    'created' => 'created',
    'edit_link' => 'edit_link',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'notify_interval' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_link' => array(
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
  $handler->display->display_options['header']['area']['content'] = '<p>You can select sets of resources to track by designated category such as resource type, provider, CRL licensing status, or any combination of filters in the <a href="/resources/main">A-Z index</a>. Email alerts about new additions to your watchsets can be sent to you.</p>
<p><a class="button" href="/resources/main" onclick="return window.confirm(\'You will be directed to the A-Z resource listings. To create a new watchset, first input some personalized filter criteria and then click the \\\'Watch this Resource Set\\\' option that appears at the top of the results page.\');"></span><b>+</b>&nbsp;&nbsp;Create</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p><strong>No watchsets found.</strong></p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Saved search: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'search_api_saved_search';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Saved search: Saved search ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'search_api_saved_search';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Saved search: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'search_api_saved_search';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Field: Saved search: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'search_api_saved_search';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['label'] = '';
  $handler->display->display_options['fields']['delete_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_link']['element_label_colon'] = FALSE;
  /* Field: Saved search: Notify_interval */
  $handler->display->display_options['fields']['notify_interval']['id'] = 'notify_interval';
  $handler->display->display_options['fields']['notify_interval']['table'] = 'search_api_saved_search';
  $handler->display->display_options['fields']['notify_interval']['field'] = 'notify_interval';
  $handler->display->display_options['fields']['notify_interval']['label'] = 'Notify interval';
  $handler->display->display_options['fields']['notify_interval']['exclude'] = TRUE;
  $handler->display->display_options['fields']['notify_interval']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['notify_interval']['alter']['text'] = '[notify_interval]&nbsp;&nbsp;<a href="/search-api/saved-search/[id]/edit?destination=my">change</a>';
  $handler->display->display_options['fields']['notify_interval']['granularity'] = '2';
  $handler->display->display_options['fields']['notify_interval']['custom_labels'] = 0;
  /* Field: Saved search: Label */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'search_api_saved_search';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Name';
  $handler->display->display_options['fields']['name']['link_to_page'] = 1;
  /* Field: Saved search: Results */
  $handler->display->display_options['fields']['results']['id'] = 'results';
  $handler->display->display_options['fields']['results']['table'] = 'search_api_saved_search';
  $handler->display->display_options['fields']['results']['field'] = 'results';
  $handler->display->display_options['fields']['results']['label'] = 'Resource count';
  $handler->display->display_options['fields']['results']['list']['mode'] = 'count';
  $handler->display->display_options['fields']['results']['link_to_entity'] = 0;
  /* Field: Saved search: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_saved_search';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Watched since';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Saved search: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'search_api_saved_search';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = '';
  $handler->display->display_options['fields']['edit_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_link']['alter']['text'] = '<a href="/search-api/saved-search/[id]/delete?destination=me">Delete</a>';
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['mydes_saved_searches'] = $view;

  return $export;
}
