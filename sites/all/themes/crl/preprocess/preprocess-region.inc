<?php
function crl_alpha_preprocess_region(&$vars) {
  $theme = alpha_get_theme();
  $menu_object = menu_get_object();
  if (isset($menu_object->type) && $vars['region'] == 'content') {
    $vars['theme_hook_suggestions'][] = 'region__content__' . $menu_object->type;
    $vars['attributes_array']['class'][] = 'region-content-' . $menu_object->type;
  }
}