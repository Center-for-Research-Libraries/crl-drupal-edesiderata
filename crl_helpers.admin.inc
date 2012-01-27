<?php

function crl_admin_settings() {
  $form = array();

  $form['crl_admin_description'] = array(
    '#type' => 'markup',
    '#value' => t('The options on this form provide ways to customize various case-specific CRL functionality') . "<br/><br/>"
  );
  $form['crl_institution_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Institution List Management'),
    '#description' => t('Options related to the central management of Institution select options'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    );
    $form['crl_institution_options']['crl_institutions'] = array(
      '#type' => 'textarea',
      '#title' => t('Institution List'),
      '#default_value' => variable_get('crl_institutions', NULL),
      '#description' => t('The master list of CRL institutions, in key|value pairs. This list is automatically used by webform components and CCK fields that are configured to be CRL institution select lists. <strong>Note that the order of items in this list represents the order that users will see in their selection pulldowns.<strong>'),
      '#element_validate' => array('_crl_helpers_edit_validate_select'),
    );
  return system_settings_form($form);
}



/**
 * Element validation callback. Ensure keys are not duplicated.
 * This is taken straight from select.ini in the webform module.
 */
function _crl_helpers_edit_validate_select($element, &$form_state) {
  // Check for duplicate key values to prevent unexpected data loss. Require
  // all options to include a safe_key.
  if (!empty($element['#value'])) {
    $lines = explode("\n", trim($element['#value']));
    $existing_keys = array();
    $duplicate_keys = array();
    $missing_keys = array();
    $long_keys = array();
    $group = '';
    foreach ($lines as $line) {
      $matches = array();
      $line = trim($line);
      if (preg_match('/^\<([^>]*)\>$/', $line, $matches)) {
        $group = $matches[1];
        $key = NULL; // No need to store group names.
      }
      elseif (preg_match('/^([^|]*)\|(.*)$/', $line, $matches)) {
        $key = $matches[1];
        if (strlen($key) > 128) {
          $long_keys[] = $key;
        }
      }
      else {
        $missing_keys[] = $line;
      }

      if (isset($key)) {
        if (isset($existing_keys[$group][$key])) {
          $duplicate_keys[$key] = $key;
        }
        else {
          $existing_keys[$group][$key] = $key;
        }
      }
    }

    if (!empty($missing_keys)) {
      form_error($element, t('Every option must have a key specified. Specify each option as "safe_key|Some readable option".'));
    }

    if (!empty($long_keys)) {
      form_error($element, t('Option keys must be less than 128 characters. The following keys exceed this limit:') . theme('item_list', $long_keys));
    }

    if (!empty($duplicate_keys)) {
      form_error($element, t('Options within the select list must be unique. The following keys have been used multiple times:') . theme('item_list', $duplicate_keys));
    }

  }

  return TRUE;
}
