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


/**
 * Returns HTML for the alpha facet and sort swither block.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
 */
function theme_crl_helpers_alpha_facet_sort(&$vars) {
  // Add the javascript that will trigger the path change on the selection of
  // a new sort option.
  drupal_add_js('jQuery("select#helpers_sort_opts").change(function() { window.location = jQuery(this).val(); });', array('type' => 'inline', 'scope' => 'footer'));
  drupal_add_js('jQuery("div#helpers_sort_opts_links").toggle(); jQuery("select#helpers_sort_opts").toggle();', array('type' => 'inline', 'scope' => 'footer'));
  // Build the sort pulldown. We don't use the Drupal FAPI for this as it's
  // just a simple select list (no real form). Note however that this approach
  // has no "action" logic to process the selected values which means things
  // won't work for users without javascript enabled.
  $output = '';
  if (!empty($vars['form_options'])) {
    $output .= '<select id="helpers_sort_opts">';
    foreach ($vars['form_options'] as $path => $details) {
      $output .= '<option ' . ($details['selected'] ? 'selected="selected" ' : '') . 'value="' . $details['url'] . '" title="' . $details['text'] . '">' . $details['text'] . '</option>';
    }
    $output .= '</select>';
    // Also add a pure html version of the toggle for non javascript devices.
    $output .= '<div id="helpers_sort_opts_links">';
    foreach ($vars['form_options'] as $path => $details) {
      if ($details['selected']) {
        $output .= '<strong>' . $details['text'] . '</strong><br/>';
      }
      else {
        $output .= l($details['text'], $path) . '<br/>';
      }
    }
    $output .= '</div>';
  }
  // Add the alpha facets block.
  $output .= render($vars['alpha_block']['content']);
  return $output;
}
