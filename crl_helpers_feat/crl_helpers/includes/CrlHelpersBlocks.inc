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
    if (isset($_GET['f']) || !empty($_GET['search_api_views_fulltext'])) {
      $base_path = current_path();
      // Get the most recent breadcrumb.
      $breadcrumb = drupal_get_breadcrumb();
      // Drop the "home" value for the breadcrumb.
      array_shift($breadcrumb);
      $extra = '';
      // Integration with the crl_mydes_feat module to inject a save this
      // search option into the breadcrumb block (only applicable to resource
      // list).
      if (module_exists('crl_mydes_feat') && drupal_match_path(current_path(), 'resources/*')) {
        $extra = crl_mydes_feat_build_saved_search_form();
      }
      $output = array(
        'facet_breadcrumb' => array(
          '#breadcrumb' => $breadcrumb,
          '#base_path' => $base_path,
          '#extra' => $extra,
          '#theme' => 'crl_helpers_facet_breadcrumb',
        ),
      );
    }
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
    $menu_item = array_pop(menu_get_active_trail());
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

}
