<?php
/**
 * @file
 * crl_helpers_feat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crl_helpers_feat_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
