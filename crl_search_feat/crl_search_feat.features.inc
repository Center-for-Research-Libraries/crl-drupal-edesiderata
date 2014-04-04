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
    "server" : "db_server_test",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "crl_resource_expiration_countdown" : { "type" : "integer" },
        "crl_resource_glossary_value" : { "type" : "string" },
        "crl_resource_master_update_timestamp" : { "type" : "date" },
        "crl_resource_status_backref" : { "type" : "list\\u003Cstring\\u003E" },
        "field_activity_crl_status" : { "type" : "list\\u003Cstring\\u003E" },
        "field_activity_offer_duration:value2" : { "type" : "date" },
        "field_jisc_id" : { "type" : "integer" },
        "field_provider" : { "type" : "integer", "entity_type" : "node" },
        "field_resource_reference" : { "type" : "integer", "entity_type" : "node" },
        "field_resource_title_for_sort" : { "type" : "string" },
        "field_resource_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_subject_area" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_update_alert" : { "type" : "date" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
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

/**
 * Implements hook_default_search_api_server().
 */
function crl_search_feat_default_search_api_server() {
  $items = array();
  $items['db_server_test'] = entity_import('search_api_server', '{
    "name" : "DB Main Dev",
    "machine_name" : "db_server_test",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "indexes" : { "title_search_index" : {
          "nid" : {
            "table" : "search_api_db_title_search_index",
            "column" : "nid_1",
            "type" : "integer",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_title_search_index",
            "column" : "type_1",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_title_search_index_title_1",
            "type" : "text",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_title_search_index",
            "column" : "status_1",
            "type" : "integer",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_title_search_index",
            "column" : "created_1",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_title_search_index",
            "column" : "changed_1",
            "type" : "date",
            "boost" : "1.0"
          },
          "crl_resource_status_backref" : {
            "table" : "search_api_db_title_search_index_crl_resource_status_backref_1",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "crl_resource_master_update_timestamp" : {
            "table" : "search_api_db_title_search_index",
            "column" : "crl_resource_master_update_timestamp_1",
            "type" : "date",
            "boost" : "1.0"
          },
          "crl_resource_expiration_countdown" : {
            "table" : "search_api_db_title_search_index",
            "column" : "crl_resource_expiration_countdown_1",
            "type" : "integer",
            "boost" : "1.0"
          },
          "crl_resource_glossary_value" : {
            "table" : "search_api_db_title_search_index",
            "column" : "crl_resource_glossary_value_1",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_subject_area" : {
            "table" : "search_api_db_title_search_index_field_subject_area_1",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_resource_title_for_sort" : {
            "table" : "search_api_db_title_search_index",
            "column" : "field_resource_title_for_sort_1",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_jisc_id" : {
            "table" : "search_api_db_title_search_index",
            "column" : "field_jisc_id_1",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_provider" : {
            "table" : "search_api_db_title_search_index",
            "column" : "field_provider_1",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_resource_type" : {
            "table" : "search_api_db_title_search_index_field_resource_type_1",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_update_alert" : {
            "table" : "search_api_db_title_search_index",
            "column" : "field_update_alert_1",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_resource_reference" : {
            "table" : "search_api_db_title_search_index",
            "column" : "field_resource_reference_1",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_activity_crl_status" : {
            "table" : "search_api_db_title_search_index_field_activity_crl_status_1",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_title_search_index",
            "column" : "search_api_language_1",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_title_search_index_body_value_1",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_activity_offer_duration:value2" : {
            "table" : "search_api_db_title_search_index",
            "column" : "field_activity_offer_duration_value2_1",
            "type" : "date",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  $items['solr_main_prod'] = entity_import('search_api_server', '{
    "name" : "Solr Main Prod",
    "machine_name" : "solr_main_prod",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/edesiderata_prod",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "http_method" : "AUTO"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  $items['solr_main_stage'] = entity_import('search_api_server', '{
    "name" : "Solr Main Stage",
    "machine_name" : "solr_main_stage",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/edesiderata_stage",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "http_method" : "AUTO"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
