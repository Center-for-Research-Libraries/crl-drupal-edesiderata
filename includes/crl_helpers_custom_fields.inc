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
  $jisc_id = crl_resource_get_single_node_field($entity, 'field_jisc_id');
  $source_status = crl_resource_get_single_node_field($entity, 'field_resource_source_status');
  // If the status flags this as a JISC display, and we have a JISC ID, then
  // display the JISC details fields.
  if (($source_status == 'jisc_only') && !empty($jisc_id)) {
    $fields_array = array('field_resource_jisc_full_text', 'field_resource_jisc_federated', 'field_resource_jisc_metadata_std', 'field_resource_jisc_marc', 'field_resource_jisc_search', 'field_resource_jisc_post_search', 'field_resource_jisc_usage_stat', 'field_resource_jisc_auth', 'field_resource_jisc_access');
    foreach ($fields_array as $fieldname) {
      $output .= drupal_render(field_view_field('node', $entity, $fieldname));
    }
  }
  return $output;
}


/**
 * Custom field to show the activity summary.
 * 
 * field_resource_status_summary
 */
function computed_field_field_resource_status_summary_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  $data = $entity->resource_summary;
  // Calculate editor link.
  $edit_link = '';
  if (!empty($data['backref_entities'])) { // Activity data exists
    // Just get the first backref entity in the array (for now there should
    // just be one).
    $activity_entity = reset($data['backref_entities']);
    if (entity_access('update', 'node', $activity_entity)) {
      $edit_link = url('node/' . $activity_entity->nid . '/edit', array('query' => array('activity_title' => rawurlencode('Activity: ' . check_plain($entity->title)))));
    }
  }
  else { // No activity data exists
    if (entity_access('create', 'node')) {
      $edit_link = url('node/add/activity', array('query' => array('activity_title' => rawurlencode('Activity: ' . check_plain($entity->title)), 'resource_id' => $entity->nid)));
    }
  }
  return theme('crl_helpers_resource_status_summary', array('entity' => $entity, 'edit_link' => $edit_link));
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
  $data = $entity->resource_summary;
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
      $restricted_message = '<strong>' . t('The complete offer and activity details for this resource are only available to CRL members.') . '</strong>';
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
    $string = $entity->field_resource_title_for_sort[$entity->language][0]['value'];
    // Get first character in a multibyte-safe way.
    if(mb_strlen($string)){
      $entity_field[0]['value'] = strtoupper(mb_substr($string, 0, 1));
    }
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


/**
 * Custom field to show a CRL source summary.
 * 
 * field_resource_source_summary
 */
function computed_field_field_resource_source_summary_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  if (!empty($entity->resource_summary['source_text'])) {
    return $entity->resource_summary['source_text'];
  }
}


/**
 * Custom field to show a sources legend for resource tablefields.
 * 
 * field_resource_table_sources
 */
function computed_field_field_resource_table_sources_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  $source_status = crl_resource_get_single_node_field($entity, 'field_resource_source_status');
  if ($source_status == 'crl_review') {
    return '<div style="float: right; margin: 5px 0px 10px 10px;"><img style="vertical-align: middle;" title="Direct from Publisher" src="/' . drupal_get_path('module', 'crl_helpers') . '/images/icon_publisher.png"> - Denotes data sourced directly from publisher.</div>';
  }
}


/**
 * Custom field to show source information specific to a CRL review
 * 
 * field_resource_review_source
 */
function computed_field_field_resource_review_source_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  $source_status = crl_resource_get_single_node_field($entity, 'field_resource_source_status');
  if ($source_status == 'crl_review') {
    return t('Sources for this review include information publicly posted or obtained directly from the publisher, data collected by CRL staff and specialists at CRL libraries, members, and examination of the digital collection when possible. Other sources are noted where cited. <em>CRL continues to gather additional information on this resource and solicit critical assessment</em>.');
  }
}


/**
 * Custom field to show a special message for activity entries that apply to
 * CRL project groups.
 * 
 * field_field_activity_group_notice
 */
function computed_field_field_activity_group_notice_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  $grouping = crl_resource_get_single_node_field($entity, 'field_activity_grouping');
  if ($grouping) {
    $term = taxonomy_term_load($grouping);
    // @todo: make some of the strings below configurable and maybe even
    // multilingual friendly.
    if (!empty($term->name) && $term->name != 'CRL Members') {
      return '<div class="notice-box">' . t('The CRL activity posted here is on behalf of <strong>@group</strong> for the benefit of its members only. For inquiries about eligibility for participating in the offer, please contact Judy Alspach at jalspach@crl.edu.', array('@group' => $term->name)) . '</div>';
    }
  }
}
