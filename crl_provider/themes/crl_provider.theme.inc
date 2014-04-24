<?php

/**
 * @file
 * Theme related functions for processing output related to crl_provider.
 */


/**
 * Implements hook_preprocess_views_view_fields__provider_lists().
 * 
 * Build custom variables for resource list rows.
 */
function crl_provider_preprocess_views_view_fields__provider_lists(&$vars) {
  // Initilaize values for theme.
  $vars['provider_title'] = '';
  $vars['provider_url'] = '';
  $vars['summary'] = '';
  $vars['updated'] = '';
  $vars['status'] = array();
  $vars['status_options'] = array();
  $vars['extra'] = '';
  // Search API will have bulk-loaded all of our entities already (based on the
  // main view index and any relationships defined there), so we can work with
  // entity data directly after loading it from the static cache.
  $view = $vars['view'];
  $nid = $view->result[$view->row_index]->entity;
  if (isset($nid)) {
    $indexed_entity = node_load($nid); // From static cache
    // Get base provider wrappers.
    $p_entity_wrapper = entity_metadata_wrapper('node', $indexed_entity);
    // Get link.
    $vars['provider_title'] = isset($p_entity_wrapper->title) ? $p_entity_wrapper->title->value() : '';
    $vars['provider_url'] = isset($p_entity_wrapper->url) ? $p_entity_wrapper->url->value() : ''; 
    // Get summary.
    $body = isset($p_entity_wrapper->body) ? $p_entity_wrapper->body->value() : '';
    $vars['summary'] = $body['value'];
    // Get updated date.
    $updated_stamp = isset($p_entity_wrapper->changed) ? $p_entity_wrapper->changed->value() : 0;
    $updated = format_date($updated_stamp, 'short');
    $vars['updated'] = t('Updated') . ': ' . $updated;
  }
}
