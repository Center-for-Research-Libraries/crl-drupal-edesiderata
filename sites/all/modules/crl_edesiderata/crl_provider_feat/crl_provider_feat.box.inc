<?php
/**
 * @file
 * crl_provider_feat.box.inc
 */

/**
 * Implements hook_default_box().
 */
function crl_provider_feat_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'providers_intro';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Providers Intro (box)';
  $box->options = array(
    'body' => array(
      'value' => '<p>CRL gathers and provides information here about publishers, aggregators, preservation services, and other organizations that host, publish, and maintain digital resources of interest to the CRL community.&nbsp; This information is intended to inform library decisions on investment in electronic resources and related services.</p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['providers_intro'] = $box;

  return $export;
}
