<?php

/**
 * @file
 * crl_pp_resource_feat.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function crl_pp_resource_feat_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_currency_cad_usd'.
  $field_bases['field_currency_cad_usd'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_currency_cad_usd',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'decimal_separator' => '.',
    ),
    'translatable' => 0,
    'type' => 'number_float',
  );

  // Exported field_base: 'field_pp_attachments'.
  $field_bases['field_pp_attachments'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_attachments',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 1,
      'display_field' => 1,
      'uri_scheme' => 'private',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_pp_crl_comments'.
  $field_bases['field_pp_crl_comments'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_crl_comments',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_pp_discounted_price'.
  $field_bases['field_pp_discounted_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_discounted_price',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_pp_languages'.
  $field_bases['field_pp_languages'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_languages',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_pp_nomination_crl_holdings'.
  $field_bases['field_pp_nomination_crl_holdings'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_nomination_crl_holdings',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Fills' => 'Yes, Fills in',
        'Completes' => 'Yes, Completes',
        'No' => 'No',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_pp_nominator_comments'.
  $field_bases['field_pp_nominator_comments'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_nominator_comments',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_pp_nominator_institution'.
  $field_bases['field_pp_nominator_institution'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_nominator_institution',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_pp_notes'.
  $field_bases['field_pp_notes'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_notes',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_pp_piece_count_and_pricing'.
  $field_bases['field_pp_piece_count_and_pricing'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_piece_count_and_pricing',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_pp_proposal_purchased'.
  $field_bases['field_pp_proposal_purchased'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_proposal_purchased',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'No',
        1 => 'Yes',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_pp_publisher'.
  $field_bases['field_pp_publisher'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_publisher',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_pp_purchase_status'.
  $field_bases['field_pp_purchase_status'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_purchase_status',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'not_balloted' => 'Not Balloted',
        'no' => 'Not Purchased',
        'yes' => 'Purchased',
        'spp' => 'Deferred to Shared Purchase',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_pp_related'.
  $field_bases['field_pp_related'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_related',
    'field_permissions' => array(
      'type' => 2,
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'views',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'view' => array(
          'args' => array(),
          'display_name' => 'entityreference_1',
          'view_name' => 'pp_resource_votes_admin',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_pp_sp_target_price'.
  $field_bases['field_pp_sp_target_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_sp_target_price',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_pp_subject_area'.
  $field_bases['field_pp_subject_area'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_subject_area',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Africa' => 'Africa',
        'Anthropology' => 'Anthropology',
        'Art' => 'Art',
        'Architecture' => 'Architecture',
        'Asia' => 'Asia',
        'Austria' => 'Austria',
        'Black studies' => 'Black studies',
        'Brazil' => 'Brazil',
        'Broadcasting' => 'Broadcasting',
        'Canada' => 'Canada',
        'Caribbean' => 'Caribbean',
        'Census' => 'Census',
        'China' => 'China',
        'Cities' => 'Cities',
        'Colonies' => 'Colonies',
        'Commerce' => 'Commerce',
        'Communism' => 'Communism',
        'Eastern Europe' => 'Eastern Europe',
        'Economics' => 'Economics',
        'Education' => 'Education',
        'El Salvador' => 'El Salvador',
        'Europe' => 'Europe',
        'Foreign relations' => 'Foreign relations',
        'Foreign trade' => 'Foreign trade',
        'France' => 'France',
        'Gender studies' => 'Gender studies',
        'Germany' => 'Germany',
        'Government agencies' => 'Government agencies',
        'Government publications' => 'Government publications',
        'Great Britain' => 'Great Britain',
        'Greece' => 'Greece',
        'Human rights' => 'Human rights',
        'Hungary' => 'Hungary',
        'India' => 'India',
        'Indians of North America' => 'Indians of North America',
        'Indigenous peoples' => 'Indigenous peoples',
        'International trade' => 'International trade',
        'Italy' => 'Italy',
        'Japan' => 'Japan',
        'Labor' => 'Labor',
        'Latin America' => 'Latin America',
        'Bangladesh' => 'Bangladesh',
        'Central America' => 'Central America',
        'Egypt' => 'Egypt',
        'Holocaust' => 'Holocaust',
        'Iran' => 'Iran',
        'Iraq' => 'Iraq',
        'Israel' => 'Israel',
        'Law' => 'Law',
        'Lebanon' => 'Lebanon',
        'Legal history' => 'Legal history',
        'Literature' => 'Literature',
        'Manufacturing' => 'Manufacturing',
        'Medicine' => 'Medicine',
        'Mexico' => 'Mexico',
        'Middle Ages' => 'Middle Ages',
        'Middle East' => 'Middle East',
        'Missionary societies' => 'Missionary societies',
        'Morocco' => 'Morocco',
        'Music' => 'Music',
        'National socialism' => 'National socialism',
        'National security' => 'National security',
        'Netherlands' => 'Netherlands',
        'Nepal' => 'Nepal',
        'Nicaragua' => 'Nicaragua',
        'Philosophy' => 'Philosophy',
        'Pakistan' => 'Pakistan',
        'Photography' => 'Photography',
        'Poland' => 'Poland',
        'Portugal' => 'Portugal',
        'Politics' => 'Politics',
        'Railroads' => 'Railroads',
        'Religion' => 'Religion',
        'Russia' => 'Russia',
        'Saudi Arabia' => 'Saudi Arabia',
        'Science' => 'Science',
        'Slavery' => 'Slavery',
        'Socialism' => 'Socialism',
        'South Asia' => 'South Asia',
        'Southeast Asia' => 'Southeast Asia',
        'South America' => 'South America',
        'Soviet Union' => 'Soviet Union',
        'Spain' => 'Spain',
        'Syria' => 'Syria',
        'Technology' => 'Technology',
        'Theater' => 'Theater',
        'Turkey' => 'Turkey',
        'United Nations' => 'United Nations',
        'United States' => 'United States',
        'Vietnam' => 'Vietnam',
        'Water' => 'Water',
        'Western Europe' => 'Western Europe',
        'War' => 'War',
        'War crimes' => 'War crimes',
        'World War I' => 'World War I',
        'World War II' => 'World War II',
        'News' => 'News',
        'Dissertations' => 'Dissertations',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_pp_summary_comments'.
  $field_bases['field_pp_summary_comments'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pp_summary_comments',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_voting_results'.
  $field_bases['field_voting_results'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_voting_results',
    'field_permissions' => array(
      'type' => 2,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'viewfield',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'viewfield',
  );

  return $field_bases;
}
