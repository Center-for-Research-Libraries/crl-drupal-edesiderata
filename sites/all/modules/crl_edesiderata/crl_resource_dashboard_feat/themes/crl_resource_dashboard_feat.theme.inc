<?php

/**
 * @file
 * Theme related functions for processing output related to
 * crl_resource_dashboard_feat.
 */


/**
 * Implements hook_preprocess_views_view_fields__resource_dashboard().
 * 
 * Build custom variables for dashboard block rows.
 */
function crl_resource_dashboard_feat_preprocess_views_view_fields__resource_dashboard(&$vars) {
  // Initilaize values for theme.
  $vars['resource_title'] = '';
  $vars['resource_url'] = '';
  $vars['alert_active'] = FALSE;
  $vars['days_left'] = NULL;
  // Search API will have bulk-loaded all of our entities already (based on the
  // main view index and any relationships defined there), so we can work with
  // entity data directly after loading it from the static cache.
  $view = $vars['view'];
  $nid = $view->result[$view->row_index]->entity;
  if (isset($nid)) {
    $indexed_entity = node_load($nid);
    // Get base resource and activity wrappers. Note that the indexed entry
    // may be either a resoruce or activity.
    $wrappers = crl_resource_get_wrappers($indexed_entity);
    $r_entity_wrapper = $wrappers['r_entity_wrapper'];
    // Check alerts.
    $vars['alert_active'] = $r_entity_wrapper->value() ? $r_entity_wrapper->crl_resource_alert->value() : FALSE;
    // Get link.
    $vars['resource_title'] = $r_entity_wrapper->value() ? $r_entity_wrapper->title->value() : '';
    $vars['resource_url'] = $r_entity_wrapper->value() ? $r_entity_wrapper->url->value() : ''; 
    // Check for expiration message, but only on the offer list.
    if ($view->current_display == 'block_2') {
      $vars['days_left'] = isset($r_entity_wrapper->crl_resource_expiration_countdown) ? $r_entity_wrapper->crl_resource_expiration_countdown->value() : NULL;
    }
  }
}


/**
 * Returns HTML for the header of a block on the resources dashboard.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
*/
function theme_crl_resource_dashboard_feat_view_head($vars) {
  $markup = '<div class="dashboard-lead">';
  $markup .= '<h3><a href="' . $vars['url'] . '"><i class="icon icon-' . $vars['status'] . '"></i>' . $vars['title'] . '</a></h3>';
  $markup .= '<a href="' . $vars['url'] . '" class="no-link-style"><span class="super-num">' . $vars['count'] . '</span></a>';
  $markup .= '<p>' . $vars['tagline'];
  $markup .= '<br /><sup>(' . $vars['aux_text'] . ')</sup></p>  </div>';
  $markup .= '<hr>';
  return $markup;
}


/**
 * Returns HTML for the header of a TOP block on the resources dashboard.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
*/
function theme_crl_resource_dashboard_feat_view_head_top($vars) {
  $markup = '<div class="dashboard-lead dashboard-lead-top">';
  $markup .= '<h3><a href="' . $vars['url'] . '">' . $vars['title'] . '</a></h3>';
  $markup .= '<a href="' . $vars['url'] . '" class="no-link-style"><span class="super-num">' . $vars['count'] . '</span></a>';
  $markup .= '</div>';
  return $markup;
}
