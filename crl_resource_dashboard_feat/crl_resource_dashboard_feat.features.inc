<?php
/**
 * @file
 * crl_resource_dashboard_feat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crl_resource_dashboard_feat_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function crl_resource_dashboard_feat_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
