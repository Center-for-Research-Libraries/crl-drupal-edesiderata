<?php

/**
 * @file
 * crl_resource_feat.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function crl_resource_feat_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_resource';
  $strongarm->value = '0';
  $export['comment_anonymous_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_resource';
  $strongarm->value = 1;
  $export['comment_default_mode_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_resource';
  $strongarm->value = '70';
  $export['comment_default_per_page_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_resource';
  $strongarm->value = 1;
  $export['comment_form_location_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_resource';
  $strongarm->value = '1';
  $export['comment_preview_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_resource';
  $strongarm->value = '2';
  $export['comment_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_resource';
  $strongarm->value = 0;
  $export['comment_subject_field_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_resource';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_resource';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_resource';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__resource';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'embedded' => array(
        'custom_settings' => TRUE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '6',
        ),
        'redirect' => array(
          'weight' => '12',
        ),
        'uniqueness' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(
        'pseudo_field_resource_status_summary' => array(
          'default' => array(
            'weight' => '999',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'embedded' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'pseudo_field_resource_all_jisc_details' => array(
          'default' => array(
            'weight' => '80',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'embedded' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'pseudo_field_resource_provider_details' => array(
          'default' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'embedded' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'pseudo_field_resource_activity' => array(
          'default' => array(
            'weight' => '1000',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'embedded' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'pseudo_field_resoruce_coll_content_tax' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'pseudo_field_resource_source_summary' => array(
          'default' => array(
            'weight' => '930',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'embedded' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'pseudo_field_resource_table_sources' => array(
          'default' => array(
            'weight' => '906',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'embedded' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
        'pseudo_field_resource_review_source' => array(
          'default' => array(
            'weight' => '93',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'embedded' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
        ),
        'pseudo_field_resource_added' => array(
          'default' => array(
            'weight' => '926',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'embedded' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
        ),
        'pseudo_field_resource_updated' => array(
          'default' => array(
            'weight' => '927',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'embedded' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
        ),
        'pseudo_field_resource_alerts' => array(
          'default' => array(
            'weight' => '922',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'embedded' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
        'pseudo_field_resource_coll_content_tax' => array(
          'default' => array(
            'weight' => '904',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'embedded' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'pseudo_field_resource_improve_widget' => array(
          'default' => array(
            'weight' => '911',
            'visible' => TRUE,
          ),
        ),
        'pseudo_field_resource_special_access' => array(
          'default' => array(
            'weight' => '924',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_resource';
  $strongarm->value = array();
  $export['menu_options_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_resource';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_resource';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_resource';
  $strongarm->value = '1';
  $export['node_preview_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_resource';
  $strongarm->value = 0;
  $export['node_submitted_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_resource_pattern';
  $strongarm->value = 'resources/[node:title]';
  $export['pathauto_node_resource_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_resource_languages_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_resource_languages_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_resource_type_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_resource_type_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_title_type_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_title_type_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uniqueness_type_resource';
  $strongarm->value = array(
    0 => 1,
  );
  $export['uniqueness_type_resource'] = $strongarm;

  return $export;
}
