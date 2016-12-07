<?php
/**
 * @file
 * crl_resource_feat.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function crl_resource_feat_field_group_info() {
  $field_groups = array();

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
        'id' => 'crl-review',
        'classes' => ' group-analysis field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_analysis|node|title_review|default'] = $field_group;

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
      0 => 'field_resource_reviewers',
      1 => 'field_resource_contributors',
      2 => 'field_resource_coll_content',
      3 => 'field_resource_delivery',
      4 => 'field_resource_terms',
      5 => 'field_resource_strength_weak',
      6 => 'field_resource_analysis_notes',
      7 => 'field_resource_external_reviews',
      8 => 'field_facets',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'CRL Review',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-analysis field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_analysis|node|title_review|form'] = $field_group;

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
      'label' => 'Appendix',
      'instance_settings' => array(
        'id' => 'crl-appendix',
        'classes' => ' group-appendix field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_appendix|node|resource|default'] = $field_group;

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
        'classes' => ' group-appendix field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_appendix|node|resource|form'] = $field_group;

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
    'label' => 'CRL Offers & Status',
    'weight' => '15',
    'children' => array(
      0 => 'pseudo_field_resource_status_summary',
      1 => 'pseudo_field_resource_activity',
      2 => 'group_history',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'CRL Offers & Status',
      'instance_settings' => array(
        'id' => 'crl-offers-status',
        'classes' => ' group-crl-details field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_crl_details|node|title_review|default'] = $field_group;

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
      2 => 'pseudo_field_resource_coll_content_tax',
      3 => 'pseudo_field_resource_table_sources',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Collection Content',
      'instance_settings' => array(
        'id' => 'node_resource_full_group_details_collection_content',
        'classes' => 'group-details-collection-content field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_details_collection_content|node|resource|default'] = $field_group;

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
    'label' => 'Terms and Provider Details',
    'weight' => '93',
    'children' => array(
      0 => 'field_resource_terms_tb',
      1 => 'field_resource_provider_notes',
      2 => 'pseudo_field_resource_provider_details',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Terms and Provider Details',
      'instance_settings' => array(
        'id' => 'node_resource_full_group_details_provider_terms',
        'classes' => 'group-details-provider-terms field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_details_provider_terms|node|resource|default'] = $field_group;

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
      3 => 'field_resource_gen_specs',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Specifications',
      'instance_settings' => array(
        'id' => 'node_resource_full_group_details_specs',
        'classes' => 'group-details-specs field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_details_specs|node|resource|default'] = $field_group;

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
      1 => 'group_details_provider_terms',
      2 => 'group_details_specs',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => 'crl-details',
        'classes' => ' group-details field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_details|node|title_review|default'] = $field_group;

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
      7 => 'field_resource_gen_specs',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-details field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_details|node|title_review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_history|node|resource|default';
  $field_group->group_name = 'group_history';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_crl_details';
  $field_group->data = array(
    'label' => 'Previous Offer History',
    'weight' => '1002',
    'children' => array(
      0 => 'field_resource_activity_history',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Previous Offer History',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-history field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_history|node|resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_official|entityform|resource_suggestion|form';
  $field_group->group_name = 'group_official';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'resource_suggestion';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Offical Use Only',
    'weight' => '7',
    'children' => array(
      0 => 'field_resource_reference',
      1 => 'field_internal_notes',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Offical Use Only',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-official field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_official|entityform|resource_suggestion|form'] = $field_group;

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
      7 => 'pseudo_field_resource_added',
      8 => 'pseudo_field_resource_updated',
      9 => 'pseudo_field_resource_alerts',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Overview',
      'instance_settings' => array(
        'id' => 'crl-overview',
        'classes' => ' group-overview field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_overview|node|title_review|default'] = $field_group;

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
        'classes' => ' group-overview field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_overview|node|title_review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_process|entityform|resource_suggestion|default';
  $field_group->group_name = 'group_process';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'resource_suggestion';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Entry Processing',
    'weight' => '10',
    'children' => array(
      0 => 'field_resource_reference',
      1 => 'field_internal_notes',
      2 => 'flag_resource_suggestion_process',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Entry Processing',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-process field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_process|entityform|resource_suggestion|default'] = $field_group;

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
    'weight' => '2',
    'children' => array(
      0 => 'field_platform_and_user_interfac',
      1 => 'field_content_scope_and_complete',
      2 => 'field_cost_and_price_structure',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Community Ratings',
      'instance_settings' => array(
        'id' => 'node_resource_full_group_ratings',
        'classes' => 'rating-wrapper group-ratings field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_ratings|node|title_review|default'] = $field_group;

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
        'classes' => 'group-sources field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_resource_full_group_sources',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_sources|node|resource|default'] = $field_group;

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
    'weight' => '11',
    'children' => array(
      0 => 'field_platform_and_user_interfac',
      1 => 'field_content_scope_and_complete',
      2 => 'field_cost_and_price_structure',
      3 => 'field_resource_activity_history',
      4 => 'field_source_guid',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'System Fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-system-fields field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_resource_form_group_system_fields',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_system_fields|node|resource|form'] = $field_group;

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
      0 => 'group_analysis',
      1 => 'group_appendix',
      2 => 'group_crl_details',
      3 => 'group_details',
      4 => 'group_overview',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-tabbed field-group-htabs',
      ),
    ),
  );
  $field_groups['group_tabbed|node|title_review|default'] = $field_group;

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
    'weight' => '4',
    'children' => array(
      0 => 'group_analysis',
      1 => 'group_appendix',
      2 => 'group_details',
      3 => 'group_overview',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-tabbed field-group-htabs',
      ),
    ),
  );
  $field_groups['group_tabbed|node|title_review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_temp_old_reviews|node|resource|form';
  $field_group->group_name = 'group_temp_old_reviews';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Temporary Data from Old Reviews',
    'weight' => '10',
    'children' => array(
      0 => 'field_temp_subjects_covered',
      1 => 'field_temp_topics_from_review',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Temporary Data from Old Reviews',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-temp-old-reviews field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_temp_old_reviews|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_update_alerts|node|resource|form';
  $field_group->group_name = 'group_update_alerts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Update Alert',
    'weight' => '7',
    'children' => array(
      0 => 'field_update_alert',
      1 => 'field_update_alert_message',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Update Alert',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-update-alerts field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_resource_form_group_update_alerts',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_update_alerts|node|resource|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Appendix');
  t('CRL Offers & Status');
  t('CRL Review');
  t('Collection Content');
  t('Community Ratings');
  t('Details');
  t('Entry Processing');
  t('Offical Use Only');
  t('Overview');
  t('Previous Offer History');
  t('Sources');
  t('Specifications');
  t('System Fields');
  t('Tabbed');
  t('Temporary Data from Old Reviews');
  t('Terms and Provider Details');
  t('Update Alert');

  return $field_groups;
}
