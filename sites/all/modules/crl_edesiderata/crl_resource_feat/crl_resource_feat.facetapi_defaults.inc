<?php

/**
 * @file
 * crl_resource_feat.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function crl_resource_feat_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@title_search_index::crl_resource_status_backref';
  $facet->searcher = 'search_api@title_search_index';
  $facet->realm = '';
  $facet->facet = 'crl_resource_status_backref';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '75',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
  );
  $export['search_api@title_search_index::crl_resource_status_backref'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@title_search_index::field_facets';
  $facet->searcher = 'search_api@title_search_index';
  $facet->realm = '';
  $facet->facet = 'field_facets';
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
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@title_search_index::field_facets'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@title_search_index::field_provider';
  $facet->searcher = 'search_api@title_search_index';
  $facet->realm = '';
  $facet->facet = 'field_provider';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '75',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'individual_parent' => 0,
    'limit_active_items' => 0,
    'exclude' => 0,
  );
  $export['search_api@title_search_index::field_provider'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@title_search_index::field_resource_type';
  $facet->searcher = 'search_api@title_search_index';
  $facet->realm = '';
  $facet->facet = 'field_resource_type';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '75',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'individual_parent' => '0',
    'limit_active_items' => 0,
  );
  $export['search_api@title_search_index::field_resource_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@title_search_index::field_subject_area';
  $facet->searcher = 'search_api@title_search_index';
  $facet->realm = '';
  $facet->facet = 'field_subject_area';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '75',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'individual_parent' => '0',
    'limit_active_items' => 0,
    'exclude' => 0,
  );
  $export['search_api@title_search_index::field_subject_area'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@title_search_index:block:crl_resource_status_backref';
  $facet->searcher = 'search_api@title_search_index';
  $facet->realm = 'block';
  $facet->facet = 'crl_resource_status_backref';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'crl_status_sort' => 'crl_status_sort',
      'indexed' => 0,
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'crl_status_sort' => '-50',
      'indexed' => '-49',
      'active' => '-48',
      'count' => '-47',
      'display' => '-46',
    ),
    'sort_order' => array(
      'crl_status_sort' => '4',
      'indexed' => '4',
      'active' => '3',
      'count' => '3',
      'display' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '15',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@title_search_index:block:crl_resource_status_backref'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@title_search_index:block:field_facets';
  $facet->searcher = 'search_api@title_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_facets';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
      'crl_status_sort' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
      'crl_status_sort' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
      'crl_status_sort' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
  );
  $export['search_api@title_search_index:block:field_facets'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@title_search_index:block:field_provider';
  $facet->searcher = 'search_api@title_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_provider';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
      'crl_status_sort' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'display' => '-48',
      'count' => '-49',
      'indexed' => '-47',
      'crl_status_sort' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'display' => '4',
      'count' => '3',
      'indexed' => '4',
      'crl_status_sort' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '10',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@title_search_index:block:field_provider'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@title_search_index:block:field_resource_type';
  $facet->searcher = 'search_api@title_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_resource_type';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'display' => 'display',
      'count' => 'count',
      'indexed' => 0,
      'crl_status_sort' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-48',
      'display' => '-49',
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
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@title_search_index:block:field_resource_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@title_search_index:block:field_subject_area';
  $facet->searcher = 'search_api@title_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_subject_area';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'display' => 'display',
      'count' => 'count',
      'indexed' => 0,
      'crl_status_sort' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-48',
      'display' => '-49',
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
    'soft_limit' => '10',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@title_search_index:block:field_subject_area'] = $facet;

  return $export;
}
