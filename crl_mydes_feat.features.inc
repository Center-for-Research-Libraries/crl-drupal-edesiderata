<?php
/**
 * @file
 * crl_mydes_feat.features.inc
 */

/**
 * Implements hook_views_api().
 */
function crl_mydes_feat_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function crl_mydes_feat_flag_default_flags() {
  $flags = array();
  // Exported flag: "My eDesiderata".
  $flags['mydes'] = array(
    'entity_type' => 'node',
    'title' => 'My eDesiderata',
    'global' => 0,
    'types' => array(
      0 => 'resource',
    ),
    'flag_short' => '+ My eDesiderata',
    'flag_long' => 'Add to my eDesiderata',
    'flag_message' => 'Added to My eDesiderata',
    'unflag_short' => 'Remove',
    'unflag_long' => 'Remove from My eDesiderata',
    'unflag_message' => 'Removed from My eDesiderata',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'embedded' => 0,
      'diff_standard' => 0,
      'print' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'crl_mydes_feat',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
