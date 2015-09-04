<?php
function crl_alpha_preprocess_region(&$vars) {
  $theme = alpha_get_theme();
  $menu_object = menu_get_object();
  if (isset($menu_object->type) && $vars['region'] == 'content') {
    $vars['theme_hook_suggestions'][] = 'region__content__' . $menu_object->type;
    $vars['attributes_array']['class'][] = 'region-content-' . $menu_object->type;
  }
  // For a more modular layout we place the title info inside the branding
  // region, so we need to set the appropriate variables.
  if ($vars['region'] == 'branding') {
    $vars['title_prefix'] = $theme->page['title_prefix'];
    $vars['title'] = $theme->page['title'];
    $vars['title_suffix'] = $theme->page['title_suffix'];
    $vars['title_hidden'] = $theme->page['title_hidden'];
  }
  // Hide the title on the homepage.
  if (drupal_is_front_page()) {
    $vars['title_hidden'] = TRUE;
  }
}