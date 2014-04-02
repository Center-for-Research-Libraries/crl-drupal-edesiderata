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
 * Implements hook_node_info().
 */
function crl_activity_feat_node_info() {
  $items = array(
    'activity' => array(
      'name' => t('Resource Offer and Status Details'),
      'base' => 'node_content',
      'description' => t('This is a container for CRL offer, status and offer information that relates to a specific resource entry. <strong>You will typically not create new content of this type from the "add content" page and should instead navigate to the related resource and click on the "Edit offer & status details" link</strong>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
