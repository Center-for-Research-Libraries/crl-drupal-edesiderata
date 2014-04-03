<?php
/**
 * @file
 * crl_pp_resource_feat.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function crl_pp_resource_feat_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_pp_resource';
  $strongarm->value = 0;
  $export['comment_anonymous_pp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_spp_resource';
  $strongarm->value = 0;
  $export['comment_anonymous_spp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_pp_resource';
  $strongarm->value = 1;
  $export['comment_default_mode_pp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_spp_resource';
  $strongarm->value = 1;
  $export['comment_default_mode_spp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_pp_resource';
  $strongarm->value = '50';
  $export['comment_default_per_page_pp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_spp_resource';
  $strongarm->value = '50';
  $export['comment_default_per_page_spp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_pp_resource';
  $strongarm->value = 1;
  $export['comment_form_location_pp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_spp_resource';
  $strongarm->value = 1;
  $export['comment_form_location_spp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_pp_resource';
  $strongarm->value = '2';
  $export['comment_pp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_pp_resource';
  $strongarm->value = '1';
  $export['comment_preview_pp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_spp_resource';
  $strongarm->value = '1';
  $export['comment_preview_spp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_spp_resource';
  $strongarm->value = '2';
  $export['comment_spp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_pp_resource';
  $strongarm->value = 0;
  $export['comment_subject_field_pp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_spp_resource';
  $strongarm->value = 0;
  $export['comment_subject_field_spp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__pp_resource';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'embedded' => array(
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
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
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
          'weight' => '11',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'pseudo_field_pp_resource_source_notice' => array(
          'default' => array(
            'weight' => '907',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'pseudo_field_pp_resource_vote_input' => array(
          'teaser' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'pseudo_field_pp_resource_sp_vote_input' => array(
          'teaser' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__pp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__spp_resource';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'embedded' => array(
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
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'pseudo_field_pp_resource_source_notice' => array(
          'default' => array(
            'weight' => '11',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'pseudo_field_pp_resource_sp_vote_input' => array(
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__spp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_pp_resource';
  $strongarm->value = array();
  $export['menu_options_pp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_spp_resource';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_spp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_pp_resource';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_pp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_spp_resource';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_spp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_pp_resource';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_pp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_spp_resource';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_spp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_pp_resource';
  $strongarm->value = '1';
  $export['node_preview_pp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_spp_resource';
  $strongarm->value = '1';
  $export['node_preview_spp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_pp_resource';
  $strongarm->value = 0;
  $export['node_submitted_pp_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_spp_resource';
  $strongarm->value = 0;
  $export['node_submitted_spp_resource'] = $strongarm;

  return $export;
}
