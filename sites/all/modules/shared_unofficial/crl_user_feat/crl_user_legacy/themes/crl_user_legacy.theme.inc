<?php

/**
 * @file
 * Theme related functions for processing output related to crl_user.
 */

/**
 * Returns HTML for the user tools landing page.
 *
 * @param array $vars
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
 */
function theme_crl_user_legacy_tools_landing_text($vars) {
  $output = '';
  $output .= '<p>' . t('These admin tools offer methods to interact with CUD user data that would not otherwise be possible with other interfaces (such as the Crowd Console).') . '</p>';
  $output .= '<p><strong>' . t('All operations here work on REMOTE user data (in CUD) and do not immediatly impact any user objects managed by this Drupal instance.') . '</strong></p>';
  $output .= '<br/>';
  $tasks = menu_local_tasks();
  $output .= '<dl>';
  foreach($tasks['tabs']['output'] as $tab) {
    if (empty($tab['#active'])) {
      $output .= '<dt><strong>' . l($tab['#link']['title'], $tab['#link']['href']) . '</strong></dt>';
      $output .= '<dd>' . $tab['#link']['description'] . '</dd>';
    }
  }
  $output .= '</dl>';
  return $output;
}