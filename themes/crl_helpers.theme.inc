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
    
    $markup .= '<a href="' . url('node/' . $entity->nid) . '"><h2>' . check_plain($entity->title) . '</h2></a>';
    
    $input_form = drupal_render(crl_desiderata_get_input_form($nid));
    if (!empty($input_form)) {
      $markup .= '<div class="view-teaser-input-form">' . $input_form . '</div>';
    }
    $markup .= check_markup($data['abstract'], 'full_html');
    $provider_id = crl_helpers_get_single_node_field($entity, 'field_provider');
    if (isset($provider_id)) {
      $provider = entity_load('node', array($provider_id));
      if (isset($provider[$provider_id])) {
        $markup .= t('Provider') . ': ' . check_plain($provider[$provider_id]->title);
      }
    }
    $markup .= '<br/>' . t('Updated') . ': ' . format_date($entity->changed, 'medium_no_time');
    
    if (!empty($data['status'])) {
      $markup .= '<div class="view-teaser-status-icons">';
      $status_options = crl_helpers_activity_status_property_oplist();
      foreach ($data['status'] as $status) {
        if ($status == 'license_renewal_available' || $status == 'past_license_offer') {
          //continue;
        }
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
    // @TODO: Perhaps split some of this out as a theme hook once the exact 
    // logic is finalized.
    $data = crl_helpers_get_resource_summary($entity);
    $markup .= check_markup($data['abstract'], 'full_html');
    $markup .= '<p><strong>Source: </strong>' . $data['source_text'] . '<p>';
    $highlights = array();
    if (!empty($data['status'])) {
      $status_options = crl_helpers_activity_status_property_oplist();
      foreach ($data['status'] as $status) {
        if ($status == 'license_renewal_available' || $status == 'past_license_offer') {
          //continue;
        }
        $highlights['r1'][] = '<span class="summary-icon ' . $status . '"></span>' . $status_options[$status];
      }
    }
    $highlights['r2'][] = '<span class="big_num">' . $data['comment_count'] . '</span> Comments';
    $highlights['r2'][] = '<span class="big_num">' . $data['subscription_count'] . '</span> Institutions Reporting';
    $highlights['r2'][] = '<span class="big_num">' . $data['vote_average'] . '</span> Average Rating';
    foreach($highlights as $row) {
      foreach ($row as $key => $highlight) {
        $markup .= '<div class="res_highlight">' . $highlight;
        if (isset($row[$key + 1])) {
          $markup .= '<span class="slasher">&nbsp;</span>';
        }
        else {
          $markup .= '<span class="slasher">&nbsp;</span>';
        }
        $markup .= '</div>';
      }
      $markup .= '<div class="clearfix"></div>';
    }
  }
  return $markup;
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
  if (isset($_GET['f']) || isset($_GET['search_api_views_fulltext'])) {
    $glue = "»";
    
    // Get the most recent breadcrumb and strip the first 2 items off (for
    // this case we assume these are "home" and "section")
    $variables['breadcrumb'] = drupal_get_breadcrumb();
    if (count($variables['breadcrumb']) > 2) {
      array_shift($variables['breadcrumb']);
      array_shift($variables['breadcrumb']);
    }

    if (!empty($variables['breadcrumb'])) {  

      $output = '<div id="facet-breadcrumb" class="clearfix"><ul class="breadcrumb"><li><strong>' . t('Your Filters') . ': </strong></li>';
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

      $output .= '</ul></div>';
    }
  }
  return $output;
}
