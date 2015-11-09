<?php
/**
 * @file
 * crl_resource_feat.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crl_resource_feat_default_rules_configuration() {
  $items = array();
  $items['rules_convert_to_resource'] = entity_import('rules_config', '{ "rules_convert_to_resource" : {
      "LABEL" : "Convert to Resource",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag", "mimemail" ],
      "ON" : { "flag_flagged_resource_suggestion_process" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "flagged-entityform" ],
            "type" : "entityform",
            "bundle" : { "value" : { "resource_suggestion" : "resource_suggestion" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "flagging" ], "field" : "field_provider" } },
        { "entity_has_field" : {
            "entity" : [ "flagging" ],
            "field" : "field_resource_suggestion_status"
          }
        },
        { "data_is" : {
            "data" : [ "flagging:field-resource-suggestion-status" ],
            "value" : "yes"
          }
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "resource",
              "param_title" : [ "flagged-entityform:field-title-sort" ],
              "param_author" : [ "flagging-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "node_unpublish" : { "node" : [ "entity-created" ] } },
        { "data_set" : {
            "data" : [ "entity-created:field-provider" ],
            "value" : [ "flagging:field-provider" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-title-sort" ],
            "value" : [ "flagged-entityform:field-title-sort" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-resource-source-status" ],
            "value" : "stub"
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:body" ],
            "value" : [ "flagged-entityform:field-further-description" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-subject-area" ],
            "value" : [ "flagged-entityform:field-subject-area" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-resource-type" ],
            "value" : [ "flagged-entityform:field-resource-type" ]
          }
        },
        { "entity_save" : { "data" : [ "entity-created" ], "immediate" : "1" } },
        { "data_set" : {
            "data" : [ "flagged-entityform:field-resource-reference" ],
            "value" : [ "entity-created" ]
          }
        },
        { "flag_flagnode" : {
            "flag" : "base_node_watch",
            "node" : [ "entity-created" ],
            "flagging_user" : [ "flagged-entityform:user" ],
            "permission_check" : "0"
          }
        },
        { "flag_flagnode" : {
            "flag" : "email_node_watch",
            "node" : [ "entity-created" ],
            "flagging_user" : [ "flagged-entityform:user" ],
            "permission_check" : "0"
          }
        },
        { "mimemail" : {
            "key" : "resource_suggest_converted",
            "to" : [ "flagged-entityform:user:mail" ],
            "from_name" : "Websystems",
            "from_mail" : "[site:mail]",
            "subject" : "[eDesiderata] Your suggested resource has been added to the site.",
            "body" : "\\u003Cp\\u003EThe message is to inform you that the following eDesiderata resource has been created based on a suggestion that you submitted:\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003E\\u003Ca href=\\u0022[entity-created:url]\\u0022\\u003E[entity-created:title]\\u003C\\/a\\u003E\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EThis resource has automatically been added to your watch list in \\u003Ca href=\\u0022\\/me\\u0022\\u003EmeDesiderata\\u003C\\/a\\u003E.\\u003C\\/p\\u003E",
            "plaintext" : "The message is to inform you that the following eDesiderata resource has been created based on a suggestion that you submitted:\\r\\n\\r\\n[entity-created:title]\\r\\n\\r\\nThis resource has automatically been added to your watch list in meDesiderata",
            "language" : [ "" ]
          }
        },
        { "drupal_message" : { "message" : "The resource suggestion has been converted to a stub and the submitting user has been notified." } },
        { "drupal_message" : {
            "message" : "The new resource stub is currently \\u003Cstrong\\u003Eunpublished\\u003C\\/strong\\u003E. Please make any necessary edits and be sure to publish this resource once it is ready for public display.",
            "type" : "warning"
          }
        },
        { "redirect" : { "url" : [ "entity-created:edit-url" ] } }
      ]
    }
  }');
  return $items;
}
