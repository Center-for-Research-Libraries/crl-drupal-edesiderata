<?php
/**
 * @file
 * crl_resource_feat.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crl_resource_feat_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'resource_lists';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_title_search_index';
  $view->human_name = 'Resource Lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Resources A-Z';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'crl_resource_glossary_value',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p><strong>No results found. Please consider refining your search and filter criteria.</strong></p>

<p>If your permissions allow, you may also <a href="/node/42">suggest a new resource</a> for inclusion in the resource lists.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Indexed Node: Provider */
  $handler->display->display_options['relationships']['field_provider']['id'] = 'field_provider';
  $handler->display->display_options['relationships']['field_provider']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['relationships']['field_provider']['field'] = 'field_provider';
  /* Relationship: Indexed Node: CRL Resource Backreference */
  $handler->display->display_options['relationships']['crl_resource_backref']['id'] = 'crl_resource_backref';
  $handler->display->display_options['relationships']['crl_resource_backref']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['relationships']['crl_resource_backref']['field'] = 'crl_resource_backref';
  /* Field: Indexed Node: CRL Resource Glossary Value */
  $handler->display->display_options['fields']['crl_resource_glossary_value']['id'] = 'crl_resource_glossary_value';
  $handler->display->display_options['fields']['crl_resource_glossary_value']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['fields']['crl_resource_glossary_value']['field'] = 'crl_resource_glossary_value';
  $handler->display->display_options['fields']['crl_resource_glossary_value']['label'] = '';
  $handler->display->display_options['fields']['crl_resource_glossary_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['crl_resource_glossary_value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['crl_resource_glossary_value']['link_to_entity'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'This is a placeholder field. The real content should be rendered through the appropriate theme hooks and preprocessors.';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'entity_node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_provider';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'entity_node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'crl_resource_backref';
  $handler->display->display_options['fields']['title_1']['link_to_entity'] = 0;
  /* Sort criterion: Indexed Node: Sorting Title */
  $handler->display->display_options['sorts']['field_resource_title_for_sort']['id'] = 'field_resource_title_for_sort';
  $handler->display->display_options['sorts']['field_resource_title_for_sort']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['sorts']['field_resource_title_for_sort']['field'] = 'field_resource_title_for_sort';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resource' => 'resource',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Filter by keyword';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );

  /* Display: Page - All Resources */
  $handler = $view->new_display('page', 'Page - All Resources', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'resources/main';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Resources A-Z';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Resources A-Z';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Page - All Resources (date sort) */
  $handler = $view->new_display('page', 'Page - All Resources (date sort)', 'page_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Node: Date changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Date updated';
  $handler->display->display_options['path'] = 'resources/main-date';
  $handler->display->display_options['menu']['title'] = 'Date List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block - By Provider */
  $handler = $view->new_display('block', 'Block - By Provider', 'block_1');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No resources are currently listed for this provider.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Node: Provider */
  $handler->display->display_options['arguments']['field_provider']['id'] = 'field_provider';
  $handler->display->display_options['arguments']['field_provider']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['arguments']['field_provider']['field'] = 'field_provider';
  $handler->display->display_options['arguments']['field_provider']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_provider']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_provider']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_provider']['summary_options']['grouping'] = array(
    0 => array(
      'field' => 'crl_resource_glossary_value',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['arguments']['field_provider']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_provider']['not'] = 0;
  $export['resource_lists'] = $view;

  $view = new view();
  $view->name = 'resource_votes_admin';
  $view->description = '';
  $view->tag = 'admin';
  $view->base_table = 'node';
  $view->human_name = 'Resource Votes Admin (Aggregate)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Resource Votes Summary';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    12 => '12',
    11 => '11',
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_activity_crl_status' => 'field_activity_crl_status',
    'value' => 'value',
    'value_4' => 'value_4',
    'comment_count' => 'comment_count',
    'value_1' => 'value_1',
    'value_2' => 'value_2',
    'value_3' => 'value_3',
  );
  $handler->display->display_options['style_options']['default'] = 'value';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
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
    'value' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_4' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_3' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_resource_reference_node']['id'] = 'reverse_field_resource_reference_node';
  $handler->display->display_options['relationships']['reverse_field_resource_reference_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_resource_reference_node']['field'] = 'reverse_field_resource_reference_node';
  /* Relationship: Vote results - Interest - Yes */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['ui_name'] = 'Vote results - Interest - Yes';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Vote results - Interest - Yes';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => 'resource_interest',
    'function' => 'option-1',
  );
  /* Relationship: Vote results - Interest - No */
  $handler->display->display_options['relationships']['votingapi_cache_4']['id'] = 'votingapi_cache_4';
  $handler->display->display_options['relationships']['votingapi_cache_4']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_4']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_4']['ui_name'] = 'Vote results - Interest - No';
  $handler->display->display_options['relationships']['votingapi_cache_4']['label'] = 'Vote results - Interest - No';
  $handler->display->display_options['relationships']['votingapi_cache_4']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => 'resource_interest',
    'function' => 'option--1',
  );
  /* Relationship: Vote results - Platform */
  $handler->display->display_options['relationships']['votingapi_cache_1']['id'] = 'votingapi_cache_1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_1']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_1']['ui_name'] = 'Vote results - Platform';
  $handler->display->display_options['relationships']['votingapi_cache_1']['label'] = 'Vote results - Platform';
  $handler->display->display_options['relationships']['votingapi_cache_1']['votingapi'] = array(
    'value_type' => 'percent',
    'tag' => 'platform',
    'function' => 'average',
  );
  /* Relationship: Vote results - Content */
  $handler->display->display_options['relationships']['votingapi_cache_2']['id'] = 'votingapi_cache_2';
  $handler->display->display_options['relationships']['votingapi_cache_2']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_2']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_2']['ui_name'] = 'Vote results - Content';
  $handler->display->display_options['relationships']['votingapi_cache_2']['label'] = 'Vote results - Content';
  $handler->display->display_options['relationships']['votingapi_cache_2']['votingapi'] = array(
    'value_type' => 'percent',
    'tag' => 'content',
    'function' => 'average',
  );
  /* Relationship: Vote results - Cost */
  $handler->display->display_options['relationships']['votingapi_cache_3']['id'] = 'votingapi_cache_3';
  $handler->display->display_options['relationships']['votingapi_cache_3']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_3']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_3']['ui_name'] = 'Vote results - Cost';
  $handler->display->display_options['relationships']['votingapi_cache_3']['label'] = 'Vote results - Cost';
  $handler->display->display_options['relationships']['votingapi_cache_3']['votingapi'] = array(
    'value_type' => 'percent',
    'tag' => 'cost',
    'function' => 'average',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: CRL Status */
  $handler->display->display_options['fields']['field_activity_crl_status']['id'] = 'field_activity_crl_status';
  $handler->display->display_options['fields']['field_activity_crl_status']['table'] = 'field_data_field_activity_crl_status';
  $handler->display->display_options['fields']['field_activity_crl_status']['field'] = 'field_activity_crl_status';
  $handler->display->display_options['fields']['field_activity_crl_status']['relationship'] = 'reverse_field_resource_reference_node';
  $handler->display->display_options['fields']['field_activity_crl_status']['delta_offset'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Interest Count - Yes';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_4']['id'] = 'value_4';
  $handler->display->display_options['fields']['value_4']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_4']['field'] = 'value';
  $handler->display->display_options['fields']['value_4']['relationship'] = 'votingapi_cache_4';
  $handler->display->display_options['fields']['value_4']['label'] = 'Interest Count - No';
  $handler->display->display_options['fields']['value_4']['precision'] = '0';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'votingapi_cache_1';
  $handler->display->display_options['fields']['value_1']['label'] = 'Platform Rating (0-100)';
  $handler->display->display_options['fields']['value_1']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['relationship'] = 'votingapi_cache_2';
  $handler->display->display_options['fields']['value_2']['label'] = 'Content Rating (0-100)';
  $handler->display->display_options['fields']['value_2']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['relationship'] = 'votingapi_cache_3';
  $handler->display->display_options['fields']['value_3']['label'] = 'Cost Rating (0-100)';
  $handler->display->display_options['fields']['value_3']['precision'] = '0';
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
  /* Filter criterion: Content: CRL Status (field_activity_crl_status) */
  $handler->display->display_options['filters']['field_activity_crl_status_value']['id'] = 'field_activity_crl_status_value';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['table'] = 'field_data_field_activity_crl_status';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['field'] = 'field_activity_crl_status_value';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['relationship'] = 'reverse_field_resource_reference_node';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_crl_status_value']['expose']['operator_id'] = 'field_activity_crl_status_value_op';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['expose']['label'] = 'Filter by CRL status';
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
  );

  /* Display: Page - Full */
  $handler = $view->new_display('page', 'Page - Full', 'page');
  $handler->display->display_options['path'] = 'admin/votes/aggregate';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Votes Aggregate';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Votes Administration';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Block - Summary */
  $handler = $view->new_display('block', 'Block - Summary', 'block_1');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<p align=right><strong><a href="/admin/votes/aggregate">Votes Aggregate</a>  |  <a href="/admin/votes/details">Votes Details</a></strong></p>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Vote results - Interest */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['ui_name'] = 'Vote results - Interest';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Vote results - Interest';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => 'resource_interest',
    'function' => 'option-1',
  );
  /* Relationship: Vote results - Platform */
  $handler->display->display_options['relationships']['votingapi_cache_1']['id'] = 'votingapi_cache_1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_1']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_1']['ui_name'] = 'Vote results - Platform';
  $handler->display->display_options['relationships']['votingapi_cache_1']['label'] = 'Vote results - Platform';
  $handler->display->display_options['relationships']['votingapi_cache_1']['votingapi'] = array(
    'value_type' => 'percent',
    'tag' => 'platform',
    'function' => 'average',
  );
  /* Relationship: Vote results - content */
  $handler->display->display_options['relationships']['votingapi_cache_2']['id'] = 'votingapi_cache_2';
  $handler->display->display_options['relationships']['votingapi_cache_2']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_2']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_2']['ui_name'] = 'Vote results - content';
  $handler->display->display_options['relationships']['votingapi_cache_2']['label'] = 'Vote results - content';
  $handler->display->display_options['relationships']['votingapi_cache_2']['votingapi'] = array(
    'value_type' => 'percent',
    'tag' => 'content',
    'function' => 'average',
  );
  /* Relationship: Vote results - cost */
  $handler->display->display_options['relationships']['votingapi_cache_3']['id'] = 'votingapi_cache_3';
  $handler->display->display_options['relationships']['votingapi_cache_3']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_3']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_3']['ui_name'] = 'Vote results - cost';
  $handler->display->display_options['relationships']['votingapi_cache_3']['label'] = 'Vote results - cost';
  $handler->display->display_options['relationships']['votingapi_cache_3']['votingapi'] = array(
    'value_type' => 'percent',
    'tag' => 'cost',
    'function' => 'average',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Interest Count';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'votingapi_cache_1';
  $handler->display->display_options['fields']['value_1']['label'] = 'Platform Rating';
  $handler->display->display_options['fields']['value_1']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['relationship'] = 'votingapi_cache_2';
  $handler->display->display_options['fields']['value_2']['label'] = 'Content Rating';
  $handler->display->display_options['fields']['value_2']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['relationship'] = 'votingapi_cache_3';
  $handler->display->display_options['fields']['value_3']['label'] = 'Cost Rating';
  $handler->display->display_options['fields']['value_3']['precision'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $export['resource_votes_admin'] = $view;

  $view = new view();
  $view->name = 'resource_votes_admin_details_';
  $view->description = '';
  $view->tag = 'admin';
  $view->base_table = 'node';
  $view->human_name = 'Resource Votes Admin (Details)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Resource Votes Details';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    12 => '12',
    11 => '11',
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'timestamp' => 'timestamp',
    'name' => 'name',
    'field_institution' => 'field_institution',
    'rid' => 'rid',
    'title' => 'title',
    'tag' => 'tag',
    'value' => 'value',
    'value_type' => 'value_type',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_institution' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
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
    'tag' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Votes */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['votingapi'] = array(
    'value_type' => '',
    'tag' => 'resource_interest',
  );
  $handler->display->display_options['relationships']['votingapi_vote']['current_user'] = 0;
  /* Relationship: Votes: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'votingapi_vote';
  /* Field: Votes: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Vote Timestamp';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Voter';
  /* Field: User: Institution */
  $handler->display->display_options['fields']['field_institution']['id'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['table'] = 'field_data_field_institution';
  $handler->display->display_options['fields']['field_institution']['field'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['relationship'] = 'uid';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['relationship'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Resource Voted On';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Votes: Tag */
  $handler->display->display_options['fields']['tag']['id'] = 'tag';
  $handler->display->display_options['fields']['tag']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['tag']['field'] = 'tag';
  $handler->display->display_options['fields']['tag']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['tag']['label'] = 'Vote Type';
  /* Field: Votes: Value type */
  $handler->display->display_options['fields']['value_type']['id'] = 'value_type';
  $handler->display->display_options['fields']['value_type']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value_type']['field'] = 'value_type';
  $handler->display->display_options['fields']['value_type']['relationship'] = 'votingapi_vote';
  /* Field: Votes: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['precision'] = '0';
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
  /* Filter criterion: Votes: Tag */
  $handler->display->display_options['filters']['tag']['id'] = 'tag';
  $handler->display->display_options['filters']['tag']['table'] = 'votingapi_vote';
  $handler->display->display_options['filters']['tag']['field'] = 'tag';
  $handler->display->display_options['filters']['tag']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['filters']['tag']['operator'] = 'not empty';
  /* Filter criterion: Votes: Tag */
  $handler->display->display_options['filters']['tag_1']['id'] = 'tag_1';
  $handler->display->display_options['filters']['tag_1']['table'] = 'votingapi_vote';
  $handler->display->display_options['filters']['tag_1']['field'] = 'tag';
  $handler->display->display_options['filters']['tag_1']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['filters']['tag_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['tag_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tag_1']['expose']['operator_id'] = 'tag_1_op';
  $handler->display->display_options['filters']['tag_1']['expose']['label'] = 'Filter by vote type';
  $handler->display->display_options['filters']['tag_1']['expose']['operator'] = 'tag_1_op';
  $handler->display->display_options['filters']['tag_1']['expose']['identifier'] = 'tag_1';
  $handler->display->display_options['filters']['tag_1']['expose']['remember_roles'] = array(
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
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['path'] = 'admin/votes/details';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Votes Details';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['resource_votes_admin_details_'] = $view;

  $view = new view();
  $view->name = 'reviews_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Reviews Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['fields']['nid_2']['table'] = 'node';
  $handler->display->display_options['fields']['nid_2']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_2']['label'] = 'guid';
  $handler->display->display_options['fields']['nid_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid_2']['alter']['text'] = 'edesiderata-[nid_2]';
  $handler->display->display_options['fields']['nid_2']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path_1']['id'] = 'path_1';
  $handler->display->display_options['fields']['path_1']['table'] = 'node';
  $handler->display->display_options['fields']['path_1']['field'] = 'path';
  $handler->display->display_options['fields']['path_1']['label'] = 'url';
  $handler->display->display_options['fields']['path_1']['absolute'] = TRUE;
  /* Field: Content: Provider */
  $handler->display->display_options['fields']['field_provider']['id'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['table'] = 'field_data_field_provider';
  $handler->display->display_options['fields']['field_provider']['field'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['label'] = 'provider';
  $handler->display->display_options['fields']['field_provider']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_provider']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'post-date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'U';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'published';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Sorting Title */
  $handler->display->display_options['fields']['field_resource_title_for_sort']['id'] = 'field_resource_title_for_sort';
  $handler->display->display_options['fields']['field_resource_title_for_sort']['table'] = 'field_data_field_resource_title_for_sort';
  $handler->display->display_options['fields']['field_resource_title_for_sort']['field'] = 'field_resource_title_for_sort';
  $handler->display->display_options['fields']['field_resource_title_for_sort']['label'] = 'sort-title';
  $handler->display->display_options['fields']['field_resource_title_for_sort']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resource' => 'resource',
  );
  /* Filter criterion: Content: Source status (field_resource_source_status) */
  $handler->display->display_options['filters']['field_resource_source_status_value']['id'] = 'field_resource_source_status_value';
  $handler->display->display_options['filters']['field_resource_source_status_value']['table'] = 'field_data_field_resource_source_status';
  $handler->display->display_options['filters']['field_resource_source_status_value']['field'] = 'field_resource_source_status_value';
  $handler->display->display_options['filters']['field_resource_source_status_value']['value'] = array(
    'crl_review' => 'crl_review',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['path'] = 'reviews/export';
  $export['reviews_export'] = $view;

  return $export;
}
