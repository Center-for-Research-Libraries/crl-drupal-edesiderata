<?php
/**
 * @file
 * crl_pp_resource_feat.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function crl_pp_resource_feat_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-pp-main-menu.
  $menus['menu-pp-main-menu'] = array(
    'menu_name' => 'menu-pp-main-menu',
    'title' => 'PP Main menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('PP Main menu');

  return $menus;
}
