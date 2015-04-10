<?php
function crl_alpha_preprocess_zone(&$vars) {
  if (!empty($vars['zone']) && $vars['zone'] == 'header') {
    // Calculate the user message
    global $user;
    if ($user->uid) {
      $user_message = t('You are logged-in as <strong>@name</strong>', array('@name' => format_username($user)));
      $user_message .= '<br/><a class="inline-button" href="' . url('user/' . $user->uid . '/edit') . '">' . t('your account') . '</a>&nbsp&nbsp<a class="inline-button" href="' . url('user/logout') . '">' . t('logout') . '</a>';
    }
    else {
      $login_url = url('user', array('query' => array('destination' => request_path())));
      $signup_url = url('user/register', array('query' => array('destination' => request_path())));
      $user_message = t('Please !login_link or !signup_link to access all resource details and interactive features', array('!login_link' => '<a class="inline-button" href="' . $login_url . '">' . t('log in') . '</a>', '!signup_link' => '<a class="inline-button" href="' . $signup_url . '">' . t('sign up') . '</a>'));
    }
    $vars['user_message'] = $user_message;
    $vars['site_name'] = variable_get('site_name', '');
    // $vars['site_name'] = variable_get('site_name', '') . '<span class="rtm">&reg;</span>';
    $vars['site_slogan'] = variable_get('site_slogan', '');

    // Calculate menus
    $vars['jump_menu'] = '';
    if (module_exists('jump_menu')) {
      $vars['jump_menu'] = jump_menu('menu-mobile-menu', 1);
    }
    $main_menu = variable_get('menu_main_links_source', 'main-menu');
    $secondary_menu = variable_get('menu_secondary_links_source', NULL);
    // Get menu trees. Note that we can't call menu_tree() directly as we need
    // to manually specify 1-level only for display (while maintaining the
    // active trail.
    $vars['tree_main'] = menu_tree_output(menu_tree_page_data($main_menu, 1));
    $vars['tree_secondary'] = menu_tree_output(menu_tree_page_data($secondary_menu, 1));
  }
}
