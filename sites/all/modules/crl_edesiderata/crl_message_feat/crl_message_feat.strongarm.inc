<?php

/**
 * @file
 * crl_message_feat.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function crl_message_feat_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__resource_expires_soon';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__resource_expires_soon'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__resource_new';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__resource_new'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__resource_new_alert';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__resource_new_alert'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__resource_new_comment';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__resource_new_comment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__resource_new_review';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__resource_new_review'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__resource_special_access';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__resource_special_access'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__resource_status_update';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__resource_status_update'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__resource_suggested';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__resource_suggested'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__resource_update';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__resource_update'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'message_purge_days';
  $strongarm->value = '365';
  $export['message_purge_days'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'message_purge_enable';
  $strongarm->value = 1;
  $export['message_purge_enable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'message_purge_quota';
  $strongarm->value = '';
  $export['message_purge_quota'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'message_subscribe_default_notifiers';
  $strongarm->value = array();
  $export['message_subscribe_default_notifiers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'message_subscribe_flag_prefix';
  $strongarm->value = 'base';
  $export['message_subscribe_flag_prefix'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'message_subscribe_notify_own_actions';
  $strongarm->value = 1;
  $export['message_subscribe_notify_own_actions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'message_subscribe_use_queue';
  $strongarm->value = 0;
  $export['message_subscribe_use_queue'] = $strongarm;

  return $export;
}
