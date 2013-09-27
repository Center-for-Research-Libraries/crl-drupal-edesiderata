<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php 
  // Get the nid of our current row.
  $nid = $view->result[$view->row_index]->entity;
  // We don't display any fields directly, we just use our custom theme
  // function to build the whole row from scratch based on the nid.
  if (isset($nid)) {
    $entities = entity_load('node', array($nid)); // Should alerady be in static cache from view
    if (!empty($entities[$nid])) {
      $entity = $entities[$nid];
      $entity_wrapper = entity_metadata_wrapper('node', $entity);
      // Get link.
      $url = entity_uri('node', $entity);
      $link = l($entity_wrapper->title->value(), $url['path'], $url['options']);
      // Get summary via Entity API.
      $body = $entity_wrapper->body->value();
      $summary = $body['value'];
      // Get provider title.
      $provider = isset($entity_wrapper->field_provider) ? $entity_wrapper->field_provider->value()->title : '';
      // Get updated and added dates.
      // @todo: consider making formats more configurable, or move to theme
      // hook.
      $updated = format_date($entity_wrapper->changed->value(), 'custom', 'm-d-Y');
      $added = format_date($entity_wrapper->created->value(), 'custom', 'm-d-Y');
      // Get status info
      $status = isset($entity_wrapper->crl_resource_status_backref) ? $entity_wrapper->crl_resource_status_backref->value() : array();
      $status_options = crl_resource_activity_status_property_oplist();
      print theme('crl_resource_teaser', array('link' => $link, 'summary' => $summary, 'provider' => $provider, 'updated' => $updated, 'added' => $added, 'status' => $status, 'status_options' => $status_options));
    }
  }
  
  
