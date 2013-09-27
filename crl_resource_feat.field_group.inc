<?php
/**
 * @file
 * crl_resource_feat.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function crl_resource_feat_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_analysis|node|title_review|default';
  $field_group->group_name = 'group_analysis';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'CRL Review',
    'weight' => '14',
    'children' => array(
      0 => 'field_resource_reviewers',
      1 => 'field_resource_contributors',
      2 => 'field_resource_coll_content',
      3 => 'field_resource_delivery',
      4 => 'field_resource_terms',
      5 => 'field_resource_strength_weak',
      6 => 'group_sources',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'CRL Review',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_analysis|node|title_review|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_analysis|node|title_review|form';
  $field_group->group_name = 'group_analysis';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'CRL Review',
    'weight' => '13',
    'children' => array(
      0 => 'field_resource_sources',
      1 => 'field_resource_reviewers',
      2 => 'field_resource_contributors',
      3 => 'field_resource_coll_content',
      4 => 'field_resource_delivery',
      5 => 'field_resource_terms',
      6 => 'field_resource_strength_weak',
      7 => 'field_resource_analysis_notes',
      8 => 'field_resource_external_reviews',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'CRL Review',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_analysis|node|title_review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_appendix|node|resource|default';
  $field_group->group_name = 'group_appendix';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Appendix',
    'weight' => '16',
    'children' => array(
      0 => 'field_resource_title_lists',
      1 => 'field_resource_attachments',
      2 => 'field_resource_appendix_notes',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_appendix|node|resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_appendix|node|resource|form';
  $field_group->group_name = 'group_appendix';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Appendix',
    'weight' => '14',
    'children' => array(
      0 => 'field_resource_title_lists',
      1 => 'field_resource_attachments',
      2 => 'field_resource_appendix_notes',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_appendix|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_crl_details|node|title_review|default';
  $field_group->group_name = 'group_crl_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'CRL Offers & Activity',
    'weight' => '15',
    'children' => array(
      0 => 'pseudo_field_resource_status_summary',
      1 => 'pseudo_field_resource_activity',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'CRL Offers & Activity',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_crl_details|node|title_review|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details_collection_content|node|resource|default';
  $field_group->group_name = 'group_details_collection_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Collection Content',
    'weight' => '91',
    'children' => array(
      0 => 'field_resource_coll_content_tb',
      1 => 'field_resource_languages',
      2 => 'pseudo_field_resoruce_coll_content_tax',
      3 => 'pseudo_field_resource_table_sources',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Collection Content',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_details_collection_content|node|resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details_provider_terms|node|resource|default';
  $field_group->group_name = 'group_details_provider_terms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Provider and Terms',
    'weight' => '93',
    'children' => array(
      0 => 'field_resource_terms_tb',
      1 => 'field_resource_provider_notes',
      2 => 'pseudo_field_resource_provider_details',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Provider and Terms',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_details_provider_terms|node|resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details_specs|node|resource|default';
  $field_group->group_name = 'group_details_specs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Specifications',
    'weight' => '92',
    'children' => array(
      0 => 'field_resource_metadata_tb',
      1 => 'field_resource_tech_platform_tb',
      2 => 'field_resource_interf_tools_tb',
      3 => 'pseudo_field_resource_all_jisc_details',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Specifications',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_details_specs|node|resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|title_review|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '13',
    'children' => array(
      0 => 'group_details_collection_content',
      1 => 'group_details_specs',
      2 => 'group_details_provider_terms',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_details|node|title_review|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|title_review|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '12',
    'children' => array(
      0 => 'field_resource_coll_content_tb',
      1 => 'field_resource_metadata_tb',
      2 => 'field_resource_tech_platform_tb',
      3 => 'field_resource_interf_tools_tb',
      4 => 'field_resource_terms_tb',
      5 => 'field_resource_languages',
      6 => 'field_resource_provider_notes',
      7 => 'field_temp_subjects_covered',
      8 => 'field_temp_topics_from_review',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_details|node|title_review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_jisc_data|node|resource|default';
  $field_group->group_name = 'group_jisc_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Jisc Data',
    'weight' => '19',
    'children' => array(
      0 => 'field_resource_jisc_overview',
      1 => 'field_resource_jisc_description',
      2 => 'group_jisc_standards_compliance',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_jisc_data|node|resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_jisc_data|node|resource|form';
  $field_group->group_name = 'group_jisc_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Jisc Data',
    'weight' => '8',
    'children' => array(
      0 => 'field_jisc_id',
      1 => 'field_jisc_guid',
      2 => 'field_resource_jisc_overview',
      3 => 'field_resource_jisc_description',
      4 => 'field_jisc_import_batch',
      5 => 'group_jisc_standards_compliance',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Jisc Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_jisc_data|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_jisc_standards_compliance|node|resource|default';
  $field_group->group_name = 'group_jisc_standards_compliance';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_jisc_data';
  $field_group->data = array(
    'label' => 'Standards Compliance',
    'weight' => '41',
    'children' => array(
      0 => 'field_resource_jisc_federated',
      1 => 'field_resource_jisc_full_text',
      2 => 'field_resource_jisc_marc',
      3 => 'field_resource_jisc_search',
      4 => 'field_resource_jisc_post_search',
      5 => 'field_resource_jisc_usage_stat',
      6 => 'field_resource_jisc_auth',
      7 => 'field_resource_jisc_access',
      8 => 'field_resource_jisc_person',
      9 => 'field_resource_jisc_sc_notes',
      10 => 'field_resource_jisc_metadata_std',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Standards Compliance',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_jisc_standards_compliance|node|resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_jisc_standards_compliance|node|resource|form';
  $field_group->group_name = 'group_jisc_standards_compliance';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_jisc_data';
  $field_group->data = array(
    'label' => 'Standards Compliance',
    'weight' => '43',
    'children' => array(
      0 => 'field_resource_jisc_federated',
      1 => 'field_resource_jisc_full_text',
      2 => 'field_resource_jisc_marc',
      3 => 'field_resource_jisc_search',
      4 => 'field_resource_jisc_post_search',
      5 => 'field_resource_jisc_usage_stat',
      6 => 'field_resource_jisc_auth',
      7 => 'field_resource_jisc_access',
      8 => 'field_resource_jisc_person',
      9 => 'field_resource_jisc_sc_notes',
      10 => 'field_resource_jisc_metadata_std',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_jisc_standards_compliance|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overview|node|title_review|default';
  $field_group->group_name = 'group_overview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Overview',
    'weight' => '12',
    'children' => array(
      0 => 'body',
      1 => 'field_subject_area',
      2 => 'field_provider',
      3 => 'field_resource_type',
      4 => 'field_see_also',
      5 => 'field_see',
      6 => 'pseudo_field_resource_source_summary',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_overview|node|title_review|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overview|node|title_review|form';
  $field_group->group_name = 'group_overview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Overview',
    'weight' => '11',
    'children' => array(
      0 => 'body',
      1 => 'field_subject_area',
      2 => 'field_resource_type',
      3 => 'field_see_also',
      4 => 'field_see',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_overview|node|title_review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ratings|node|title_review|default';
  $field_group->group_name = 'group_ratings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Community Ratings',
    'weight' => '1',
    'children' => array(
      0 => 'field_platform_and_user_interfac',
      1 => 'field_content_scope_and_complete',
      2 => 'field_cost_and_price_structure',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Community Ratings',
      'instance_settings' => array(
        'classes' => 'rating-wrapper',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ratings|node|title_review|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sources|node|resource|default';
  $field_group->group_name = 'group_sources';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_analysis';
  $field_group->data = array(
    'label' => 'Sources',
    'weight' => '23',
    'children' => array(
      0 => 'field_resource_analysis_notes',
      1 => 'field_resource_external_reviews',
      2 => 'pseudo_field_resource_review_source',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Sources',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_sources|node|resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_system_fields|node|resource|form';
  $field_group->group_name = 'group_system_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'System Fields',
    'weight' => '10',
    'children' => array(
      0 => 'field_platform_and_user_interfac',
      1 => 'field_content_scope_and_complete',
      2 => 'field_cost_and_price_structure',
      3 => 'field_resource_glossary',
      4 => 'field_resource_all_jisc_details',
      5 => 'field_resource_provider_details',
      6 => 'field_resource_activity',
      7 => 'field_resource_status_summary',
      8 => 'field_coll_content_tax',
      9 => 'field_resource_table_sources',
      10 => 'field_resource_source_summary',
      11 => 'field_resource_review_source',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'System Fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_system_fields|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabbed|node|title_review|default';
  $field_group->group_name = 'group_tabbed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabbed',
    'weight' => '0',
    'children' => array(
      0 => 'group_overview',
      1 => 'group_details',
      2 => 'group_crl_details',
      3 => 'group_analysis',
      4 => 'group_appendix',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tabbed|node|title_review|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabbed|node|title_review|form';
  $field_group->group_name = 'group_tabbed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabbed',
    'weight' => '5',
    'children' => array(
      0 => 'group_overview',
      1 => 'group_details',
      2 => 'group_analysis',
      3 => 'group_appendix',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tabbed|node|title_review|form'] = $field_group;

  return $export;
}
