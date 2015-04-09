<?php
/**
 * @file
 * crl_pp_resource_feat.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crl_pp_resource_feat_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'pp_resource_export';
  $view->description = 'XSL export for internal use';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PP Resource Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'PP Resource Export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_pp_publisher' => 'field_pp_publisher',
    'field_pp_publisher_url' => 'field_pp_publisher_url',
    'field_pp_subject_area' => 'field_pp_subject_area',
    'field_pp_notes' => 'field_pp_notes',
    'field_pp_piece_count_and_pricing' => 'field_pp_piece_count_and_pricing',
    'field_pp_nominator_comments' => 'field_pp_nominator_comments',
    'field_pp_crl_comments' => 'field_pp_crl_comments',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Content: Provider */
  $handler->display->display_options['fields']['field_pp_publisher']['id'] = 'field_pp_publisher';
  $handler->display->display_options['fields']['field_pp_publisher']['table'] = 'field_data_field_pp_publisher';
  $handler->display->display_options['fields']['field_pp_publisher']['field'] = 'field_pp_publisher';
  /* Field: Content: Provider URL */
  $handler->display->display_options['fields']['field_pp_publisher_url']['id'] = 'field_pp_publisher_url';
  $handler->display->display_options['fields']['field_pp_publisher_url']['table'] = 'field_data_field_pp_publisher_url';
  $handler->display->display_options['fields']['field_pp_publisher_url']['field'] = 'field_pp_publisher_url';
  /* Field: Content: Topic(s) Covered */
  $handler->display->display_options['fields']['field_pp_subject_area']['id'] = 'field_pp_subject_area';
  $handler->display->display_options['fields']['field_pp_subject_area']['table'] = 'field_data_field_pp_subject_area';
  $handler->display->display_options['fields']['field_pp_subject_area']['field'] = 'field_pp_subject_area';
  $handler->display->display_options['fields']['field_pp_subject_area']['delta_offset'] = '0';
  /* Field: Content: Scope */
  $handler->display->display_options['fields']['field_pp_notes']['id'] = 'field_pp_notes';
  $handler->display->display_options['fields']['field_pp_notes']['table'] = 'field_data_field_pp_notes';
  $handler->display->display_options['fields']['field_pp_notes']['field'] = 'field_pp_notes';
  /* Field: Content: Piece Count and Pricing */
  $handler->display->display_options['fields']['field_pp_piece_count_and_pricing']['id'] = 'field_pp_piece_count_and_pricing';
  $handler->display->display_options['fields']['field_pp_piece_count_and_pricing']['table'] = 'field_data_field_pp_piece_count_and_pricing';
  $handler->display->display_options['fields']['field_pp_piece_count_and_pricing']['field'] = 'field_pp_piece_count_and_pricing';
  /* Field: Content: Nominator's Comments */
  $handler->display->display_options['fields']['field_pp_nominator_comments']['id'] = 'field_pp_nominator_comments';
  $handler->display->display_options['fields']['field_pp_nominator_comments']['table'] = 'field_data_field_pp_nominator_comments';
  $handler->display->display_options['fields']['field_pp_nominator_comments']['field'] = 'field_pp_nominator_comments';
  /* Field: Content: CRL Comments */
  $handler->display->display_options['fields']['field_pp_crl_comments']['id'] = 'field_pp_crl_comments';
  $handler->display->display_options['fields']['field_pp_crl_comments']['table'] = 'field_data_field_pp_crl_comments';
  $handler->display->display_options['fields']['field_pp_crl_comments']['field'] = 'field_pp_crl_comments';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'pp_resource' => 'pp_resource',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'pp/export';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_pp_publisher' => 'field_pp_publisher',
    'field_pp_publisher_url' => 'field_pp_publisher_url',
    'field_pp_subject_area' => 'field_pp_subject_area',
    'field_pp_notes' => 'field_pp_notes',
    'field_pp_piece_count_and_pricing' => 'field_pp_piece_count_and_pricing',
    'field_pp_nominator_comments' => 'field_pp_nominator_comments',
    'field_pp_crl_comments' => 'field_pp_crl_comments',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h2';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Provider */
  $handler->display->display_options['fields']['field_pp_publisher']['id'] = 'field_pp_publisher';
  $handler->display->display_options['fields']['field_pp_publisher']['table'] = 'field_data_field_pp_publisher';
  $handler->display->display_options['fields']['field_pp_publisher']['field'] = 'field_pp_publisher';
  $handler->display->display_options['fields']['field_pp_publisher']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_pp_publisher']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pp_publisher']['hide_empty'] = TRUE;
  /* Field: Content: Provider URL */
  $handler->display->display_options['fields']['field_pp_publisher_url']['id'] = 'field_pp_publisher_url';
  $handler->display->display_options['fields']['field_pp_publisher_url']['table'] = 'field_data_field_pp_publisher_url';
  $handler->display->display_options['fields']['field_pp_publisher_url']['field'] = 'field_pp_publisher_url';
  $handler->display->display_options['fields']['field_pp_publisher_url']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_pp_publisher_url']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pp_publisher_url']['hide_empty'] = TRUE;
  /* Field: Content: Topic(s) Covered */
  $handler->display->display_options['fields']['field_pp_subject_area']['id'] = 'field_pp_subject_area';
  $handler->display->display_options['fields']['field_pp_subject_area']['table'] = 'field_data_field_pp_subject_area';
  $handler->display->display_options['fields']['field_pp_subject_area']['field'] = 'field_pp_subject_area';
  $handler->display->display_options['fields']['field_pp_subject_area']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_pp_subject_area']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pp_subject_area']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_pp_subject_area']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_pp_subject_area']['multi_type'] = 'ul';
  /* Field: Content: Scope */
  $handler->display->display_options['fields']['field_pp_notes']['id'] = 'field_pp_notes';
  $handler->display->display_options['fields']['field_pp_notes']['table'] = 'field_data_field_pp_notes';
  $handler->display->display_options['fields']['field_pp_notes']['field'] = 'field_pp_notes';
  $handler->display->display_options['fields']['field_pp_notes']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_pp_notes']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pp_notes']['hide_empty'] = TRUE;
  /* Field: Content: Piece Count and Pricing */
  $handler->display->display_options['fields']['field_pp_piece_count_and_pricing']['id'] = 'field_pp_piece_count_and_pricing';
  $handler->display->display_options['fields']['field_pp_piece_count_and_pricing']['table'] = 'field_data_field_pp_piece_count_and_pricing';
  $handler->display->display_options['fields']['field_pp_piece_count_and_pricing']['field'] = 'field_pp_piece_count_and_pricing';
  $handler->display->display_options['fields']['field_pp_piece_count_and_pricing']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_pp_piece_count_and_pricing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pp_piece_count_and_pricing']['hide_empty'] = TRUE;
  /* Field: Content: Nominator's Comments */
  $handler->display->display_options['fields']['field_pp_nominator_comments']['id'] = 'field_pp_nominator_comments';
  $handler->display->display_options['fields']['field_pp_nominator_comments']['table'] = 'field_data_field_pp_nominator_comments';
  $handler->display->display_options['fields']['field_pp_nominator_comments']['field'] = 'field_pp_nominator_comments';
  $handler->display->display_options['fields']['field_pp_nominator_comments']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_pp_nominator_comments']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pp_nominator_comments']['hide_empty'] = TRUE;
  /* Field: Content: CRL Comments */
  $handler->display->display_options['fields']['field_pp_crl_comments']['id'] = 'field_pp_crl_comments';
  $handler->display->display_options['fields']['field_pp_crl_comments']['table'] = 'field_data_field_pp_crl_comments';
  $handler->display->display_options['fields']['field_pp_crl_comments']['field'] = 'field_pp_crl_comments';
  $handler->display->display_options['fields']['field_pp_crl_comments']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_pp_crl_comments']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pp_crl_comments']['hide_empty'] = TRUE;
  $handler->display->display_options['path'] = 'pp/export_all';
  $export['pp_resource_export'] = $view;

  $view = new view();
  $view->name = 'pp_resource_lists';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PP Resource Lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Purchase Proposal Ballot';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<hr />
