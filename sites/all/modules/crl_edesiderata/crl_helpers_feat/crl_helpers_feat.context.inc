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
        'boxes-footer1' => array(
          'module' => 'boxes',
          'delta' => 'footer1',
          'region' => 'footer_first',
          'weight' => '-9',
        ),
        'boxes-footer2' => array(
          'module' => 'boxes',
          'delta' => 'footer2',
          'region' => 'footer_second',
          'weight' => '-9',
        ),
        'boxes-footer3' => array(
          'module' => 'boxes',
          'delta' => 'footer3',
          'region' => 'footer_third',
          'weight' => '-9',
        ),
        'boxes-footer4' => array(
          'module' => 'boxes',
          'delta' => 'footer4',
          'region' => 'footer_fourth',
          'weight' => '-9',
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
