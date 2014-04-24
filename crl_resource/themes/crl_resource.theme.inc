<?php

/**
 * @file
 * Theme related functions for processing output related to crl_resource.
 */


/**
 * Implements hook_preprocess_views_view_fields__resource_lists().
 * 
 * Build custom variables for resource list rows.
 */
function crl_resource_preprocess_views_view_fields__resource_lists(&$vars) {
  // Initilaize values for theme.
  $vars['resource_title'] = '';
  $vars['resource_url'] = '';
  $vars['alert_active'] = FALSE;
  $vars['summary'] = '';
  $vars['provider'] = '';
  $vars['updated'] = '';
  $vars['status'] = array();
  $vars['status_options'] = array();
  $vars['days_left'] = NULL;
  $vars['extra'] = '';
  // Search API will have bulk-loaded all of our entities already (based on the
  // main view index and any relationships defined there), so we can work with
  // entity data directly after loading it from the static cache.
  $view = $vars['view'];
  $nid = $view->result[$view->row_index]->entity;
  if (isset($nid)) {
    $indexed_entity = node_load($nid); // From static cache
    // Get base resource and activity wrappers.
    $wrappers = crl_resource_get_wrappers($indexed_entity);
    $r_entity_wrapper = $wrappers['r_entity_wrapper'];
    // Check alerts.
    $vars['alert_active'] = isset($r_entity_wrapper->crl_resource_alert) ? $r_entity_wrapper->crl_resource_alert->value() : FALSE;
    // Get link.
    $vars['resource_title'] = isset($r_entity_wrapper->title) ? $r_entity_wrapper->title->value() : '';
    $vars['resource_url'] = isset($r_entity_wrapper->url) ? $r_entity_wrapper->url->value() : ''; 
    // Get summary.
    $body = isset($r_entity_wrapper->body) ? $r_entity_wrapper->body->value() : '';
    $vars['summary'] = $body['value'];
    // Get provider title.
    $provider = isset($r_entity_wrapper->field_provider) ? $r_entity_wrapper->field_provider->value()->title : '';
    $vars['provider'] = t('Provider') . ': ' . check_plain($provider);
    // Get updated date.
    $updated_stamp = isset($r_entity_wrapper->crl_resource_master_update_timestamp) ? $r_entity_wrapper->crl_resource_master_update_timestamp->value() : 0;
    $updated = format_date($updated_stamp, 'short');
    $vars['updated'] = t('Updated') . ': ' . $updated;
    // Get status info
    $vars['status'] = isset($r_entity_wrapper->crl_resource_status_backref) ? $r_entity_wrapper->crl_resource_status_backref->value() : array();
    $vars['status_options'] = crl_resource_activity_status_property_oplist();
    // Check for expiration message, but only on the offer list.
    $vars['days_left'] = isset($r_entity_wrapper->crl_resource_expiration_countdown) ? $r_entity_wrapper->crl_resource_expiration_countdown->value() : NULL;
    // Integration with crl_mydes_feat to add a watch flag link to each item
    // in the index.
    if (module_exists('crl_mydes_feat') && user_access('crl access member features')) {
      $vars['extra'] = flag_create_link(CRL_WATCH_FLAG, $indexed_entity->nid);
    }
  }
}


/**
 * Implements hook_preprocess_rate_widget__resource_interest().
 * 
 * Build custom variables for the resource interest widget.
 */
function crl_resource_preprocess_rate_widget__resource_interest(&$variables) {
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
  $output .= '</div><div class="clearfix"></div>';
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
    $output .= '<p style="text-align: right;"><strong>' . l(t('Edit CRL Offers & Status'), $vars['edit_link']['path'], $vars['edit_link']['options']) . '</a></strong></p>';
  }
  // Build the status display.
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
function theme_crl_resource_back_to_index(&$vars) {
  $onclick = '';
  if ($vars['browser_back']) {
    $onclick = 'onclick="window.history.go(-1);return false;"';
  }
  return '<strong>&larr;&nbsp;<a id="back-to-index" href="' . $vars['url'] . '" ' . $onclick . '>' . $vars['back_text'] . '</a></strong>';
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


/**
 * Returns HTML for a resource alert "tag".
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
 */
function theme_crl_resource_alert_tag(&$vars) {
  return '<a class="no-link-style" href="' . $vars['url'] . '"><span class="crl-tag alert">alert</span></a>';
}


/**
 * Returns HTML for a resource countdown alert "tag".
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
 */
function theme_crl_resource_countdown_alert_tag(&$vars) {
  $markup = '';
  $expiration_alert = FALSE;
  $days_left = $vars['days_left'];
  if (!is_null($days_left) && $days_left >= 0 && $days_left <= 30) {
    if ($days_left == 0) {
      $expiration_message = t('expiring now');
    }
    elseif ($days_left == 1) {
      $expiration_message = t('expires in 1 day');
    }
    else {
      $expiration_message = t('expires in @days days', array('@days' => $days_left));
    }
    if (!empty($vars['long'])) {
      $expiration_message = t('offer') . ' ' . $expiration_message;
    }
    if ($days_left < 7) {
      $expiration_alert = TRUE;
    }
    $class = 'crl-tag expiration';
    $class .= $expiration_alert ? ' urgent' : '';
    $markup .= '<a class="no-link-style" href="' . $vars['url'] . '"><span class="' . $class . '">' . $expiration_message . '</span></a>';
  }
  return $markup;
}


/**
 * Returns HTML for the alpha facet and sort swither block.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
 */
function theme_crl_resource_alpha_facet_sort(&$vars) {
  // Add the javascript that will trigger the path change on the selection of
  // a new sort option.
  drupal_add_js('jQuery("select#resource_sort_opts").change(function() { window.location = jQuery(this).val(); });', array('type' => 'inline', 'scope' => 'footer'));
  drupal_add_js('jQuery("div#resource_sort_opts_links").toggle(); jQuery("select#resource_sort_opts").toggle();', array('type' => 'inline', 'scope' => 'footer'));
  // Build the sort pulldown. We don't use the Drupal FAPI for this as it's
  // just a simple select list (no real form). Note however that this approach
  // has no "action" logic to process the selected values which means things
  // won't work for users without javascript enabled.
  $output = '';
  if (!empty($vars['form_options'])) {
    $output .= '<select id="resource_sort_opts">';
    foreach ($vars['form_options'] as $path => $details) {
      $output .= '<option ' . ($details['selected'] ? 'selected="selected" ' : '') . 'value="' . $details['url'] . '" title="' . $details['text'] . '">' . $details['text'] . '</option>';
    }
    $output .= '</select>';
    // Also add a pure html version of the toggle for non javascript devices.
    $output .= '<div id="resource_sort_opts_links">';
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