<?php
/**
 * @file
 * crl_search_feat.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function crl_search_feat_default_search_api_index() {
  $items = array();
  $items['title_search_index'] = entity_import('search_api_index', '{
    "name" : "Node Search Index",
    "machine_name" : "title_search_index",
    "description" : null,
    "server" : "main_search_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "nid" : { "type" : "integer" },
        "type" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "2.0" },
        "status" : { "type" : "integer" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "crl_glossary_value" : { "type" : "string" },
        "crl_resource_status_backref" : { "type" : "list\\u003Cstring\\u003E" },
        "crl_resource_master_update_timestamp" : { "type" : "date" },
        "crl_resource_expiration_countdown" : { "type" : "integer" },
        "field_subject_area" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_jisc_id" : { "type" : "integer" },
        "field_provider" : { "type" : "integer", "entity_type" : "node" },
        "field_resource_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_resource_languages" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_update_alert" : { "type" : "date" },
        "field_title_sort" : { "type" : "string" },
        "field_resource_reference" : { "type" : "integer", "entity_type" : "node" },
        "field_activity_crl_status" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "body:value" : { "type" : "text" },
        "field_activity_offer_duration:value2" : { "type" : "date" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_crl_status" : true,
              "field_crl_offer_status" : true,
              "field_provider" : true,
              "search_api_language" : true,
              "body:value" : true,
              "field_sources:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
