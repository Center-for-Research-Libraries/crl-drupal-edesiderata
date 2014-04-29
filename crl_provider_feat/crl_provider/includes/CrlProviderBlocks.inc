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
    $nid = arg(1); // Assumes block is placed only one node page.
    $comment_count = 0;
    $entities = entity_load('node', array($nid));
    if (!empty($entities[$nid])) {
      $entity = $entities[$nid];
      $entity_wrapper = entity_metadata_wrapper('node', $entity);
      if (isset($entity->comment_count)) {
        $comment_count = $entity->comment_count;
      }
    }
    $block['subject'] = '';
    $block['content'] = array(
      'resource_summary' => array(
        '#theme' => 'crl_helpers_summary',
        '#status' => $status,
        '#comment_count' => $comment_count,
      ),
    );
    return $block;
  }

}
