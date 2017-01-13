<?php
/**
 * @file
 * crl_helpers_feat.box.inc
 */

/**
 * Implements hook_default_box().
 */
function crl_helpers_feat_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'footer1';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Footer 1 (box)';
  $box->options = array(
    'body' => array(
      'value' => '<ul>
	<li><a href="http://www.crl.edu">Main Website</a></li>
	<li><a href="http://catalog.crl.edu">Catalog</a></li>
	<li>&nbsp;</li>
	<li><a href="http://www.crl.edu/privacy-policy">Privacy Policy</a></li>
</ul>

<p>&nbsp;</p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['footer1'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'footer2';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Footer 2 (box)';
  $box->options = array(
    'body' => array(
      'value' => '<p>6050 S. Kenwood Avenue<br />
	Chicago, IL 60637-2804 USA<br />
	Phone: (800) 621-6044 or (773) 955-4545<br />
	Fax: (773) 955-4339</p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['footer2'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'footer3';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Footer 3 (box)';
  $box->options = array(
    'body' => array(
      'value' => '<ul>
	<li><a href="http://www.crl.edu/about/" target="_blank">About CRL</a></li>
	<li><a href="http://www.crl.edu/membership/">Membership</a></li>
	<li><a href="http://www.crl.edu/collaborations" target="_blank">Collaborations</a></li>
</ul>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['footer3'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'footer4';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Footer 4 (box)';
  $box->options = array(
    'body' => array(
      'value' => '<ul>
	<li><a href="http://www.crl.edu/collections/" target="_blank">Collections</a></li>
	<li><a href="http://www.crl.edu/services/" target="_blank">Services</a></li>
	<li><a href="http://www.crl.edu/archiving-preservation/" target="_blank">Archiving &amp; Preservation</a></li>
</ul>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['footer4'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'general_disclaimer';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'General disclaimer (box)';
  $box->options = array(
    'body' => array(
      'value' => '<p><br />
	While CRL makes every effort to verify statements made herein, the opinions expressed and evaluative information provided here represent the considered viewpoints of individual librarians and specialists at CRL and in the CRL community.&nbsp; They do not necessarily reflect the views of CRL management, its board, and/or its officers.</p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['general_disclaimer'] = $box;

  return $export;
}
