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


/**
 * Returns HTML for a generic pseudo field display. This provides a very quick
 * and dirty way to theme a "field" without constructing lots of theme
 * variables.
 *
 * @param array $vars
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
 */
function theme_crl_helpers_pseudo_field($vars) {
  $class = 'field-label-above';
  $separator = '';
  if (!empty($vars['inline'])) {
    $class = 'field-label-inline';
    $separator = ':&nbsp;';
  }
  $output = '<div class="field ' . $class . '">';
  if (!empty($vars['label'])) {
    $output .= '<div class="field-label">' . $vars['label'] . $separator . '</div>';
  }
  $output .= '<div class="field-item even">' . $vars['output'] . '</div>';
  $output .= '</div><div class="clearfix"></div>';
  return $output;
}


/**
 * Returns HTML for a full entry summary block.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
 */
function theme_crl_helpers_summary($vars) {
  $markup = '';
  if (!empty($vars)) {
    // Get status row.
    $status_options = $vars['status_options'];
    $highlights = array();
    if (!empty($vars['status'])) {
      foreach ($vars['status'] as $status) {
        $highlights['one'][] = '<span class="summary-icon ' . $status . '"></span>' . $status_options[$status];
      }
    }
    // Get feedback row.
    if (!empty($vars['comment_count'])) {
      $highlights['two'][] = '<span class="big-num">' . $vars['comment_count'] . '</span> ' . t('User comments');
    }
    if (!empty($vars['vote_average'])) {
      $highlights['two'][] = '<span class="big-num">' . $vars['vote_average'] . '</span> ' . t('Average Rating');
    }
    if (!empty($vars['interest_count_up'])) {
      $highlights['two'][] = '<span class="big-num">' . $vars['interest_count_up'] . '</span><span title="Thumbs Up" alt="Thumbs Up" class="crl-icon-small thumbsup-icon-dark"></span>';
    }
    if (!empty($vars['interest_count_down'])) {
      $highlights['two'][] = '<span class="big-num">' . $vars['interest_count_down'] . '</span><span title="Thumbs Down" alt="Thumbs Down" class="crl-icon-small thumbsdown-icon-dark"></span>';
    }
    foreach($highlights as $row_key => $row) {
      if ($row_key == 'one') {
        $heading = t('CRL Status');
      }
      else {
        $heading = t('Feedback');
      }
      $markup .= '<div class="res-highlight-row ' . $row_key . ' clearfix">';
      $markup .= '<div class="res-highlight-row-label">' . $heading . ':</div>';
      $markup .= '<div class="res-highlight-row-items">';
      foreach ($row as $key => $highlight) {
        $markup .= '<div class="res-highlight">' . $highlight . '</div>';
      }
      $markup .= '</div></div>';
    }
  }
  return $markup;
}


/**
 * Returns HTML for a "back to index link".
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
 */
function theme_crl_helpers_back_to_index(&$vars) {
  $onclick = '';
  if ($vars['browser_back']) {
    $onclick = 'onclick="window.history.go(-1);return false;"';
  }
  return '<strong>&larr;&nbsp;<a id="back-to-index" href="' . $vars['url'] . '" ' . $onclick . '>' . $vars['back_text'] . '</a></strong>';
}