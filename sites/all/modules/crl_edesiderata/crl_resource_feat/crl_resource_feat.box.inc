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

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'special_access';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Special Access Available';
  $box->options = array(
    'body' => array(
      'value' => '<p><i class="icon icon-special_access"></i>Given the increased value of electronic access to resources during the COVID-19 pandemic, CRL is negotiating special access to key primary source collections from commercial partners on behalf of CRL member institutions. The list below includes online resources that are freely available to all CRL institutions through the end of the academic year (dates may vary). Note: some resources may already be available to your users through prior institutional purchase.</p>
',
      'format' => 'literal',
    ),
    'additional_classes' => '',
  );
  $export['special_access'] = $box;

  return $export;
}
