<?php
/**
 * @file
 * crl_user_feat.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function crl_user_feat_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pro_info|user|user|form';
  $field_group->group_name = 'group_pro_info';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Professional Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_institution',
      1 => 'field_first_name',
      2 => 'field_last_name',
      3 => 'field_phone',
      4 => 'field_profile_roles',
      5 => 'field_profile_interests',
      6 => 'field_profile_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Professional Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-pro-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_pro_info|user|user|form'] = $field_group;

  return $export;
}
