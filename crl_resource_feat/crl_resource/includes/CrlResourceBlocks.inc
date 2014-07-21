<?php

/**
 * Class to group block build logic for crl_resource.
 */
class CrlResourceBlocks {
  
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
  protected function build_crl_resource_summary() {
    $block = array();
    $nid = arg(1); // Assumes block is placed only one node page.
    $status = array();
    $status_options = crl_resource_activity_status_property_oplist();
    $comment_count = 0;
    $vote_average = 0;
    $entities = entity_load('node', array($nid));
    if (!empty($entities[$nid])) {
      $entity = $entities[$nid];
      $entity_wrapper = entity_metadata_wrapper('node', $entity);
      $status = isset($entity_wrapper->crl_resource_status_backref) ? $entity_wrapper->crl_resource_status_backref->value() : array();
      $vote_average = isset($entity_wrapper->crl_resource_vote_average) ? $entity_wrapper->crl_resource_vote_average->value() : 0;
      $interest_count_up = isset($entity_wrapper->crl_helpers_interest_count_up) ? $entity_wrapper->crl_helpers_interest_count_up->value() : 0;
      $interest_count_down = isset($entity_wrapper->crl_helpers_interest_count_down) ? $entity_wrapper->crl_helpers_interest_count_down->value() : 0;
      if (isset($entity->comment_count)) {
        $comment_count = $entity->comment_count;
      }
    }
    $block['subject'] = '';
    $block['content'] = array(
      'resource_summary' => array(
        '#theme' => 'crl_helpers_summary',
        '#status' => $status,
        '#status_options' => $status_options,
        '#comment_count' => $comment_count,
        '#vote_average' => $vote_average,
        '#interest_count_up' => $interest_count_up,
        '#interest_count_down' => $interest_count_down,
      ),
    );
    return $block;
  }

}
