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
  $items['rules_alert_created'] = entity_import('rules_config', '{ "rules_alert_created" : {
      "LABEL" : "Alert Created",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "activity" ],
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
              "param_type" : "log_new_alert",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-message-content" ],
            "value" : [ "node" ]
          }
        }
      ]
    }
  }');
  $items['rules_alert_extended'] = entity_import('rules_config', '{ "rules_alert_extended" : {
      "LABEL" : "Alert Extended",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "activity" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--resource" : { "bundle" : "resource" } },
      "IF" : [
        { "data_is" : {
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
              "param_type" : "alert_extended",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-message-content" ],
            "value" : [ "node" ]
          }
        }
      ]
    }
  }');
  $items['rules_log_new_comment'] = entity_import('rules_config', '{ "rules_log_new_comment" : {
      "LABEL" : "Log new Comment",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : { "comment_insert--comment_node_resource" : { "bundle" : "comment_node_resource" } },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "log_new_comment",
              "param_user" : [ "comment:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-message-comment" ],
            "value" : [ "comment" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-message-content" ],
            "value" : [ "comment:node" ]
          }
        }
      ]
    }
  }');
  $items['rules_log_new_content'] = entity_import('rules_config', '{ "rules_log_new_content" : {
      "LABEL" : "Log new Content",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--resource" : { "bundle" : "resource" } },
      "IF" : [ { "node_is_published" : { "node" : [ "node" ] } } ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "log_new_resource",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-message-content" ],
            "value" : [ "node" ]
          }
        }
      ]
    }
  }');
  $items['rules_log_new_vote'] = entity_import('rules_config', '{ "rules_log_new_vote" : {
      "LABEL" : "Log new Vote",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "voting_rules" ],
      "ON" : { "voting_rules_insert_node" : [] },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "log_new_vote",
              "param_user" : [ "vote:user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-message-content" ],
            "value" : [ "node" ]
          }
        }
      ]
    }
  }');
  $items['rules_log_status_update'] = entity_import('rules_config', '{ "rules_log_status_update" : {
      "LABEL" : "Log Status Update",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "activity" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--activity" : { "bundle" : "activity" } },
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "node:field-activity-crl-status" ],
            "value" : [ "node-unchanged:field-activity-crl-status" ]
          }
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "log_status_update",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-message-content" ],
            "value" : [ "node:field-resource-reference" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-activity-crl-status" ],
            "value" : [ "node-unchanged:field-activity-crl-status" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-message-activity" ],
            "value" : [ "node" ]
          }
        }
      ]
    }
  }');
  $items['rules_log_update_activity'] = entity_import('rules_config', '{ "rules_log_update_activity" : {
      "LABEL" : "Log update Activity",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "activity" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--activity" : { "bundle" : "activity" } },
      "IF" : [
        { "data_is" : {
            "data" : [ "node-unchanged:changed" ],
            "op" : "\\u003C",
            "value" : { "select" : "node:changed", "date_offset" : { "value" : -3600 } }
          }
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "log_activity_update",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-message-content" ],
            "value" : [ "node:field-resource-reference" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-message-activity" ],
            "value" : [ "node" ]
          }
        }
      ]
    }
  }');
  $items['rules_log_update_content'] = entity_import('rules_config', '{ "rules_log_update_content" : {
      "LABEL" : "Log update Content",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--resource" : { "bundle" : "resource" } },
      "IF" : [
        { "data_is" : {
            "data" : [ "node-unchanged:changed" ],
            "op" : "\\u003C",
            "value" : { "select" : "node:changed", "date_offset" : { "value" : -3600 } }
          }
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "log_resource_update",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-message-content" ],
            "value" : [ "node" ]
          }
        }
      ]
    }
  }');
  return $items;
}
