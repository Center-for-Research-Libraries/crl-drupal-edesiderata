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
 * Implements hook_default_message_type().
 */
function crl_message_feat_default_message_type() {
  $items = array();
  $items['alert_extended'] = entity_import('message_type', '{
    "name" : "alert_extended",
    "description" : "Alert extended",
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
          "value" : "Alert has been extended for \\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E.",
          "format" : "php_code"
        },
        {
          "value" : "\\u003Cp\\u003Ealert extended\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "eDesiderata-  Alert has been extended for eDesiderata Resource",
          "format" : "php_code"
        },
        {
          "value" : "Dear [current-user:name],\\r\\nAlert has been extended for \\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E in eDesiderata.\\r\\n\\r\\n- eDesiderata Team",
          "format" : "php_code"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['log_activity_update'] = entity_import('message_type', '{
    "name" : "log_activity_update",
    "description" : "Activity Update",
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
          "value" : "\\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E has been updated.",
          "format" : "php_code"
        },
        {
          "value" : "\\u003Cp\\u003EActivity Update\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "eDesiderata: Resource Activity Update\\r\\n",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EeDesiderata: Resource Activity Update\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "Dear [current-user:name],\\r\\n\\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E has been updated.\\r\\n\\r\\n- eDesiderata Team",
          "format" : "php_code"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['log_new_alert'] = entity_import('message_type', '{
    "name" : "log_new_alert",
    "description" : "New Alert",
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
          "value" : "New alert  has been added for \\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E.",
          "format" : "php_code"
        },
        {
          "value" : "\\u003Cp\\u003ENew alert\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "eDesiderata- New Alert for eDesiderata Resource",
          "format" : "php_code"
        },
        {
          "value" : "Dear [current-user:name],\\r\\nThere is a new alert  for \\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E in eDesiderata.\\r\\n\\r\\n- eDesiderata Team",
          "format" : "php_code"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['log_new_comment'] = entity_import('message_type', '{
    "name" : "log_new_comment",
    "description" : "New Comment",
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
          "value" : "A new comment has been added in \\u003Ca href=\\u0027[message:field-message-comment:url:absolute]\\u0027\\u003E[message:field-message-comment:node:title]\\u003C\\/a\\u003E",
          "format" : "php_code"
        },
        {
          "value" : "\\u003Cp\\u003ENew Comment has been added\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "eDesiderata: New Comment has been added\\r\\n",
          "format" : "php_code"
        },
        {
          "value" : "Dear [current-user:name],\\r\\nA new comment has been added in \\u003Ca href=\\u0027[message:field-message-comment:url:absolute]\\u0027\\u003E[message:field-message-comment:node:title]\\u003C\\/a\\u003E\\r\\n\\r\\n- eDesiderata Team",
          "format" : "php_code"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['log_new_resource'] = entity_import('message_type', '{
    "name" : "log_new_resource",
    "description" : "New Resource",
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
          "value" : "\\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E has been added by [message:user:name]",
          "format" : "php_code"
        },
        {
          "value" : "\\u003Cp\\u003EResource has been added\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "eDesiderata: New Resource has been added\\r\\n",
          "format" : "php_code"
        },
        {
          "value" : "Dear [current-user:name],\\r\\n\\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E has been added by [message:user:name].\\r\\n\\r\\n-eDesiderata Team\\r\\n",
          "format" : "php_code"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['log_new_vote'] = entity_import('message_type', '{
    "name" : "log_new_vote",
    "description" : "New Vote",
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
          "value" : "[message:user:name] has voted on \\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E\\r\\n",
          "format" : "php_code"
        },
        {
          "value" : "\\u003Cp\\u003Evoted\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        { "value" : "eDesiderata: New vote \\r\\n", "format" : "php_code" },
        {
          "value" : "Dear,\\r\\n[message:user:name] has voted on \\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E\\r\\n\\r\\n- eDesiderata Team",
          "format" : "php_code"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['log_resource_update'] = entity_import('message_type', '{
    "name" : "log_resource_update",
    "description" : "Resource Update",
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
          "value" : "\\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E has been updated.",
          "format" : "php_code"
        },
        {
          "value" : "\\u003Cp\\u003EUpdated\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "eDesiderata: Resource Update\\r\\n",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EeDesiderata: Resource Update\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "Dear [current-user:name],\\r\\n\\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E has been updated.\\r\\n\\r\\n- eDesiderata Team",
          "format" : "php_code"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['log_status_update'] = entity_import('message_type', '{
    "name" : "log_status_update",
    "description" : "Status Update",
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
          "value" : "CRL Status for \\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E has been updated from [message:field_activity_crl_status] to [message:field-message-activity:field-activity-crl-status]",
          "format" : "php_code"
        },
        {
          "value" : "\\u003Cp\\u003ECRL Status Update\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "eDesiderata: CRL Status Update\\r\\n",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EeDesiderata: CRL Status Update\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "Dear [current-user:name],\\r\\nCRL Status for \\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E has been updated from [message:field_activity_crl_status] to [message:field-message-activity:field-activity-crl-status]\\r\\n\\r\\n- eDesiderata Team",
          "format" : "php_code"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['offer_expiration'] = entity_import('message_type', '{
    "name" : "offer_expiration",
    "description" : "Offer Expiration",
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
          "value" : "CRLOffer for \\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E is expiring soon.",
          "format" : "php_code"
        },
        {
          "value" : "\\u003Cp\\u003Eoffer expiring\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html"
        },
        {
          "value" : "eDesiderata: Resource offer about to expire\\r\\n",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EeDesiderata: Resource offer about to expire\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "Dear [current-user:name],\\r\\nA CRLOffer for \\u003Ca href=\\u0027[message:field-message-content:url:absolute]\\u0027\\u003E[message:field-message-content:title]\\u003C\\/a\\u003E is expiring soon.\\r\\n\\r\\n- eDesiderata Team",
          "format" : "php_code"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
