<?php

/**
 * @file
 * Page-specific logic and callback(s) for the resource suggest page.
 */


/**
 * Page callback for the resource suggestion page.
 */
function crl_resource_suggest_page() {
  $text = '<p>' . t('In addition to providing input on resources already listed in the eDesiderata index, CRL members are also invited to suggest new resources for inclusion. Resource suggestions are reviewed by CRL staff before being included in the index.') . '</p>';
  if (!user_access('crl access member features')) {
    global $user;
    if ($user->uid) {
      $text .= '<p><strong>' . t('You logged in as a non-member. Resource suggestions can only be submitted by CRL members.') . '</strong></p>';
    }
    else {
      $text .= '<p><strong>' . t('To submit new resources you must be <a href="@login-url">logged-in</a> as a CRL member', array('@login-url' => url('user', array('query' => array('destination' => current_path()))))) . '</strong></p>';
    }
  }
  else {
    $text .= l('<button>+&nbsp;&nbsp;' . t('Suggest New Resource') . '</button>', 'eform/submit/resource-suggestion', array('html' => TRUE));
  }
  return $text;
}