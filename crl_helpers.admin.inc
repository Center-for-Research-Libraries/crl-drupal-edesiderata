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


function crl_helpers_pp_sso_settings() {
  $form['crl_pp_sso'] = array(
    '#type' => 'fieldset',
    '#title' => t('Purchase Proposal SSO'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => -1,
  );
    $form['crl_pp_sso']['crl_pp_sso_remote_url'] = array(
      '#title' => t('Purchase Proposal (PP) Remote URL'),
      '#type' => 'textfield',
      '#default_value' => variable_get('crl_pp_sso_remote_url', 'http://www-apps.crl.edu/content/pp/ballot2.asp'),
      '#description' => t('The PP URL that Drupal should redirect users to upon successful credential check (with remote login query paramaters).'),
    );
    $form['crl_pp_sso']['crl_pp_sso_user_map'] = array(
      '#title' => t('User to Purchase Proposal (PP) Institution Mappings'),
      '#type' => 'textarea',
      '#default_value' => variable_get('crl_pp_sso_user_map', 'key|value'),
      '#description' => t('key|value pairs where the key matches the PP insitiution ID and the value matches the local Drupal user ID that is the PP user for the keyed institution.'),
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

function crl_helpers_pp_sso_validate() {
  $pp_salt = "Hkui8lhL";
  $user_maps = variable_get('crl_pp_sso_user_map', 'key|value');
  $user_maps_array = array();
  $lines = explode("\n", $user_maps);
  foreach ($lines as $line) {
    $line = trim($line);
    list($key, $value) = explode("|", $line);
    $user_maps_array += array($key => $value);
  }
  $header = array(t('PP Inst ID'), t('Drupal User ID'), t("Drupal Status"), t('Drupal eMail'), t('Drupal Username'), t('Test PP Login Link'));
  $rows = array();
  foreach ($user_maps_array as $key => $value) {
    $d_error = FALSE;
    if (!is_numeric($key) || !is_numeric($value)) {
      $d_error = t("Non-numeric value for ID");
    }
    else {
      $user = user_load($value);
      if ($user === FALSE) {
        $d_error = t("Not a valid Drupal user");
      }
    }
    if ($d_error) {
      $status = '<strong style="color: red;">' . $d_error . '</strong>';
      $mail = $name = $link = "";
    }
    else {
      $status = '<strong style="color: green;">OK</strong>';
      $mail = $user->mail;
      $name = $user->name;
      $ip = ip_address();
      // @TODO: Remove... for testing environemnts set a working ip
      if ($ip == '::1' || $ip == '127.0.0.1') {
        $ip = '192.168.1.92';
      }
      $token = md5($ip . $key . $pp_salt);
      $link = variable_get('crl_pp_sso_remote_url', 'http://www-apps.crl.edu/content/pp/ballot2.asp') . '?inst=' . $key . '&token=' . $token;
      $link = l($link, $link, array('attributes' => array('target' => '_blank')));
    }
    $rows[] = array(
      'data' => array(
        $key,
        $value,
        $status,
        $mail,
        $name,
        $link,
      ),
    );  
  }
  $output = theme('table', $header, $rows);
  $output .= "<br/><br/>";
  return $output;
}

