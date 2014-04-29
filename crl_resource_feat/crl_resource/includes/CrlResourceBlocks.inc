<?php

/**
 * Class to group block build logic for crl_resource.
 */
class CrlResourceBlocks {
  
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
   * Build crl_resource_summary.
   */
  protected function crl_resource_summary_build() {
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
      $interest_count_up = isset($entity_wrapper->crl_resource_interest_count_up) ? $entity_wrapper->crl_resource_interest_count_up->value() : 0;
      $interest_count_down = isset($entity_wrapper->crl_resource_interest_count_down) ? $entity_wrapper->crl_resource_interest_count_down->value() : 0;
      if (isset($entity->comment_count)) {
        $comment_count = $entity->comment_count;
      }
    }
    $block['subject'] = '';
    $block['content'] = array(
      'resource_summary' => array(
        '#theme' => 'crl_resource_summary',
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
  
  /**
   * Build crl_resource_back_to_index.
   */
  protected function crl_resource_back_to_index_build() {
    $block = array();
    $browser_back = FALSE;
    $url = url('resources/main');
    drupal_add_js(drupal_get_path('module', 'crl_resource') .'/js/crl_resource.js', 'file');
    $block['subject'] = '';
    $block['content'] = array(
      'back_link' => array(
        '#theme' => 'crl_resource_back_to_index',
        '#url' => $url,
        '#back_text' => t('Back to listings'),
        '#browser_back' => $browser_back,
      ),
    );
    return $block;
  }
 
  /**
   * Build crl_resource_common_input.
   */
  protected function crl_resource_common_input_build() {
    $block = array();
    global $user;
    $nid = arg(1);
    $node = node_load($nid);
    // Make sure block should be visible
    if (isset($node->type) && $node->type == 'resource' && $user->uid) {
      $block['subject'] = t('Interested in this Resource?');
      $block['content'] = array('#markup' => rate_embed($node, 'resource_interest'));
    }
    return $block;
  }

}
