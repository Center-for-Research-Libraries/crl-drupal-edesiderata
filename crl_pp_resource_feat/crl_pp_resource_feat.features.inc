<?php
/**
 * @file
 * crl_pp_resource_feat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crl_pp_resource_feat_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
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
function crl_pp_resource_feat_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function crl_pp_resource_feat_node_info() {
  $items = array(
    'pp_resource' => array(
      'name' => t('Purchase Proposal Resource'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'spp_resource' => array(
      'name' => t('Shared Purchase Proposal Resource'),
      'base' => 'node_content',
      'description' => t('This is a container for the CRL Shared Purchase Proposals.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