<p><strong>The FY2014 Purchase Proposal ballot is now closed.</strong></p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Vote results (pp_pref) */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['ui_name'] = 'Vote results (pp_pref)';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Vote results (pp_pref)';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'percent',
    'tag' => 'pp_preference',
    'function' => 'average',
  );
  /* Relationship: Vote results (pp_own_lend) */
  $handler->display->display_options['relationships']['votingapi_cache_1']['id'] = 'votingapi_cache_1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_1']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_1']['ui_name'] = 'Vote results (pp_own_lend)';
  $handler->display->display_options['relationships']['votingapi_cache_1']['label'] = 'Vote results (pp_own_lend)';
  $handler->display->display_options['relationships']['votingapi_cache_1']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => 'pp_own_lend',
    'function' => 'count',
  );
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[path]">[title]</a><br/>
<a class="vote-results" href="[path]#comments">[comment_count] comments</a>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Purchase Ranking';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['appearance'] = 'rate_views_widget_compact';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'votingapi_cache_1';
  $handler->display->display_options['fields']['value_1']['label'] = 'Member Library Holdings';
  $handler->display->display_options['fields']['value_1']['precision'] = '0';
  $handler->display->display_options['fields']['value_1']['appearance'] = 'rate_views_widget_compact';
  /* Sort criterion: Content: Sorting Title (field_title_sort) */
  $handler->display->display_options['sorts']['field_title_sort_value']['id'] = 'field_title_sort_value';
  $handler->display->display_options['sorts']['field_title_sort_value']['table'] = 'field_data_field_title_sort';
  $handler->display->display_options['sorts']['field_title_sort_value']['field'] = 'field_title_sort_value';
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
    'pp_resource' => 'pp_resource',
  );

  /* Display: Index - PP */
  $handler = $view->new_display('page', 'Index - PP', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div class="edes-vid-highlight">
<a target="_blank" href="/pp/about-video"><img src="/sites/default/files/images/pp_video_thumb.png"></a><p>Voting video tutorial</p>
</div>
<p>CRL\'s <a href="http://www.crl.edu/collections/collection-building/cooperative-resource-development/pp-program">Purchase Proposal program</a> is an annual cooperative collection development activity. Member libraries nominate and vote for CRL to purchase microform and hard copy collections that may be too costly or esoteric for individual institutions to acquire. CRL collections are developed by and for the member community, with input and participation of all voting members.</p>

<p><strong>The FY2015 ballot is now closed</strong></p>

<div id="ballot"></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<hr />';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['path'] = 'pp';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Purchase Proposal Ballot';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pp-main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Index - SP */
  $handler = $view->new_display('page', 'Index - SP', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Shared Purchase Proposal Ballot';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'item-list-box';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p>CRL’s <a href="http://www.crl.edu/shared-purchase-program">Shared Purchase Program</a> supports the cooperative acquisition of costly sets that were nominated for the Purchase Proposal Program, but were not of sufficiently broad interest to warrant purchase (or were proposed after voting). In Shared Purchase the nominating library and CRL contribute seed funds, and through the ballot other member libraries can voluntarily pledge funds toward the purchase of sets.  Purchased materials are available for use to all member libraries.</p>

<p><strong>The shared purchase proposal ballot is currently closed.</strong></p>

<div id="ballot"></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<hr />';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[path]">[title]</a><br/>
<a class="vote-results" href="[path]#comments">[comment_count] comments</a>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
    'spp_resource' => 'spp_resource',
  );
  $handler->display->display_options['path'] = 'spp';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Shared Purchase Proposal Ballot';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-pp-main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['pp_resource_lists'] = $view;

  $view = new view();
  $view->name = 'pp_resource_votes_admin';
  $view->description = '';
  $view->tag = 'admin';
  $view->base_table = 'node';
  $view->human_name = 'PP Resource Votes Admin (aggregate)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'PP Votes Aggregate';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    21 => '21',
    12 => '12',
    11 => '11',
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_fy' => 'field_fy',
    'value' => 'value',
    'value_3' => 'value_3',
    'value_1' => 'value_1',
    'comment_count' => 'comment_count',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fy' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'value_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
  );
  /* Relationship: Vote results - Preference Rank */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['ui_name'] = 'Vote results - Preference Rank';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Vote results - Preference Rank';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'percent',
    'tag' => 'pp_preference',
    'function' => 'average',
  );
  /* Relationship: Vote results - Holding Status */
  $handler->display->display_options['relationships']['votingapi_cache_1']['id'] = 'votingapi_cache_1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_1']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_1']['ui_name'] = 'Vote results - Holding Status';
  $handler->display->display_options['relationships']['votingapi_cache_1']['label'] = 'Vote results - Holding Status';
  $handler->display->display_options['relationships']['votingapi_cache_1']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => 'pp_own_lend',
    'function' => 'count',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Fiscal Year */
  $handler->display->display_options['fields']['field_fy']['id'] = 'field_fy';
  $handler->display->display_options['fields']['field_fy']['table'] = 'field_data_field_fy';
  $handler->display->display_options['fields']['field_fy']['field'] = 'field_fy';
  $handler->display->display_options['fields']['field_fy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Preference Rank';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['appearance'] = 'rate_views_widget_compact_disabled';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_3']['label'] = 'Preference Rank Raw';
  $handler->display->display_options['fields']['value_3']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'votingapi_cache_1';
  $handler->display->display_options['fields']['value_1']['label'] = 'Holdings Status';
  $handler->display->display_options['fields']['value_1']['precision'] = '0';
  $handler->display->display_options['fields']['value_1']['appearance'] = 'rate_views_widget_compact_disabled';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  /* Field: Content: Purchase Status */
  $handler->display->display_options['fields']['field_pp_purchase_status']['id'] = 'field_pp_purchase_status';
  $handler->display->display_options['fields']['field_pp_purchase_status']['table'] = 'field_data_field_pp_purchase_status';
  $handler->display->display_options['fields']['field_pp_purchase_status']['field'] = 'field_pp_purchase_status';
  /* Sort criterion: Content: Fiscal Year (field_fy) */
  $handler->display->display_options['sorts']['field_fy_tid']['id'] = 'field_fy_tid';
  $handler->display->display_options['sorts']['field_fy_tid']['table'] = 'field_data_field_fy';
  $handler->display->display_options['sorts']['field_fy_tid']['field'] = 'field_fy_tid';
  $handler->display->display_options['sorts']['field_fy_tid']['order'] = 'DESC';
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
    'pp_resource' => 'pp_resource',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    106 => '106',
  );
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Fiscal Year';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'fy';

  /* Display: PP Aggregate */
  $handler = $view->new_display('page', 'PP Aggregate', 'page_1');
  $handler->display->display_options['path'] = 'admin/pp/aggregate';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'PP Votes Aggregate';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'PP Votes Administration';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: PP Aggregate Export */
  $handler = $view->new_display('views_data_export', 'PP Aggregate Export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'pp_votes_aggregate_export.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Vote results - Preference Rank */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['ui_name'] = 'Vote results - Preference Rank';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Vote results - Preference Rank';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'percent',
    'tag' => 'pp_preference',
    'function' => 'average',
  );
  /* Relationship: Vote results - Holding Status - Op 1 */
  $handler->display->display_options['relationships']['votingapi_cache_1']['id'] = 'votingapi_cache_1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_1']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_1']['ui_name'] = 'Vote results - Holding Status - Op 1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['label'] = 'Vote results - Holding Status - Op 1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => 'pp_own_lend',
    'function' => 'option-1',
  );
  /* Relationship: Vote results - Holding Status - Op 2 */
  $handler->display->display_options['relationships']['votingapi_cache_2']['id'] = 'votingapi_cache_2';
  $handler->display->display_options['relationships']['votingapi_cache_2']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_2']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_2']['ui_name'] = 'Vote results - Holding Status - Op 2';
  $handler->display->display_options['relationships']['votingapi_cache_2']['label'] = 'Vote results - Holding Status - Op 2';
  $handler->display->display_options['relationships']['votingapi_cache_2']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => 'pp_own_lend',
    'function' => 'option-2',
  );
  /* Relationship: Vote results - Holding Status - Op 3 */
  $handler->display->display_options['relationships']['votingapi_cache_3']['id'] = 'votingapi_cache_3';
  $handler->display->display_options['relationships']['votingapi_cache_3']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_3']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_3']['ui_name'] = 'Vote results - Holding Status - Op 3';
  $handler->display->display_options['relationships']['votingapi_cache_3']['label'] = 'Vote results - Holding Status - Op 3';
  $handler->display->display_options['relationships']['votingapi_cache_3']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => 'pp_own_lend',
    'function' => 'option-3',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Fiscal Year */
  $handler->display->display_options['fields']['field_fy']['id'] = 'field_fy';
  $handler->display->display_options['fields']['field_fy']['table'] = 'field_data_field_fy';
  $handler->display->display_options['fields']['field_fy']['field'] = 'field_fy';
  $handler->display->display_options['fields']['field_fy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Title ID';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_3']['label'] = 'Preference Rank Average';
  $handler->display->display_options['fields']['value_3']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache_1';
  $handler->display->display_options['fields']['value']['label'] = 'Do not own';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'votingapi_cache_2';
  $handler->display->display_options['fields']['value_1']['label'] = 'Own, can lend';
  $handler->display->display_options['fields']['value_1']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['relationship'] = 'votingapi_cache_3';
  $handler->display->display_options['fields']['value_2']['label'] = 'Own, cannot lend';
  $handler->display->display_options['fields']['value_2']['precision'] = '0';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  /* Field: Content: Purchase Status */
  $handler->display->display_options['fields']['field_pp_purchase_status']['id'] = 'field_pp_purchase_status';
  $handler->display->display_options['fields']['field_pp_purchase_status']['table'] = 'field_data_field_pp_purchase_status';
  $handler->display->display_options['fields']['field_pp_purchase_status']['field'] = 'field_pp_purchase_status';
  $handler->display->display_options['path'] = 'admin/pp/aggregate/export';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );

  /* Display: SP Aggregate */
  $handler = $view->new_display('page', 'SP Aggregate', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'SPP Votes Aggregate';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_fy' => 'field_fy',
    'value' => 'value',
    'value_2' => 'value_2',
    'value_1' => 'value_1',
    'value_3' => 'value_3',
    'comment_count' => 'comment_count',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fy' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'value_2' => array(
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
    'value_3' => array(
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
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Vote results - SP USD */
  $handler->display->display_options['relationships']['votingapi_cache_3']['id'] = 'votingapi_cache_3';
  $handler->display->display_options['relationships']['votingapi_cache_3']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_3']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_3']['ui_name'] = 'Vote results - SP USD';
  $handler->display->display_options['relationships']['votingapi_cache_3']['label'] = 'Vote results - SP USD';
  $handler->display->display_options['relationships']['votingapi_cache_3']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'pp_shared_pledge_usd',
    'function' => 'sum',
  );
  /* Relationship: Vote results - SP CAD */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['ui_name'] = 'Vote results - SP CAD';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Vote results - SP CAD';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'pp_shared_pledge_cad',
    'function' => 'sum',
  );
  /* Relationship: Vote count USD */
  $handler->display->display_options['relationships']['votingapi_cache_1']['id'] = 'votingapi_cache_1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_1']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_1']['ui_name'] = 'Vote count USD';
  $handler->display->display_options['relationships']['votingapi_cache_1']['label'] = 'Vote count USD';
  $handler->display->display_options['relationships']['votingapi_cache_1']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'pp_shared_pledge_usd',
    'function' => 'count',
  );
  /* Relationship: Vote count CAD */
  $handler->display->display_options['relationships']['votingapi_cache_2']['id'] = 'votingapi_cache_2';
  $handler->display->display_options['relationships']['votingapi_cache_2']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_2']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_2']['ui_name'] = 'Vote count CAD';
  $handler->display->display_options['relationships']['votingapi_cache_2']['label'] = 'Vote count CAD';
  $handler->display->display_options['relationships']['votingapi_cache_2']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'pp_shared_pledge_cad',
    'function' => 'count',
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'fy' => 'fy',
    'grouping' => 0,
    'resource_languages' => 0,
    'title_type' => 0,
    'resource_type' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Fiscal Year */
  $handler->display->display_options['fields']['field_fy']['id'] = 'field_fy';
  $handler->display->display_options['fields']['field_fy']['table'] = 'field_data_field_fy';
  $handler->display->display_options['fields']['field_fy']['field'] = 'field_fy';
  $handler->display->display_options['fields']['field_fy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache_3';
  $handler->display->display_options['fields']['value']['label'] = 'USD totals';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['relationship'] = 'votingapi_cache_1';
  $handler->display->display_options['fields']['value_2']['label'] = 'Input count USD';
  $handler->display->display_options['fields']['value_2']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_1']['label'] = 'CAD Totals (unconverted)';
  $handler->display->display_options['fields']['value_1']['precision'] = '0';
  /* Field: Taxonomy term: Currency */
  $handler->display->display_options['fields']['field_currency_cad_usd']['id'] = 'field_currency_cad_usd';
  $handler->display->display_options['fields']['field_currency_cad_usd']['table'] = 'field_data_field_currency_cad_usd';
  $handler->display->display_options['fields']['field_currency_cad_usd']['field'] = 'field_currency_cad_usd';
  $handler->display->display_options['fields']['field_currency_cad_usd']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_currency_cad_usd']['label'] = 'CAD Conversion';
  $handler->display->display_options['fields']['field_currency_cad_usd']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['relationship'] = 'votingapi_cache_2';
  $handler->display->display_options['fields']['value_3']['label'] = 'Input count CAD';
  $handler->display->display_options['fields']['value_3']['precision'] = '0';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  /* Field: Content: Proposal Purchased */
  $handler->display->display_options['fields']['field_pp_proposal_purchased']['id'] = 'field_pp_proposal_purchased';
  $handler->display->display_options['fields']['field_pp_proposal_purchased']['table'] = 'field_data_field_pp_proposal_purchased';
  $handler->display->display_options['fields']['field_pp_proposal_purchased']['field'] = 'field_pp_proposal_purchased';
  $handler->display->display_options['fields']['field_pp_proposal_purchased']['label'] = 'Purchased';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'spp_resource' => 'spp_resource',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    106 => '106',
  );
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Fiscal Year';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'fy';
  $handler->display->display_options['path'] = 'admin/pp/sp/aggregate';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'SPP Votes Aggregate';
  $handler->display->display_options['menu']['weight'] = '50';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: SP Aggregate Export */
  $handler = $view->new_display('views_data_export', 'SP Aggregate Export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'spp_votes_aggregate_export.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Vote results - SP USD */
  $handler->display->display_options['relationships']['votingapi_cache_3']['id'] = 'votingapi_cache_3';
  $handler->display->display_options['relationships']['votingapi_cache_3']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_3']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_3']['ui_name'] = 'Vote results - SP USD';
  $handler->display->display_options['relationships']['votingapi_cache_3']['label'] = 'Vote results - SP USD';
  $handler->display->display_options['relationships']['votingapi_cache_3']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'pp_shared_pledge_usd',
    'function' => 'sum',
  );
  /* Relationship: Vote results - SP CAD */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['ui_name'] = 'Vote results - SP CAD';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Vote results - SP CAD';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'pp_shared_pledge_cad',
    'function' => 'sum',
  );
  /* Relationship: Vote count USD */
  $handler->display->display_options['relationships']['votingapi_cache_1']['id'] = 'votingapi_cache_1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_1']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_1']['ui_name'] = 'Vote count USD';
  $handler->display->display_options['relationships']['votingapi_cache_1']['label'] = 'Vote count USD';
  $handler->display->display_options['relationships']['votingapi_cache_1']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'pp_shared_pledge_usd',
    'function' => 'count',
  );
  /* Relationship: Vote count CAD */
  $handler->display->display_options['relationships']['votingapi_cache_2']['id'] = 'votingapi_cache_2';
  $handler->display->display_options['relationships']['votingapi_cache_2']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_2']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_2']['ui_name'] = 'Vote count CAD';
  $handler->display->display_options['relationships']['votingapi_cache_2']['label'] = 'Vote count CAD';
  $handler->display->display_options['relationships']['votingapi_cache_2']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'pp_shared_pledge_cad',
    'function' => 'count',
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'fy' => 'fy',
    'grouping' => 0,
    'resource_languages' => 0,
    'title_type' => 0,
    'resource_type' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Fiscal Year */
  $handler->display->display_options['fields']['field_fy']['id'] = 'field_fy';
  $handler->display->display_options['fields']['field_fy']['table'] = 'field_data_field_fy';
  $handler->display->display_options['fields']['field_fy']['field'] = 'field_fy';
  $handler->display->display_options['fields']['field_fy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache_3';
  $handler->display->display_options['fields']['value']['label'] = 'USD totals';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['relationship'] = 'votingapi_cache_1';
  $handler->display->display_options['fields']['value_2']['label'] = 'Input count USD';
  $handler->display->display_options['fields']['value_2']['precision'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_1']['label'] = 'CAD Totals (unconverted)';
  $handler->display->display_options['fields']['value_1']['precision'] = '0';
  /* Field: Taxonomy term: Currency */
  $handler->display->display_options['fields']['field_currency_cad_usd']['id'] = 'field_currency_cad_usd';
  $handler->display->display_options['fields']['field_currency_cad_usd']['table'] = 'field_data_field_currency_cad_usd';
  $handler->display->display_options['fields']['field_currency_cad_usd']['field'] = 'field_currency_cad_usd';
  $handler->display->display_options['fields']['field_currency_cad_usd']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_currency_cad_usd']['label'] = 'CAD Conversion';
  $handler->display->display_options['fields']['field_currency_cad_usd']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['relationship'] = 'votingapi_cache_2';
  $handler->display->display_options['fields']['value_3']['label'] = 'Input count CAD';
  $handler->display->display_options['fields']['value_3']['precision'] = '0';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  /* Field: Content: Proposal Purchased */
  $handler->display->display_options['fields']['field_pp_proposal_purchased']['id'] = 'field_pp_proposal_purchased';
  $handler->display->display_options['fields']['field_pp_proposal_purchased']['table'] = 'field_data_field_pp_proposal_purchased';
  $handler->display->display_options['fields']['field_pp_proposal_purchased']['field'] = 'field_pp_proposal_purchased';
  $handler->display->display_options['fields']['field_pp_proposal_purchased']['label'] = 'Purchased';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'spp_resource' => 'spp_resource',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    106 => '106',
  );
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Fiscal Year';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'fy';
  $handler->display->display_options['path'] = 'admin/pp/sp/aggregate/export';
  $handler->display->display_options['displays'] = array(
    'page_2' => 'page_2',
    'default' => 0,
    'page_1' => 0,
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'value' => 0,
    'value_3' => 0,
    'value_1' => 0,
    'comment_count' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Fiscal Year */
  $handler->display->display_options['fields']['field_fy']['id'] = 'field_fy';
  $handler->display->display_options['fields']['field_fy']['table'] = 'field_data_field_fy';
  $handler->display->display_options['fields']['field_fy']['field'] = 'field_fy';
  $handler->display->display_options['fields']['field_fy']['label'] = '';
  $handler->display->display_options['fields']['field_fy']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
    'pp_resource' => 'pp_resource',
  );
  $export['pp_resource_votes_admin'] = $view;

  $view = new view();
  $view->name = 'pp_resource_votes_admin_details_';
  $view->description = '';
  $view->tag = 'admin';
  $view->base_table = 'node';
  $view->human_name = 'PP Resource Votes Admin (details)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    21 => '21',
    12 => '12',
    11 => '11',
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'uid',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'name' => 'name',
    'mail' => 'mail',
    'field_institution' => 'field_institution',
    'uid' => 'uid',
    'tag' => 'tag',
    'value' => 'value',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = 'tag';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'mail' => array(
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
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tag' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
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
  $handler->display->display_options['header']['area']['label'] = 'Legend';
  $handler->display->display_options['header']['area']['content'] = '<p><strong>pp_preference = PP Purchase ranking</strong>. Values are percentages (Five stars = 100).</p>
<p><strong>pp_own_lend = PP Member Library Holdings input</strong>. 1 = Do not own | 2 = Own, can lend | 3 = Own, cannot lend</p>
<p><strong>pp_shared_pledge_[currency] = SPP Pledge</strong>. Values shown are <strong>not</strong> converted.</p>
<p><strong>The raw data that this report is based on is also available in <a href="/admin/pp/details-export">Excel format</a>.</strong></p>
<hr/>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No data to show (yet).';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Votes */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['ui_name'] = 'Votes';
  $handler->display->display_options['relationships']['votingapi_vote']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
  );
  $handler->display->display_options['relationships']['votingapi_vote']['current_user'] = 0;
  /* Relationship: Votes: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'votingapi_vote';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<br/><h3>[title]</h3>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Institution */
  $handler->display->display_options['fields']['field_institution']['id'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['table'] = 'field_data_field_institution';
  $handler->display->display_options['fields']['field_institution']['field'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_institution']['exclude'] = TRUE;
  /* Field: Votes: User */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[name] ([mail]), [field_institution]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Fiscal Year */
  $handler->display->display_options['fields']['field_fy']['id'] = 'field_fy';
  $handler->display->display_options['fields']['field_fy']['table'] = 'field_data_field_fy';
  $handler->display->display_options['fields']['field_fy']['field'] = 'field_fy';
  $handler->display->display_options['fields']['field_fy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Votes: Tag */
  $handler->display->display_options['fields']['tag']['id'] = 'tag';
  $handler->display->display_options['fields']['tag']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['tag']['field'] = 'tag';
  $handler->display->display_options['fields']['tag']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['tag']['label'] = 'Input';
  /* Field: Votes: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Votes: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  /* Sort criterion: Votes: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'votingapi_vote';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'pp_resource' => 'pp_resource',
    'spp_resource' => 'spp_resource',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    106 => '106',
  );
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Fiscal Year';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'fy';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'pp_resource' => 'pp_resource',
    'spp_resource' => 'spp_resource',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
    24 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Votes: Tag */
  $handler->display->display_options['filters']['tag']['id'] = 'tag';
  $handler->display->display_options['filters']['tag']['table'] = 'votingapi_vote';
  $handler->display->display_options['filters']['tag']['field'] = 'tag';
  $handler->display->display_options['filters']['tag']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['filters']['tag']['group'] = 1;
  $handler->display->display_options['filters']['tag']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tag']['expose']['operator_id'] = 'tag_op';
  $handler->display->display_options['filters']['tag']['expose']['label'] = 'Tag';
  $handler->display->display_options['filters']['tag']['expose']['operator'] = 'tag_op';
  $handler->display->display_options['filters']['tag']['expose']['identifier'] = 'tag';
  $handler->display->display_options['filters']['tag']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['tag']['group_info']['label'] = 'Vote type';
  $handler->display->display_options['filters']['tag']['group_info']['identifier'] = 'tag';
  $handler->display->display_options['filters']['tag']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'pp_own_lend',
      'operator' => '=',
      'value' => 'pp_own_lend',
    ),
    2 => array(
      'title' => 'pp_preference',
      'operator' => '=',
      'value' => 'pp_preference',
    ),
    3 => array(
      'title' => 'pp_shared_pledge_usd',
      'operator' => '=',
      'value' => 'pp_shared_pledge_usd',
    ),
    4 => array(
      'title' => 'pp_shared_pledge_cad',
      'operator' => '=',
      'value' => 'pp_shared_pledge_cad',
    ),
  );
  /* Filter criterion: User: Institution (field_institution) */
  $handler->display->display_options['filters']['field_institution_value']['id'] = 'field_institution_value';
  $handler->display->display_options['filters']['field_institution_value']['table'] = 'field_data_field_institution';
  $handler->display->display_options['filters']['field_institution_value']['field'] = 'field_institution_value';
  $handler->display->display_options['filters']['field_institution_value']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_institution_value']['group'] = 1;
  $handler->display->display_options['filters']['field_institution_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_institution_value']['expose']['operator_id'] = 'field_institution_value_op';
  $handler->display->display_options['filters']['field_institution_value']['expose']['label'] = 'Institution';
  $handler->display->display_options['filters']['field_institution_value']['expose']['operator'] = 'field_institution_value_op';
  $handler->display->display_options['filters']['field_institution_value']['expose']['identifier'] = 'field_institution_value';
  $handler->display->display_options['filters']['field_institution_value']['expose']['remember_roles'] = array(
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
    24 => 0,
  );

  /* Display: All Details */
  $handler = $view->new_display('page', 'All Details', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All PP and SPP Vote Details';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'field_fy' => 'field_fy',
    'name' => 'name',
    'mail' => 'mail',
    'uid' => 'uid',
    'field_institution' => 'field_institution',
    'tag' => 'tag',
    'value' => 'value',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fy' => array(
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
    'mail' => array(
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
    'field_institution' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tag' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['text'] = '<br/><h3>[title]</h3>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['max_length'] = '15';
  $handler->display->display_options['fields']['type']['alter']['trim'] = TRUE;
  /* Field: Content: Fiscal Year */
  $handler->display->display_options['fields']['field_fy']['id'] = 'field_fy';
  $handler->display->display_options['fields']['field_fy']['table'] = 'field_data_field_fy';
  $handler->display->display_options['fields']['field_fy']['field'] = 'field_fy';
  $handler->display->display_options['fields']['field_fy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Votes: User */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['label'] = 'Voter';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[name] ([mail])';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Institution */
  $handler->display->display_options['fields']['field_institution']['id'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['table'] = 'field_data_field_institution';
  $handler->display->display_options['fields']['field_institution']['field'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_institution']['alter']['text'] = '<br/><h3>[field_institution]</h3>';
  $handler->display->display_options['fields']['field_institution']['element_label_colon'] = FALSE;
  /* Field: Votes: Tag */
  $handler->display->display_options['fields']['tag']['id'] = 'tag';
  $handler->display->display_options['fields']['tag']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['tag']['field'] = 'tag';
  $handler->display->display_options['fields']['tag']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['tag']['label'] = 'Input';
  /* Field: Votes: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Votes: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['path'] = 'admin/pp/details';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'All Details';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'PP Votes Administration';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: All Details by Title */
  $handler = $view->new_display('page', 'All Details by Title', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All PP and SPP Vote Details by Title';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '200';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'uid',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'name' => 'name',
    'mail' => 'mail',
    'field_institution' => 'field_institution',
    'uid' => 'uid',
    'tag' => 'tag',
    'value' => 'value',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'mail' => array(
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
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tag' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'admin/pp/details-title';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'All Details by Title';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: All details export */
  $handler = $view->new_display('views_data_export', 'All details export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['text'] = '<br/><h3>[title]</h3>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Resource ID';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Institution */
  $handler->display->display_options['fields']['field_institution']['id'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['table'] = 'field_data_field_institution';
  $handler->display->display_options['fields']['field_institution']['field'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['relationship'] = 'uid';
  /* Field: Votes: User */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[name] ([mail]), [field_institution]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Votes: Tag */
  $handler->display->display_options['fields']['tag']['id'] = 'tag';
  $handler->display->display_options['fields']['tag']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['tag']['field'] = 'tag';
  $handler->display->display_options['fields']['tag']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['tag']['label'] = 'Input';
  /* Field: Votes: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Votes: Value type */
  $handler->display->display_options['fields']['value_type']['id'] = 'value_type';
  $handler->display->display_options['fields']['value_type']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value_type']['field'] = 'value_type';
  $handler->display->display_options['fields']['value_type']['relationship'] = 'votingapi_vote';
  /* Field: Votes: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['path'] = 'admin/pp/details-export';
  $handler->display->display_options['displays'] = array(
    'page_5' => 'page_5',
    'page_1' => 'page_1',
    'default' => 0,
    'block_1' => 0,
    'page_3' => 0,
    'page_4' => 0,
    'page_2' => 0,
  );

  /* Display: Embed Details by Title */
  $handler = $view->new_display('block', 'Embed Details by Title', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'uid',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'name' => 'name',
    'mail' => 'mail',
    'field_institution' => 'field_institution',
    'uid' => 'uid',
    'tag' => 'tag',
    'value' => 'value',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = 'tag';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'mail' => array(
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
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tag' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<br/><h3>[title]</h3>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Institution */
  $handler->display->display_options['fields']['field_institution']['id'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['table'] = 'field_data_field_institution';
  $handler->display->display_options['fields']['field_institution']['field'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_institution']['exclude'] = TRUE;
  /* Field: Votes: User */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[name] ([mail]), [field_institution]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Votes: Tag */
  $handler->display->display_options['fields']['tag']['id'] = 'tag';
  $handler->display->display_options['fields']['tag']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['tag']['field'] = 'tag';
  $handler->display->display_options['fields']['tag']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['tag']['label'] = 'Input';
  /* Field: Votes: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Votes: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Misc - Holding Details */
  $handler = $view->new_display('page', 'Misc - Holding Details', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Holding Details';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'name' => 'name',
    'mail' => 'mail',
    'field_institution' => 'field_institution',
    'uid' => 'uid',
    'tag' => 'tag',
    'value' => 'value',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_institution' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tag' => array(
      'sortable' => 0,
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
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Legend';
  $handler->display->display_options['header']['area']['content'] = '<p><strong>Member Library Holdings input = pp_own_lend</strong>.<br/>1 = Do not own | 2 = Own, can lend | 3 = Own, cannot lend</p>
<hr/>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Votes */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['ui_name'] = 'Votes';
  $handler->display->display_options['relationships']['votingapi_vote']['votingapi'] = array(
    'value_type' => '',
    'tag' => 'pp_own_lend',
  );
  $handler->display->display_options['relationships']['votingapi_vote']['current_user'] = 0;
  /* Relationship: Votes: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['text'] = '<br/><h3>[title]</h3>';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Institution */
  $handler->display->display_options['fields']['field_institution']['id'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['table'] = 'field_data_field_institution';
  $handler->display->display_options['fields']['field_institution']['field'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['relationship'] = 'uid';
  /* Field: Votes: User */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[name] ([mail]), [field_institution]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Votes: Tag */
  $handler->display->display_options['fields']['tag']['id'] = 'tag';
  $handler->display->display_options['fields']['tag']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['tag']['field'] = 'tag';
  $handler->display->display_options['fields']['tag']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['tag']['label'] = 'Input';
  $handler->display->display_options['fields']['tag']['exclude'] = TRUE;
  /* Field: Votes: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['label'] = 'PP Own Lend (if 2 or 3)';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Votes: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
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
    'pp_resource' => 'pp_resource',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Filter by Title (contains)';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['relationship'] = 'uid';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'Filter by User (email contains)';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Votes: Value */
  $handler->display->display_options['filters']['value']['id'] = 'value';
  $handler->display->display_options['filters']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['filters']['value']['field'] = 'value';
  $handler->display->display_options['filters']['value']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['filters']['value']['operator'] = '>=';
  $handler->display->display_options['filters']['value']['value']['value'] = '2';
  $handler->display->display_options['path'] = 'admin/pp/details-holding';
  $handler->display->display_options['menu']['title'] = 'Holding Details';
  $handler->display->display_options['menu']['weight'] = '40';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Misc - Pref Vote Counts */
  $handler = $view->new_display('page', 'Misc - Pref Vote Counts', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Pref Vote Counts';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'mail' => 'mail',
    'field_institution' => 'field_institution',
    'uid' => 'uid',
    'tag' => 'tag',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_institution' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tag' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Votes */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['ui_name'] = 'Votes';
  $handler->display->display_options['relationships']['votingapi_vote']['votingapi'] = array(
    'value_type' => '',
    'tag' => 'pp_preference',
  );
  $handler->display->display_options['relationships']['votingapi_vote']['current_user'] = 0;
  /* Relationship: Votes: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Institution */
  $handler->display->display_options['fields']['field_institution']['id'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['table'] = 'field_data_field_institution';
  $handler->display->display_options['fields']['field_institution']['field'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['relationship'] = 'uid';
  /* Field: Votes: User */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[name] ([mail]), [field_institution]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['title']['label'] = 'Preference Vote Count';
  $handler->display->display_options['fields']['title']['alter']['text'] = '<br/><h3>[title]</h3>';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
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
    'pp_resource' => 'pp_resource',
  );
  $handler->display->display_options['path'] = 'admin/pp/details-rank-count';
  $handler->display->display_options['menu']['title'] = 'Pref Vote Counts';
  $handler->display->display_options['menu']['weight'] = '30';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Misc - Pref Ranking */
  $handler = $view->new_display('page', 'Misc - Pref Ranking', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Preference Rank Details';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'name' => 'name',
    'mail' => 'mail',
    'field_institution' => 'field_institution',
    'uid' => 'uid',
    'tag' => 'tag',
    'value' => 'value',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_institution' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tag' => array(
      'sortable' => 0,
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
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Legend';
  $handler->display->display_options['header']['area']['content'] = '<p><strong>Purchase ranking = pp_preference</strong>.<br/>Values are percentages (Five stars = 100).</p>
<hr/>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Votes */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['ui_name'] = 'Votes';
  $handler->display->display_options['relationships']['votingapi_vote']['votingapi'] = array(
    'value_type' => '',
    'tag' => 'pp_preference',
  );
  $handler->display->display_options['relationships']['votingapi_vote']['current_user'] = 0;
  /* Relationship: Votes: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['text'] = '<br/><h3>[title]</h3>';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Institution */
  $handler->display->display_options['fields']['field_institution']['id'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['table'] = 'field_data_field_institution';
  $handler->display->display_options['fields']['field_institution']['field'] = 'field_institution';
  $handler->display->display_options['fields']['field_institution']['relationship'] = 'uid';
  /* Field: Votes: User */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[name] ([mail]), [field_institution]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Votes: Tag */
  $handler->display->display_options['fields']['tag']['id'] = 'tag';
  $handler->display->display_options['fields']['tag']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['tag']['field'] = 'tag';
  $handler->display->display_options['fields']['tag']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['tag']['label'] = 'Input';
  $handler->display->display_options['fields']['tag']['exclude'] = TRUE;
  /* Field: Votes: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['label'] = 'PP Preference';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Field: Votes: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
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
    'pp_resource' => 'pp_resource',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Filter by Title (contains)';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['relationship'] = 'uid';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'Filter by User (email contains)';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'admin/pp/details-rank';
  $handler->display->display_options['menu']['title'] = 'Pref Ranking Details';
  $handler->display->display_options['menu']['weight'] = '30';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['pp_resource_votes_admin_details_'] = $view;

  return $export;
}
