<?php

/**
 * @file
 * crl_pp_resource_feat.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function crl_pp_resource_feat_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|pp_resource|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pp_resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '10',
    'children' => array(
      0 => 'body',
      1 => 'field_pp_notes',
      2 => 'field_pp_piece_count_and_pricing',
      3 => 'field_pp_publisher',
      4 => 'field_pp_subject_area',
      5 => 'field_pp_attachments',
      6 => 'field_link',
      7 => 'field_pp_languages',
      8 => 'pseudo_field_pp_resource_source_notice',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-details field-group-htab',
      ),
    ),
  );
  $field_groups['group_details|node|pp_resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|pp_resource|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pp_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '25',
    'children' => array(
      0 => 'body',
      1 => 'field_pp_notes',
      2 => 'field_pp_piece_count_and_pricing',
      3 => 'field_pp_publisher',
      4 => 'field_pp_subject_area',
      5 => 'field_pp_attachments',
      6 => 'field_contacts',
      7 => 'field_link',
      8 => 'field_pp_languages',
      9 => 'group_nominator',
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
  $field_groups['group_details|node|pp_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|spp_resource|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'spp_resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '21',
    'children' => array(
      0 => 'body',
      1 => 'field_pp_notes',
      2 => 'field_pp_piece_count_and_pricing',
      3 => 'field_pp_publisher',
      4 => 'field_pp_subject_area',
      5 => 'field_pp_attachments',
      6 => 'field_link',
      7 => 'field_pp_languages',
      8 => 'pseudo_field_pp_resource_source_notice',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-details field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_details|node|spp_resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|spp_resource|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'spp_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '25',
    'children' => array(
      0 => 'body',
      1 => 'field_pp_notes',
      2 => 'field_pp_piece_count_and_pricing',
      3 => 'field_pp_publisher',
      4 => 'field_pp_subject_area',
      5 => 'field_pp_attachments',
      6 => 'field_link',
      7 => 'field_pp_languages',
      8 => 'group_nominator',
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
  $field_groups['group_details|node|spp_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nominator|node|pp_resource|form';
  $field_group->group_name = 'group_nominator';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pp_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Nominator',
    'weight' => '23',
    'children' => array(
      0 => 'field_pp_nominator_institution',
      1 => 'field_contact_email',
      2 => 'field_contact_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-nominator field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_nominator|node|pp_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nominator|node|spp_resource|form';
  $field_group->group_name = 'group_nominator';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'spp_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Nominator',
    'weight' => '22',
    'children' => array(
      0 => 'field_pp_nominator_institution',
      1 => 'field_contact_email',
      2 => 'field_contact_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-nominator field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_nominator|node|spp_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_official|entityform|purchase_proposal_nomination|form';
  $field_group->group_name = 'group_official';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'purchase_proposal_nomination';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Offical Use Only',
    'weight' => '14',
    'children' => array(
      0 => 'field_pp_related',
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
  $field_groups['group_official|entityform|purchase_proposal_nomination|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pp_admin|node|pp_resource|form';
  $field_group->group_name = 'group_pp_admin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pp_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Administrative Fields',
    'weight' => '2',
    'children' => array(
      0 => 'field_pp_related',
      1 => 'field_pp_sp_target_price',
      2 => 'field_fy',
      3 => 'field_pp_purchase_status',
      4 => 'field_pp_proposal_purchased',
      5 => 'field_pp_discounted_price',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Administrative Fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'node_pp_resource_form_group_pp_admin',
        'classes' => 'notice-box',
        'description' => '<b>These fields are for administrative purpose and will not be displayed in any public views</b>',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'slow',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_pp_admin|node|pp_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pp_admin|node|spp_resource|form';
  $field_group->group_name = 'group_pp_admin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'spp_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Administrative Fields',
    'weight' => '2',
    'children' => array(
      0 => 'field_fy',
      1 => 'field_pp_proposal_purchased',
      2 => 'field_pp_related',
      3 => 'field_pp_sp_target_price',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Administrative Fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'node_spp_resource_form_group_pp_admin',
        'classes' => 'notice-box',
        'description' => '<b>These fields are for administrative purpose and will not be displayed in any public views</b>',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'slow',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_pp_admin|node|spp_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_process|entityform|purchase_proposal_nomination|default';
  $field_group->group_name = 'group_process';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'purchase_proposal_nomination';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Entry Processing',
    'weight' => '14',
    'children' => array(
      0 => 'field_pp_related',
      1 => 'field_internal_notes',
      2 => 'flag_entityform_pp_convert',
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
  $field_groups['group_process|entityform|purchase_proposal_nomination|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rationale|node|pp_resource|default';
  $field_group->group_name = 'group_rationale';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pp_resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Rationale',
    'weight' => '11',
    'children' => array(
      0 => 'field_pp_crl_comments',
      1 => 'field_pp_nominator_comments',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-rationale field-group-htab',
      ),
    ),
  );
  $field_groups['group_rationale|node|pp_resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rationale|node|pp_resource|form';
  $field_group->group_name = 'group_rationale';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pp_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Rationale',
    'weight' => '26',
    'children' => array(
      0 => 'field_pp_crl_comments',
      1 => 'field_pp_nominator_comments',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-rationale field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_rationale|node|pp_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rationale|node|spp_resource|default';
  $field_group->group_name = 'group_rationale';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'spp_resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Rationale',
    'weight' => '22',
    'children' => array(
      0 => 'field_pp_crl_comments',
      1 => 'field_pp_nominator_comments',
      2 => 'field_pp_summary_comments',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-rationale field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_rationale|node|spp_resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rationale|node|spp_resource|form';
  $field_group->group_name = 'group_rationale';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'spp_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Rationale',
    'weight' => '26',
    'children' => array(
      0 => 'field_pp_crl_comments',
      1 => 'field_pp_nominator_comments',
      2 => 'field_pp_summary_comments',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-rationale field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_rationale|node|spp_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_system_fields|node|pp_resource|form';
  $field_group->group_name = 'group_system_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pp_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'System Fields',
    'weight' => '8',
    'children' => array(
      0 => 'field_voting_results',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_system_fields|node|pp_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_system_fields|node|spp_resource|form';
  $field_group->group_name = 'group_system_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'spp_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'System Fields',
    'weight' => '5',
    'children' => array(
      0 => 'field_voting_results',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_system_fields|node|spp_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabbed|node|pp_resource|default';
  $field_group->group_name = 'group_tabbed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pp_resource';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabbed',
    'weight' => '0',
    'children' => array(
      0 => 'group_details',
      1 => 'group_rationale',
      2 => 'group_vote_results',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-tabbed field-group-htabs',
      ),
    ),
  );
  $field_groups['group_tabbed|node|pp_resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabbed|node|pp_resource|form';
  $field_group->group_name = 'group_tabbed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pp_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'tabbed',
    'weight' => '3',
    'children' => array(
      0 => 'group_details',
      1 => 'group_rationale',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-tabbed field-group-htabs',
      ),
    ),
  );
  $field_groups['group_tabbed|node|pp_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabbed|node|spp_resource|default';
  $field_group->group_name = 'group_tabbed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'spp_resource';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabbed',
    'weight' => '0',
    'children' => array(
      0 => 'group_details',
      1 => 'group_rationale',
      2 => 'group_vote_results',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabbed field-group-htabs',
      ),
    ),
  );
  $field_groups['group_tabbed|node|spp_resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabbed|node|spp_resource|form';
  $field_group->group_name = 'group_tabbed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'spp_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'tabbed',
    'weight' => '3',
    'children' => array(
      0 => 'group_details',
      1 => 'group_rationale',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-tabbed field-group-htabs',
      ),
    ),
  );
  $field_groups['group_tabbed|node|spp_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vote_results|node|pp_resource|default';
  $field_group->group_name = 'group_vote_results';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pp_resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Admin Notes & Vote Results',
    'weight' => '12',
    'children' => array(
      0 => 'field_internal_notes',
      1 => 'field_voting_results',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Admin Notes & Vote Results',
      'instance_settings' => array(
        'id' => '',
        'classes' => ' group-vote-results field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_vote_results|node|pp_resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vote_results|node|spp_resource|default';
  $field_group->group_name = 'group_vote_results';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'spp_resource';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabbed';
  $field_group->data = array(
    'label' => 'Admin Notes & Vote Results',
    'weight' => '23',
    'children' => array(
      0 => 'field_internal_notes',
      1 => 'field_voting_results',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Admin Notes & Vote Results',
      'instance_settings' => array(
        'id' => '',
        'classes' => ' group-vote-results field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_vote_results|node|spp_resource|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Admin Notes & Vote Results');
  t('Administrative Fields');
  t('Details');
  t('Entry Processing');
  t('Nominator');
  t('Offical Use Only');
  t('Rationale');
  t('System Fields');
  t('Tabbed');
  t('tabbed');

  return $field_groups;
}
