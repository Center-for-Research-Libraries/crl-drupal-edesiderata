<?php

/**
 * @file
 * crl_pp_resource_feat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crl_pp_resource_feat_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
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
 * Implements hook_default_entityform_type().
 */
function crl_pp_resource_feat_default_entityform_type() {
  $items = array();
  $items['purchase_proposal_nomination'] = entity_import('entityform_type', '{
    "type" : "purchase_proposal_nomination",
    "label" : "Purchase Proposal Nomination",
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
      "submission_text" : { "value" : "", "format" : "full_html" },
      "submission_show_submitted" : 1,
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
        "value" : "\\u003Cdiv class=\\u0022edes-vid-highlight\\u0022\\u003E\\u003Ca href=\\u0022https:\\/\\/www.youtube.com\\/watch?v=DMCHloR0XYY\\u0022 target=\\u0022_blank\\u0022\\u003E\\u003Cimg src=\\u0022\\/sites\\/default\\/files\\/images\\/eDes_vid_tut_thumb.jpg\\u0022 \\/\\u003E\\u003C\\/a\\u003E\\r\\n\\t\\u003Cp\\u003ENomination overview\\u003C\\/p\\u003E\\r\\n\\u003C\\/div\\u003E\\r\\n\\u003Cp\\u003EPlease feel out the below nomination form.\\u0026nbsp;Contact\\u0026nbsp;\\u003Ca href=\\u0022mailto:mwilke@crl.edu\\u0022\\u003EMary Wilke\\u003C\\/a\\u003E with questions or problems related to this form.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003ERequired fields are with asterisks (*)\\u003C\\/p\\u003E\\r\\n",
        "format" : "full_html"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/purchase-proposal-nomination",
        "alias" : "pp\\/nomination",
        "language" : "und"
      }
    }
  }');
  return $items;
}

/**
 * Implements hook_flag_default_flags().
 */
function crl_pp_resource_feat_flag_default_flags() {
  $flags = array();
  // Exported flag: "PP Nomination Convert".
  $flags['entityform_pp_convert'] = array(
    'entity_type' => 'entityform',
    'title' => 'PP Nomination Convert',
    'global' => 1,
    'types' => array(
      0 => 'purchase_proposal_nomination',
    ),
    'flag_short' => 'Copy to new PP Resource',
    'flag_long' => 'Copy the submission to a new Purchase Proposal Resource',
    'flag_message' => 'The submission has been copied to a new Purchase Proposal Resource. Please review and edit the node before publishing.',
    'unflag_short' => 'Remove',
    'unflag_long' => 'This will not delete the Purchase Proposal Resource. ',
    'unflag_message' => 'Removed the flag',
    'unflag_denied_text' => 'Converted',
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
    'flag_confirmation' => 'Are you sure you want to convert this submission to a Purchase Proposal Resource?',
    'unflag_confirmation' => 'This is active for test purpose only!!!',
    'module' => 'crl_pp_resource_feat',
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
