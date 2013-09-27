<?php

/**
 * @file
 * Theme related functions for processing output related to crl_activity.
 */

/**
 * Returns HTML for an activity group notive field.
 *
 * @param array $vars
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
 */
function theme_crl_activity_group_notice_field($vars) {
  return '<div class="notice-box">' . $vars['message'] . '</div>';
}