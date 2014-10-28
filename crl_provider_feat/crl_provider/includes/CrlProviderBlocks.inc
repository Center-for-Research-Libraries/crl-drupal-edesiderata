<?php

/**
 * Class to group block build logic for crl_provider.
 */
class CrlProviderBlocks {
  
  /**
   * Common public build method that calles specific protected build method.
   */
  public function buildBlock($block) {
    if (method_exists($this, 'build_' . $block)) {
      return $this->{'build_' . $block}();
    }
    return array();
  }
  
  
  /**
   * Build crl_resource_summary.
   */
  protected function build_crl_provider_summary() {
    $block = array();
    // Our block logic only applies to nodes.
    $menu_item = menu_get_item();
    if ($menu_item['path'] == 'node/%') {
      $nid = arg(1);
      $node = node_load($nid);
      if (!empty($node) && $node->type == 'provider') {
        $entity_wrapper = entity_metadata_wrapper('node', $node);
        $status_options = crl_provider_status_property_oplist();
        $status = isset($entity_wrapper->crl_provider_status) ? $entity_wrapper->crl_provider_status->value() : array();
        $interest_count_up = isset($entity_wrapper->crl_helpers_interest_count_up) ? $entity_wrapper->crl_helpers_interest_count_up->value() : 0;
        $interest_count_down = isset($entity_wrapper->crl_helpers_interest_count_down) ? $entity_wrapper->crl_helpers_interest_count_down->value() : 0;
        $comment_count = isset($node->comment_count) ? check_plain($node->comment_count) : 0;
        $block['subject'] = '';
        $block['content'] = array(
          'resource_summary' => array(
            '#theme' => 'crl_helpers_summary',
            '#status' => $status,
            '#status_options' => $status_options,
            '#comment_count' => $comment_count,
            '#interest_count_up' => $interest_count_up,
            '#interest_count_down' => $interest_count_down,
          ),
        );
      }
    }
    return $block;
  }
  
  
  /**
   * Build crl_provider_update_links.
   */
  protected function build_crl_provider_update_links() {
    $block = array();
    // Our block logic only applies to nodes.
    $menu_item = menu_get_item();
    if ($menu_item['path'] == 'node/%') {
      $nid = arg(1);
      $node = node_load($nid);
      if (!empty($node) && $node->type == 'provider') {
        $link_path = 'update-provider-information';
        $link_options = array(
          'attributes' => array(
            'class' => array('button')),
          'query' => array(
            'name' => $node->title,
            'nid' => $nid),
        );
        $block['subject'] = 'Update Provider Details';
        $block['content'] = array(
          '#markup' => '<p>' . t('Do you have corrections or updates to suggest regarding this provider?') . '<br/>' . l(t('Submit Corrections'), $link_path, $link_options),
        );
      }
    }
    return $block;
  }

}
