<?php
/**
 * @file
 * crl_mydes_feat.delta.inc
 */

/**
 * Implements hook_delta_default_templates().
 */
function crl_mydes_feat_delta_default_templates() {
  $export = array();

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'mydes_dashboard';
  $delta->name = 'My eDes Dashboard';
  $delta->description = '';
  $delta->theme = 'crl';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_crl_settings' => array(
      'alpha_debug_grid_roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
        7 => 0,
        8 => 0,
        9 => 0,
        10 => 0,
        11 => 0,
        12 => 0,
        13 => 0,
        14 => 0,
        15 => 0,
        16 => 0,
        17 => 0,
        18 => 0,
        19 => 0,
        20 => 0,
        21 => 0,
        22 => 0,
        23 => 0,
      ),
      'alpha_region_preface_second_columns' => '6',
      'alpha_region_user_second_columns' => '6',
      'alpha_region_postscript_fourth_zone' => NULL,
      'alpha_region_postscript_fourth_equal_height_element' => FALSE,
      'alpha_zone_content_force' => 0,
      'alpha_zone_content_order' => 0,
      'alpha_zone_content_weight' => '1',
      'alpha_region_sidebar_first_columns' => '4',
      'alpha_region_sidebar_second_columns' => '4',
      'alpha_region_content_columns' => '4',
      'alpha_zone_preface_weight' => '2',
      'alpha_zone_preface_equal_height_container' => 1,
      'alpha_region_preface_first_equal_height_element' => 1,
      'alpha_region_postscript_first_columns' => '6',
      'alpha_region_postscript_second_columns' => '6',
      'alpha_region_postscript_third_zone' => NULL,
      'alpha_region_postscript_third_columns' => '4',
      'alpha_zone_user_weight' => '4',
    ),
  );
  $export['mydes_dashboard'] = $delta;

  return $export;
}
