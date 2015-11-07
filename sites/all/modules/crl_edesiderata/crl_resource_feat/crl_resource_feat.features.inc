<?php
/**
 * @file
 * crl_resource_feat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crl_resource_feat_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
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
function crl_resource_feat_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_entityform_type().
 */
function crl_resource_feat_default_entityform_type() {
  $items = array();
  $items['resource_suggestion'] = entity_import('entityform_type', '{
    "type" : "resource_suggestion",
    "label" : "Resource Suggestion",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "",
      "submit_confirm_msg" : "",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "Thank you for your submission",
      "submission_text" : {
        "value" : "\\u003Cp\\u003EThe details of your submission will be reviewed by CRL staff.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022\\/resources\\/suggestions\\u0022\\u003EBrowse all resource suggestions\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
        "format" : "full_html"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "3" : "3",
        "4" : "4",
        "5" : "5",
        "9" : "9",
        "1" : 0,
        "2" : 0,
        "6" : 0,
        "7" : 0,
        "8" : 0,
        "10" : 0,
        "11" : 0,
        "12" : 0,
        "13" : 0,
        "14" : 0,
        "15" : 0,
        "16" : 0,
        "17" : 0,
        "18" : 0,
        "19" : 0,
        "20" : 0,
        "21" : 0,
        "22" : 0,
        "23" : 0
      },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003Cp\\u003EUse the form below to submit a resource suggestion for inclusion in the A-Z Resource index. Submissions will be reviewed by CRL staff before being included in the index.\\u003C\\/p\\u003E\\r\\n",
        "format" : "full_html"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  return $items;
}

/**
 * Implements hook_flag_default_flags().
 */
function crl_resource_feat_flag_default_flags() {
  $flags = array();
  // Exported flag: "Resource Suggestion Process".
  $flags['resource_suggestion_process'] = array(
    'entity_type' => 'entityform',
    'title' => 'Resource Suggestion Process',
    'global' => 1,
    'types' => array(
      0 => 'resource_suggestion',
    ),
    'flag_short' => 'Process this Resource Suggestion',
    'flag_long' => 'Process (Accept or Reject) this Resource Suggestion',
    'flag_message' => 'The submission has been processed',
    'unflag_short' => 'Unprocess',
    'unflag_long' => 'This will not remove the converted Resource. ',
    'unflag_message' => 'Removed the flag',
    'unflag_denied_text' => 'Processed',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'email' => 0,
      'confirmation' => 0,
      'download' => 0,
      'table' => 0,
      'review' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'flag_confirmation' => 'Process this Resource Suggestion',
    'unflag_confirmation' => 'This is active for test purpose only!!!',
    'module' => 'crl_resource_feat',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function crl_resource_feat_node_info() {
  $items = array(
    'resource' => array(
      'name' => t('Resource'),
      'base' => 'node_content',
      'description' => t('This is the main container for a site resource.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
