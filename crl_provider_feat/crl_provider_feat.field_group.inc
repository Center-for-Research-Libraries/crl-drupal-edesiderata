<?php
/**
 * @file
 * crl_provider_feat.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function crl_provider_feat_field_group_info() {
  $export = array();

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
      0 => 'field_provider_address',
      1 => 'field_provider_contacts',
      2 => 'field_provider_current_owner',
      3 => 'field_title_alt',
      4 => 'field_contacts',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-details field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_details|node|provider|default'] = $field_group;

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
      0 => 'field_provider_address',
      1 => 'field_provider_contacts',
      2 => 'field_contacts',
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
  $export['group_details|node|provider|form'] = $field_group;

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
      1 => 'field_country',
      2 => 'field_postal_code',
      3 => 'field_provider_in_operation',
      4 => 'field_link',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-overview field-group-htab',
        'id' => '',
      ),
    ),
  );
  $export['group_overview|node|provider|default'] = $field_group;

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
      1 => 'field_country',
      2 => 'field_postal_code',
      3 => 'field_provider_current_owner',
      4 => 'field_provider_in_operation',
      5 => 'field_link',
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
  $export['group_overview|node|provider|form'] = $field_group;

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
    'label' => 'CRL Profile & Analysis',
    'weight' => '2',
    'children' => array(
      0 => 'field_provider_mission_statement',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-profile-analysis field-group-htab',
        'id' => '',
      ),
    ),
  );
  $export['group_profile_analysis|node|provider|default'] = $field_group;

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
    'label' => 'CRL Profile & Analysis',
    'weight' => '23',
    'children' => array(
      0 => 'field_provider_mission_statement',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-profile-analysis field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_profile_analysis|node|provider|form'] = $field_group;

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
      0 => 'field_provider_resources',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Resources',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-resources field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_resources|node|provider|default'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'field_jisc_guid',
      1 => 'field_jisc_id',
      2 => 'field_jisc_import_batch',
      3 => 'field_provider_resources',
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
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_system_fields|node|provider|form'] = $field_group;

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
      2 => 'group_resources',
      3 => 'group_profile_analysis',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabbed field-group-htabs',
      ),
    ),
  );
  $export['group_tabbed|node|provider|default'] = $field_group;

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
    'weight' => '3',
    'children' => array(
      0 => 'group_overview',
      1 => 'group_details',
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
  $export['group_tabbed|node|provider|form'] = $field_group;

  return $export;
}
