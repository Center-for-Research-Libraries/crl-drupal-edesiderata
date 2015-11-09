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
  $items['rules_resource_suggested_message'] = entity_import('rules_config', '{ "rules_resource_suggested_message" : {
      "LABEL" : "Resource Suggested Message",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entityform" ],
      "ON" : { "entityform_insert" : [] },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "resource_suggested",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        }
      ]
    }
  }');
  return $items;
}
