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
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_flagged_resource_suggestion_convert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "flagged-entityform" ],
            "type" : "entityform",
            "bundle" : { "value" : { "resource_suggestion" : "resource_suggestion" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "flagging" ], "field" : "field_provider" } }
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
        { "redirect" : { "url" : [ "entity-created:edit-url" ] } }
      ]
    }
  }');
  return $items;
}
