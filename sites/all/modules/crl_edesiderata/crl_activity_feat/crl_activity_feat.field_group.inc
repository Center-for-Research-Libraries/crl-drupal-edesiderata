<?php
/**
 * @file
 * crl_activity_feat.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function crl_activity_feat_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_documents|node|activity|default';
  $field_group->group_name = 'group_activity_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_activity_offer';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '18',
    'children' => array(
      0 => 'field_activity_attachments',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Documents',
      'instance_settings' => array(
        'id' => 'activity-documents',
        'classes' => 'group-activity-documents field-group-html5',
        'wrapper' => 'aside',
      ),
    ),
  );
  $field_groups['group_activity_documents|node|activity|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_documents|node|activity|embedded';
  $field_group->group_name = 'group_activity_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'embedded';
  $field_group->parent_name = 'group_activity_offer';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '17',
    'children' => array(
      0 => 'field_activity_license_doc',
      1 => 'field_activity_attachments',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Documents',
      'instance_settings' => array(
        'id' => 'activity-documents',
        'classes' => 'group-activity-documents field-group-html5',
        'wrapper' => 'aside',
      ),
    ),
  );
  $field_groups['group_activity_documents|node|activity|embedded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_offer|node|activity|default';
  $field_group->group_name = 'group_activity_offer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Offer Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_activity_offer_duration',
      1 => 'field_activty_offer_terms',
      2 => 'field_activity_licensing_type',
      3 => 'field_activity_billing',
      4 => 'field_activity_est_savings',
      5 => 'field_activity_license_duration',
      6 => 'group_activity_documents',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Offer Information',
      'instance_settings' => array(
        'classes' => ' group-activity-offer field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_activity_full_group_activity_offer',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_activity_offer|node|activity|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_offer|node|activity|embedded';
  $field_group->group_name = 'group_activity_offer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'embedded';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Offer Information',
    'weight' => '2',
    'children' => array(
      0 => 'field_activity_offer_duration',
      1 => 'field_activty_offer_terms',
      2 => 'field_activity_get_started',
      3 => 'field_activity_licensing_type',
      4 => 'field_activity_billing',
      5 => 'field_activity_est_savings',
      6 => 'field_activity_license_duration',
      7 => 'group_activity_documents',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Offer Information',
      'instance_settings' => array(
        'classes' => ' group-activity-offer field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_activity_embedded_group_activity_offer',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_activity_offer|node|activity|embedded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_offer|node|activity|form';
  $field_group->group_name = 'group_activity_offer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Offer Information',
    'weight' => '8',
    'children' => array(
      0 => 'field_activity_offer_duration',
      1 => 'field_activty_offer_terms',
      2 => 'field_activity_get_started',
      3 => 'field_activity_license_doc',
      4 => 'field_activity_attachments',
      5 => 'field_activity_licensing_type',
      6 => 'field_activity_billing',
      7 => 'field_activity_est_savings',
      8 => 'field_activity_license_duration',
      9 => 'field_activity_pricing_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Offer Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-activity-offer field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_activity_offer|node|activity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_trial|node|activity|default';
  $field_group->group_name = 'group_activity_trial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Trial Information',
    'weight' => '10',
    'children' => array(
      0 => 'field_activity_trial_duration',
      1 => 'field_activity_trial_link',
      2 => 'field_activity_trial_access',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Trial Information',
      'instance_settings' => array(
        'classes' => ' group-activity-trial field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_activity_full_group_activity_trial',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_activity_trial|node|activity|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_trial|node|activity|embedded';
  $field_group->group_name = 'group_activity_trial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'embedded';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Trial Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_activity_trial_duration',
      1 => 'field_activity_trial_link',
      2 => 'field_activity_trial_access',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Trial Information',
      'instance_settings' => array(
        'classes' => ' group-activity-trial field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_activity_embedded_group_activity_trial',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_activity_trial|node|activity|embedded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_trial|node|activity|form';
  $field_group->group_name = 'group_activity_trial';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Trial Information',
    'weight' => '9',
    'children' => array(
      0 => 'field_activity_trial_duration',
      1 => 'field_activity_trial_link',
      2 => 'field_activity_trial_access',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Trial Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-activity-trial field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_activity_trial|node|activity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_system_fields|node|activity|form';
  $field_group->group_name = 'group_system_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'System Fields',
    'weight' => '11',
    'children' => array(
      0 => 'field_trial_access_info',
      1 => 'field_access_trial_url',
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
        'id' => 'node_activity_form_group_system_fields',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_system_fields|node|activity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_update_alerts|node|activity|form';
  $field_group->group_name = 'group_update_alerts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Update Alert',
    'weight' => '13',
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
        'id' => 'node_activity_form_group_update_alerts',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_update_alerts|node|activity|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Documents');
  t('Offer Information');
  t('System Fields');
  t('Trial Information');
  t('Update Alert');

  return $field_groups;
}
