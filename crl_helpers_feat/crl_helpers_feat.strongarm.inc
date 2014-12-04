<?php
/**
 * @file
 * crl_helpers_feat.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function crl_helpers_feat_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_custom_disabled_strings_en';
  $strongarm->value = array();
  $export['locale_custom_disabled_strings_en'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_custom_strings_en';
  $strongarm->value = array(
    '' => array(
      '%name must be a positive integer.' => '%name must be a positive integer (e.g., 100).',
      '<a href="@login">Log in</a> or <a href="@register">register</a> to post comments' => '<a href="@login">Log in</a> or <a href="@register">sign up</a> to post comments',
      'A valid e-mail address. All e-mails from the system will be sent to this address. The e-mail address is not made public and will only be used if you wish to receive a new password or wish to receive certain news or notifications by e-mail.' => 'Please enter a valid email address, preferably one from your affiliated institution. You will use this email address for all future logins, and CRL will use it for all email communications with you.',
      'Comments' => 'Community comments and discussion',
      'Do you really want to delete this saved search?' => 'Do you really want to delete this watchset?',
      'Once a day in an email digest' => 'Daily email digest',
      'Once a week in an email digest' => 'Weekly email digest',
      'Submitted by !username on !datetime' => '!username on !datetime',
      'The saved search was successfully deleted.' => 'The watchset was successfully deleted.',
      'Your saved search was successfully created.' => 'Your watchset was successfully created in meDesiderata.',
      'Your saved search was successfully created. You will receive e-mail notifications for new results in the future.' => 'Your watchset was successfully created in meDesiderata. You will receive e-mail notifications for new results in the future.',
      'Show End Date' => 'Use End Date',
    ),
  );
  $export['locale_custom_strings_en'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mailsystem_theme';
  $strongarm->value = 'current';
  $export['mailsystem_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mail_system';
  $strongarm->value = array(
    'default-system' => 'DefaultMailSystem',
    'mimemail' => 'MimeMailSystem',
    'search_api_saved_searches' => 'MimeMailSystem',
    'message_notify' => 'MimeMailSystem',
    'message_digest' => 'MimeMailSystem',
    'print_mail' => 'DefaultMailSystem',
  );
  $export['mail_system'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mimemail_format';
  $strongarm->value = 'full_html';
  $export['mimemail_format'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mimemail_linkonly';
  $strongarm->value = 0;
  $export['mimemail_linkonly'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mimemail_mail';
  $strongarm->value = 'websystems@crl.edu';
  $export['mimemail_mail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mimemail_name';
  $strongarm->value = 'eDesiderata';
  $export['mimemail_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mimemail_simple_address';
  $strongarm->value = 0;
  $export['mimemail_simple_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mimemail_sitestyle';
  $strongarm->value = 0;
  $export['mimemail_sitestyle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mimemail_textonly';
  $strongarm->value = 0;
  $export['mimemail_textonly'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rate_widgets';
  $strongarm->value = array(
    1 => (object) array(
      'name' => 'resource_interest',
      'tag' => 'resource_interest',
      'title' => 'Interested in this Resource?',
      'node_types' => array(
        0 => 'resource',
      ),
      'comment_types' => array(),
      'options' => array(
        0 => array(
          0 => '1',
          1 => 'yes',
        ),
        1 => array(
          0 => '-1',
          1 => 'no',
        ),
      ),
      'template' => 'custom',
      'node_display' => '0',
      'teaser_display' => FALSE,
      'comment_display' => '2',
      'node_display_mode' => '1',
      'teaser_display_mode' => '1',
      'comment_display_mode' => '1',
      'roles' => array(
        3 => 0,
        13 => 0,
        14 => 0,
        15 => 0,
        16 => 0,
        17 => 0,
        18 => 0,
        1 => 0,
        2 => 0,
        22 => 0,
        21 => 0,
        12 => 0,
        11 => 0,
        4 => 0,
        5 => 0,
        19 => 0,
        20 => 0,
        23 => 0,
        8 => 0,
        9 => 0,
        6 => 0,
        10 => 0,
        7 => 0,
      ),
      'allow_voting_by_author' => 1,
      'noperm_behaviour' => '1',
      'displayed' => '1',
      'displayed_just_voted' => '2',
      'description' => 'I recommend that CRL prioritize this resource for evaluation and possible pricing negotiations.',
      'description_in_compact' => FALSE,
      'delete_vote_on_second_click' => '1',
      'use_source_translation' => TRUE,
      'value_type' => 'option',
      'translate' => TRUE,
    ),
    2 => (object) array(
      'name' => 'pp_preference',
      'tag' => 'pp_preference',
      'title' => 'Purchase preference ranking',
      'node_types' => array(
        0 => 'pp_resource',
      ),
      'comment_types' => array(),
      'options' => array(
        0 => array(
          0 => '20',
          1 => '1 - little or no interest',
        ),
        1 => array(
          0 => '40',
          1 => '2',
        ),
        2 => array(
          0 => '60',
          1 => '3 - favor',
        ),
        3 => array(
          0 => '80',
          1 => '4',
        ),
        4 => array(
          0 => '100',
          1 => '5 - strongly favor',
        ),
      ),
      'template' => 'custom',
      'node_display' => '0',
      'teaser_display' => FALSE,
      'comment_display' => '2',
      'node_display_mode' => '1',
      'teaser_display_mode' => '1',
      'comment_display_mode' => '1',
      'roles' => array(
        3 => '3',
        13 => 0,
        14 => 0,
        15 => 0,
        16 => 0,
        17 => 0,
        18 => 0,
        1 => 0,
        2 => 0,
        22 => 0,
        21 => 0,
        12 => 0,
        11 => 0,
        4 => 0,
        5 => 0,
        19 => 0,
        20 => 0,
        23 => 0,
        8 => 0,
        9 => 0,
        6 => 0,
        10 => 0,
        7 => 0,
      ),
      'allow_voting_by_author' => 1,
      'noperm_behaviour' => '3',
      'displayed' => '1',
      'displayed_just_voted' => '1',
      'description' => '',
      'description_in_compact' => TRUE,
      'delete_vote_on_second_click' => '1',
      'use_source_translation' => TRUE,
      'value_type' => 'percent',
      'translate' => TRUE,
    ),
    3 => (object) array(
      'name' => 'pp_own_lend',
      'tag' => 'pp_own_lend',
      'title' => 'Purchase preference own and lend status',
      'node_types' => array(
        0 => 'pp_resource',
      ),
      'comment_types' => array(),
      'options' => array(
        0 => array(
          0 => '1',
          1 => 'Do not own',
        ),
        1 => array(
          0 => '2',
          1 => 'Own, can lend',
        ),
        2 => array(
          0 => '3',
          1 => 'Own, cannot lend',
        ),
      ),
      'template' => 'custom',
      'node_display' => '0',
      'teaser_display' => FALSE,
      'comment_display' => '2',
      'node_display_mode' => '1',
      'teaser_display_mode' => '1',
      'comment_display_mode' => '1',
      'roles' => array(
        3 => '3',
        13 => 0,
        14 => 0,
        15 => 0,
        16 => 0,
        17 => 0,
        18 => 0,
        1 => 0,
        2 => 0,
        22 => 0,
        21 => 0,
        12 => 0,
        11 => 0,
        4 => 0,
        5 => 0,
        19 => 0,
        20 => 0,
        23 => 0,
        8 => 0,
        9 => 0,
        6 => 0,
        10 => 0,
        7 => 0,
      ),
      'allow_voting_by_author' => 1,
      'noperm_behaviour' => '3',
      'displayed' => '1',
      'displayed_just_voted' => '1',
      'description' => '',
      'description_in_compact' => TRUE,
      'delete_vote_on_second_click' => '1',
      'use_source_translation' => TRUE,
      'value_type' => 'option',
      'translate' => TRUE,
    ),
    4 => (object) array(
      'name' => 'provider_interest',
      'tag' => 'provider_interest',
      'title' => 'Want to learn more about this Provider?',
      'node_types' => array(
        0 => 'provider',
      ),
      'comment_types' => array(),
      'options' => array(
        0 => array(
          0 => '1',
          1 => 'yes',
        ),
        1 => array(
          0 => '-1',
          1 => 'no',
        ),
      ),
      'template' => 'custom',
      'node_display' => '0',
      'teaser_display' => FALSE,
      'comment_display' => '2',
      'node_display_mode' => '1',
      'teaser_display_mode' => '1',
      'comment_display_mode' => '1',
      'roles' => array(
        3 => 0,
        13 => 0,
        14 => 0,
        15 => 0,
        16 => 0,
        17 => 0,
        18 => 0,
        1 => 0,
        2 => 0,
        22 => 0,
        21 => 0,
        12 => 0,
        11 => 0,
        4 => 0,
        5 => 0,
        19 => 0,
        20 => 0,
        23 => 0,
        8 => 0,
        9 => 0,
        6 => 0,
        10 => 0,
        7 => 0,
      ),
      'allow_voting_by_author' => 1,
      'noperm_behaviour' => '1',
      'displayed' => '1',
      'displayed_just_voted' => '2',
      'description' => 'I recommend that CRL prioritize this provider for additional analysis and research.',
      'description_in_compact' => FALSE,
      'delete_vote_on_second_click' => '1',
      'use_source_translation' => TRUE,
      'value_type' => 'option',
      'translate' => TRUE,
    ),
  );
  $export['rate_widgets'] = $strongarm;

  return $export;
}
