<?php
/**
 * @file
 * crl_resource_dashboard_feat.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crl_resource_dashboard_feat_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'resource_dashboard';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_title_search_index';
  $view->human_name = 'Resource Dashboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Sort criterion: Indexed Node: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resource' => 'resource',
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );

  /* Display: A-Z - Main */
  $handler = $view->new_display('block', 'A-Z - Main', 'block_4');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = ' ';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';

  /* Display: Reviews - Main */
  $handler = $view->new_display('block', 'Reviews - Main', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resource' => 'resource',
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed Node: CRL Resource Status Backreference */
  $handler->display->display_options['filters']['crl_resource_status_backref']['id'] = 'crl_resource_status_backref';
  $handler->display->display_options['filters']['crl_resource_status_backref']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['filters']['crl_resource_status_backref']['field'] = 'crl_resource_status_backref';
  $handler->display->display_options['filters']['crl_resource_status_backref']['value'] = array(
    'crl_review_available' => 'crl_review_available',
  );

  /* Display: Offers - Main */
  $handler = $view->new_display('block', 'Offers - Main', 'block_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Related resource */
  $handler->display->display_options['fields']['field_resource_reference']['id'] = 'field_resource_reference';
  $handler->display->display_options['fields']['field_resource_reference']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['fields']['field_resource_reference']['field'] = 'field_resource_reference';
  $handler->display->display_options['fields']['field_resource_reference']['label'] = '';
  $handler->display->display_options['fields']['field_resource_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resource_reference']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_resource_reference']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_resource_reference']['bypass_access'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Offer Duration: End date (indexed) */
  $handler->display->display_options['sorts']['field_activity_offer_duration_value2']['id'] = 'field_activity_offer_duration_value2';
  $handler->display->display_options['sorts']['field_activity_offer_duration_value2']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['sorts']['field_activity_offer_duration_value2']['field'] = 'field_activity_offer_duration_value2';
  /* Sort criterion: Indexed Node: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'activity' => 'activity',
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed Node: CRL Status */
  $handler->display->display_options['filters']['field_activity_crl_status']['id'] = 'field_activity_crl_status';
  $handler->display->display_options['filters']['field_activity_crl_status']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['filters']['field_activity_crl_status']['field'] = 'field_activity_crl_status';
  $handler->display->display_options['filters']['field_activity_crl_status']['value'] = array(
    'license_available' => 'license_available',
    'trial_access_available' => 'trial_access_available',
    'license_renewal_available' => 'license_renewal_available',
  );

  /* Display: Pipeline - Main */
  $handler = $view->new_display('block', 'Pipeline - Main', 'block_3');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Related resource */
  $handler->display->display_options['fields']['field_resource_reference']['id'] = 'field_resource_reference';
  $handler->display->display_options['fields']['field_resource_reference']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['fields']['field_resource_reference']['field'] = 'field_resource_reference';
  $handler->display->display_options['fields']['field_resource_reference']['label'] = '';
  $handler->display->display_options['fields']['field_resource_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resource_reference']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_resource_reference']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_resource_reference']['bypass_access'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'activity' => 'activity',
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed Node: CRL Status */
  $handler->display->display_options['filters']['field_activity_crl_status']['id'] = 'field_activity_crl_status';
  $handler->display->display_options['filters']['field_activity_crl_status']['table'] = 'search_api_index_title_search_index';
  $handler->display->display_options['filters']['field_activity_crl_status']['field'] = 'field_activity_crl_status';
  $handler->display->display_options['filters']['field_activity_crl_status']['value'] = array(
    'crl_desiderata' => 'crl_desiderata',
    'license_under_consideration' => 'license_under_consideration',
  );
  $export['resource_dashboard'] = $view;

  return $export;
}
