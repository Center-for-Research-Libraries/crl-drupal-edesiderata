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
    // Our block logic only applies to nodes.
    $menu_item = menu_get_item();
    if ($menu_item['path'] == 'node/%') {
      $node = menu_get_object();
      if (!empty($node) && $node->type == 'resource') {
        $entity_wrapper = entity_metadata_wrapper('node', $node);
        $status_options = crl_resource_activity_status_property_oplist();
        $status_descriptions = crl_activity_status_calc_descriptions();
        $status = isset($entity_wrapper->crl_resource_status_backref) ? $entity_wrapper->crl_resource_status_backref->value() : array();
        $vote_average = isset($entity_wrapper->crl_resource_vote_average) ? $entity_wrapper->crl_resource_vote_average->value() : 0;
        $interest_count_up = isset($entity_wrapper->crl_helpers_interest_count_up) ? $entity_wrapper->crl_helpers_interest_count_up->value() : 0;
        $interest_count_down = isset($entity_wrapper->crl_helpers_interest_count_down) ? $entity_wrapper->crl_helpers_interest_count_down->value() : 0;
        $comment_count = isset($node->comment_count) ? check_plain($node->comment_count) : 0;
        $block['subject'] = '';
        $block['content'] = array(
          'resource_summary' => array(
            '#theme' => 'crl_helpers_summary',
            '#status' => $status,
            '#status_options' => $status_options,
            '#status_descriptions' => $status_descriptions,
            '#comment_count' => $comment_count,
            '#vote_average' => $vote_average,
            '#interest_count_up' => $interest_count_up,
            '#interest_count_down' => $interest_count_down,
          ),
        );
      }
    }
    return $block;
  }

  /**
   * Build crl_resource_suggest_resource.
   */
  protected function build_crl_resource_suggest() {
    $block = array(
      'subject' => t('Suggest a New Resource'),
      'content' => array(
        '#markup' => '<p>' . t('Interested in a resource that you don\'t see listed? Please consider submitting a new <a href="@suggest-url">resource suggestion</a>.', array('@suggest-url' => url('resources/suggestions'))) . '</p>',
      ),
    );
    return $block;
  }

  /**
   * Build crl_resource_suggest_resource_collapsed.
   */
  protected function build_crl_resource_suggest_collapsed() {
    $suggest_block = $this->build_crl_resource_suggest();
    $block = array(
      'subject' => '',
      'content' => array(
        '#theme' => 'fieldset',
        '#attributes' => array('class' => array('collapsible', 'collapsed')),
        '#title' => $suggest_block['subject'],
        '#description' => '',
        '#children' => drupal_render($suggest_block['content']),
        '#attached' => array(
          'library' => array(array('system', 'drupal.collapse')),
        ),
      ),
    );
    return $block;
  }
  
  /**
   * Build crl_resource_suggest_resource_long.
   */
  protected function build_crl_resource_suggest_long() {
    $block = array(
      'subject' => t('Suggest a New Resource'),
      'content' => array(
        '#markup' => '<p>' . t('In addition to providing comments and insights on resources already listed in the eDesiderata index, CRL members are also invited to <a href="@suggest-url">suggest new resources</a> for inclusion.', array('@suggest-url' => url('resources/suggestions'))) . '</p>',
      ),
    );
    return $block;
  }

}
