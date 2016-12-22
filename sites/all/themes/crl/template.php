<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */


// Facet API: Adjust theme function that builds facet links to exclude count 
// value in some cases. Also add span to support icon additions to select
// facet terms
function crl_facetapi_link_inactive($variables) {
  $icon_span = '';
  if (function_exists('crl_resource_activity_status_property_oplist')) {
    $status_options = crl_resource_activity_status_property_oplist();
    $status = array_search(t($variables['text']), $status_options);
    if ($status) {
      $icon_span = '<i class="icon icon-' . $status . '"></i>';
    }
  }
  // Builds accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => FALSE,
  );
  $accessible_markup = theme('facetapi_accessible_markup', $accessible_vars);

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $variables['text'] = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Style the count part of the link so we can manipulate it better with css
  if (isset($variables['count'])) {
    $variables['text'] .= '<span class="facetapi_count_value"> ' . theme('facetapi_count', $variables) . '</span>';
  }
  
  // Manipulate the link text for formatting
  $variables['text'] = $icon_span . '<span class="facet_api_text">' . $variables['text'] . '</span>';

  // Resets link text, sets to options to HTML since we already sanitized the
  // link text and are providing additional markup for accessibility.
  $variables['text'] .= $accessible_markup;
  $variables['options']['html'] = TRUE;
  return theme_link($variables);
}


// Facet API: Also process active items.
function crl_facetapi_link_active($variables) {
  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];
  
  // Manipulate the link text for formatting
  $link_text = '<span class="facet_api_text">' . $link_text . '</span>';

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_deactivate_widget' => theme('facetapi_deactivate_widget', $variables),
    '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
  );
  $variables['text'] = t('!facetapi_deactivate_widget !facetapi_accessible_markup', $replacements);
  $variables['options']['html'] = TRUE;
  return theme_link($variables) . $link_text;
}


// Facet API: Tweaks the decativate text/button that appears next to active item.
function crl_facetapi_deactivate_widget($variables) {
  return '<i class="icon icon-cancel"></i>';
}


// Delta Blocks: Add "»" glue between breadcrumb items 
function crl_delta_blocks_breadcrumb($variables) {
  $output = '';
  $glue = "»";
   
  if (!empty($variables['breadcrumb'])) {  
    if ($variables['breadcrumb_current']) {
      $variables['breadcrumb'][] = l(drupal_get_title(), current_path(), array('html' => TRUE));
    }
  
    $output = '<div id="breadcrumb" class="clearfix"><ul class="breadcrumb">';
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
  
  return $output;
}


// CORE Fields: Adjust rendering of fields and field labels to allow the colon
// part of the label to be controlled in CSS.
function crl_field($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . '<span class="field-colon">:</span>&nbsp;</div>';
  }

  // Render the items.
  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}


// CORE: Move the field description text above the field for WYSIWYG text
// areas that go thorugh theme_text_format_wrapper().
function crl_text_format_wrapper($variables) {
  $element = $variables['element'];
  
  // Move the description after the first label if one is found. This is very
  // much a hack. 
  if (!empty($element['#description'])) {
    if (strpos($element['#children'], '</label>')) {
      $description = '<div class="description">' . $element['#description'] . '</div>';
      $element['#children'] = preg_replace('/<\/label>/', '</label>' . $description, $element['#children'], 1);
      unset($element['#description']);
    }
  }
  
  // Complete the rest of the theme function normally.
  $output = '<div class="text-format-wrapper">';
  $output .= $element['#children'];
  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . '</div>';
  }
  $output .= "</div>\n";

  return $output;
}


/**
 * Implements hook_comment_view_alter().
 * 
 * Add a custom nesting wrapper that includes the initial comment and all its
 * replies. Core adds indent wrappers that work fine for each specific level of
 * reply, but no wrapper that includes the comment itself. Due to the way core
 * handles the markup related to comment indents, we need to work directly on
 * the render array for each comment as opposed to altering, or pre-processing,
 * any comment-specific theme functions. Note that alter hooks are allowed
 * inside theme functions (unlike normal module hooks). 
 */
function crl_comment_view_alter(&$build, $type) {
  // Don't do anything if this is not a node comment.
  if (!isset($build['#node']->nid)) {
    return;
  }
  static $processed_first_comment = array();
  // We will open and close our nesting wrapper only on top-level comments.
  if (isset($build['#comment']->depth) && $build['#comment']->depth == 0) {
    // Strip newlines in the prefix as they can totally mess up our regex.
    $build['#prefix'] = str_replace(array("\r", "\n"), '', $build['#prefix']);
    // Every top-level comment needs to CLOSE the nesting wrapper from the
    // previous comment/group (with the exception of the first comment).
    if (!empty($processed_first_comment[$build['#node']->nid])) {
      // Using #prefix for this is ugly, but that's what core does when setting
      // indents, so we follow suit so as not to break indent nesting.
      $build['#prefix'] = preg_replace('/^(<a id="new"><\/a>)*/', '$0</div>', $build['#prefix']);
    }
    // Every top level comment needs to OPEN a nesting wrapper. This too
    // requires special care so as not to disturb core's indent wrapping.
    $build['#prefix'] = preg_replace('/^(<a id="new"><\/a>)?(<\/div>)*/', '$0<div class="comment-nested-wrapper">', $build['#prefix']);
    $processed_first_comment[$build['#node']->nid] = TRUE;
  }
  // The final comment also needs to close our nesting wrapper. In this case we
  // use the suffix.
  if (isset($build['#comment']->divs_final)) {
    $suffix = !empty($build['#suffix']) ? $build['#suffix'] : '';
    $suffix = $suffix . '</div>';
    $build['#suffix'] = $suffix;
  }
}
