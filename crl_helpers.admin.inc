<?php

function crl_admin_settings() {
  $form = array();

  $form['crl_admin_description'] = array(
    '#type' => 'markup',
    '#value' => t('The options on this form provide ways to customize various case-specific CRL functionality') . "<br/><br/>"   
  );
  $form['crl_general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => -1,
    );
    $form['crl_general']['crl_expand_menublock'] = array(
      '#type' => 'checkbox',
      '#title' => t('Expand Menublocks an Extra Level'),
      '#description' => t('Expand all menu blocks <em>2 levels past the current</em> by default instead of 1 (when not already set to be fully expanded).'),
      '#default_value' => variable_get('crl_expand_menublock', FALSE),
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

