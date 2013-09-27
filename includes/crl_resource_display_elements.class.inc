<?php

/**
 * Class to fetch and store the custom properties that we want to make available
 * when the resource is displayed (custom fields, etc.). This does not
 * necessarially need to be an object, but using one makes packaging all this
 * logic a lot easier.
 */
class CrlResourceDisplayElements {
  
  /**
   * Define our base properties.
   */
  protected $entity;
  protected $entity_wrapper;
  protected $source_status;
  // Properties for our custom fields.
  public $pseudo_field_resource_status_summary;
  public $pseudo_field_resource_all_jisc_details;
  public $pseudo_field_resource_provider_details;
  public $pseudo_field_resource_activity;
  public $pseudo_field_resoruce_coll_content_tax;
  public $pseudo_field_resource_source_summary;
  public $pseudo_field_resource_table_sources;
  public $pseudo_field_resource_review_source;
  
  /**
   * Constructor
   */
  public function __construct($node) {
    $this->entity = $node;
    $this->entity_wrapper = entity_metadata_wrapper('node', $this->entity);
    $this->source_status = isset($this->entity_wrapper->field_resource_source_status) ? $this->entity_wrapper->field_resource_source_status->value() : NULL;
  }
  
  /**
   * Main method to get/build our custom resoruce data and store it in the
   * object properties.
   */
  public function build() {
    foreach ($this as $prop_name => $prop) {
      if (strpos($prop_name, 'pseudo_field') === 0) {
        $this->{'build_' . $prop_name}();
      }
    }
    return $this;  
  }
  
  /**
   * Build custom field: pseudo_field_resource_status_summary
   */
  protected function build_pseudo_field_resource_status_summary() {
    $built = NULL;
    // Calculate editor link.
    $edit_link = '';
    $backref_entities = isset($this->entity_wrapper->crl_resource_backref) ? $this->entity_wrapper->crl_resource_backref->value() : array();
    $backref_status = isset($this->entity_wrapper->crl_resource_status_backref) ? $this->entity_wrapper->crl_resource_status_backref->value() : array();
    if (!empty($backref_entities)) { // Activity data exists
      // Just get the first backref entity in the array (for now there should
      // just be one).
      $activity_entity = node_load(reset($backref_entities));
      if (entity_access('update', 'node', $activity_entity)) {
        $edit_link = url('node/' . $activity_entity->nid . '/edit', array('query' => array('activity_title' => rawurlencode('CRL Activity: ' . check_plain($this->entity->title)))));
      }
    }
    else { // No activity data exists.
      if (entity_access('create', 'node')) {
        $edit_link = url('node/add/activity', array('query' => array('activity_title' => rawurlencode('CRL Activity: ' . check_plain($this->entity->title)), 'resource_id' => $this->entity->nid)));
      }
    }
    // If we have anything to output, create render array.
    if (!empty($edit_link) || !empty($backref_status)) {
      $built = array(
        '#theme' => 'crl_resource_field_status_summary',
        '#edit_link' => $edit_link,
        '#status' => $backref_status,
        '#status_options' => crl_resource_activity_status_property_oplist(),
        '#status_descriptions' => $this->get_status_descriptions()
      );
    }
    $this->pseudo_field_resource_status_summary = $built;
  }
  
  /**
   * Build custom field: pseudo_field_resource_all_jisc_details
   */
  protected function build_pseudo_field_resource_all_jisc_details() {
    $built = NULL;
    $jisc_id = isset($this->entity_wrapper->field_jisc_id) ? $this->entity_wrapper->field_jisc_id->value() : NULL;
    // If the status flags this as a JISC display, and we have a JISC ID, then
    // display the JISC details fields.
    if (($this->source_status == 'jisc_only') && !empty($jisc_id)) {
      $output = '';
      $fields_array = array('field_resource_jisc_full_text', 'field_resource_jisc_federated', 'field_resource_jisc_metadata_std', 'field_resource_jisc_marc', 'field_resource_jisc_search', 'field_resource_jisc_post_search', 'field_resource_jisc_usage_stat', 'field_resource_jisc_auth', 'field_resource_jisc_access');
      foreach ($fields_array as $fieldname) {
        // Explicitly redner each JISC field. We can't render the values right
        // off the $entity->content array as many of these values are not
        // visible there (hidden fields in default display).
        $output .= drupal_render(field_view_field('node', $this->entity, $fieldname));
      }
      if (!empty($output)) {
        $built = array('#markup' => $output);
      }
    }
    $this->pseudo_field_resource_all_jisc_details = $built;
  }

  /**
   * Build custom field: pseudo_field_resource_provider_details
   */
  protected function build_pseudo_field_resource_provider_details() {
    $built = NULL;
    $output = '';
    // Show the provider field (again) from the resource
    $output .= drupal_render($this->entity->content['field_provider']);
    // Add the embedded display for the provider
    $provider = isset($this->entity_wrapper->field_provider) ? $this->entity_wrapper->field_provider->value() : NULL;
    if (!empty($provider)) {
      // Make sure we can view the provider node.
      if (entity_access('view', 'node', $provider)) {
        $provider_build = node_view($provider, 'embedded');
        // Drop the title from this view.
        $provider_build['#node']->title = '';
        $output .= drupal_render($provider_build);
      }
    }
    if (!empty($output)) {
      $built = array('#markup' => $output);
    }
    $this->pseudo_field_resource_provider_details = $built;
  }
  
