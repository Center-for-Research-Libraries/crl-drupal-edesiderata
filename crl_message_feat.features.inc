<?php
/**
 * @file
 * crl_message_feat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crl_message_feat_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function crl_message_feat_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function crl_message_feat_flag_default_flags() {
  $flags = array();
  // Exported flag: "Email watch".
  $flags['email_node_watch'] = array(
    'entity_type' => 'node',
    'title' => 'Email watch',
    'global' => 0,
    'types' => array(
      0 => 'resource',
    ),
    'flag_short' => 'Send Email',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Don\'t send Email',
    'unflag_long' => '',
    'unflag_message' => '',
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
    'module' => 'crl_message_feat',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_default_message_type().
 */
function crl_message_feat_default_message_type() {
  $items = array();
  $items['resource_new'] = entity_import('message_type', '{
    "name" : "resource_new",
    "description" : "Resource new",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was added.",
          "format" : "literal",
          "safe_value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was added."
        },
        {
          "value" : "Resource was added.\\r\\n",
          "format" : "literal",
          "safe_value" : "Resource was added.\\n"
        },
        {
          "value" : "eDesiderata: New Resource was added\\r\\n",
          "format" : "literal",
          "safe_value" : "eDesiderata: New Resource was added\\n"
        },
        {
          "value" : "Dear [current-user:name],\\r\\n\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was added.\\r\\n\\r\\n-eDesiderata Team\\r\\n",
          "format" : "literal",
          "safe_value" : "Dear [current-user:name],\\n\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was added.\\n\\n-eDesiderata Team\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['resource_new_alert'] = entity_import('message_type', '{
    "name" : "resource_new_alert",
    "description" : "Resource new alert",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "CRL staff issued an alert on \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E.",
          "format" : "literal",
          "safe_value" : "CRL staff issued an alert on \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E."
        },
        {
          "value" : "New alert issued by CRL staff.\\r\\n",
          "format" : "literal",
          "safe_value" : "New alert issued by CRL staff.\\n"
        },
        {
          "value" : "eDesiderata- New Alert for eDesiderata Resource",
          "format" : "literal",
          "safe_value" : "eDesiderata- New Alert for eDesiderata Resource"
        },
        {
          "value" : "Dear [current-user:name],\\r\\nCRL staff issued an alert on \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E in eDesiderata.\\r\\n\\r\\n- eDesiderata Team",
          "format" : "literal",
          "safe_value" : "Dear [current-user:name],\\nCRL staff issued an alert on \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E in eDesiderata.\\n\\n- eDesiderata Team"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['resource_new_comment'] = entity_import('message_type', '{
    "name" : "resource_new_comment",
    "description" : "Resource new comment",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "A new comment was added to \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E",
          "format" : "literal",
          "safe_value" : "A new comment was added to \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E"
        },
        {
          "value" : "New comment was added.\\r\\n",
          "format" : "literal",
          "safe_value" : "New comment was added.\\n"
        },
        {
          "value" : "eDesiderata: New Comment was added\\r\\n",
          "format" : "literal",
          "safe_value" : "eDesiderata: New Comment was added\\n"
        },
        {
          "value" : "Dear [current-user:name],\\r\\nA new comment was added in \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E\\r\\n\\r\\n- eDesiderata Team",
          "format" : "literal",
          "safe_value" : "Dear [current-user:name],\\nA new comment was added in \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E\\n\\n- eDesiderata Team"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['resource_new_review'] = entity_import('message_type', '{
    "name" : "resource_new_review",
    "description" : "Resource new review",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "CRL staff issued a new review for \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E.",
          "format" : "literal",
          "safe_value" : "CRL staff issued a new review for \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E."
        },
        {
          "value" : "New review issued by CRL staff.",
          "format" : "literal",
          "safe_value" : "New review issued by CRL staff."
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['resource_status_update'] = entity_import('message_type', '{
    "name" : "resource_status_update",
    "description" : "Resource status update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was updated and CRL Status changed to \\u003Cem\\u003E[message:field-activity-crl-status]\\u003C\\/em\\u003E.",
          "format" : "literal",
          "safe_value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was updated and CRL Status changed to \\u003Cem\\u003E[message:field-activity-crl-status]\\u003C\\/em\\u003E."
        },
        {
          "value" : "Resource was updated and CRL Status changed to \\u003Cem\\u003E[message:field-activity-crl-status]\\u003C\\/em\\u003E.\\r\\n",
          "format" : "literal",
          "safe_value" : "Resource was updated and CRL Status changed to \\u003Cem\\u003E[message:field-activity-crl-status]\\u003C\\/em\\u003E.\\n"
        },
        {
          "value" : "eDesiderata: CRL Status Update\\r\\n",
          "format" : "literal",
          "safe_value" : "eDesiderata: CRL Status Update\\n"
        },
        {
          "value" : "Dear [current-user:name],\\r\\n\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was updated and CRL Status changed to [message:field-activity-crl-status].\\r\\n\\r\\n- eDesiderata Team",
          "format" : "literal",
          "safe_value" : "Dear [current-user:name],\\n\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was updated and CRL Status changed to [message:field-activity-crl-status].\\n\\n- eDesiderata Team"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['resource_update'] = entity_import('message_type', '{
    "name" : "resource_update",
    "description" : "Resource update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was updated.",
          "format" : "literal",
          "safe_value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was updated."
        },
        {
          "value" : "Resource was updated.\\r\\n",
          "format" : "literal",
          "safe_value" : "Resource was updated.\\n"
        },
        {
          "value" : "eDesiderata: Resource Update\\r\\n",
          "format" : "literal",
          "safe_value" : "eDesiderata: Resource Update\\n"
        },
        {
          "value" : "Dear [current-user:name],\\r\\n\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was updated.\\r\\n\\r\\n- eDesiderata Team",
          "format" : "literal",
          "safe_value" : "Dear [current-user:name],\\n\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was updated.\\n\\n- eDesiderata Team"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['resource_update_activity'] = entity_import('message_type', '{
    "name" : "resource_update_activity",
    "description" : "Resource update activity",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was updated (CRL Activity).",
          "format" : "literal",
          "safe_value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was updated (CRL Activity)."
        },
        {
          "value" : "Resource was updated (CRL Activity).\\r\\n",
          "format" : "literal",
          "safe_value" : "Resource was updated (CRL Activity).\\n"
        },
        {
          "value" : "eDesiderata: Resource Update\\r\\n",
          "format" : "literal",
          "safe_value" : "eDesiderata: Resource Update\\n"
        },
        {
          "value" : "Dear [current-user:name],\\r\\n\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was updated (CRL Activity).\\r\\n\\r\\n- eDesiderata Team",
          "format" : "literal",
          "safe_value" : "Dear [current-user:name],\\n\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E was updated (CRL Activity).\\n\\n- eDesiderata Team"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
