<?php

/**
 * Class to group block build logic for crl_helpers.
 */
class CrlHelpersBlocks {

  /**
   * Common public build method that calls specific protected build method.
   */
  public function buildBlock($block) {
    if (method_exists($this, 'build_' . $block)) {
      return $this->{'build_' . $block}();
    }
    return array();
  }

  /**
   * Build crl_helpers_facet_breadcrumb.
   */
  protected function build_crl_helpers_facet_breadcrumb() {
    $block = array();
    $output = '';
    $active_facets = array();
    // Detect the active facets from the query string (the query string should
    // list them in the order they were entered).
    if (isset($_GET['f'])) {
      foreach ($_GET['f'] as $f) {
        // Get facet details directly from facetapi.
        list($facet_name, $item) = explode(':', $f);
        $adapter = facetapi_adapter_load('search_api@title_search_index');
        $processor = $adapter->getProcessor($facet_name);
        if ($processor) {
          $build = $processor->getBuild();
          $item_build = $build[$item];
          $active_facets[] = array(
            'path' => $item_build['#path'],
            'text' => $item_build['#markup'],
            'options' => array(
              'html' => TRUE,
              'query' => isset($item_build['#query']) ? $item_build['#query'] : array(),
            ),
          );
        }
      }
    }
    // Also treat any fulltext search inputs as a facet.
    if (!empty($_GET['search_api_views_fulltext'])) {
      $active_facets[] = array(
        'path' => current_path(),
        'text' => check_plain($_GET['search_api_views_fulltext']),
        'options' => array(
          'html' => TRUE,
          'query' => drupal_get_query_parameters(NULL, array('q', 'search_api_views_fulltext')),
        ),
      );
    }
    $extra = array();
    $base_path = current_path();
    // In some displays, when facets are active, we also want to display saved
    // search options.
    if ($active_facets) {      
      if (drupal_match_path(current_path(), 'resources/*')) {
        // Integration with the crl_mydes_feat module to inject a save this
        // search option into the breadcrumb block.
        if (module_exists('crl_mydes_feat')) {
          $extra['save_search'] = crl_mydes_feat_build_saved_search_form();
        }
      }
    }
    // When no facets are active set a class that can be used to control
    // visibility in CSS if needed.
    else {
      $block['attributes']['class'] = array('no-active-filters');
    }
    $output = array(
      'facet_breadcrumb' => array(
        '#active_facets' => $active_facets,
        '#base_path' => $base_path,
        '#extra' => $extra,
        '#theme' => 'crl_helpers_facet_breadcrumb',
      ),
    );
    $block['content'] = $output;
    return $block;
  }

  /**
   * Build crl_helpers_editor_tools.
   */
  protected function build_crl_helpers_editor_tools() {
    $block = array();
    $block['subject'] = '';
    $output = array(
      'editor_tools' => array(
        '#theme' => 'crl_helpers_editor_tools',
      ),
    );
    $block['content'] = $output;
    return $block;
  }

  /**
   * Build crl_helpers_alpha_facet_sort.
   */
  protected function build_crl_helpers_alpha_facet_sort() {
    $block = array();
    $alpha_block = array('content' => '');
    // We only want to show the A-Z facet filters if we are in the default
    // alphabetical sort mode.
    if (drupal_match_path(current_path(), 'resources/main') || drupal_match_path(current_path(), 'providers/main')) {
      // Lookup the delta for our glossary value facet block.
      foreach (facetapi_get_delta_map() as $delta => $map) {
        if (strpos($map, 'crl_glossary_value') !== FALSE) {
          $alpha_block = module_invoke('facetapi', 'block_view', $delta);
          break;
        }
      }
    }
    $query = drupal_get_query_parameters();
    // Structure the pulldown options as path => name pairs and then convert
    // to detailed multi-dimension array.
    $form_options = array();
    if (drupal_match_path(current_path(), 'resources/*')) {
      $form_options = array('resources/main' => t('Alphabetical'), 'resources/expiring' => t('Expiring first'), 'resources/updated' => t('Updated first'), 'resources/newest' => t('Newest first'));
    }
    if (drupal_match_path(current_path(), 'providers/*')) {
      $form_options = array('providers/main' => t('Alphabetical'), 'providers/updated' => t('Updated first'), 'providers/newest' => t('Newest first'));
    }
    foreach ($form_options as $path => &$option) {
      $text = $option;
      $option = array(
        'text' => $text,
        'url' => url($path, array('query' => $query)),
        'selected' => drupal_match_path(current_path(), $path),
      );
    }
    $block['subject'] = '';
    $block['content'] = array('#theme' => 'crl_helpers_alpha_facet_sort', '#alpha_block' => $alpha_block, '#form_options' => $form_options);
    return $block;
  }

  /**
   * Build crl_helpers_back_to_index.
   */
  protected function build_crl_helpers_back_to_index() {
    $block = array();
    // For our purposes context should have set our menu trail such that we can
    // get out "back to" URL out of the menu trail.
    $trail = menu_get_active_trail();
    $menu_item = array_pop($trail);
    $url = url($menu_item['href']);
    $block['subject'] = '';
    $block['content'] = array(
      'back_link' => array(
        '#theme' => 'crl_helpers_back_to_index',
        '#url' => $url,
        '#back_text' => t('Back to listings'),
      ),
    );
    $block['content']['#attached']['js'][] = drupal_get_path('module', 'crl_helpers') .'/js/crl_helpers_back_to_index.js';
    return $block;
  }

  /**
   * Build crl_resource_interest_input.
   */
  protected function build_crl_helpers_interest_input() {
    $block = array();
    global $user;
    $nid = arg(1);
    $node = node_load($nid);
    // Make sure block should be visible
    if (isset($node->type) && user_access('crl access member features')) {
      $subject = t('Interested in this Entry?');
      $widgets = variable_get(RATE_VAR_WIDGETS, array());
      foreach ($widgets as $id => $widget) {
        if ($widget->name == $node->type . '_interest') {
          $subject = $widget->title;
        }
      }
      $block['subject'] = $subject;
      $block['content'] = array('#markup' => rate_embed($node, $node->type . '_interest'));
    }
    return $block;
  }

  /**
   * Build crl_helpers_lim_access_mess.
   */
  protected function build_crl_helpers_lim_access_mess() {
    global $user;
    $block = array();
    // We only output content for users that cannot access member features.
    if (!user_access('crl access member features')) {
      // The specific message displayed depends on whether-or-not the user is
      // logged-in.
      if ($user->uid) {
        $block['subject'] = t('Information for non-members');
        $block['content'] = t('You logged in as a non-member. This means that some CRL licensing information and community input features are not available.');
      }
      else {
        $urls = array(
          '!mlist' => 'http://www.crl.edu/membership/members',
          '!login' => url('user', array('query' => drupal_get_destination())),
          '!signup' => url('user/register', array('query' => drupal_get_destination())),
        );
        $block['subject'] = t('You are not logged-in');
        $block['content'] = '<p>' . t('CRL licensing and community input features are only available with a CRL member login.') . '</p>';
        $block['content'] .= '</p>' . t('If your institution is a <a href="!mlist">CRL Member</a> please<br><a class="button" href="!login">log in</a> or <a class="button" href="!signup">sign up</a>', $urls) . '</p>';
      }
    }
    return $block;
  }

}
