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
      '<a href="@login">Log in</a> or <a href="@register">register</a> to post comments' => '<a href="@login">Log in</a> or <a href="@register">sign up</a> to post comments',
      'A valid e-mail address. All e-mails from the system will be sent to this address. The e-mail address is not made public and will only be used if you wish to receive a new password or wish to receive certain news or notifications by e-mail.' => 'Please enter a valid email address, preferably one from your affiliated institution. You will use this email address for all future logins, and CRL will use it for all email communications with you.',
      'Comments' => 'Community comments and discussion',
      'Create new revision and moderate' => 'Regular update with moderation (used rarely)',
      'Create new revision, no moderation' => 'Regular update',
      'Modify current revision, no moderation' => 'Minor update (do NOT notify watchers, alter activity feeds or create a new revision)',
      'Submitted by !username on !datetime' => '!username on !datetime',
    ),
  );
  $export['locale_custom_strings_en'] = $strongarm;

  return $export;
}
