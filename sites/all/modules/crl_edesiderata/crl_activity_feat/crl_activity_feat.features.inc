<?php
/**
 * @file
 * crl_activity_feat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crl_activity_feat_ctools_plugin_api($module = NULL, $api = NULL) {
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
function crl_activity_feat_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function crl_activity_feat_node_info() {
  $items = array(
    'activity' => array(
      'name' => t('Licensing Cycle'),
      'base' => 'node_content',
      'description' => t('This is a container for CRL offer, status and offer information that relates to a specific resource entry. <strong>You will typically not create new content of this type from the "add content" page and should instead navigate to the resource and click on the related edit link for a new or current licensing cycle</strong>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
