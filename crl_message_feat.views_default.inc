<?php
/**
 * @file
 * crl_message_feat.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crl_message_feat_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'crl_messages';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'message';
  $view->human_name = 'CRL messages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Activity';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = '[type]';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Notable recent site activity sorted by resource title.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<p><a class="button" href="/messages/rss"><span class="crl-icon-small rss-icon"></span>Subscribe via RSS</a></p>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No activity to display.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_resource_reference_target_id']['id'] = 'field_resource_reference_target_id';
  $handler->display->display_options['relationships']['field_resource_reference_target_id']['table'] = 'field_data_field_resource_reference';
  $handler->display->display_options['relationships']['field_resource_reference_target_id']['field'] = 'field_resource_reference_target_id';
  /* Field: Message: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'message';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Field: Short Message */
  $handler->display->display_options['fields']['message_render_1']['id'] = 'message_render_1';
  $handler->display->display_options['fields']['message_render_1']['table'] = 'message';
  $handler->display->display_options['fields']['message_render_1']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render_1']['ui_name'] = 'Short Message';
  $handler->display->display_options['fields']['message_render_1']['label'] = '';
  $handler->display->display_options['fields']['message_render_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['message_render_1']['alter']['text'] = '<span class="message-icon-small [type]"></span>[message_render_1] ([timestamp])';
  $handler->display->display_options['fields']['message_render_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message_render_1']['partials'] = 1;
  $handler->display->display_options['fields']['message_render_1']['partials_delta'] = '1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_resource_reference_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';

  /* Display: Page - Title Grouped */
  $handler = $view->new_display('page', 'Page - Title Grouped', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Site Activity by Title';
  $handler->display->display_options['path'] = 'messages/group';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'By title';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Messages';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Page - Date Grouped */
  $handler = $view->new_display('page', 'Page - Date Grouped', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Site Activity by Date';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'timestamp',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = '[type]';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Notable recent site activity sorted by date.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Message: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'message';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'F d, Y';
  /* Field: Time */
  $handler->display->display_options['fields']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['fields']['timestamp_1']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp_1']['ui_name'] = 'Time';
  $handler->display->display_options['fields']['timestamp_1']['label'] = '';
  $handler->display->display_options['fields']['timestamp_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp_1']['custom_date_format'] = 'g:i a';
  /* Field: Long Message */
  $handler->display->display_options['fields']['message_render_1']['id'] = 'message_render_1';
  $handler->display->display_options['fields']['message_render_1']['table'] = 'message';
  $handler->display->display_options['fields']['message_render_1']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render_1']['ui_name'] = 'Long Message';
  $handler->display->display_options['fields']['message_render_1']['label'] = '';
  $handler->display->display_options['fields']['message_render_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['message_render_1']['alter']['text'] = '<span class="message-icon-small [type]"></span>[message_render_1] ([timestamp_1])';
  $handler->display->display_options['fields']['message_render_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message_render_1']['partials'] = 1;
  $handler->display->display_options['fields']['message_render_1']['partials_delta'] = '0';
  $handler->display->display_options['path'] = 'messages/date-group';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'By date';
  $handler->display->display_options['menu']['weight'] = '20';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Messages';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Block - Summary list */
  $handler = $view->new_display('block', 'Block - Summary list', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Site Activity';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More site activity';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Message: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'message';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Field: Long Message */
  $handler->display->display_options['fields']['message_render_1']['id'] = 'message_render_1';
  $handler->display->display_options['fields']['message_render_1']['table'] = 'message';
  $handler->display->display_options['fields']['message_render_1']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render_1']['ui_name'] = 'Long Message';
  $handler->display->display_options['fields']['message_render_1']['label'] = '';
  $handler->display->display_options['fields']['message_render_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['message_render_1']['alter']['text'] = '<span class="message-icon-small [type]"></span>[message_render_1] ([timestamp])';
  $handler->display->display_options['fields']['message_render_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message_render_1']['partials'] = 1;
  $handler->display->display_options['fields']['message_render_1']['partials_delta'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Page - Watched */
  $handler = $view->new_display('page', 'Page - Watched', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Watchlist Activity';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>This view lists the recent site activity that applies specifically to your watchlist. You can manage your watchlist, and other related features, in <a href="/my">My eDesiderata</a>.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_resource_reference_target_id']['id'] = 'field_resource_reference_target_id';
  $handler->display->display_options['relationships']['field_resource_reference_target_id']['table'] = 'field_data_field_resource_reference';
  $handler->display->display_options['relationships']['field_resource_reference_target_id']['field'] = 'field_resource_reference_target_id';
  /* Relationship: Flags: base_node_watch */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['relationship'] = 'field_resource_reference_target_id';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'base_node_watch';
  $handler->display->display_options['path'] = 'my/messages';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My Watched Activity';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-secondary-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['link_field'] = 'view_node';
  $handler->display->display_options['row_options']['description_field'] = 'message_render_1';
  $handler->display->display_options['row_options']['creator_field'] = 'nothing';
  $handler->display->display_options['row_options']['date_field'] = 'timestamp';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'mid',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_resource_reference_target_id']['id'] = 'field_resource_reference_target_id';
  $handler->display->display_options['relationships']['field_resource_reference_target_id']['table'] = 'field_data_field_resource_reference';
  $handler->display->display_options['relationships']['field_resource_reference_target_id']['field'] = 'field_resource_reference_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Message: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'message';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'medium';
  /* Field: Short Message */
  $handler->display->display_options['fields']['message_render_1']['id'] = 'message_render_1';
  $handler->display->display_options['fields']['message_render_1']['table'] = 'message';
  $handler->display->display_options['fields']['message_render_1']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render_1']['ui_name'] = 'Short Message';
  $handler->display->display_options['fields']['message_render_1']['label'] = '';
  $handler->display->display_options['fields']['message_render_1']['alter']['text'] = '<span class="message-icon-small [type]"></span>[message_render_1] ([timestamp])';
  $handler->display->display_options['fields']['message_render_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message_render_1']['partials'] = 1;
  $handler->display->display_options['fields']['message_render_1']['partials_delta'] = '1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_resource_reference_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'field_resource_reference_target_id';
  /* Field: Message: Message ID */
  $handler->display->display_options['fields']['mid']['id'] = 'mid';
  $handler->display->display_options['fields']['mid']['table'] = 'message';
  $handler->display->display_options['fields']['mid']['field'] = 'mid';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'CRL staff';
  $handler->display->display_options['path'] = 'messages/rss';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
    'page_2' => 0,
    'block_1' => 0,
    'page_1' => 0,
  );
  $export['crl_messages'] = $view;

  return $export;
}
