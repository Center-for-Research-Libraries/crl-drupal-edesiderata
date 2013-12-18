<?php
/**
 * @file
 * crl_mydes_feat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crl_mydes_feat_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function crl_mydes_feat_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function crl_mydes_feat_flag_default_flags() {
  $flags = array();
  // Exported flag: "My eDesiderata Watch".
  $flags['mydes'] = array(
    'entity_type' => 'node',
    'title' => 'My eDesiderata Watch',
    'global' => 0,
    'types' => array(
      0 => 'resource',
    ),
    'flag_short' => '+ Watch',
    'flag_long' => 'Watch this item via my eDesiderata',
    'flag_message' => 'Added to watched items in My eDesiderata',
    'unflag_short' => 'Unwatch',
    'unflag_long' => 'Unwatch this item',
    'unflag_message' => 'Removed from watched items in My eDesiderata',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'embedded' => 0,
      'diff_standard' => 0,
      'print' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'crl_mydes_feat',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_default_search_api_saved_searches_settings().
 */
function crl_mydes_feat_default_search_api_saved_searches_settings() {
  $items = array();
  $items['title_search_index'] = entity_import('search_api_saved_searches_settings', '{
    "delta" : "title_search_index",
    "index_id" : "title_search_index",
    "enabled" : "1",
    "options" : {
      "date_field" : "changed",
      "description" : "",
      "registered_choose_mail" : 0,
      "choose_name" : 1,
      "registered_user_delete_key" : 0,
      "show_empty_list" : 1,
      "default_true" : true,
      "ids_list" : [],
      "user_select_interval" : 1,
      "interval_options" : { "-1" : "Never", "86400" : "Daily", "604800" : "Weekly" },
      "set_interval" : "86400",
      "mail" : {
        "activate" : {
          "send" : 1,
          "title" : "Activate your saved search at [site:name]",
          "body" : "A saved search on [site:name] with this e-mail address was created.\\r\\nTo activate this saved search, click the following link:\\r\\n\\r\\n[search-api-saved-search:activate-url]\\r\\n\\r\\nIf you didn\\u0027t create this saved search, just ignore this mail and it will be deleted.\\r\\n\\r\\n--  [site:name] team"
        },
        "notify" : {
          "title" : "New results for your saved search at [site:name]",
          "body" : "[user:name],\\r\\n\\r\\nThere are new results for your saved search on [site:name]:\\r\\n\\r\\n[search-api-saved-searches:results]\\r\\n\\r\\nYou can configure your saved searches at the following address:\\r\\n[user:search-api-saved-searches-url]\\r\\n\\r\\n--  [site:name] team",
          "results" : "New results for search \\u0022[search-api-saved-search:name]\\u0022:\\r\\n[search-api-saved-search:items]\\r\\n[search-api-saved-search:results-capped]",
          "result" : "[search-api-saved-search-result:label] ([search-api-saved-search-result:url])",
          "max_results" : "0",
          "results_capped" : "\\u2026\\r\\nView all results: [search-api-saved-search:view-url]"
        }
      },
      "manual" : {
        "allow" : 0,
        "fulltext" : 1,
        "fields" : [
          "crl_resource_status_backref",
          "field_subject_area",
          "field_provider",
          "field_resource_type"
        ],
        "page" : {
          "path" : "resources\\/main",
          "fulltext" : "",
          "direct_filter_params" : "0"
        }
      }
    },
    "rdf_mapping" : []
  }');
  return $items;
}
