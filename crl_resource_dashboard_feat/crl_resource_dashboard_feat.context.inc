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
        'crl_pp_resource_feat-crl_pp_resource_feat_pp_link' => array(
          'module' => 'crl_pp_resource_feat',
          'delta' => 'crl_pp_resource_feat_pp_link',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-crl_messages-block_1' => array(
          'module' => 'views',
          'delta' => 'crl_messages-block_1',
          'region' => 'user_first',
          'weight' => '-10',
        ),
        'crl_resource_dashboard_feat-crl_resource_dashboard_feat_top' => array(
          'module' => 'crl_resource_dashboard_feat',
          'delta' => 'crl_resource_dashboard_feat_top',
          'region' => 'preface_first',
          'weight' => '-10',
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
      'class' => 'dashboard resources-dashboard equal-postscript',
    ),
  );
  $context->condition_mode = 0;
  $export['resource_dashboard'] = $context;

  return $export;
}
