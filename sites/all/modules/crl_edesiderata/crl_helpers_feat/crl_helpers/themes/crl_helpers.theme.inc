<?php

/**
 * @file
 * Theme related functions for processing output related to crl_helpers.
 */


/**
 * Implements hook_preprocess_crl_helpers_interest_widget().
 *
 * Build custom variables for the interest widget.
 */
function crl_helpers_preprocess_crl_helpers_interest_widget(&$variables) {
  extract($variables);
  $info = array();
  if ($mode == RATE_CLOSED) {
    $info[] = t('Voting is closed.');
  }
  if ($mode != RATE_COMPACT && $mode != RATE_COMPACT_DISABLED) {
    if (isset($results['user_vote'])) {
      $info[] = t('You voted \'@option\'.', array('@option' => t($results['user_vote'])));
      // We also want any status messages set to trickle through as part of an
      // AHAH update.
      if ($just_voted) {
        $messages = drupal_get_messages('status');
        foreach ($messages as $message) {
          $info[] = $message[0];
        }
      }
    }
  }
  $variables['info'] = implode(' ', $info);
}


/**
 * Returns HTML for a vote interest widget.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
*/
function theme_crl_helpers_interest_widget($variables) {
  extract($variables);
  $output = '';
  if ($display_options['description']) {
    $output .= '<p>' . $display_options['description'] . '</p>';
  }

  $yes_button = '<a class="rate-button button" id="rate-button-100" rel="nofollow" href="' . htmlentities($links[0]['href']) . '" title="' . $links[0]['text'] . '">' . '<i class="icon icon-thumbs-up-alt"></i>' . $links[0]['text'] . '</a>';
  $no_button = '<a class="rate-button button" id="rate-button-101" rel="nofollow" href="' . htmlentities($links[1]['href']) . '" title="' . $links[1]['text'] . '">' . '<i class="icon icon-thumbs-down-alt"></i>' . $links[1]['text'] . '</a>';
  $output .= '<p class="interest-input">' . $yes_button . ' ' . $no_button . '</p>';

  if ($info) {
    $output .= '<p class="rate-info interest-vote">' . $info . '</p>';
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
  $output .= '<div class="facet-breadcrumb-content">';
  $output .= '<div class="facet-breadcrumb-facets clearfix">';
  if (count($variables['active_facets'])) {
    $output .= '<div class="active-facet-wrapper facet-breadcrumb-misc">' . t('Active Filters:') . '</div>';
    $output .= '<div class="active-facet-wrapper facet-breadcrumb-reset">' . l('<i class="facet-breadcrumb-reset-icon icon-cancel"></i>' . t('Clear all filters'), $variables['base_path'], array('html' => TRUE)) . '</div>';
    foreach ($variables['active_facets'] as $facet) {
      $output .= '<div class="active-facet-wrapper facet-breadcrumb-facet">' . l('<i class="facet-breadcrumb-reset-icon icon-cancel"></i>', $facet['path'], $facet['options']) . '<span class="facet-breadcrumb-label">' . $facet['text'] . '</span></div>';
    }
  }
  $output .= '<div class="active-facet-wrapper facet-breadcrumb-facet facet-breadcrumb-add"><a href="#region-sidebar-first">' . t('+ Add new filter') . '</a></div>';
  $output .= '</div>';
  $extra = drupal_render($variables['extra']);
  if (!empty($extra)) {
    $output .= '<div class="facet-breadcrumb-extras clearfix">' . $extra . '</div>';
  }
  $output .= '</div>';
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
    $separator = '<span class="field-colon">:</span>&nbsp;';
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
    $status_descriptions = $vars['status_descriptions'];
    $highlights = array();
    if (!empty($vars['status'])) {
      foreach ($vars['status'] as $status) {
        $highlights['one'][] = '<span title="' . $status_descriptions[$status] . '"><i class="icon icon-' . $status . ' icon-large"></i>' . $status_options[$status] . "</span>";
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
      $highlights['two'][] = '<span class="big-num">' . $vars['interest_count_up'] . '</span><i title="Thumbs Up" alt="Thumbs Up" class="icon-large icon-thumbs-up-alt"></i>';
    }
    if (!empty($vars['interest_count_down'])) {
      $highlights['two'][] = '<span class="big-num">' . $vars['interest_count_down'] . '</span><i title="Thumbs Down" alt="Thumbs Down" class="icon-large icon-thumbs-down-alt"></i>';
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
  return '<strong>&larr;&nbsp;&nbsp;<a id="back-to-index" href="' . $vars['url'] . '" ' . $onclick . '>' . $vars['back_text'] . '</a></strong>';
}
