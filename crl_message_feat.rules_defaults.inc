<?php
/**
 * @file
 * crl_message_feat.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crl_message_feat_default_rules_configuration() {
  $items = array();
  $items['rules_message_email_notification'] = entity_import('rules_config', '{ "rules_message_email_notification" : {
      "LABEL" : "Message Email Notification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "crl_message_feat", "message" ],
      "ON" : { "message_insert" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "message" ], "field" : "field_resource_reference" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "message:field-resource-reference" ],
            "type" : "node",
            "bundle" : { "value" : { "resource" : "resource" } }
          }
        },
        { "OR" : [
            { "NOT data_is" : { "data" : [ "message:type" ], "value" : "resource_new_vote" } }
          ]
        }
      ],
      "DO" : [ { "crl_message_feat_process" : { "message" : [ "message" ] } } ]
    }
  }');
  $items['rules_message_resource_new_comment'] = entity_import('rules_config', '{ "rules_message_resource_new_comment" : {
      "LABEL" : "Message resource new comment",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Messages" ],
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : { "comment_insert--comment_node_resource" : { "bundle" : "comment_node_resource" } },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "resource_new_comment",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created_resource_comment" : "Created entity resource comment" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-resource-comment:field-resource-reference" ],
            "value" : [ "comment:node" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-resource-comment:field-message-cat" ],
            "value" : "minor"
          }
        }
      ]
    }
  }');
  return $items;
}
