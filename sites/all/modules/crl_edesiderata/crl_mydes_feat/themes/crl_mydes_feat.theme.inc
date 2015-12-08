<?php

/**
 * @file
 * Theme related functions for processing output related to crl_mydes_feat.
 */


/**
 * Returns HTML for a meDes video link with thumbnail.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
*/
function theme_crl_mydes_feat_video_link($variables) {
  $output = '';
  if (!$variables['thumb']) {
    $output .= l($variables['text'], $variables['video_path'], array('target' => '_blank'));
  }
  else {
    $output .= '<div class="edes-vid-highlight">';
    $output .= '<a href="' . url($variables['video_path']) . '" target="_blank"><img src="' .  file_create_url($variables['thumb_uri']) . '" /></a>';
    $output .= '<p>' . check_plain($variables['text']) . '</p>';
    $output .= '</div>';
  }
  $output .= '';
  return $output;
}
