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
  $nid = $vars['nid'];
  $markup = '';
  $entities = entity_load('node', array($nid)); // Should alerady be in static cache from view
  if (!empty($entities[$nid])) {
    $entity = $entities[$nid];
    $data = crl_helpers_get_resource_summary($entity);
    $markup .= '<h2>' . l($entity->title, 'node/' . $entity->nid) . '</h2>';
    
    if (function_exists('crl_desiderata_get_input_form')) {
      $input_form = drupal_render(crl_desiderata_get_input_form($nid));
      if (!empty($input_form)) {
        $markup .= '<div class="view-teaser-input-form">' . $input_form . '</div>';
      }
    }
    $markup .= $data['abstract'];
    $markup .= '<div class="teaser-details">';
    $provider_id = crl_helpers_get_single_node_field($entity, 'field_provider');
    if (isset($provider_id)) {
      $provider = entity_load('node', array($provider_id));
      if (isset($provider[$provider_id])) {
        $markup .= t('Provider') . ': ' . check_plain($provider[$provider_id]->title);
      }
    }
    $markup .= '<br/>' . t('Updated') . ': ' . format_date($entity->changed, 'medium_no_time');
    $markup .= '<br/>' . t('Added') . ': ' . format_date($entity->created, 'medium_no_time');
    $markup .= '</div>';
    
    if (!empty($data['status'])) {
      $markup .= '<div class="view-teaser-status-icons">';
      $status_options = crl_helpers_activity_status_property_oplist();
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
  $nid = $vars['nid'];
  $markup = '';
  // Load the entity from the nid. This should just reference the static cache
  // as the entity will probably already have been loaded once.
  $entities = entity_load('node', array($nid));
  if (!empty($entities[$nid])) {
    $entity = $entities[$nid];
    $data = crl_helpers_get_resource_summary($entity);
    $markup .= check_markup($data['abstract'], 'full_html');
    if (!isset($_GET['rview'])) {
      $highlights = array();
      if (!empty($data['status'])) {
        $status_options = crl_helpers_activity_status_property_oplist();
        foreach ($data['status'] as $status) {
          $highlights['one'][] = '<span class="summary-icon ' . $status . '"></span>' . $status_options[$status];
        }
      }
      $highlights['two'][] = '<span class="big_num">' . $data['comment_count'] . '</span> Comments';
      $highlights['two'][] = '<span class="big_num">' . $data['des_input_count'] . '</span> Institutions Reporting';
      $highlights['two'][] = '<span class="big_num">' . $data['vote_average'] . '</span> Average Rating';

      foreach($highlights as $row_key => $row) {
        if ($row_key == 'one') {
          $heading = t('CRL Status');
        }
        else {
          $heading = t('Feedback');
        }
        $markup .= '<div class="res_highlight_row ' . $row_key . ' clearfix">';
        $markup .= '<div class="res_highlight_row_label">' . $heading . ':</div>';
        $markup .= '<div class="res_highlight_row_items">';
        foreach ($row as $key => $highlight) {
          $markup .= '<div class="res_highlight">' . $highlight . '</div>';
        }
        $markup .= '</div></div>';
      }
      $markup .= '<p>' . t('Source') . ': ' . $data['source_text'] . '<p>';
    }
    else {
      $markup .= '<p>' . t('View more details for this resource in the ') . l(t('full desiderata resource entry'), current_path()) . '.</p>';
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
  $data = $vars['data'];
  $status_names = $vars['status_names'];
  $output = '';
  // Add editor link.
  if (!empty($vars['edit_link'])) {
    $output .= '<p style="text-align: right;"><strong><a href="' . $vars['edit_link'] . '">' . t('Edit activity details') . '</a></strong></p>';
  }
  // Build the status display.
  if (!empty($data['status'])) {
    foreach ($status_names as $status_key => $text) {
      $active_class = ' status-inactive';
      $des = ' - no';
      if (in_array($status_key, $data['status'])) {
        $active_class = ' status-active';
        $des = ' - yes';
      }
      $output .= '<span class="activity-report' . $active_class . '"><span class="summary-icon-small ' . $status_key . $active_class . '"></span>' . $status_names[$status_key] . $des . '</span><br/>';
    }
    $output .= '<br/><br/>';
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

  if (!empty($variables['breadcrumb'])) {
    $base_path = '/';
    if ($base_url = parse_url($_SERVER['REQUEST_URI'])) {
      $base_path = $base_url['path']; 
    }
    $reset_markup = '<span class="facet-breadcrumb-reset"><a href="' . $base_path . '"><span class="facet-breadcrumb-reset-icon"></span><span class="facet-breadcrumb-label">' . t('New Search') . '</span></a></span>';

    $output .= '<div id="facet-breadcrumb" class="clearfix"><ul class="breadcrumb"><li><span class="facet-breadcrumb-label">' . t('Active Filter Trail') . ': </span></li>';
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
