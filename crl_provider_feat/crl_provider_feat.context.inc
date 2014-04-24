<?php
/**
 * @file
 * crl_provider_feat.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crl_provider_feat_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'provider_index';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'provider_lists' => 'provider_lists',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'crl_helpers-crl_helpers_alpha_facet_sort' => array(
          'module' => 'crl_helpers',
          'delta' => 'crl_helpers_alpha_facet_sort',
          'region' => 'content',
          'weight' => '-49',
        ),
        'views--exp-provider_lists-page' => array(
          'module' => 'views',
          'delta' => '-exp-provider_lists-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'crl_helpers-crl_helpers_facet_breadcrumb' => array(
          'module' => 'crl_helpers',
          'delta' => 'crl_helpers_facet_breadcrumb',
          'region' => 'preface_first',
          'weight' => '-50',
        ),
        'delta_blocks-tabs' => array(
          'module' => 'delta_blocks',
          'delta' => 'tabs',
          'region' => 'preface_first',
          'weight' => '-40',
        ),
      ),
    ),
    'breadcrumb' => 'providers/main',
    'menu' => 'providers/main',
    'theme_html' => array(
      'class' => 'resources-index',
    ),
  );
  $context->condition_mode = 0;
  $export['provider_index'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'provider_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'provider' => 'provider',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '~comment/*' => '~comment/*',
        '~node/*/edit' => '~node/*/edit',
        '~node/add*' => '~node/add*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'crl_resource-crl_resource_back_to_index' => array(
          'module' => 'crl_resource',
          'delta' => 'crl_resource_back_to_index',
          'region' => 'branding',
          'weight' => '-7',
        ),
        'crl_resource-crl_resource_summary' => array(
          'module' => 'crl_resource',
          'delta' => 'crl_resource_summary',
          'region' => 'preface_first',
          'weight' => '10',
        ),
      ),
    ),
    'breadcrumb' => 'providers/main',
    'menu' => 'providers/main',
  );
  $context->condition_mode = 1;
  $export['provider_page'] = $context;

  return $export;
}
