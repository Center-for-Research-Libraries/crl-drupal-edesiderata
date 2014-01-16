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
  $items['rules_message_resource_alert_created'] = entity_import('rules_config', '{ "rules_message_resource_alert_created" : {
      "LABEL" : "Message resource alert created",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Messages" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--resource" : { "bundle" : "resource" } },
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "node:field-update-alert-message" ],
            "value" : [ "node-unchanged:field-update-alert-message" ]
          }
        },
        { "data_is" : {
            "data" : [ "node:field-update-alert" ],
            "op" : "\\u003E",
            "value" : [ "site:current-date" ]
          }
        },
        { "data_is" : {
            "data" : [ "node:field-update-alert" ],
            "op" : "\\u003E",
            "value" : [ "node-unchanged:field-update-alert" ]
          }
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "resource_new_alert",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created_resource_alert_created" : "Created entity resource alert created" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-resource-alert-created:field-resource-reference" ],
            "value" : [ "node" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-resource-alert-created:field-message-cat" ],
            "value" : "major"
          }
        }
      ]
    }
  }');
  $items['rules_message_resource_new'] = entity_import('rules_config', '{ "rules_message_resource_new" : {
      "LABEL" : "Message resource new",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "OWNER" : "rules",
      "TAGS" : [ "Messages" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--resource" : { "bundle" : "resource" } },
      "IF" : [ { "data_is" : { "data" : [ "node:status" ], "value" : "1" } } ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "resource_new",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created_resource_new" : "Created entity resource new" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-resource-new:field-resource-reference" ],
            "value" : [ "node" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-resource-new:field-message-cat" ],
            "value" : "major"
          }
        }
      ]
    }
  }');
  $items['rules_message_resource_new_activity'] = entity_import('rules_config', '{ "rules_message_resource_new_activity" : {
      "LABEL" : "Message resource new activity",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "OWNER" : "rules",
      "TAGS" : [ "Messages" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--activity" : { "bundle" : "activity" } },
      "IF" : [ { "data_is" : { "data" : [ "node:status" ], "value" : "1" } } ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "resource_update_activity",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created_resource_activity_new" : "Created entity resource activity new" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-resource-activity-new:field-resource-reference" ],
            "value" : [ "node:field-resource-reference" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-resource-activity-new:field-message-cat" ],
            "value" : "major"
          }
        }
      ]
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
  $items['rules_message_resource_new_vote'] = entity_import('rules_config', '{ "rules_message_resource_new_vote" : {
      "LABEL" : "Message resource new vote",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Messages" ],
      "REQUIRES" : [ "rules", "voting_rules" ],
      "ON" : { "voting_rules_insert_node" : [] },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "resource_new_vote",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created_resource_vote" : "Created entity resource vote" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-resource-vote:field-resource-reference" ],
            "value" : [ "node" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-resource-vote:field-message-cat" ],
            "value" : "minor"
          }
        }
      ]
    }
  }');
  $items['rules_message_resource_status_update'] = entity_import('rules_config', '{ "rules_message_resource_status_update" : {
      "LABEL" : "Message resource status update",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Messages" ],
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_update--activity" : { "bundle" : "activity" },
        "node_insert--activity" : { "bundle" : "activity" }
      },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "node:field-activity-crl-status" ] } },
        { "OR" : [
            { "NOT data_is" : {
                "data" : [ "node:field-activity-crl-status" ],
                "value" : [ "node-unchanged:field-activity-crl-status" ]
              }
            },
            { "entity_is_new" : { "entity" : [ "node" ] } }
          ]
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "resource_status_update",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created_status_update" : "Created entity status update" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-status-update:field-activity-crl-status" ],
            "value" : [ "node:field-activity-crl-status" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-status-update:field-resource-reference" ],
            "value" : [ "node:field-resource-reference" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-status-update:field-message-cat" ],
            "value" : "major"
          }
        }
      ]
    }
  }');
  $items['rules_message_resource_update'] = entity_import('rules_config', '{ "rules_message_resource_update" : {
      "LABEL" : "Message resource update",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "OWNER" : "rules",
      "TAGS" : [ "Messages" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--resource" : { "bundle" : "resource" } },
      "IF" : [
        { "data_is" : { "data" : [ "node:status" ], "value" : "1" } },
        { "data_is" : {
            "data" : [ "node-unchanged:changed" ],
            "op" : "\\u003C",
            "value" : { "select" : "node:changed", "date_offset" : { "value" : -43200 } }
          }
        },
        { "OR" : [
            { "NOT data_is" : { "data" : [ "node:vid" ], "value" : [ "node-unchanged:vid" ] } },
            { "data_is" : { "data" : [ "node-unchanged:status" ], "value" : "0" } }
          ]
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "resource_update",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created_resource_updated" : "Created entity resource updated" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-resource-updated:field-resource-reference" ],
            "value" : [ "node" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-resource-updated:field-message-cat" ],
            "value" : "major"
          }
        }
      ]
    }
  }');
  $items['rules_message_resource_update_activity'] = entity_import('rules_config', '{ "rules_message_resource_update_activity" : {
      "LABEL" : "Message resource update activity",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "OWNER" : "rules",
      "TAGS" : [ "Messages" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--activity" : { "bundle" : "activity" } },
      "IF" : [
        { "data_is" : { "data" : [ "node:status" ], "value" : "1" } },
        { "data_is" : {
            "data" : [ "node-unchanged:changed" ],
            "op" : "\\u003C",
            "value" : { "select" : "node:changed", "date_offset" : { "value" : -43200 } }
          }
        },
        { "data_is" : {
            "data" : [ "node:field-activity-crl-status" ],
            "value" : [ "node-unchanged:field-activity-crl-status" ]
          }
        },
        { "OR" : [
            { "NOT data_is" : { "data" : [ "node:vid" ], "value" : [ "node-unchanged:vid" ] } },
            { "data_is" : { "data" : [ "node-unchanged:status" ], "value" : "0" } }
          ]
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "resource_update_activity",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created_resource_activity_updated" : "Created entity resource activity updated" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-resource-activity-updated:field-resource-reference" ],
            "value" : [ "node:field-resource-reference" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created-resource-activity-updated:field-message-cat" ],
            "value" : "major"
          }
        }
      ]
    }
  }');
  return $items;
}
