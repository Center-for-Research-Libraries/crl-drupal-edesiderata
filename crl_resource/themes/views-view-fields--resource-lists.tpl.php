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
<h2>
  <?php print '<a href="' . $resource_url . '">' . $resource_title . '</a>';
  if ($alert_active) {
    print theme('crl_resource_alert_tag', array('url' => $resource_url));
  }
  if (isset($days_left)) {
    print theme('crl_resource_countdown_alert_tag', array('url' => $resource_url, 'days_left' => $days_left, 'long' => TRUE));
  } ?>
</h2>
<?php print $summary ?>
<div class="teaser-details">
<?php print $provider ?>
<br />
<?php print $updated ?>
</div>
<?php
  if (!empty($status)) {
    print '<div class="view-teaser-status-icons">';
    foreach ($status as $stat) {
      print '<span class="summary-icon-small ' . $stat . '" title="' . $status_options[$stat] . '"></span>';
    }
    print '</div>';
  } 
  print $extra;
  ?>
<div class="clearfix"></div>
