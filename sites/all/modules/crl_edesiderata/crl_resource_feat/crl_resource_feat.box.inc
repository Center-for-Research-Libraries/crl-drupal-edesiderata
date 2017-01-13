<?php
/**
 * @file
 * crl_resource_feat.box.inc
 */

/**
 * Implements hook_default_box().
 */
function crl_resource_feat_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'resources_intro';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Resources intro (box)';
  $box->options = array(
    'body' => array(
      'value' => '<p>CRL gathers and provides information here about commercial and open access digital resources of interest to the CRL community.&nbsp; This information is intended to inform library decisions on investment in electronic resources and related services.</p>

<p style="text-align: right"><a href="/resources/suggestions">+ Suggest New Resource</a></p>
',
      'format' => 'full_html',
    ),
  );
  $export['resources_intro'] = $box;

  return $export;
}
