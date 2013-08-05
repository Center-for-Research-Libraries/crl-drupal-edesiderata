<?php


/**
 * @file
 * Custom field display handlers for fields defined with the Computed Fields
 * module. IMPORTANT - most of these functions depend on the patch decribed in
 * https://drupal.org/node/1883156 being applied!
 * 
 * @todo: See if we could implement these fields with hook_node_load()
 * (to compute the field) and hook_field_extra_fields() (to add the computed
 * data as a field) instead of computed field.
 */


/**
 * Custom field to show JISC details.
 * 
 * field_resource_all_jisc_details
 */
function computed_field_field_resource_all_jisc_details_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  $output = '';
  $jisc_id = crl_helpers_get_single_node_field($entity, 'field_jisc_id');
  $source_status = crl_helpers_get_single_node_field($entity, 'field_resource_source_status');
  // If the status flags this as a JISC display, and we have a JISC ID, then
  // display the JISC details fields.
  if (($source_status == 'jisc_only') && !empty($jisc_id)) {
    $fields_array = array('field_resource_jisc_full_text', 'field_resource_jisc_federated', 'field_resource_jisc_metadata_std', 'field_resource_jisc_marc', 'field_resource_jisc_search', 'field_resource_jisc_post_search', 'field_resource_jisc_usage_stat', 'field_resource_jisc_auth', 'field_resource_jisc_access');
    foreach ($fields_array as $fieldname) {
      $output .= drupal_render(field_view_field('node', $entity, $fieldname));
    }
  }
  // If this is a CRL review but we also have a JISC ID, show a note about
  // the fact that additional details may be available at JISC.
  elseif ($source_status == 'crl_review' && !empty($jisc_id)) {
    $output .= '<h3>' . t("Additional Details from JISC") . '</h3>';
    $output .= t("Additional details may be available in the !itemlink for this item from !sitelink", array('!itemlink' => crl_helpers_jisc_link(t('catalog entry'), $jisc_id), '!sitelink' => crl_helpers_jisc_link(t('JISC Collections'))));
  }
  return $output;
}


/**
 * Custom field to show the activity summary.
 * 
 * field_resource_status_summary
 */
function computed_field_field_resource_status_summary_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  $data = crl_helpers_get_backref_summary($entity);
  $status_names = crl_helpers_activity_status_property_oplist();
  // Calculate editor link.
  $edit_link = '';
  if (!empty($data['backref_entities'])) { // Activity data exists
    // Just get the first backref entity in the array (for now there should
    // just be one).
    $activity_entity = reset($data['backref_entities']);
    if (entity_access('update', 'node', $activity_entity)) {
      $edit_link = url('node/' . $activity_entity->nid . '/edit', array('query' => array('destination' => current_path(), 'activity_title' => rawurlencode('Activity: ' . check_plain($entity->title)))));
    }
  }
  else { // No activity data exists
    if (entity_access('create', 'node')) {
      $edit_link = url('node/add/activity', array('query' => array('destination' => current_path(), 'activity_title' => rawurlencode('Activity: ' . check_plain($entity->title)), 'resource_id' => $entity->nid)));
    }
  }
  return theme('crl_helpers_resource_status_summary', array('data' => $data, 'status_names' => $status_names, 'edit_link' => $edit_link));
}


/**
 * Custom field to show an "embedded" display of the providers details that are
 * related to a resource.
 * 
 * field_resource_provider_details
 */
function computed_field_field_resource_provider_details_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  $items = field_get_items('node', $entity, 'field_provider');
  if (!empty($items[0]['entity']->nid)) {
    $provider = node_load($items[0]['entity']->nid);
    // Make sure we can view the provider node.
    if (entity_access('view', 'node', $provider)) {
      $provider_build = node_view($provider, 'embedded');
      // Drop the title from this view.
      $provider_build['#node']->title = '';
      return drupal_render($provider_build);
    }
  }
}


/**
 * Custom field to show an "embedded" display of the activity details that are
 * related to a resource.
 * 
 * field_resource_activity
 */
function computed_field_field_resource_activity_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  $data = crl_helpers_get_backref_summary($entity);
  if (!empty($data['backref_entities'])) { // Activity data exists
    // Just get the first backref entity in the array (for now there should
    // just be one).
    $activity_entity = reset($data['backref_entities']);
    // Make sure we can view the activity node.
    if (entity_access('view', 'node', $activity_entity)) {
      $activity_entity_build = node_view($activity_entity, 'embedded');
      // Drop the title from this view.
      $activity_entity_build['#node']->title = '';
      return drupal_render($activity_entity_build);
    }
    else {
      $restricted_message = t('The complete offer and activity details for this resource are only available to CRL members.');
      global $user;
      if (!$user->uid) {
        $restricted_message .= '<br/>' . t('Please <a href="!link">login</a> to view more.', array('!link' => url('user')));
      }
      return $restricted_message;
    }
  }
}


/**
 * Custom field to simply show the entity title as a field.
 * 
 * field_entity_title
 */
function computed_field_field_entity_title_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity->title;
}


/**
 * Custom field to show (or re-display) collection content taxonomy values.
 * 
 * field_coll_content_tax
 */
function computed_field_field_coll_content_tax_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  $output = '';
  $output .= drupal_render(field_view_field('node', $entity, 'field_subject_area', 'default'));
  $output .= drupal_render(field_view_field('node', $entity, 'field_resource_type', 'default'));
  return $output;
}


/**
 * Custom field compute a resource glossary value.
 * 
 * field_resource_glossary
 */
function computed_field_field_resource_glossary_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  // Grab first character from the field title_for_sort
  $entity_field[0]['value'] = '';
  if (!empty($entity->field_resource_title_for_sort[$entity->language][0]['value'][0])) {
    $entity_field[0]['value'] = strtoupper($entity->field_resource_title_for_sort[$entity->language][0]['value'][0]);
  }
}


/**
 * Custom field to show a resource glossary value.
 * 
 * field_resource_glossary
 */
function computed_field_field_resource_glossary_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  // Just display the value from the database.
  return $entity_field_item['value'];
}


function computed_field_field_resource_table_sources_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  $source_status = crl_helpers_get_single_node_field($entity, 'field_resource_source_status');
  if ($source_status == 'crl_review') {
    return '<div style="float: right; margin: 5px 0px 10px 10px;"><img style="vertical-align: middle;" title="Direct from Publisher" src="/' . drupal_get_path('module', 'crl_helpers') . '/images/icon_publisher.png"> - Denotes data sourced directly from publisher.</div>';
  }
}
