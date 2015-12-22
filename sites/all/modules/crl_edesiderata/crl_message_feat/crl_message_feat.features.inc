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
  $items['resource_expires_soon'] = entity_import('message_type', '{
    "name" : "resource_expires_soon",
    "description" : "Offers expiring soon",
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
          "value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E: An \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#crl-offers-status\\u0027\\u003Eoffer\\u003C\\/a\\u003E is scheduled to expire in less than 2 weeks.",
          "format" : "literal",
          "safe_value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E: An \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#crl-offers-status\\u0027\\u003Eoffer\\u003C\\/a\\u003E is scheduled to expire in less than 2 weeks."
        },
        {
          "value" : "An \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#crl-offers-status\\u0027\\u003Eoffer\\u003C\\/a\\u003E is scheduled to expire in less than 2 weeks.",
          "format" : "literal",
          "safe_value" : "An \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#crl-offers-status\\u0027\\u003Eoffer\\u003C\\/a\\u003E is scheduled to expire in less than 2 weeks."
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['resource_new'] = entity_import('message_type', '{
    "name" : "resource_new",
    "description" : "New resource entries",
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
          "value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E: Resource entry was added.",
          "format" : "literal",
          "safe_value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E: Resource entry was added."
        },
        {
          "value" : "Resource entry was added.\\r\\n",
          "format" : "literal",
          "safe_value" : "Resource entry was added.\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['resource_new_alert'] = entity_import('message_type', '{
    "name" : "resource_new_alert",
    "description" : "New CRL alerts",
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
          "value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E: CRL staff issued an alert.",
          "format" : "literal",
          "safe_value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E: CRL staff issued an alert."
        },
        {
          "value" : "CRL staff issued an alert.\\r\\n",
          "format" : "literal",
          "safe_value" : "CRL staff issued an alert.\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['resource_new_comment'] = entity_import('message_type', '{
    "name" : "resource_new_comment",
    "description" : "New comments",
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
          "value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E: A new \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#comment-[message:field-comment-reference:cid]\\u0027\\u003Ecomment\\u003C\\/a\\u003E was added.",
          "format" : "literal",
          "safe_value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E: A new \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#comment-[message:field-comment-reference:cid]\\u0027\\u003Ecomment\\u003C\\/a\\u003E was added."
        },
        {
          "value" : "A new \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#comment-[message:field-comment-reference:cid]\\u0027\\u003Ecomment\\u003C\\/a\\u003E was added.\\r\\n",
          "format" : "literal",
          "safe_value" : "A new \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#comment-[message:field-comment-reference:cid]\\u0027\\u003Ecomment\\u003C\\/a\\u003E was added.\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['resource_new_review'] = entity_import('message_type', '{
    "name" : "resource_new_review",
    "description" : "CRL reviews posted",
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
          "value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E: CRL staff posted a new \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#crl-review\\u0027\\u003Ereview\\u003C\\/a\\u003E.",
          "format" : "literal",
          "safe_value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E: CRL staff posted a new \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#crl-review\\u0027\\u003Ereview\\u003C\\/a\\u003E."
        },
        {
          "value" : "CRL staff posted a new \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#crl-review\\u0027\\u003Ereview\\u003C\\/a\\u003E.",
          "format" : "literal",
          "safe_value" : "CRL staff posted a new \\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#crl-review\\u0027\\u003Ereview\\u003C\\/a\\u003E."
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['resource_status_update'] = entity_import('message_type', '{
    "name" : "resource_status_update",
    "description" : "CRL status updates",
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
          "value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E: CRL Status was changed to \\u003Cem\\u003E\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#crl-offers-status\\u0027\\u003E[message:field-activity-crl-status]\\u003C\\/a\\u003E\\u003C\\/em\\u003E.",
          "format" : "literal",
          "safe_value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E: CRL Status was changed to \\u003Cem\\u003E\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#crl-offers-status\\u0027\\u003E[message:field-activity-crl-status]\\u003C\\/a\\u003E\\u003C\\/em\\u003E."
        },
        {
          "value" : "CRL Status was changed to \\u003Cem\\u003E\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#crl-offers-status\\u0027\\u003E[message:field-activity-crl-status]\\u003C\\/a\\u003E\\u003C\\/em\\u003E.\\r\\n",
          "format" : "literal",
          "safe_value" : "CRL Status was changed to \\u003Cem\\u003E\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]#crl-offers-status\\u0027\\u003E[message:field-activity-crl-status]\\u003C\\/a\\u003E\\u003C\\/em\\u003E.\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['resource_suggested'] = entity_import('message_type', '{
    "name" : "resource_suggested",
    "description" : "Resource Suggested",
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
          "value" : "\\u003Ca href=\\u0022\\/resources\\/suggestions\\u0022\\u003EResource Suggestions\\u003C\\/a\\u003E: A new resource was suggested by a CRL member.\\r\\n",
          "format" : "literal",
          "safe_value" : "\\u003Ca href=\\u0022\\/resources\\/suggestions\\u0022\\u003EResource Suggestions\\u003C\\/a\\u003E: A new resource was suggested by a CRL member.\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['resource_update'] = entity_import('message_type', '{
    "name" : "resource_update",
    "description" : "Resource entry updates",
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
          "value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E: Resource entry was updated.",
          "format" : "literal",
          "safe_value" : "\\u003Ca href=\\u0027[message:field-resource-reference:url:absolute]\\u0027\\u003E[message:field-resource-reference:title]\\u003C\\/a\\u003E: Resource entry was updated."
        },
        {
          "value" : "Resource entry was updated.\\r\\n",
          "format" : "literal",
          "safe_value" : "Resource entry was updated.\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
