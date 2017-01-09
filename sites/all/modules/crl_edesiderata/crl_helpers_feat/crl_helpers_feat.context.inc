<?php
/**
 * @file
 * crl_helpers_feat.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crl_helpers_feat_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'editors';
  $context->description = '';
  $context->tag = 'permissions';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'editor basic' => 'editor basic',
        'editor power' => 'editor power',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'crl_helpers-crl_helpers_editor_tools' => array(
          'module' => 'crl_helpers',
          'delta' => 'crl_helpers_editor_tools',
          'region' => 'branding',
          'weight' => '-50',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('permissions');
  $export['editors'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'layout_default';
  $context->description = '';
  $context->tag = 'layout';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-19' => array(
          'module' => 'block',
          'delta' => '19',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'block-20' => array(
          'module' => 'block',
          'delta' => '20',
          'region' => 'footer_second',
          'weight' => '-10',
        ),
        'block-21' => array(
          'module' => 'block',
          'delta' => '21',
          'region' => 'footer_third',
          'weight' => '-10',
        ),
        'block-22' => array(
          'module' => 'block',
          'delta' => '22',
          'region' => 'footer_fourth',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('layout');
  $export['layout_default'] = $context;

  return $export;
}
