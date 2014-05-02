<?php
/**
 * @file
 * crl_resource_feat.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crl_resource_feat_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'resource_index';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'resource_lists' => 'resource_lists',
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
        'views--exp-resource_lists-page' => array(
          'module' => 'views',
          'delta' => '-exp-resource_lists-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-5BBuHdjWrZavBCvlArM0upLIQkpiQe1r' => array(
          'module' => 'facetapi',
          'delta' => '5BBuHdjWrZavBCvlArM0upLIQkpiQe1r',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-Frv8nBNGz5sOpVJ06a5SkvHfTFT7RMiV' => array(
          'module' => 'facetapi',
          'delta' => 'Frv8nBNGz5sOpVJ06a5SkvHfTFT7RMiV',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-4ucqlY1vS1kYr001uOAUlkpmWQNxXNej' => array(
          'module' => 'facetapi',
          'delta' => '4ucqlY1vS1kYr001uOAUlkpmWQNxXNej',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-o8OnPY6U8DgY85bgiLs3LCoaTWIv5PXS' => array(
          'module' => 'facetapi',
          'delta' => 'o8OnPY6U8DgY85bgiLs3LCoaTWIv5PXS',
          'region' => 'sidebar_first',
          'weight' => '-6',
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
    'breadcrumb' => 'resources/main',
    'menu' => 'resources/main',
    'theme_html' => array(
      'class' => 'resources-index',
    ),
  );
  $context->condition_mode = 0;
  $export['resource_index'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'resource_index_auth';
  $context->description = '';
  $context->tag = 'permissions';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'resource_index' => 'resource_index',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-12' => array(
          'module' => 'block',
          'delta' => '12',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('permissions');
  $export['resource_index_auth'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'resource_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'resource' => 'resource',
      ),
      'options' => array(
        'node_form' => '0',
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
        'crl_helpers-crl_helpers_back_to_index' => array(
          'module' => 'crl_helpers',
          'delta' => 'crl_helpers_back_to_index',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'crl_resource-crl_resource_summary' => array(
          'module' => 'crl_resource',
          'delta' => 'crl_resource_summary',
          'region' => 'preface_first',
          'weight' => '10',
        ),
      ),
    ),
    'menu' => array(
      0 => 'main-menu:resources/main',
    ),
  );
  $context->condition_mode = 1;
  $export['resource_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'resource_page_anon';
  $context->description = '';
  $context->tag = 'permissions';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'resource' => 'resource',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-27' => array(
          'module' => 'block',
          'delta' => '27',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('permissions');
  $export['resource_page_anon'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'resource_page_mem';
  $context->description = '';
  $context->tag = 'permissions';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'resource' => 'resource',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'crl-staff' => 'crl-staff',
        'editor basic' => 'editor basic',
        'editor power' => 'editor power',
        'member-crl' => 'member-crl',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'crl_resource-crl_resource_common_input' => array(
          'module' => 'crl_resource',
          'delta' => 'crl_resource_common_input',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'crl_mydes_feat-crl_mydes_feat_flag' => array(
          'module' => 'crl_mydes_feat',
          'delta' => 'crl_mydes_feat_flag',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('permissions');
  $export['resource_page_mem'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'resource_page_nonmem';
  $context->description = '';
  $context->tag = 'permissions';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~resource_page_mem' => '~resource_page_mem',
      ),
    ),
    'node' => array(
      'values' => array(
        'resource' => 'resource',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-28' => array(
          'module' => 'block',
          'delta' => '28',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('permissions');
  $export['resource_page_nonmem'] = $context;

  return $export;
}
