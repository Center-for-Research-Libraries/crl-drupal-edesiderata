<?php

/**
 * @file
 * Theme related functions for processing output related to crl_helpers.
 */


/**
 * Returns HTML for a view resource teaser.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
*/
function theme_crl_helpers_resource_teaser(&$vars) {
  $markup = '';
  $entity = $vars['resource_entity'];
  $data = $entity->resource_summary;
  $provider_entity = $vars['provider_entity'];
  if (!empty($data)) {
    $status_options = $data['status_options'];
    $markup .= '<h2>' . l($entity->title, 'node/' . $entity->nid) . '</h2>';
    $input_form = '';
    if (!empty($input_form)) {
      $markup .= '<div class="view-teaser-input-form">' . $input_form . '</div>';
    }
    $markup .= $data['abstract'];
    $markup .= '<div class="teaser-details">';
    $markup .= t('Provider') . ': ' . check_plain($provider_entity->title);
    $markup .= '<br/>' . t('Updated') . ': ' . format_date($entity->changed, 'medium_no_time');
    $markup .= '<br/>' . t('Added') . ': ' . format_date($entity->created, 'medium_no_time');
    $markup .= '</div>';
    
    if (!empty($data['status'])) {
      $markup .= '<div class="view-teaser-status-icons">';
      foreach ($data['status'] as $status) {
        $markup .= '<span class="summary-icon-small ' . $status . '" title="' . $status_options[$status] . '"></span>';
      }
      $markup .= '</div>';
    }
    $markup .= '<div class="clearfix"></div>';
  }
  return $markup;
}


/**
 * Returns HTML for a full resource summary.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
*/
function theme_crl_helpers_resource_summary($vars) {
  $markup = '';
  $data = $vars['entity']->resource_summary;
  if (!empty($data)) {
    $status_options = $data['status_options'];
    $highlights = array();
    if (!empty($data['status'])) {
      foreach ($data['status'] as $status) {
        $highlights['one'][] = '<span class="summary-icon ' . $status . '"></span>' . $status_options[$status];
      }
    }
    $highlights['two'][] = '<span class="big-num">' . $data['comment_count'] . '</span> Comments';
    $highlights['two'][] = '<span class="big-num">' . $data['vote_average'] . '</span> Average Rating';

    foreach($highlights as $row_key => $row) {
      if ($row_key == 'one') {
        $heading = t('CRL Status');
      }
      else {
        $heading = t('Feedback');
      }
      $markup .= '<div class="res-highlight-row ' . $row_key . ' clearfix">';
      $markup .= '<div class="res-highlight-row-label">' . $heading . ':</div>';
      $markup .= '<div class="res-highlight-row-tems">';
      foreach ($row as $key => $highlight) {
        $markup .= '<div class="res-highlight">' . $highlight . '</div>';
      }
      $markup .= '</div></div>';
    }
  }
  return $markup;
}


/**
 * Returns HTML for a resoruce status summary field.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
*/
function theme_crl_helpers_resource_status_summary($vars) {
  $data = $vars['entity']->resource_summary;
  $output = '';
  // Add editor link.
  if (!empty($vars['edit_link'])) {
    $output .= '<p style="text-align: right;"><strong><a href="' . $vars['edit_link'] . '">' . t('Edit activity details') . '</a></strong></p>';
  }
  // Build the status display.
  if (!empty($data['status'])) {
    $header = array('', t('Status'), t('Current'), t('Description'));
    $rows = array();
    foreach ($data['status_options'] as $status_key => $text) {
      // Get the status information
      $active_class = 'status-inactive';
      $current = t('no');
      if (in_array($status_key, $data['status'])) {
        $active_class = 'status-active';
        $current = t('yes');
      }
      // Set values
      $rows[] = array(
        'data' => array(
          '<span class="summary-icon-small ' . $status_key . ' ' . $active_class . '"></span>',
          $text,
          $current,
          $data['status_descriptions'][$status_key],
        ),
        'class' => $active_class,
        'no_striping' => TRUE,
      );
    }
    $output .= '<div id="status-summary">';
    $output .= theme('table', array('header' => $header, 'rows' => $rows));
    $output .= '</div>';
  }
  return $output;
}


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

  // Get the most recent breadcrumb and strip the first 2 items off (for
  // this case we assume these are "home" and "section")
  $variables['breadcrumb'] = drupal_get_breadcrumb();
  // Drop the "home" value for the breadcrumb
  array_shift($variables['breadcrumb']);

  if (!empty($variables['breadcrumb'])) {
    $base_path = '/';
    if ($base_url = parse_url($_SERVER['REQUEST_URI'])) {
      $base_path = $base_url['path']; 
    }
    $reset_markup = '<span class="facet-breadcrumb-reset"><a href="' . $base_path . '"><span class="facet-breadcrumb-reset-icon"></span><span class="facet-breadcrumb-label">' . t('Reset') . '</span></a></span>';
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
  }
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
  $output .= '<div class="editor-tools"><strong>' . l(t('+ Add Content'), 'node/add') . '<br/>' . l(t('Editor Dashboard'), 'admin/dashboard') . '</strong></div>';
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
  return '<p><strong>←&nbsp;<a href="' . $vars['url'] . '" ' . $onclick . '>' . t('Back to Index') . '</a></strong></p>';
}