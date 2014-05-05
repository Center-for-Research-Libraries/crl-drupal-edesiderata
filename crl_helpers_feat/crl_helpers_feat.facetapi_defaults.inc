<?php
/**
 * @file
 * crl_helpers_feat.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function crl_helpers_feat_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@title_search_index::crl_glossary_value';
  $facet->searcher = 'search_api@title_search_index';
  $facet->realm = '';
  $facet->facet = 'crl_glossary_value';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@title_search_index::crl_glossary_value'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@title_search_index:block:crl_glossary_value';
  $facet->searcher = 'search_api@title_search_index';
  $facet->realm = 'block';
  $facet->facet = 'crl_glossary_value';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'display' => 'display',
      'active' => 'active',
      'count' => 0,
      'indexed' => 0,
      'crl_status_sort' => 0,
    ),
    'sort_weight' => array(
      'active' => '-49',
      'count' => '-48',
      'display' => '-50',
      'indexed' => '-47',
      'crl_status_sort' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
      'crl_status_sort' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '40',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
  );
  $export['search_api@title_search_index:block:crl_glossary_value'] = $facet;

  return $export;
}
