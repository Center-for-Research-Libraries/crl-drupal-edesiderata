<?php

/**
 * @file
 * Theme related functions for processing output related to crl_mydes_feat.
 */


/**
 * Returns HTML for a collapsible saved search form.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
*/
function theme_crl_mydes_feat_save_search_form($variables) {
  $output = '';
  $output .= '<strong><a id="toggle-saved-search" href="javascript:void(0);">Watch this Group</a></strong>';
  $output .= '<div style="display: none;" id="breadcrumb-saved-search">' . drupal_render($variables['block']) . '</div>';
  return $output;
}