  /**
   * Build custom field: pseudo_field_resource_activity
   */
  protected function build_pseudo_field_resource_activity() {
    $built = NULL;
    $backref_entities = isset($this->entity_wrapper->crl_resource_backref) ? $this->entity_wrapper->crl_resource_backref->value() : array();
    if (!empty($backref_entities)) { // Activity data exists
      // Just get the first backref entity in the array (for now there should
      // just be one).
      $activity_entity = node_load(reset($backref_entities));
      // Make sure we can view the activity node.
      if (entity_access('view', 'node', $activity_entity)) {
        $activity_entity_build = node_view($activity_entity, 'embedded');
        // Drop the title from this view.
        $activity_entity_build['#node']->title = '';
        $built = $activity_entity_build;
      }
      else {
        $restricted_message = t('The complete offer and activity details for this resource are only available to CRL members.');
        //$built = array('#markup' => $restricted_message);
        $built = array('#theme' => 'crl_resource_pseudo_field', '#output' => $restricted_message);
      }
    }
    $this->pseudo_field_resource_activity = $built;
  }
  
  /**
   * Build custom field: pseudo_field_resoruce_coll_content_tax
   */
  protected function build_pseudo_field_resoruce_coll_content_tax() {
    $built = NULL;
    $output = '';
    $output .= drupal_render($this->entity->content['field_subject_area']);
    $output .= drupal_render($this->entity->content['field_resource_type']);
    if (!empty($output)) {
      $built = array('#markup' => $output);
    }
    $this->pseudo_field_resoruce_coll_content_tax = $built;
  }
  
  /**
   * Build custom field: pseudo_field_resource_source_summary
   */
  protected function build_pseudo_field_resource_source_summary() {
    $built = NULL;
    $output = $this->get_source_text();
    if (!empty($output)) {
      $built = array('#theme' => 'crl_resource_pseudo_field', '#label' => t('Source'), '#output' => $output);
    }
    $this->pseudo_field_resource_source_summary = $built;
  }
  
  /**
   * Build custom field: pseudo_field_resource_table_sources
   */
  protected function build_pseudo_field_resource_table_sources() {
    $built = NULL;
    if ($this->source_status == 'crl_review') {
      $built = array('#theme' => 'crl_resource_publisher_legend', '#icon_alt_title' => t('Direct from Publisher'), '#icon_text' => t('Denotes data sourced directly from publisher'));
    }
    $this->pseudo_field_resource_table_sources = $built;
  }
  
  /**
   * Build custom field: pseudo_field_resource_review_source
   */
  protected function build_pseudo_field_resource_review_source() {
    $built = NULL;
    if ($this->source_status == 'crl_review') {
      $built = array('#theme' => 'crl_resource_pseudo_field', '#output' => t('Sources for this review include information publicly posted or obtained directly from the publisher, data collected by CRL staff and specialists at CRL libraries, members, and examination of the digital collection when possible. Other sources are noted where cited. <em>CRL continues to gather additional information on this resource and solicit critical assessment</em>.'));
    }
    $this->pseudo_field_resource_review_source = $built;
  }
  
  /**
   * Helper to centrally define description values to associate with each CRL
   * status option.
   */
  protected function get_status_descriptions() {
    return array(
      'crl_desiderata' => t('Potential interest to CRL community'),
      'license_under_consideration' => t('Currently a candidate for CRL offer'),
      'license_available' => t('Currently offered for purchase or new subscription'),
      'license_renewal_available' => t('Currently offered for renewal'),
      'trial_access_available' => t('Available for trial'),
      'past_license_offer' => t('Past offers'),
      'crl_review_available' => t('Evaluation available by CRL and community'),
    );
  }
  
  /**
   * Helper to generate fixed "source" text based on resoruce status.
   */
  protected function get_source_text() {
    $jisc_id = isset($this->entity_wrapper->field_jisc_id) ? $this->entity_wrapper->field_jisc_id->value() : NULL;
    $source_status = $this->source_status;
    $source_text = '';
    if ($source_status == 'crl_review') {
      $source_text = t('CRL reviews are based on independent research. Information is researched by CRL staff and other specialists at CRL libraries. See CRL Review for additional source notes.');
    }
    elseif ($source_status == 'stub') {
      $source_text = t('Information provided here drawn from from a number of sources, and may not yet be fully verified by CRL.');
    }
    elseif ($source_status == 'jisc_only' && !empty($jisc_id)) {
      $source_text = t('Information has been sourced from a !sitelink entry, with additional edits by CRL.', array('!sitelink' => $this->jisc_link(t('JISC catalog'))));
    }
    else {
      $source_text = t('Source details are unknown for this entry.');
    }
    return $source_text;
  }
  
  /**
   * Helper to build a link to a JISC resource.
   * 
   * @param string $anchor
   *   The anchor text to use in the link.
   * @param int $jisc_id
   *   The ID to a JISC resrouce. If non-zero the link will point to that specific
   *   resource, if "0" the link will point to the JISC catalog index and if NULL
   *   the link will point to the JISC homepage.
   * @param string $sub_path
   *   The sub-path, or tab, of a resource to point to. Only applies for a
   *   non-zero JISC id. 
   * @return string
   *   A formatted link to JISC.
   */
  public function jisc_link($anchor, $jisc_id = NULL, $sub_path = 'Overview') {
    if (isset($jisc_id)) {
      if ($jisc_id == 0) {
        $path = 'http://www.jisc-collections.ac.uk/Catalogue';
      }
      else {
        $path = 'http://www.jisc-collections.ac.uk/Catalogue/' . $sub_path . '/Index/' . $jisc_id;
      }
    }
    else {
      $path = 'http://www.jisc-collections.ac.uk';
    }
    return l($anchor, $path, array('attributes' => array('target'=>'_blank')));
  }

}
