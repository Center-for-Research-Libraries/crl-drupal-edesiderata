<?php
/**
 * @file
 * crl_resource_dashboard_feat.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crl_resource_dashboard_feat_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'resource_dashboard';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-resource_dashboard-block_4' => array(
          'module' => 'views',
          'delta' => 'resource_dashboard-block_4',
          'region' => 'preface_first',
          'weight' => '-8',
        ),
        'views-resource_dashboard-block_1' => array(
          'module' => 'views',
          'delta' => 'resource_dashboard-block_1',
          'region' => 'postscript_first',
          'weight' => '-9',
        ),
        'views-resource_dashboard-block_2' => array(
          'module' => 'views',
          'delta' => 'resource_dashboard-block_2',
          'region' => 'postscript_second',
          'weight' => '-9',
        ),
        'views-resource_dashboard-block_3' => array(
          'module' => 'views',
          'delta' => 'resource_dashboard-block_3',
          'region' => 'postscript_third',
          'weight' => '-9',
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
  $export['resource_dashboard'] = $context;

  return $export;
}
