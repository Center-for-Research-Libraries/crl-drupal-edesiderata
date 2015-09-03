<?php
/**
 * @file
 * crl_activity_feat.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function crl_activity_feat_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-activity-field_activity_add_notes'
  $field_instances['node-activity-field_activity_add_notes'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use this space to add any general notes that are not specific to the offer or trial information above, and should be shown at the end of the page.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'embedded' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_add_notes',
    'label' => 'Additional Notes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 8,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_attachments'
  $field_instances['node-activity-field_activity_attachments'] = array(
    'bundle' => 'activity',
    'deleted' => 0,
    'description' => 'Related documents will be shown along with the offer while it is active and in the offer history once the offer expires. Documents like agreement forms (which need to be available for reference indefinitely) should be included here, but documents like pricing schedules (which are only applicable while the offer is active) should <strong>not</strong> be placed here.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 18,
      ),
      'embedded' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_attachments',
    'label' => 'Related Documents',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => 'activity_docs',
      'file_extensions' => 'jpg jpeg gif png txt doc xls pdf ppt pps odt ods odp docx xlsx pptx',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 43,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_billing'
  $field_instances['node-activity-field_activity_billing'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The entity that will handle the billing for this offer.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 24,
      ),
      'embedded' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_billing',
    'label' => 'Bill Handling',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 40,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_crl_status'
  $field_instances['node-activity-field_activity_crl_status'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => 'Select the status values that <em>currently</em> apply. Note that any "Offer Information" or "Trial Information" details entered below will not be displayed to users unless the respective status is enabled here.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_crl_status',
    'label' => 'CRL Status',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_est_savings'
  $field_instances['node-activity-field_activity_est_savings'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 23,
      ),
      'embedded' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_est_savings',
    'label' => 'Estimated Savings',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 39,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_gen_notes'
  $field_instances['node-activity-field_activity_gen_notes'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field will only be visible to member users before an offer is active (CRL status "Flagged", "Pending" or "Declined"). It can be used to show general notes about CRL work that is not yet officially tied to a specific offer or trial.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'embedded' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_gen_notes',
    'label' => 'Pre-Offer Notes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 8,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_get_started'
  $field_instances['node-activity-field_activity_get_started'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Provide some brief notes about what users should do to take advantage of this offer (who to contact, etc).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'embedded' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_get_started',
    'label' => 'How to Get Started',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 8,
      ),
      'type' => 'text_textarea',
      'weight' => 42,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_grouping'
  $field_instances['node-activity-field_activity_grouping'] = array(
    'bundle' => 'activity',
    'default_value' => array(
      0 => array(
        'tid' => 59,
      ),
    ),
    'deleted' => 0,
    'description' => 'Select which CRL group(s) this offer should be visible to. Use ctrl+click to choose multiple. Note that the "CRL Members" option is special in that deselecting it will not remove member view access (CRL members can always view <strong>all</strong> offers). However a special note will be displayed to clarify that the offer is group-exclusive when the "CRL Members" option is not selected.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_grouping',
    'label' => 'Grouping',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_license_doc'
  $field_instances['node-activity-field_activity_license_doc'] = array(
    'bundle' => 'activity',
    'deleted' => 0,
    'description' => 'Offer documents will be shown along with the offer while it is active but will <strong>not</strong> be available in the offer history once the offer expires. Documents like pricing schedules (which are only applicable while the offer is active) should be included here, but documents like agreement forms (which need to be available for reference indefinitely) should <strong>not</strong> be included here.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'embedded' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_license_doc',
    'label' => 'Offer Documents',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => 'activity_docs',
      'file_extensions' => 'jpg jpeg gif png txt doc xls pdf ppt pps odt ods odp docx xlsx pptx',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 44,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_license_duration'
  $field_instances['node-activity-field_activity_license_duration'] = array(
    'bundle' => 'activity',
    'deleted' => 0,
    'description' => 'If the license related to this offer has a specific subscription duration associated with it, and that duration is universally applicable, enter it here. This should be left blank for offers that do not follow a specific time-frame (once-off purchases, subscriptions with variable start and end dates, etc.).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'medium',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 21,
      ),
      'embedded' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'medium',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_license_duration',
    'label' => 'Subscription Period',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'Y-m-d H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_licensing_type'
  $field_instances['node-activity-field_activity_licensing_type'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 20,
      ),
      'embedded' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_licensing_type',
    'label' => 'Licensing Type(s)',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 36,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_offer_duration'
  $field_instances['node-activity-field_activity_offer_duration'] = array(
    'bundle' => 'activity',
    'deleted' => 0,
    'description' => 'Enter a start and end date during which this offer is open for enrollment (active). If this offer should never expire automatically you may unchecked the "Use End Date" option to remove the 2nd (end) date field.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'medium',
          'fromto' => 'value2',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 19,
      ),
      'embedded' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'medium',
          'fromto' => 'value2',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 19,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_offer_duration',
    'label' => 'Offer Duration',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'blank',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'none',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 35,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_pricing_type'
  $field_instances['node-activity-field_activity_pricing_type'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 22,
      ),
      'embedded' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_pricing_type',
    'label' => 'Pricing Type(s)',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 38,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_see'
  $field_instances['node-activity-field_activity_see'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If this entry represents an alias or derivative version of another one, add a link to the entry that should be considered the canonical (master) version. If you place a value in this field you will most likely leave almost all other fields blank for this entry.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 5,
      ),
      'embedded' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_see',
    'label' => 'See',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_see_also'
  $field_instances['node-activity-field_activity_see_also'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If this entry has relationships with other entries, add links to those entries here (one or more as needed).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 6,
      ),
      'embedded' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_see_also',
    'label' => 'See Also',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_trial_access'
  $field_instances['node-activity-field_activity_trial_access'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_trial_access',
    'label' => 'Access Information',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_trial_duration'
  $field_instances['node-activity-field_activity_trial_duration'] = array(
    'bundle' => 'activity',
    'deleted' => 0,
    'description' => 'Enter a start and end date for this trial. If this trial should never expire automatically you may unchecked the "Use End Date" option to remove the 2nd (end) date field.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'embedded' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'medium',
          'fromto' => 'value2',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_trial_duration',
    'label' => 'Trial Duration',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'blank',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'none',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-activity-field_activity_trial_link'
  $field_instances['node-activity-field_activity_trial_link'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Provide the full text of the trial URL (e.g. http://www.trial.com/trial?id=123).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_trial_link',
    'label' => 'Trial Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-activity-field_activty_offer_terms'
  $field_instances['node-activity-field_activty_offer_terms'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 25,
      ),
      'embedded' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activty_offer_terms',
    'label' => 'Offer Details',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 8,
      ),
      'type' => 'text_textarea',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'node-activity-field_internal_notes'
  $field_instances['node-activity-field_internal_notes'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This information is for internal use only and is not displayed to any site users.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_internal_notes',
    'label' => 'Internal Notes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
      'wysiwyg_unload' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-activity-field_resource_reference'
  $field_instances['node-activity-field_resource_reference'] = array(
    'bundle' => 'activity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Typically this value will be auto-filled for you.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_reference',
    'label' => 'Related resource',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Information');
  t('Additional Notes');
  t('Bill Handling');
  t('CRL Status');
  t('Enter a start and end date during which this offer is open for enrollment (active). If this offer should never expire automatically you may unchecked the "Use End Date" option to remove the 2nd (end) date field.');
  t('Enter a start and end date for this trial. If this trial should never expire automatically you may unchecked the "Use End Date" option to remove the 2nd (end) date field.');
  t('Estimated Savings');
  t('Grouping');
  t('How to Get Started');
  t('If the license related to this offer has a specific subscription duration associated with it, and that duration is universally applicable, enter it here. This should be left blank for offers that do not follow a specific time-frame (once-off purchases, subscriptions with variable start and end dates, etc.).');
  t('If this entry has relationships with other entries, add links to those entries here (one or more as needed).');
  t('If this entry represents an alias or derivative version of another one, add a link to the entry that should be considered the canonical (master) version. If you place a value in this field you will most likely leave almost all other fields blank for this entry.');
  t('Internal Notes');
  t('Licensing Type(s)');
  t('Offer Details');
  t('Offer Documents');
  t('Offer Duration');
  t('Offer documents will be shown along with the offer while it is active but will <strong>not</strong> be available in the offer history once the offer expires. Documents like pricing schedules (which are only applicable while the offer is active) should be included here, but documents like agreement forms (which need to be available for reference indefinitely) should <strong>not</strong> be included here.');
  t('Pre-Offer Notes');
  t('Pricing Type(s)');
  t('Provide some brief notes about what users should do to take advantage of this offer (who to contact, etc).');
  t('Provide the full text of the trial URL (e.g. http://www.trial.com/trial?id=123).');
  t('Related Documents');
  t('Related documents will be shown along with the offer while it is active and in the offer history once the offer expires. Documents like agreement forms (which need to be available for reference indefinitely) should be included here, but documents like pricing schedules (which are only applicable while the offer is active) should <strong>not</strong> be placed here.');
  t('Related resource');
  t('See');
  t('See Also');
  t('Select the status values that <em>currently</em> apply. Note that any "Offer Information" or "Trial Information" details entered below will not be displayed to users unless the respective status is enabled here.');
  t('Select which CRL group(s) this offer should be visible to. Use ctrl+click to choose multiple. Note that the "CRL Members" option is special in that deselecting it will not remove member view access (CRL members can always view <strong>all</strong> offers). However a special note will be displayed to clarify that the offer is group-exclusive when the "CRL Members" option is not selected.');
  t('Subscription Period');
  t('The entity that will handle the billing for this offer.');
  t('This field will only be visible to member users before an offer is active (CRL status "Flagged", "Pending" or "Declined"). It can be used to show general notes about CRL work that is not yet officially tied to a specific offer or trial.');
  t('This information is for internal use only and is not displayed to any site users.');
  t('Trial Duration');
  t('Trial Link');
  t('Typically this value will be auto-filled for you.');
  t('Use this space to add any general notes that are not specific to the offer or trial information above, and should be shown at the end of the page.');

  return $field_instances;
}
