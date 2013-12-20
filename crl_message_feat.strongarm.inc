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
  $strongarm->name = 'field_bundle_settings_message__alert_extended';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
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
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
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
        ),
        'message__message_text__2' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__alert_extended'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__log_activity_update';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
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
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '2',
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
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__log_activity_update'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__log_new_alert';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
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
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__log_new_alert'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__log_new_comment';
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
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
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
            'weight' => '3',
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
          'message_notify_daily_digest' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__log_new_comment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__log_new_resource';
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
            'visible' => FALSE,
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
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__log_new_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__log_new_vote';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '3',
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
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__log_new_vote'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__log_resource_update';
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
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
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
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__log_resource_update'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__log_status_update';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '3',
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
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__log_status_update'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__offer_expiration';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__offer_expiration'] = $strongarm;

  return $export;
}
