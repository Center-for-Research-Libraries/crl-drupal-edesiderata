<?php

/**
 * Class to fetch and store the custom properties that we want to make available
 * when the provider entry is displayed (custom fields, etc.). This does not
 * necessarially need to be an object, but using one makes packaging all this
 * logic a lot easier.
 */
class CrlProviderDisplayElements {

  /**
   * Define our base properties.
   */
  protected $entity;
  protected $entity_wrapper;

  /**
   * Constructor
   */
  public function __construct($node) {
    $this->entity = $node;
    $this->entity_wrapper = entity_metadata_wrapper('node', $this->entity);
  }

  /**
   * Common public build method that calls specific protected build method.
   */
  public function buildField($field) {
    if (method_exists($this, 'build_' . $field)) {
      return $this->{'build_' . $field}();
    }
    return array();
  }

  /**
   * Build custom field: pseudo_field_provider_added
   */
  protected function build_pseudo_field_provider_added() {
    return array('#theme' => 'crl_helpers_pseudo_field', '#label' => t('Posted'), '#output' => format_date($this->entity_wrapper->created->value(), 'short'), '#inline' => TRUE);
  }

  /**
   * Build custom field: pseudo_field_provider_updated
   */
  protected function build_pseudo_field_provider_updated() {
    return array('#theme' => 'crl_helpers_pseudo_field', '#label' => t('Updated'), '#output' => format_date($this->entity_wrapper->changed->value(), 'short'), '#inline' => TRUE);
  }

  /**
   * Build custom field: pseudo_field_provider_resources_view
   */
  protected function build_pseudo_field_provider_resources_view() {
    $rendered_view = views_embed_view('resource_lists', 'block_1', $this->entity->nid);
    // Only show if we have view results.
    if (trim(strip_tags($rendered_view))) {
      return array('#theme' => 'crl_helpers_pseudo_field', '#label' => t('eDesiderata Resources by this Provider'), '#output' => $rendered_view, '#inline' => FALSE);
    }
  }

  /**
   * Build custom field: pseudo_field_provider_full_link
   */
  protected function build_pseudo_field_provider_full_link() {
    $link = l('<strong>' . t('View all provider details' . '</strong>'), $this->entity_wrapper->url->value(), array('html' => TRUE));
    return array('#theme' => 'crl_helpers_pseudo_field', '#label' => '', '#output' => $link, '#inline' => TRUE);
  }

  /**
   * Build custom field: pseudo_field_resource_source_summary
   */
  protected function build_pseudo_field_provider_source_summary() {
    $built = array();
    $output = $this->get_source_text();
    if (!empty($output)) {
      $built = array('#theme' => 'crl_pseudo_field', '#label' => t('Source'), '#output' => $output);
    }
    return $built;
  }

  /**
   * Helper to generate fixed "source" text based on resoruce status.
   */
  protected function get_source_text() {
    $source_text = '';
    // Todo: add options.
    return $source_text;
  }

}
