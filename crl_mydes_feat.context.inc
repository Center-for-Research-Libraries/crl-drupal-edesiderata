<?php
/**
 * @file
 * crl_mydes_feat.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crl_mydes_feat_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mydes_dashboard';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'my' => 'my',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-mydes_lists-block_1' => array(
          'module' => 'views',
          'delta' => 'mydes_lists-block_1',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
        'views-mydes_saved_searches-block' => array(
          'module' => 'views',
          'delta' => 'mydes_saved_searches-block',
          'region' => 'preface_first',
          'weight' => '-9',
        ),
        'block-12' => array(
          'module' => 'block',
          'delta' => '12',
          'region' => 'preface_first',
          'weight' => '-8',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'resource_dashboard',
    ),
    'theme_html' => array(
      'class' => 'resources-dashboard',
    ),
  );
  $context->condition_mode = 0;
  $export['mydes_dashboard'] = $context;

  return $export;
}
