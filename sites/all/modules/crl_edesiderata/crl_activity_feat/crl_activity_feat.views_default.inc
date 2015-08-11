<?php
/**
 * @file
 * crl_activity_feat.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crl_activity_feat_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'activity_history';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Activity History';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_activity_crl_status' => 'field_activity_crl_status',
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
    'field_activity_crl_status' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Offer posted';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium_no_time';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Offer Duration */
  $handler->display->display_options['fields']['field_activity_offer_duration']['id'] = 'field_activity_offer_duration';
  $handler->display->display_options['fields']['field_activity_offer_duration']['table'] = 'field_data_field_activity_offer_duration';
  $handler->display->display_options['fields']['field_activity_offer_duration']['field'] = 'field_activity_offer_duration';
  $handler->display->display_options['fields']['field_activity_offer_duration']['settings'] = array(
    'format_type' => 'medium_no_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field: CRL Status */
  $handler->display->display_options['fields']['field_activity_crl_status']['id'] = 'field_activity_crl_status';
  $handler->display->display_options['fields']['field_activity_crl_status']['table'] = 'field_data_field_activity_crl_status';
  $handler->display->display_options['fields']['field_activity_crl_status']['field'] = 'field_activity_crl_status';
  $handler->display->display_options['fields']['field_activity_crl_status']['label'] = 'Final Status';
  $handler->display->display_options['fields']['field_activity_crl_status']['delta_offset'] = '0';
  /* Field: Content: Grouping */
  $handler->display->display_options['fields']['field_activity_grouping']['id'] = 'field_activity_grouping';
  $handler->display->display_options['fields']['field_activity_grouping']['table'] = 'field_data_field_activity_grouping';
  $handler->display->display_options['fields']['field_activity_grouping']['field'] = 'field_activity_grouping';
  $handler->display->display_options['fields']['field_activity_grouping']['label'] = 'Groups Eligible';
  $handler->display->display_options['fields']['field_activity_grouping']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_activity_grouping']['delta_offset'] = '0';
  /* Field: Content: Estimated Savings */
  $handler->display->display_options['fields']['field_activity_est_savings']['id'] = 'field_activity_est_savings';
  $handler->display->display_options['fields']['field_activity_est_savings']['table'] = 'field_data_field_activity_est_savings';
  $handler->display->display_options['fields']['field_activity_est_savings']['field'] = 'field_activity_est_savings';
  /* Field: Content: Billing */
  $handler->display->display_options['fields']['field_activity_billing']['id'] = 'field_activity_billing';
  $handler->display->display_options['fields']['field_activity_billing']['table'] = 'field_data_field_activity_billing';
  $handler->display->display_options['fields']['field_activity_billing']['field'] = 'field_activity_billing';
  /* Field: Content: Offer and License Document(s) */
  $handler->display->display_options['fields']['field_activity_license_doc']['id'] = 'field_activity_license_doc';
  $handler->display->display_options['fields']['field_activity_license_doc']['table'] = 'field_data_field_activity_license_doc';
  $handler->display->display_options['fields']['field_activity_license_doc']['field'] = 'field_activity_license_doc';
  $handler->display->display_options['fields']['field_activity_license_doc']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_activity_license_doc']['delta_offset'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Related resource (field_resource_reference) */
  $handler->display->display_options['arguments']['field_resource_reference_target_id']['id'] = 'field_resource_reference_target_id';
  $handler->display->display_options['arguments']['field_resource_reference_target_id']['table'] = 'field_data_field_resource_reference';
  $handler->display->display_options['arguments']['field_resource_reference_target_id']['field'] = 'field_resource_reference_target_id';
  $handler->display->display_options['arguments']['field_resource_reference_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_resource_reference_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_resource_reference_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_resource_reference_target_id']['summary_options']['items_per_page'] = '25';
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
    'activity' => 'activity',
  );
  /* Filter criterion: Field: CRL Status (field_activity_crl_status) */
  $handler->display->display_options['filters']['field_activity_crl_status_value']['id'] = 'field_activity_crl_status_value';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['table'] = 'field_data_field_activity_crl_status';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['field'] = 'field_activity_crl_status_value';
  $handler->display->display_options['filters']['field_activity_crl_status_value']['value'] = array(
    'past_license_offer' => 'past_license_offer',
    'inactive_declined' => 'inactive_declined',
  );
  $export['activity_history'] = $view;

  return $export;
}