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
  public $pseudo_field_resource_status_summary = array();
  public $pseudo_field_resource_all_jisc_details = array();
  public $pseudo_field_resource_provider_details = array();
  public $pseudo_field_resource_activity = array();
  public $pseudo_field_resource_coll_content_tax = array();
  public $pseudo_field_resource_source_summary = array();
  public $pseudo_field_resource_table_sources = array();
  public $pseudo_field_resource_review_source = array();
  public $pseudo_field_resource_added = array();
  public $pseudo_field_resource_updated = array();
  public $pseudo_field_resource_alerts = array();
  
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
    // Calculate editor link and backref status details.
    $edit_link = crl_resource_activity_edit_link($this->entity_wrapper);
    $backref_status = isset($this->entity_wrapper->crl_resource_status_backref) ? $this->entity_wrapper->crl_resource_status_backref->value() : array();
    // See if we have any activity entries. If we do we want to be sure to
    // display the status summary table (as empty) even if there are not status
    // values to report.
    $backref_entities = isset($this->entity_wrapper->crl_resource_backref) ? $this->entity_wrapper->crl_resource_backref->value() : array();
    // If we have anything to output, create render array.
    if (!empty($edit_link) || !empty($backref_status) || !empty($backref_entities)) {
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
      $activity_entity = reset($backref_entities);
      // Make sure we can view the activity node.
      if (entity_access('view', 'node', $activity_entity)) {
        $activity_entity_build = node_view($activity_entity, 'embedded');
        // We are embedding the whole activity entry as a field, so we should
        // mark it as "viewed" in the history.
        node_tag_new($activity_entity);
        // Drop the title from this view.
        $activity_entity_build['#node']->title = '';
        $built = $activity_entity_build;
      }
      else {
        $restricted_message = t('The complete offer and activity details for this resource are only available to CRL members.');
        $built = array('#theme' => 'crl_resource_pseudo_field', '#output' => $restricted_message);
      }
    }
    $this->pseudo_field_resource_activity = $built;
  }
  
  /**
   * Build custom field: pseudo_field_resource_coll_content_tax
   */
  protected function build_pseudo_field_resource_coll_content_tax() {
    $built = NULL;
    $output = '';
    $output .= drupal_render($this->entity->content['field_subject_area']);
    $output .= drupal_render($this->entity->content['field_resource_type']);
    if (!empty($output)) {
      $built = array('#markup' => $output);
    }
    $this->pseudo_field_resource_coll_content_tax = $built;
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
      $built = array('#theme' => 'crl_resource_pseudo_field', '#output' => t('Sources for this review include information publicly posted or obtained directly from the publisher; data collected by CRL staff and specialists at CRL libraries; and examination of the digital collection when possible. Other sources are noted where cited. <em>CRL continues to gather additional information on this resource and to solicit critical assessment</em>.'));
    }
    $this->pseudo_field_resource_review_source = $built;
  }
  
  /**
   * Build custom field: pseudo_field_resource_added
   */
  protected function build_pseudo_field_resource_added() {
    $built = array('#theme' => 'crl_resource_pseudo_field', '#label' => t('Posted'), '#output' => format_date($this->entity_wrapper->created->value(), 'short'), '#inline' => TRUE);
    $this->pseudo_field_resource_added = $built;
  }
  
  /**
   * Build custom field: pseudo_field_resource_updated
   */
  protected function build_pseudo_field_resource_updated() {
    $built = array('#theme' => 'crl_resource_pseudo_field', '#label' => t('Updated'), '#output' => format_date($this->entity_wrapper->crl_resource_master_update_timestamp->value(), 'short'), '#inline' => TRUE);
    $this->pseudo_field_resource_updated = $built;
  }
  
  /**
   * Build custom field: pseudo_field_resource_alerts
   */
  protected function build_pseudo_field_resource_alerts() {
    $built = NULL;
    $wrappers = crl_resource_get_wrappers($this->entity_wrapper);
    $wrappers_to_check = array_merge(array($wrappers['r_entity_wrapper']), $wrappers['a_entity_wrappers']);
    foreach($wrappers_to_check as $wrapper) {
      $alert = isset($wrapper->field_update_alert) ? $wrapper->field_update_alert->value() : NULL;
      if ((!empty($alert) && $alert > time())) {
        $alert_message = isset($wrapper->field_update_alert_message) ? $wrapper->field_update_alert_message->value() : NULL;
        $markup = theme('crl_resource_alert_tag', array('url' => '#'));
        if (!empty($alert_message['value'])) {
          if (entity_access('view', 'node', $wrapper->value())) {
            $markup .= $alert_message['value'];
          }
          else {
            $markup .= t('The full details of this alert are only available to CRL members.');
          }
        }
        $built[] = array('#theme' => 'crl_resource_pseudo_field', '#output' => $markup);
      }
    }
    $this->pseudo_field_resource_alerts = $built;
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
      'inactive_declined' => t('No longer under consideration by CRL'),
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