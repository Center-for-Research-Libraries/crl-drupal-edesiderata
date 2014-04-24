<?php

/**
 * Class to group block build logic for crl_helpers.
 */
class CrlHelpersBlocks {
  
  /**
   * Common public build method that calles specific protected build method.
   */
  public function buildBlock($block) {
    if (method_exists($this, $block . '_build')) {
      return $this->{$block . '_build'}();
    }
    return array();
  }
  
  /**
   * Build crl_helpers_facet_breadcrumb.
   */
  protected function crl_helpers_facet_breadcrumb_build() {
    $block = array();

    return $block;
  }
  
  /**
   * Build crl_helpers_editor_tools.
   */
  protected function crl_helpers_editor_tools_build() {
    $block = array();

    return $block;
  }
 
  /**
   * Build crl_helpers_alpha_facet_sort.
   */
  protected function crl_helpers_alpha_facet_sort_build() {
    $block = array();

    return $block;
  }

}
