<?php
/**
 * @file
 * crl_local_helpers_feat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crl_local_helpers_feat_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function crl_local_helpers_feat_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
