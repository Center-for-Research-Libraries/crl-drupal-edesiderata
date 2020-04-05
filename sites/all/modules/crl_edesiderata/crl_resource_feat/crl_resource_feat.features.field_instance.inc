<?php

/**
 * @file
 * crl_resource_feat.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function crl_resource_feat_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'comment-comment_node_resource-comment_body'.
  $field_instances['comment-comment_node_resource-comment_body'] = array(
    'bundle' => 'comment_node_resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'comment_body',
    'label' => 'Comment',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
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
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'comment-comment_node_resource-field_comment_privacy'.
  $field_instances['comment-comment_node_resource-field_comment_privacy'] = array(
    'bundle' => 'comment_node_resource',
    'default_value' => array(
      0 => array(
        'value' => 'normal',
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'field_comment_privacy',
    'label' => 'Comment Privacy Setting',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'entityform-resource_suggestion-field_further_description'.
  $field_instances['entityform-resource_suggestion-field_further_description'] = array(
    'bundle' => 'resource_suggestion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Include any information about this resource that will be useful for other users of this site.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_further_description',
    'label' => 'Description',
    'required' => 1,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'entityform-resource_suggestion-field_internal_notes'.
  $field_instances['entityform-resource_suggestion-field_internal_notes'] = array(
    'bundle' => 'resource_suggestion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_internal_notes',
    'label' => 'Internal Notes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'entityform-resource_suggestion-field_misc_notes'.
  $field_instances['entityform-resource_suggestion-field_misc_notes'] = array(
    'bundle' => 'resource_suggestion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please tell us your motivation for including this resource in the eDesiderata listings along with any additional comments you may have.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_misc_notes',
    'label' => 'Motivation and Comments',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 10,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'entityform-resource_suggestion-field_resource_attachments'.
  $field_instances['entityform-resource_suggestion-field_resource_attachments'] = array(
    'bundle' => 'resource_suggestion',
    'deleted' => 0,
    'description' => 'If additional resource details are available as an attachment, please upload your attachment here.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_resource_attachments',
    'label' => 'Attachments',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'resource_docs/suggested',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'entityform-resource_suggestion-field_resource_provider_text'.
  $field_instances['entityform-resource_suggestion-field_resource_provider_text'] = array(
    'bundle' => 'resource_suggestion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_resource_provider_text',
    'label' => 'Resource Provider/Publisher',
    'required' => 1,
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
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'entityform-resource_suggestion-field_resource_reference'.
  $field_instances['entityform-resource_suggestion-field_resource_reference'] = array(
    'bundle' => 'resource_suggestion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_resource_reference',
    'label' => 'Converted resource',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'entityform-resource_suggestion-field_resource_type'.
  $field_instances['entityform-resource_suggestion-field_resource_type'] = array(
    'bundle' => 'resource_suggestion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_resource_type',
    'label' => 'Resource Types',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'entityform-resource_suggestion-field_subject_area'.
  $field_instances['entityform-resource_suggestion-field_subject_area'] = array(
    'bundle' => 'resource_suggestion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_subject_area',
    'label' => 'Subject Areas',
    'required' => 1,
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

  // Exported field_instance: 'entityform-resource_suggestion-field_title_sort'.
  $field_instances['entityform-resource_suggestion-field_title_sort'] = array(
    'bundle' => 'resource_suggestion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_title_sort',
    'label' => 'Resource Title',
    'required' => 1,
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
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'flagging-resource_suggestion_process-field_crl_processing_notes'.
  $field_instances['flagging-resource_suggestion_process-field_crl_processing_notes'] = array(
    'bundle' => 'resource_suggestion_process',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Provide a <strong>very brief</strong> explanation about why this suggestion was rejected. <strong>These notes will be shown publicly</strong>.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'flagging',
    'field_name' => 'field_crl_processing_notes',
    'label' => 'CRL Comment',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'flagging-resource_suggestion_process-field_provider'.
  $field_instances['flagging-resource_suggestion_process-field_provider'] = array(
    'bundle' => 'resource_suggestion_process',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the provider that this resource should be associated with.<br/><strong class="important">If the provider value does not yet exist in the system please create it before continuing</strong>.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'flagging',
    'field_name' => 'field_provider',
    'label' => 'Provider',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'flagging-resource_suggestion_process-field_resource_suggestion_status'.
  $field_instances['flagging-resource_suggestion_process-field_resource_suggestion_status'] = array(
    'bundle' => 'resource_suggestion_process',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'flagging',
    'field_name' => 'field_resource_suggestion_status',
    'label' => 'Action',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-resource-body'.
  $field_instances['node-resource-body'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 923,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 62,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Abstract',
    'required' => 0,
    'settings' => array(
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-resource-field_content_scope_and_complete'.
  $field_instances['node-resource-field_content_scope_and_complete'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'fivestar',
        'settings' => array(
          'expose' => 1,
          'style' => 'dual',
          'text' => 'dual',
          'widget' => array(
            'fivestar_widget' => 'default',
          ),
        ),
        'type' => 'fivestar_formatter_default',
        'weight' => 24,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_content_scope_and_complete',
    'label' => 'Content scope and completeness',
    'required' => 0,
    'settings' => array(
      'allow_clear' => 0,
      'allow_ownvote' => TRUE,
      'allow_revote' => TRUE,
      'stars' => 5,
      'target' => 'none',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'fivestar',
      'settings' => array(),
      'type' => 'exposed',
      'weight' => 148,
    ),
  );

  // Exported field_instance: 'node-resource-field_cost_and_price_structure'.
  $field_instances['node-resource-field_cost_and_price_structure'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'fivestar',
        'settings' => array(
          'expose' => 1,
          'style' => 'dual',
          'text' => 'dual',
          'widget' => array(
            'fivestar_widget' => 'default',
          ),
        ),
        'type' => 'fivestar_formatter_default',
        'weight' => 25,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cost_and_price_structure',
    'label' => 'Cost and price-structure',
    'required' => 0,
    'settings' => array(
      'allow_clear' => 0,
      'allow_ownvote' => TRUE,
      'allow_revote' => TRUE,
      'stars' => 5,
      'target' => 'none',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'fivestar',
      'settings' => array(),
      'type' => 'exposed',
      'weight' => 146,
    ),
  );

  // Exported field_instance: 'node-resource-field_facets'.
  $field_instances['node-resource-field_facets'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select any subjects/facets that apply to this resource. These will be used for dynamic linking relationships with the main CRL website.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_facets',
    'label' => 'Facets',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 133,
    ),
  );

  // Exported field_instance: 'node-resource-field_internal_notes'.
  $field_instances['node-resource-field_internal_notes'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This information is for internal use only and is not displayed to any site users.',
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
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-resource-field_link'.
  $field_instances['node-resource-field_link'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_link',
    'label' => 'Access Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_allowed_values' => '',
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
      'weight' => 144,
    ),
  );

  // Exported field_instance: 'node-resource-field_platform_and_user_interfac'.
  $field_instances['node-resource-field_platform_and_user_interfac'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'fivestar',
        'settings' => array(
          'expose' => 1,
          'style' => 'dual',
          'text' => 'dual',
          'widget' => array(
            'fivestar_widget' => 'default',
          ),
        ),
        'type' => 'fivestar_formatter_default',
        'weight' => 23,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 62,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_platform_and_user_interfac',
    'label' => 'Platform and user interface',
    'required' => 0,
    'settings' => array(
      'allow_clear' => 0,
      'allow_ownvote' => TRUE,
      'allow_revote' => TRUE,
      'stars' => 5,
      'target' => 'none',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'fivestar',
      'settings' => array(),
      'type' => 'exposed',
      'weight' => 147,
    ),
  );

  // Exported field_instance: 'node-resource-field_provider'.
  $field_instances['node-resource-field_provider'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the provider that this resource should be associated with.<br/><strong class="important">If the provider value does not yet exist in the system please create it before working with this resource entry</strong>.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 925,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 58,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_provider',
    'label' => 'Provider',
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

  // Exported field_instance: 'node-resource-field_resource_activity_history'.
  $field_instances['node-resource-field_resource_activity_history'] = array(
    'bundle' => 'resource',
    'default_value' => array(
      0 => array(
        'vname' => 'activity_history|default',
        'vargs' => '[node:nid]',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 1001,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_activity_history',
    'label' => 'Offer History',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'activity_history' => 'activity_history',
        'admin_votes' => 0,
        'comment_summary' => 0,
        'content_summary' => 0,
        'crl_messages' => 0,
        'crl_staff' => 0,
        'csv_exports' => 0,
        'entityform_type_list' => 0,
        'entityforms' => 0,
        'feeds_log' => 0,
        'institution_admin_lists' => 0,
        'message' => 0,
        'mydes_lists' => 0,
        'mydes_saved_searches' => 0,
        'pp_nominations' => 0,
        'pp_resource_export' => 0,
        'pp_resource_lists' => 0,
        'pp_resource_votes_admin' => 0,
        'pp_resource_votes_admin_details_' => 0,
        'provider_lists' => 0,
        'resource_dashboard' => 0,
        'resource_lists' => 0,
        'resource_votes_admin' => 0,
        'resource_votes_admin_details_' => 0,
        'reviews_export' => 0,
        'subscribe_node' => 0,
        'subscribe_node_email' => 0,
        'subscribe_taxonomy_term' => 0,
        'subscribe_taxonomy_term_email' => 0,
        'subscribe_user' => 0,
        'subscribe_user_email' => 0,
        'temp_provider_contact_list' => 0,
        'temp_provider_contacts' => 0,
        'user_entityforms' => 0,
      ),
      'force_default' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 145,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_analysis_notes'.
  $field_instances['node-resource-field_resource_analysis_notes'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 95,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_analysis_notes',
    'label' => 'Endnotes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
      ),
      'type' => 'text_textarea',
      'weight' => 142,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_appendix_notes'.
  $field_instances['node-resource-field_resource_appendix_notes'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_appendix_notes',
    'label' => 'Appendix Notes',
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
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_attachments'.
  $field_instances['node-resource-field_resource_attachments'] = array(
    'bundle' => 'resource',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 5,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_attachments',
    'label' => 'Attachments',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => 'resource_docs',
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
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_coll_content'.
  $field_instances['node-resource-field_resource_coll_content'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_coll_content',
    'label' => 'Collection Content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
      ),
      'type' => 'text_textarea',
      'weight' => 134,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_coll_content_tb'.
  $field_instances['node-resource-field_resource_coll_content_tb'] = array(
    'bundle' => 'resource',
    'default_value' => array(
      0 => array(
        'tablefield' => array(
          'caption' => '',
          'import' => array(
            'file' => '',
            'import' => 'Upload CSV',
          ),
          'paste' => array(
            'data' => '',
            'paste_delimiter' => '',
            'paste_import' => 'Import & Rebuild',
          ),
          'rebuild' => array(
            'count_cols' => 1,
            'count_rows' => 1,
            'rebuild' => 'Rebuild Table',
          ),
          'tabledata' => array(
            'row_0' => array(
              'col_0' => '',
              'weight' => 1,
            ),
          ),
        ),
        'format' => 'full_html',
      ),
    ),
    'deleted' => 0,
    'description' => 'The first row will appear as the table header. Leave the first row blank if you do not need a header.<br />
You may append the token <strong>[provider]</strong> after any line of text to add a "Direct from publisher" icon to that cell.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'tablefield',
        'settings' => array(
          'export_csv' => 0,
          'header_orientation' => 'Horizontal',
          'hide_cols_skip_head' => FALSE,
          'hide_empty_cols' => FALSE,
          'hide_empty_rows' => FALSE,
          'hide_header' => 0,
          'sortable' => FALSE,
          'sticky_header' => TRUE,
          'striping' => TRUE,
          'trim_trailing_cols' => FALSE,
          'trim_trailing_rows' => FALSE,
        ),
        'type' => 'tablefield_default',
        'weight' => 907,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(
          'export_csv' => 0,
          'hide_header' => 0,
        ),
        'type' => 'hidden',
        'weight' => 57,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(
          'export_csv' => 0,
          'hide_header' => 0,
        ),
        'type' => 'hidden',
        'weight' => 61,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_coll_content_tb',
    'label' => 'Content Details',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'tablefield',
      'settings' => array(
        'cell_processing' => 1,
        'data_sources' => array(
          'paste' => 'paste',
          'upload' => 'upload',
        ),
        'input_type' => 'textfield',
        'lock_values' => 0,
        'max_length' => 2048,
        'restrict_rebuild' => 1,
      ),
      'type' => 'tablefield',
      'weight' => 124,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_contributors'.
  $field_instances['node-resource-field_resource_contributors'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_contributors',
    'label' => 'Contributors',
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
      'weight' => 139,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_delivery'.
  $field_instances['node-resource-field_resource_delivery'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_delivery',
    'label' => 'Delivery',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
      ),
      'type' => 'text_textarea',
      'weight' => 135,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_external_reviews'.
  $field_instances['node-resource-field_resource_external_reviews'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 94,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_external_reviews',
    'label' => 'Additional Reviews in Other Sources',
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
      'weight' => 141,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_gen_specs'.
  $field_instances['node-resource-field_resource_gen_specs'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use this space to list specifications that cannot be structured within other resource fields or in the data tables below. The structure for this field is completely at the editors discretion and if multiple sections are required they should be separated by 3rd-level headings. No label will be shown for this field.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1002,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_gen_specs',
    'label' => 'General Specifications',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
      ),
      'type' => 'text_textarea',
      'weight' => 122,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_interf_tools_tb'.
  $field_instances['node-resource-field_resource_interf_tools_tb'] = array(
    'bundle' => 'resource',
    'default_value' => array(
      0 => array(
        'tablefield' => array(
          'caption' => NULL,
          'import' => array(
            'file' => '',
            'import' => 'Upload CSV',
          ),
          'paste' => NULL,
          'rebuild' => array(
            'count_cols' => 1,
            'count_rows' => 1,
            'rebuild' => 'Rebuild Table',
          ),
          'tabledata' => array(
            'row_0' => array(
              'col_0' => '',
            ),
          ),
        ),
        'format' => 'full_html',
      ),
    ),
    'deleted' => 0,
    'description' => 'The first row will appear as the table header. Leave the first row blank if you do not need a header.<br />
You may append the token <strong>[provider]</strong> after any line of text to add a "Direct from publisher" icon to that cell.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'tablefield',
        'settings' => array(
          'export_csv' => 0,
          'header_orientation' => 'Horizontal',
          'hide_cols_skip_head' => FALSE,
          'hide_empty_cols' => FALSE,
          'hide_empty_rows' => FALSE,
          'hide_header' => 0,
          'sortable' => FALSE,
          'sticky_header' => TRUE,
          'striping' => TRUE,
          'trim_trailing_cols' => FALSE,
          'trim_trailing_rows' => FALSE,
        ),
        'type' => 'tablefield_default',
        'weight' => 1006,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(
          'export_csv' => 0,
          'hide_header' => 0,
        ),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(
          'export_csv' => 0,
          'hide_header' => 0,
        ),
        'type' => 'hidden',
        'weight' => 52,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_interf_tools_tb',
    'label' => 'Interface Tools',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'tablefield',
      'settings' => array(
        'cell_processing' => 1,
        'lock_values' => 0,
        'restrict_rebuild' => 1,
      ),
      'type' => 'tablefield',
      'weight' => 127,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_languages'.
  $field_instances['node-resource-field_resource_languages'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 905,
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
        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_languages',
    'label' => 'Major Languages',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 121,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_metadata_tb'.
  $field_instances['node-resource-field_resource_metadata_tb'] = array(
    'bundle' => 'resource',
    'default_value' => array(
      0 => array(
        'tablefield' => array(
          'caption' => NULL,
          'import' => array(
            'rebuild_field_resource_metadata_tb_0' => 'Upload CSV',
            'tablefield_csv_field_resource_metadata_tb_0' => '',
          ),
          'paste' => NULL,
          'rebuild' => array(
            'count_cols' => 1,
            'count_rows' => 1,
            'rebuild' => 'Rebuild Table',
          ),
          'tabledata' => array(
            'row_0' => array(
              'col_0' => '',
            ),
          ),
        ),
        'format' => 'full_html',
      ),
    ),
    'deleted' => 0,
    'description' => 'The first row will appear as the table header. Leave the first row blank if you do not need a header.<br />
You may append the token <strong>[provider]</strong> after any line of text to add a "Direct from publisher" icon to that cell.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'tablefield',
        'settings' => array(
          'export_csv' => 0,
          'header_orientation' => 'Horizontal',
          'hide_cols_skip_head' => FALSE,
          'hide_empty_cols' => FALSE,
          'hide_empty_rows' => FALSE,
          'hide_header' => 0,
          'sortable' => FALSE,
          'sticky_header' => TRUE,
          'striping' => TRUE,
          'trim_trailing_cols' => FALSE,
          'trim_trailing_rows' => FALSE,
        ),
        'type' => 'tablefield_default',
        'weight' => 1004,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(
          'export_csv' => 0,
          'hide_header' => 0,
        ),
        'type' => 'hidden',
        'weight' => 56,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(
          'export_csv' => 0,
          'hide_header' => 0,
        ),
        'type' => 'hidden',
        'weight' => 57,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_metadata_tb',
    'label' => 'Metadata',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'tablefield',
      'settings' => array(
        'cell_processing' => 1,
        'lock_values' => 0,
        'restrict_rebuild' => 1,
      ),
      'type' => 'tablefield',
      'weight' => 125,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_provider_notes'.
  $field_instances['node-resource-field_resource_provider_notes'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter any special <em>resource-specific</em> notes that relate to the provider. These notes will be shown near the other provider information that\'s taken from the provider\'s profile.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
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
        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_provider_notes',
    'label' => 'Provider Notes',
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
      'weight' => 129,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_reviewers'.
  $field_instances['node-resource-field_resource_reviewers'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 21,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_reviewers',
    'label' => 'Reviewers',
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
      'weight' => 138,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_source_status'.
  $field_instances['node-resource-field_resource_source_status'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => 'Select the option that best represents where this entry was sourced from.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_source_status',
    'label' => 'Source status',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_strength_weak'.
  $field_instances['node-resource-field_resource_strength_weak'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
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
        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_strength_weak',
    'label' => 'Strengths and Weaknesses',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
      ),
      'type' => 'text_textarea',
      'weight' => 137,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_tech_platform_tb'.
  $field_instances['node-resource-field_resource_tech_platform_tb'] = array(
    'bundle' => 'resource',
    'default_value' => array(
      0 => array(
        'tablefield' => array(
          'caption' => NULL,
          'import' => array(
            'file' => '',
            'import' => 'Upload CSV',
          ),
          'paste' => NULL,
          'rebuild' => array(
            'count_cols' => 1,
            'count_rows' => 1,
            'rebuild' => 'Rebuild Table',
          ),
          'tabledata' => array(
            'row_0' => array(
              'col_0' => '',
            ),
          ),
        ),
        'format' => 'full_html',
      ),
    ),
    'deleted' => 0,
    'description' => 'The first row will appear as the table header. Leave the first row blank if you do not need a header.<br />
You may append the token <strong>[provider]</strong> after any line of text to add a "Direct from publisher" icon to that cell.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'tablefield',
        'settings' => array(
          'export_csv' => 0,
          'header_orientation' => 'Horizontal',
          'hide_cols_skip_head' => FALSE,
          'hide_empty_cols' => FALSE,
          'hide_empty_rows' => FALSE,
          'hide_header' => 0,
          'sortable' => FALSE,
          'sticky_header' => TRUE,
          'striping' => TRUE,
          'trim_trailing_cols' => FALSE,
          'trim_trailing_rows' => FALSE,
        ),
        'type' => 'tablefield_default',
        'weight' => 1005,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(
          'export_csv' => 0,
          'hide_header' => 0,
        ),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(
          'export_csv' => 0,
          'hide_header' => 0,
        ),
        'type' => 'hidden',
        'weight' => 56,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_tech_platform_tb',
    'label' => 'Technical Platform',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'tablefield',
      'settings' => array(
        'cell_processing' => 1,
        'lock_values' => 0,
        'restrict_rebuild' => 1,
      ),
      'type' => 'tablefield',
      'weight' => 126,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_terms'.
  $field_instances['node-resource-field_resource_terms'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 19,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_terms',
    'label' => 'Terms',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
      ),
      'type' => 'text_textarea',
      'weight' => 136,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_terms_tb'.
  $field_instances['node-resource-field_resource_terms_tb'] = array(
    'bundle' => 'resource',
    'default_value' => array(
      0 => array(
        'tablefield' => array(
          'caption' => NULL,
          'import' => array(
            'file' => '',
            'import' => 'Upload CSV',
          ),
          'paste' => NULL,
          'rebuild' => array(
            'count_cols' => 1,
            'count_rows' => 1,
            'rebuild' => 'Rebuild Table',
          ),
          'tabledata' => array(
            'row_0' => array(
              'col_0' => '',
            ),
          ),
        ),
        'format' => 'full_html',
      ),
    ),
    'deleted' => 0,
    'description' => 'The first row will appear as the table header. Leave the first row blank if you do not need a header.<br />
You may append the token <strong>[provider]</strong> after any line of text to add a "Direct from publisher" icon to that cell.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'tablefield',
        'settings' => array(
          'export_csv' => 0,
          'header_orientation' => 'Horizontal',
          'hide_cols_skip_head' => FALSE,
          'hide_empty_cols' => FALSE,
          'hide_empty_rows' => FALSE,
          'hide_header' => 0,
          'sortable' => FALSE,
          'sticky_header' => TRUE,
          'striping' => TRUE,
          'trim_trailing_cols' => FALSE,
          'trim_trailing_rows' => FALSE,
        ),
        'type' => 'tablefield_default',
        'weight' => 6,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(
          'export_csv' => 0,
          'hide_header' => 0,
        ),
        'type' => 'hidden',
        'weight' => 53,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(
          'export_csv' => 0,
          'hide_header' => 0,
        ),
        'type' => 'hidden',
        'weight' => 51,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_terms_tb',
    'label' => 'Terms',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'tablefield',
      'settings' => array(
        'cell_processing' => 1,
        'lock_values' => 0,
        'restrict_rebuild' => 1,
      ),
      'type' => 'tablefield',
      'weight' => 128,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_title_lists'.
  $field_instances['node-resource-field_resource_title_lists'] = array(
    'bundle' => 'resource',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 4,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_title_lists',
    'label' => 'Title List',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => 'resource_docs',
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
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-resource-field_resource_type'.
  $field_instances['node-resource-field_resource_type'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please select all that apply.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 929,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 60,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_type',
    'label' => 'Resource Types',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-resource-field_see'.
  $field_instances['node-resource-field_see'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If this entry represents an alias or derivative version of another one, add a link to the entry that should be considered the canonical (master) version. If you place a value in this field you will most likely leave almost all other fields blank for this entry.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 931,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_see',
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
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-resource-field_see_also'.
  $field_instances['node-resource-field_see_also'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If this entry has relationships with other entries, add links to those entries here (one or more as needed).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 932,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_see_also',
    'label' => 'See also',
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
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-resource-field_source_guid'.
  $field_instances['node-resource-field_source_guid'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_source_guid',
    'label' => 'Source GUID',
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
      'weight' => 143,
    ),
  );

  // Exported field_instance: 'node-resource-field_subject_area'.
  $field_instances['node-resource-field_subject_area'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please select all that apply.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 928,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_subject_area',
    'label' => 'Subject Areas',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-resource-field_temp_subjects_covered'.
  $field_instances['node-resource-field_temp_subjects_covered'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_temp_subjects_covered',
    'label' => 'TEMP - Subjects Covered from Review',
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
      'weight' => 152,
    ),
  );

  // Exported field_instance: 'node-resource-field_temp_topics_from_review'.
  $field_instances['node-resource-field_temp_topics_from_review'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_temp_topics_from_review',
    'label' => 'TEMP - Topics from Review',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 151,
    ),
  );

  // Exported field_instance: 'node-resource-field_title_sort'.
  $field_instances['node-resource-field_title_sort'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This value is used for sorting when multiple resources are listed in indices. Remove any articles (such as "the") from the beginning of the title to craft this sorting title.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_title_sort',
    'label' => 'Sorting Title',
    'required' => 1,
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-resource-field_update_alert'.
  $field_instances['node-resource-field_update_alert'] = array(
    'bundle' => 'resource',
    'deleted' => 0,
    'description' => 'Flag this item with an "update alert" until this date.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'embedded' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_update_alert',
    'label' => 'Update Alert Expiration',
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
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 131,
    ),
  );

  // Exported field_instance: 'node-resource-field_update_alert_message'.
  $field_instances['node-resource-field_update_alert_message'] = array(
    'bundle' => 'resource',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The message to display along with the "update alert" when a user views the related resource.',
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
        'weight' => 27,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_update_alert_message',
    'label' => 'Update Alert Message',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
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
      'weight' => 132,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Abstract');
  t('Access Link');
  t('Action');
  t('Additional Reviews in Other Sources');
  t('Appendix Notes');
  t('Attachments');
  t('CRL Comment');
  t('Collection Content');
  t('Comment');
  t('Comment Privacy Setting');
  t('Content Details');
  t('Content scope and completeness');
  t('Contributors');
  t('Converted resource');
  t('Cost and price-structure');
  t('Delivery');
  t('Description');
  t('Endnotes');
  t('Enter any special <em>resource-specific</em> notes that relate to the provider. These notes will be shown near the other provider information that\'s taken from the provider\'s profile.');
  t('Facets');
  t('Flag this item with an "update alert" until this date.');
  t('General Specifications');
  t('If additional resource details are available as an attachment, please upload your attachment here.');
  t('If this entry has relationships with other entries, add links to those entries here (one or more as needed).');
  t('If this entry represents an alias or derivative version of another one, add a link to the entry that should be considered the canonical (master) version. If you place a value in this field you will most likely leave almost all other fields blank for this entry.');
  t('Include any information about this resource that will be useful for other users of this site.');
  t('Interface Tools');
  t('Internal Notes');
  t('Major Languages');
  t('Metadata');
  t('Motivation and Comments');
  t('Offer History');
  t('Platform and user interface');
  t('Please select all that apply.');
  t('Please tell us your motivation for including this resource in the eDesiderata listings along with any additional comments you may have.');
  t('Provide a <strong>very brief</strong> explanation about why this suggestion was rejected. <strong>These notes will be shown publicly</strong>.');
  t('Provider');
  t('Provider Notes');
  t('Resource Provider/Publisher');
  t('Resource Title');
  t('Resource Types');
  t('Reviewers');
  t('See');
  t('See also');
  t('Select any subjects/facets that apply to this resource. These will be used for dynamic linking relationships with the main CRL website.');
  t('Select the option that best represents where this entry was sourced from.');
  t('Select the provider that this resource should be associated with.<br/><strong class="important">If the provider value does not yet exist in the system please create it before continuing</strong>.');
  t('Select the provider that this resource should be associated with.<br/><strong class="important">If the provider value does not yet exist in the system please create it before working with this resource entry</strong>.');
  t('Sorting Title');
  t('Source GUID');
  t('Source status');
  t('Strengths and Weaknesses');
  t('Subject Areas');
  t('TEMP - Subjects Covered from Review');
  t('TEMP - Topics from Review');
  t('Technical Platform');
  t('Terms');
  t('The first row will appear as the table header. Leave the first row blank if you do not need a header.<br />
You may append the token <strong>[provider]</strong> after any line of text to add a "Direct from publisher" icon to that cell.');
  t('The first row will appear as the table header. Leave the first row blank if you do not need a header.<br />
You may append the token <strong>[provider]</strong> after any line of text to add a "Direct from publisher" icon to that cell.');
  t('The message to display along with the "update alert" when a user views the related resource.');
  t('This information is for internal use only and is not displayed to any site users.');
  t('This value is used for sorting when multiple resources are listed in indices. Remove any articles (such as "the") from the beginning of the title to craft this sorting title.');
  t('Title List');
  t('Update Alert Expiration');
  t('Update Alert Message');
  t('Use this space to list specifications that cannot be structured within other resource fields or in the data tables below. The structure for this field is completely at the editors discretion and if multiple sections are required they should be separated by 3rd-level headings. No label will be shown for this field.');

  return $field_instances;
}
