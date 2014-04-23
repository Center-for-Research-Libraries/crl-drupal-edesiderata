<?php

/**
 * @file
 * Theme related functions for processing output related to crl_pp_resource.
 */


/**
 * Preprocess function for the PP preference widget (taken from fivestar).
 */
function crl_pp_resource_feat_preprocess_rate_widget__pp_preference(&$variables) {
  // This widget is based on fivestar which means that rate will automatically
  // try to include its own fivestart css and js along with some wrapper divs
  // that the css and js reference. However, due to deficiencies in the rate
  // module it does not dynamically lookup the css and js paths correctly, so
  // if modules have moved, the widget can break. To get around this, we just
  // formally declare the fivestar css and js here to make sure it's included.
  drupal_add_css(drupal_get_path('module', 'rate') . '/templates/fivestar/fivestar.css');
  drupal_add_js(drupal_get_path('module', 'rate') . '/templates/fivestar/fivestar.js');
  // Get/set variables needed for calculations.
  $results = $variables['results'];
  $links = $variables['links'];
  $mode = $variables['mode'];
  $count = count($links);
  $percent_per_star = 100 / ($count);
  $variables['title'] = t('Purchase Ranking');
  // Build user-specific inputs if allowed.
  $stars_user = array();
  if ($mode == RATE_FULL || $mode == RATE_COMPACT) {
    for ($i = 0; $i < $count; $i++) {
      if (isset($results['user_vote']) && round($results['user_vote'] / $percent_per_star) > $i) {
        $class = 'rate-fivestar-btn-filled';
      }
      else {
        $class = 'rate-fivestar-btn-empty';
      }
      $class .= ' rate-fivestar-' . ($i + 1);
      $stars_user[] = theme('rate_button', array('text' => $links[$i]['text'], 'href' => $links[$i]['href'], 'class' => $class));
    }
    $variables['stars_user'] = $stars_user;
    // Build summary messages for user.
    if (isset($results['user_vote'])) {
      $results_calc = round($results['user_vote'] / $percent_per_star, 1);
      $variables['your_vote_status'] = t('You voted');
      $variables['your_vote_class'] = 'vote-filled';
      $variables['your_vote'] = t('@calc/@count', array('@calc' => $results_calc, '@count' => $count));
    }
    else {
      $variables['your_vote_status'] = t('Your vote pending');
      $variables['your_vote_class'] = 'vote-pending';
      $variables['your_vote'] = '';
    }
  }
  // Build aggregate details.
  $stars_all = array();
  for ($i = 0; $i < $count; $i++) {
    if (isset($results['rating']) && round($results['rating'] / $percent_per_star) > $i) {
      $class = 'rate-fivestar-btn-filled';
    }
    else {
      $class = 'rate-fivestar-btn-empty';
    }
    $class .= ' rate-fivestar-' . ($i + 1);
    $stars_all[] = theme('rate_button', array('text' => $links[$i]['text'], 'href' => '', 'class' => $class));
    $variables['stars_all'] = $stars_all;
  }
  // Build summary messages for aggregate.
  if (!empty($results['rating'])) {
    $results_calc_av = round($results['rating'] / $percent_per_star, 1);
    $variables['av_vote'] = t('Avg. rank: @calc/@count', array('@calc' => $results_calc_av, '@count' => $count));
  }
  else {
    $variables['av_vote'] = '';
  }
  $votes_count = isset($results['count']) ? $results['count'] : 0;
  $variables['count_text'] = t('Vote total: @count', array('@count' => $votes_count));
}


/**
 * Preprocess function for the PP own yes/no widget.
 */
function crl_pp_resource_feat_preprocess_rate_widget__pp_own_lend(&$variables) {
  $links = $variables['links'];
  $results = $variables['results'];
  $mode = $variables['mode'];
  $variables['title'] = t('Member Library Holdings');
  // Get rate buttons if user has input permissions.
  $buttons = array();
  foreach ($links as $link) {
    $button = '';
    if (!empty($results['user_vote'])) {
      if ($link['text'] == $results['user_vote']) {
        $button = theme('rate_button', array('text' => $link['text'], 'href' => $link['href'], 'class' => 'vote-filled'));
        $button .= '<br/>' . theme('rate_button', array('text' => t('undo'), 'href' => $link['href'], 'class' => ''));
      }
    }
    else {
      $button = theme('rate_button', array('text' => $link['text'], 'href' => $link['href'], 'class' => ''));
    }
    $buttons[] = $button;
  }
  $variables['buttons'] = $buttons;
  // Get user-specific summary details.
  $variables['your_vote'] = t('Your library status');
  if (isset($results['user_vote'])) {
    $variables['your_vote_class'] = 'vote-filled';
  }
  else {
    $variables['your_vote_class'] = '';
  }
  
  // Get aggregate result display
  $item_results = array();
  foreach ($links as $link) {
    if (!empty($link['votes'])) {
      $item_result = theme('rate_button', array('text' => $link['text'], 'href' => '', 'class' => ''));
      $item_result .= ': ' . $link['votes'];
      $item_results[] = $item_result;
    }
  }
  $variables['item_results'] = $item_results;
  $votes_count = isset($results['count']) ? $results['count'] : 0;
  $variables['count_text'] = t('Input total: @count', array('@count' => $votes_count));
}
