<?php
/**
 * @file
 * crl_provider_feat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crl_provider_feat_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function crl_provider_feat_node_info() {
  $items = array(
    'provider' => array(
      'name' => t('Provider'),
      'base' => 'node_content',
      'description' => t('All site resources must be linked to one provider. This content type is a container for an individual provider\'s information.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
