<?php
/**
 * @file
 * crl_user_feat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crl_user_feat_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function crl_user_feat_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
