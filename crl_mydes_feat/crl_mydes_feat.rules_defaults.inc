<?php
/**
 * @file
 * crl_mydes_feat.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crl_mydes_feat_default_rules_configuration() {
  $items = array();
  $items['rules_watch_on_comment'] = entity_import('rules_config', '{ "rules_watch_on_comment" : {
      "LABEL" : "Watch on comment",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag", "comment" ],
      "ON" : { "comment_insert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "comment:node" ],
            "type" : "node",
            "bundle" : { "value" : { "resource" : "resource" } }
          }
        },
        { "NOT flag_flagged_node" : {
            "flag" : "base_node_watch",
            "node" : [ "comment:node" ],
            "flagging_user" : [ "comment:author" ]
          }
        }
      ],
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "base_node_watch",
            "node" : [ "comment:node" ],
            "flagging_user" : [ "comment:author" ],
            "permission_check" : 0
          }
        },
        { "drupal_message" : {
            "message" : "[comment:node:title] has been added to your watchlist in \\u003Ca href=\\u0022\\/me\\u0022\\u003EmeDesiderata\\u003C\\/a\\u003E.",
            "repeat" : 0
          }
        }
      ]
    }
  }');
  $items['rules_watch_on_vote'] = entity_import('rules_config', '{ "rules_watch_on_vote" : {
      "LABEL" : "Watch on vote",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag", "voting_rules" ],
      "ON" : { "voting_rules_insert_node" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "resource" : "resource" } }
          }
        },
        { "NOT flag_flagged_node" : {
            "flag" : "base_node_watch",
            "node" : [ "node" ],
            "flagging_user" : [ "site:current-user" ]
          }
        },
        { "data_is" : { "data" : [ "vote:tag" ], "value" : "resource_interest" } },
        { "data_is" : { "data" : [ "vote:value" ], "value" : "1" } }
      ],
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "base_node_watch",
            "node" : [ "node" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : 0
          }
        },
        { "drupal_message" : {
            "message" : "This resource has also been added to your watchlist in meDesiderata.",
            "repeat" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
