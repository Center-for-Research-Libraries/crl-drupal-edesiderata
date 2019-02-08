<?php

/**
 * @file
 * crl_pp_resource_feat.box.inc
 */

/**
 * Implements hook_default_box().
 */
function crl_pp_resource_feat_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'pp_vote_instructions';
  $box->plugin_key = 'simple';
  $box->title = 'Voting Instructions';
  $box->description = 'PP Voting Instructions (box)';
  $box->options = array(
    'body' => array(
      'value' => '<ol>
	<li>Please rank the nominated title by clicking the appropriate number of star: 1 (little or no interest) through 5 (strongly favor purchase). If you wish to abstain from ranking a title, simply leave it blank.</li>
	<li>Indicate if your library holds the title and ability to lend by clicking one of the three options listed.</li>
	<li>Provide any general comments or additional information via the &quot;comments&quot; section shown at the bottom if this page.</li>
</ol>
',
      'format' => 'full_html',
    ),
  );
  $export['pp_vote_instructions'] = $box;

  return $export;
}
