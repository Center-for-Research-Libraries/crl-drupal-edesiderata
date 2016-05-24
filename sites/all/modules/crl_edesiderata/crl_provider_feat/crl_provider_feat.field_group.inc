<?php
/**
 * @file
 * crl_provider_feat.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function crl_provider_feat_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|provider|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'provider';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '1',
    'children' => array(
      0 => 'field_provider_established',
      1 => 'field_provider_in_operation',
      2 => 'field_provider_parent',
      3 => 'field_resource_type',
      4 => 'field_subject_area',
      5 => 'field_title_alt',
      6 => 'field_title_prior',
      7 => 'field_address',
      8 => 'field_contacts_group',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => 'crl-details',
        'classes' => 'group-details field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_details|node|provider|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|provider|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'provider';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '22',
    'children' => array(
      0 => 'field_provider_established',
      1 => 'field_provider_in_operation',
      2 => 'field_provider_parent',
      3 => 'field_address',
      4 => 'field_contacts_group',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-details field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_details|node|provider|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overview|node|provider|default';
  $field_group->group_name = 'group_overview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'provider';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Overview',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_link',
      2 => 'field_provider_publisher_type',
      3 => 'field_provider_see_also',
      4 => 'field_provider_type',
      5 => 'pseudo_field_provider_added',
      6 => 'pseudo_field_provider_updated',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Overview',
      'instance_settings' => array(
        'id' => 'crl-overview',
        'classes' => 'group-overview field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_overview|node|provider|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overview|node|provider|form';
  $field_group->group_name = 'group_overview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'provider';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Overview',
    'weight' => '21',
    'children' => array(
      0 => 'body',
      1 => 'field_link',
      2 => 'field_provider_publisher_type',
      3 => 'field_provider_see_also',
      4 => 'field_provider_type',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-overview field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_overview|node|provider|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_analysis|node|provider|default';
  $field_group->group_name = 'group_profile_analysis';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'provider';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'CRL Analysis & Profile',
    'weight' => '2',
    'children' => array(
      0 => 'field_provider_access',
      1 => 'field_provider_financial_info',
      2 => 'field_provider_governance',
      3 => 'field_provider_history',
      4 => 'field_provider_legal_info',
      5 => 'field_provider_mission_statement',
      6 => 'field_provider_sources',
      7 => 'field_provider_tech_info',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'CRL Analysis & Profile',
      'instance_settings' => array(
        'id' => 'crl-analysis',
        'classes' => 'group-analysis group-profile-analysis field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_profile_analysis|node|provider|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_analysis|node|provider|form';
  $field_group->group_name = 'group_profile_analysis';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'provider';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'CRL Analysis & Profile',
    'weight' => '23',
    'children' => array(
      0 => 'field_provider_access',
      1 => 'field_provider_financial_info',
      2 => 'field_provider_governance',
      3 => 'field_provider_history',
      4 => 'field_provider_legal_info',
      5 => 'field_provider_mission_statement',
      6 => 'field_provider_sources',
      7 => 'field_provider_tech_info',
      8 => 'field_provider_profile_status',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'CRL Analysis & Profile',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-profile-analysis field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_profile_analysis|node|provider|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_resources|node|provider|default';
  $field_group->group_name = 'group_resources';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'provider';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Resources',
    'weight' => '3',
    'children' => array(
      0 => 'pseudo_field_provider_resources_view',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Resources',
      'instance_settings' => array(
        'id' => 'crl-resources',
        'classes' => 'group-resources field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_resources|node|provider|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_system_fields|node|provider|form';
  $field_group->group_name = 'group_system_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'provider';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'System Fields',
    'weight' => '7',
    'children' => array(
      0 => 'field_resource_type',
      1 => 'field_subject_area',
      2 => 'field_source_guid',
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
        'id' => 'node_provider_form_group_system_fields',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_system_fields|node|provider|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabbed|node|provider|default';
  $field_group->group_name = 'group_tabbed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'provider';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabbed',
    'weight' => '0',
    'children' => array(
      0 => 'group_details',
      1 => 'group_overview',
      2 => 'group_profile_analysis',
      3 => 'group_resources',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabbed field-group-htabs',
      ),
    ),
  );
  $field_groups['group_tabbed|node|provider|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabbed|node|provider|form';
  $field_group->group_name = 'group_tabbed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'provider';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabbed',
    'weight' => '5',
    'children' => array(
      0 => 'group_details',
      1 => 'group_overview',
      2 => 'group_profile_analysis',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabbed field-group-htabs',
      ),
    ),
  );
  $field_groups['group_tabbed|node|provider|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('CRL Analysis & Profile');
  t('Details');
  t('Overview');
  t('Resources');
  t('System Fields');
  t('Tabbed');

  return $field_groups;
}
