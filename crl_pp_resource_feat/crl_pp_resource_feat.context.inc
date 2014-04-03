<?php
/**
 * @file
 * crl_pp_resource_feat.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crl_pp_resource_feat_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pp_resource_index';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'pp_resource_lists:page_2' => 'pp_resource_lists:page_2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
    'breadcrumb' => 'spp',
    'menu' => 'spp',
  );
  $context->condition_mode = 0;
  $export['pp_resource_index'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pp_resource_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'pp_resource' => 'pp_resource',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'crl_pp_resource_feat-crl_pp_resource_back_to_index' => array(
          'module' => 'crl_pp_resource_feat',
          'delta' => 'crl_pp_resource_back_to_index',
          'region' => 'branding',
          'weight' => '-7',
        ),
        'crl_pp_resource_feat-crl_pp_resource_feat_vote' => array(
          'module' => 'crl_pp_resource_feat',
          'delta' => 'crl_pp_resource_feat_vote',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
    'breadcrumb' => 'pp',
    'menu' => 'pp',
  );
  $context->condition_mode = 0;
  $export['pp_resource_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pp_resource_page_pp_main';
  $context->description = '';
  $context->tag = 'permissions';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'pp_resource_page' => 'pp_resource_page',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'pp-main' => 'pp-main',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-29' => array(
          'module' => 'block',
          'delta' => '29',
          'region' => 'sidebar_second',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('permissions');
  $export['pp_resource_page_pp_main'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'spp_resource_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'spp_resource' => 'spp_resource',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'crl_pp_resource_feat-crl_pp_resource_back_to_index' => array(
          'module' => 'crl_pp_resource_feat',
          'delta' => 'crl_pp_resource_back_to_index',
          'region' => 'branding',
          'weight' => '-7',
        ),
        'crl_pp_resource_feat-crl_pp_resource_feat_vote' => array(
          'module' => 'crl_pp_resource_feat',
          'delta' => 'crl_pp_resource_feat_vote',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
    'breadcrumb' => 'spp',
    'menu' => 'spp',
  );
  $context->condition_mode = 0;
  $export['spp_resource_page'] = $context;

  return $export;
}
