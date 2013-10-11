<?php

/**
 * @file
 * Theme related functions for processing output related to crl_resource.
 */


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
function theme_crl_resource_pseudo_field($vars) {
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
  $output .= '</div>';
  return $output;
}


/**
 * Returns HTML for a resoruce status summary field.
 *
 * @param array $vars
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
 */
function theme_crl_resource_field_status_summary($vars) {
  $output = '';
  // Add editor link.
  if (!empty($vars['edit_link'])) {
    $output .= '<p style="text-align: right;"><strong><a href="' . $vars['edit_link'] . '">' . t('Edit activity details') . '</a></strong></p>';
  }
  // Build the status display.
  if (!empty($vars['status'])) {
    $header = array('', t('Status'), t('Current'), t('Description'));
    $rows = array();
    foreach ($vars['status_options'] as $status_key => $text) {
      // Get the status information
      $active_class = 'status-inactive';
      $current = t('no');
      if (in_array($status_key, $vars['status'])) {
        $active_class = 'status-active';
        $current = t('yes');
      }
      // Set values
      $rows[] = array(
        'data' => array(
          '<span class="summary-icon-small ' . $status_key . ' ' . $active_class . '"></span>',
          $text,
          $current,
          $vars['status_descriptions'][$status_key],
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
 * Returns HTML for a publisher-legend field display.
 *
 * @param array $vars
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
 */
function theme_crl_resource_publisher_legend($vars) {
  $icon_img = theme('image', array('path' => drupal_get_path('module', 'crl_helpers') . '/images/icon_publisher.png', 'alt' => $vars['icon_alt_title'], 'title' => $vars['icon_alt_title']));
  return '<div id="publisher-legend">' . $icon_img . ' - ' . $vars['icon_text'] . '</div>';
}


/**
 * Returns HTML for a full resource summary block.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
 */
function theme_crl_resource_summary($vars) {
  $markup = '';
  if (!empty($vars)) {
    $status_options = $vars['status_options'];
    $highlights = array();
    if (!empty($vars['status'])) {
      foreach ($vars['status'] as $status) {
        $highlights['one'][] = '<span class="summary-icon ' . $status . '"></span>' . $status_options[$status];
      }
    }
    $highlights['two'][] = '<span class="big-num">' . $vars['comment_count'] . '</span> Comments';
    $highlights['two'][] = '<span class="big-num">' . $vars['vote_average'] . '</span> Average Rating';
    $highlights['two'][] = '<span class="big-num">' . $vars['interest_count'] . '</span> Interest Count';

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
 * Returns HTML for a "back to index link".
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
*/
function theme_crl_resource_back_to_index(&$vars) {
  $onclick = '';
  if ($vars['browser_back']) {
    $onclick = 'onclick="window.history.go(-1);return false;"';
  }
  return '<p><strong>&larr;&nbsp;<a id="back-to-index" href="' . $vars['url'] . '" ' . $onclick . '>' . t('Back to Index') . '</a></strong></p>';
}


/**
 * Returns HTML for a view resource teaser.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
*/
function theme_crl_resource_teaser(&$vars) {
  $markup = '';
  if (!empty($vars)) {
    $status_options = $vars['status_options'];
    $markup .= '<h2>' . $vars['link'] . '</h2>';
    $markup .= $vars['summary'];
    $markup .= '<div class="teaser-details">';
    $markup .= t('Provider') . ': ' . check_plain($vars['provider']);
    $markup .= '<br/>' . t('Added') . ': ' . $vars['added'];
    $markup .= '<br/>' . t('Updated') . ': ' . $vars['updated'];
    $markup .= '</div>';    
    if (!empty($vars['status'])) {
      $markup .= '<div class="view-teaser-status-icons">';
      foreach ($vars['status'] as $status) {
        $markup .= '<span class="summary-icon-small ' . $status . '" title="' . $vars['status_options'][$status] . '"></span>';
      }
      $markup .= '</div>';
    }
    $markup .= '<div class="clearfix"></div>';
  }
  return $markup;
}