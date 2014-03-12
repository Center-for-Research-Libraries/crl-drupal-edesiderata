<?php

/**
 * @file
 * Theme related functions for processing output related to crl_helpers.
 */


/**
 * Returns HTML for a facet breadcrumb.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
*/
function theme_crl_helpers_facet_breadcrumb($variables) {
  $output = '';
  $glue = "»";
  $reset_markup = '<span class="facet-breadcrumb-reset"><a href="' . $variables['base_path'] . '"><span class="facet-breadcrumb-reset-icon"></span><span class="facet-breadcrumb-label">' . t('Reset') . '</span></a></span>';
  $output .= '<div id="facet-breadcrumb" class="clearfix"><ul class="breadcrumb"><li><span class="facet-breadcrumb-label">' . t('Active Filters') . ': </span></li>';
  $switch = array('odd' => 'even', 'even' => 'odd');
  $zebra = 'even';
  $last = count($variables['breadcrumb']) - 1;    
  foreach ($variables['breadcrumb'] as $key => $item) {
    $zebra = $switch[$zebra];
    $attributes['class'] = array('depth-' . ($key + 1), $zebra);
    if ($key == 0) {
      $attributes['class'][] = 'first';
    }
    if ($key == $last) {
      $attributes['class'][] = 'last';
      $glue = '';
    }
    $output .= '<li' . drupal_attributes($attributes) . '>' . $item . ' ' . $glue . '</li>';
  }
  $output .= '</ul>' . $reset_markup . '</div>';
  $output .= $variables['extra'];
  return $output;
}


/**
 * Returns HTML for the editor tools.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
*/
function theme_crl_helpers_editor_tools($variables) {
  $output = '';
  $output .= '<div class="editor-tools"><strong>' . l(t('+ Add Resource'), 'node/add/resource') . '&nbsp;&nbsp;&nbsp;' . l(t('+ Add Provider'), 'node/add/provider') . '<br/>' . l(t('Editor & Admin Dashboard'), 'admin/dashboard') . '</strong></div>';
  $output .= '<p>This page\'s internal path and permalink is:<br /><strong>';
  if (arg(0) == 'node') {
    $output .='<span style="color:green;">/node/' . arg(1) . '</span>'; 
  }
  elseif (!strpos($_GET['q'], "/admin")) {
    $output .= '<span style="color:green;">/' . $_GET['q'] . '</span>';
  }
  else {
    $output .= '<span style="color:red;">/' . $_GET['q'] . ' (no public link available)</span>';
  }
  $output .= '</strong></p><hr />';
  return $output;
}
