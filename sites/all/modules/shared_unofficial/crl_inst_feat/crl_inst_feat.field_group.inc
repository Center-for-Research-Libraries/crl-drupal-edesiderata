<?php
/**
 * @file
 * crl_inst_feat.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function crl_inst_feat_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inst_grp_affiliations|node|institution|default';
  $field_group->group_name = 'group_inst_grp_affiliations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'institution';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'CRL Program Participation',
    'weight' => '4',
    'children' => array(
      0 => 'field_inst_net_affiliations',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-inst-grp-affiliations field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_inst_grp_affiliations|node|institution|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inst_grp_affiliations|node|institution|form';
  $field_group->group_name = 'group_inst_grp_affiliations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'institution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'CRL Program Participation',
    'weight' => '4',
    'children' => array(
      0 => 'field_inst_net_affiliations',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-inst-grp-affiliations field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_inst_grp_affiliations|node|institution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inst_grp_general|node|institution|default';
  $field_group->group_name = 'group_inst_grp_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'institution';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Info',
    'weight' => '3',
    'children' => array(
      0 => 'field_inst_member_type',
      1 => 'field_inst_rep',
      2 => 'field_inst_website',
      3 => 'field_inst_start_fy',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-inst-grp-general field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_inst_grp_general|node|institution|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inst_grp_general|node|institution|form';
  $field_group->group_name = 'group_inst_grp_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'institution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Info',
    'weight' => '3',
    'children' => array(
      0 => 'field_inst_member_type',
      1 => 'field_inst_rep',
      2 => 'field_inst_website',
      3 => 'field_inst_start_fy',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-inst-grp-general field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_inst_grp_general|node|institution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inst_grp_hidden|node|institution|form';
  $field_group->group_name = 'group_inst_grp_hidden';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'institution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hidden',
    'weight' => '7',
    'children' => array(
      0 => 'field_inst_active',
      1 => 'field_inst_crkn',
      2 => 'field_inst_mem_id',
      3 => 'field_inst_ohiolink',
      4 => 'field_inst_sort_name',
      5 => 'field_inst_fte',
      6 => 'field_inst_branches',
      7 => 'field_inst_ann_mat_expend',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-inst-grp-hidden field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_inst_grp_hidden|node|institution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inst_grp_wna|node|institution|default';
  $field_group->group_name = 'group_inst_grp_wna';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'institution';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'World News Archive Charter Participation',
    'weight' => '5',
    'children' => array(
      0 => 'field_inst_wna_africa',
      1 => 'field_inst_wna_latin_america',
      2 => 'field_inst_wna_latin_america_2',
      3 => 'field_inst_wna_south_asia',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-inst-grp-wna field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_inst_grp_wna|node|institution|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inst_grp_wna|node|institution|form';
  $field_group->group_name = 'group_inst_grp_wna';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'institution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'World News Archive Charter Participation',
    'weight' => '6',
    'children' => array(
      0 => 'field_inst_wna_africa',
      1 => 'field_inst_wna_latin_america',
      2 => 'field_inst_wna_latin_america_2',
      3 => 'field_inst_wna_south_asia',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-inst-grp-wna field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_inst_grp_wna|node|institution|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('CRL Program Participation');
  t('General Info');
  t('Hidden');
  t('World News Archive Charter Participation');

  return $field_groups;
}
