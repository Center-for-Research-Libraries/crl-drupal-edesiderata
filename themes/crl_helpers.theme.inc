<?php

/**
 * @file
 * Theme related functions for processing output related to crl_helpers.
 */


/**
 * Implements hook_preprocess_delta_blocks_page_title().
 * 
 * We display titles with delta blocks, so this provides a way to do some
 * special title alterations at the last min. This is a bit of a hack.
 */
function crl_helpers_preprocess_delta_blocks_page_title(&$vars) {
  $altered = FALSE;
  $altered_text = '';
  $query = drupal_get_query_parameters();
  if (!empty($query['f'][0])) {
    switch ($query['f'][0]) {
      case 'crl_resource_status_backref:crl_review_available':
        $altered = TRUE;
        $altered_text = t('Resources - CRL Reviews');
        break;
      case 'crl_resource_status_backref:license_available':
        $altered = TRUE;
        $altered_text = t('Resources - CRL Offers');
        break;
      case 'crl_resource_status_backref:crl_desiderata':
        $altered = TRUE;
        $altered_text = t('Resources - CRL Pipeline');
        break;
    }
  }
  if (drupal_is_front_page()) {
    $altered = TRUE;
    $altered_text = '';
  }
  if ($altered) {
    $vars['page_title'] = $altered_text;
  }
}


/**
 * Implements hook_preprocess_comment().
 * 
 * Alter some comment variables before they are themed. Used primarily to
 * implement some ad hoc "private comments" features.
 */
function crl_helpers_preprocess_comment(&$vars) {
  // Add the inst to the author's name if possible.
  $user_inst = crl_helpers_get_institution($vars['comment']->uid, NULL);
  if (!empty($user_inst)) {
    $vars['author'] = $vars['author'] . ' (' . $user_inst . ')';
  }
  // Hide the title/subject line.
  $vars['title'] = NULL;
  // See if any "privacy" details are set via a special "comment_privacy" field.
  $wrapper = entity_metadata_wrapper('comment', $vars['comment']);
  $privacy = isset($wrapper->field_comment_privacy) ? $wrapper->field_comment_privacy->value() : NULL;
  // Toggle the removal/addition of text based on any privacy settings and user
  // rights.
  if ($privacy == 'anon') { // Hide submitter name.
    // Don't hide anything from admins, but show a notice.
    if (user_access('administer comments')) {
      $vars['content']['privacy_note'] = array('#markup' => t('<strong>Privacy note:</strong> The submitter has chosen to hide their name from everyone except CRL staff.'));
    }
    else {
      $vars['author'] = t('(name hidden)');
      $vars['submitted'] = t('Submission details hidden');
    }
  }
  elseif ($privacy == 'private') { // Hide entire comment.
    global $user;
    // Remove "reply" option.
    if (isset($vars['content']['links']['comment']['#links']['comment-reply'])) {
      unset($vars['content']['links']['comment']['#links']['comment-reply']);
    }
    // Don't hide anything from admins or author, but show a notice.
    if (user_access('administer comments') || $vars['comment']->uid == $user->uid) {
      $vars['content']['privacy_note'] = array('#markup' => t('<strong>Privacy note:</strong> This comment has been hidden from all users except CRL staff and the original author.'));
    }
    else {
      $vars['author'] = t('(name hidden)');
      $vars['submitted'] = t('Submission details hidden');
      $vars['content']['comment_body'] = array('#markup' => t('Comment hidden - this is a private comment to CRL.'));
    }
  }
}


/**
 * Implements hook_views_data_export_xls_header().
 * 
 * Alter some export header structures.
 */
function crl_helpers_preprocess_views_data_export_xls_header(&$variables) {
  $output = '';
  $output .= "<h2>eDesiderata - Informed Investment in Electronic Resources</h2>";
  $output .= "<h3>Center for Research Libraries</h3>";
  $output .= "<p><b>Exported from eDesiderata on " . format_date(time(), 'medium')." </b></p>";
  $output .= "<p>&nbsp;</p>" . $variables['header_row'];
  $variables['header_row'] = $output;
}


/**
 * Returns HTML for a facet breadcrumb.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
*/
function theme_crl_helpers_facet_breadcrumb($variables) {
  $output = '';
  $glue = "»";
  $reset_markup = '<span class="facet-breadcrumb-reset"><a href="' . $variables['base_path'] . '"><span class="facet-breadcrumb-reset-icon"></span><span class="facet-breadcrumb-label">' . t('Reset') . '</span></a></span>';
  $output .= '<div id="facet-breadcrumb" class="clearfix"><ul class="breadcrumb"><li><span class="facet-breadcrumb-label">' . t('Active Filters') . ': </span></li>';
  $switch = array('odd' => 'even', 'even' => 'odd');
  $zebra = 'even';
  $last = count($variables['breadcrumb']) - 1;    
  foreach ($variables['breadcrumb'] as $key => $item) {
    $zebra = $switch[$zebra];
    $attributes['class'] = array('depth-' . ($key + 1), $zebra);
    if ($key == 0) {
      $attributes['class'][] = 'first';
    }
    if ($key == $last) {
      $attributes['class'][] = 'last';
      $glue = '';
    }
    $output .= '<li' . drupal_attributes($attributes) . '>' . $item . ' ' . $glue . '</li>';
  }
  $output .= '</ul>' . $reset_markup . '</div>';
  $output .= $variables['extra'];
  return $output;
}


/**
 * Returns HTML for the editor tools.
 *
 * @param array $variables
 *   An associative array containing variables used to render this HTML.
 *
 * @ingroup themeable
*/
function theme_crl_helpers_editor_tools($variables) {
  $output = '';
  $output .= '<div class="editor-tools"><strong>' . l(t('+ Add Resource'), 'node/add/resource') . '&nbsp;&nbsp;&nbsp;' . l(t('+ Add Provider'), 'node/add/provider') . '<br/>' . l(t('Editor & Admin Dashboard'), 'admin/dashboard') . '</strong></div>';
  $output .= '<p>This page\'s internal path and permalink is:<br /><strong>';
  if (arg(0) == 'node') {
    $output .='<span style="color:green;">/node/' . arg(1) . '</span>'; 
  }
  elseif (!strpos($_GET['q'], "/admin")) {
    $output .= '<span style="color:green;">/' . $_GET['q'] . '</span>';
  }
  else {
    $output .= '<span style="color:red;">/' . $_GET['q'] . ' (no public link available)</span>';
  }
  $output .= '</strong></p><hr />';
  return $output;
}
