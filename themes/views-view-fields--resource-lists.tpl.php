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
      $provider_id = crl_resource_get_single_node_field($entity, 'field_provider');
      $providers = entity_load('node', array($provider_id));
      if (!empty($providers[$provider_id])) {
        $provider = $providers[$provider_id];
        print theme('crl_helpers_resource_teaser', array('resource_entity' => $entity, 'provider_entity' => $provider));
      }
    }
  }
  
  
