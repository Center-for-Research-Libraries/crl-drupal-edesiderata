<?php

/**
 * Implements hook_drush_command().
 */
function crl_helpers_drush_command() {
  $items['fieldcopy'] = array(
    'description' => 'Copy value from field A to B and save entity.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array('field'),
    'arguments' => array(
      'source_field' => 'Source field',
      'target_field' => 'Target field',
      'bundle' => 'Bundle',
      'entity_type' => 'Entity type',
      'entity_id' => 'Entity ID',
    ),
    'examples' => array(
      'drush fieldcopy field_a field_b bundle_name(optional) entity(optional) entity_id(optional)' => 'Copy data from field_something_body to field_body.',
    ),
  );
  return $items;
}

function drush_crl_helpers_fieldcopy($source_field = NULL, $target_field = NULL, $bundle = NULL, $entity_type = 'node', $entity_id = NULL) {
	drush_log(dt('Attempting to copy data from !source_field to !target_field in !entity_type type !bundle...', array('!source_field' => $source_field, '!target_field' => $target_field,'!entity_type' => $entity_type, '!bundle' => $bundle)),'notice');
  if (is_null($source_field) || is_null($target_field)) {
    return drush_set_error('NO_INPUT_FIELDS', dt('Source or target field is missing as argument.'));
  }
  $source_field = field_info_field($source_field);
  if (is_null($source_field)) {
    return drush_set_error('NO_SOURCE_FIELD', dt('Source field doesnt exist.'));
  }
  $target_field = field_info_field($target_field);
  if (is_null($target_field)) {
    return drush_set_error('NO_TARGET_FIELD', dt('Target field doesnt exist.'));
  }

  // Bundle was given, validate that bundle exists in field.
  if (!is_null($bundle)) {
    if(isset($source_field['bundles'][$entity_type]) && in_array($bundle, $source_field['bundles'][$entity_type])) {
      drush_log(dt('Source field !source_field found in bundle !bundle.', array('!source_field' => $source_field['field_name'], '!bundle' => $bundle)), 'ok');
    }
    else {
      return drush_set_error('SOURCE_FIELD_NOT_IN_BUNDLE', dt('Source field doesnt exist in given bundle.'));
    }
    if(in_array($bundle, $target_field['bundles'][$entity_type])) {
      drush_log(dt('Target field !target_field found in bundle !bundle.', array('!target_field' => $target_field['field_name'], '!bundle' => $bundle)), 'ok');
    }
    else {
      return drush_set_error('TARGET_FIELD_NOT_IN_BUNDLE', dt('Target field doesnt exist in given bundle.'));
    }
  }
  // Operate on a single entity id.
  if (!is_null($entity_id)) {
    if(!is_numeric($entity_id)) {
      return drush_set_error('ENTITY_ID_NOT_NUMERIC', dt('Entity ID needs to be numeric. ID given !id', array('!id' => $entity_id)));
    }
    $entity_load = entity_load_single($entity_type, $entity_id);
    if (!$entity_load) {
      return drush_set_error('ENTITY_ID_NOT_EXIST', dt('Entity ID !id does not exist', array('!id' => $entity_id)));
    }
    else {
      if (!is_null($bundle) && $entity_load->type != $bundle) {
        return drush_set_error('ENTITY_ID_WRONG_BUNDLE', dt('Entity ID !id is not of bundle type !bundle', array('!id' => $entity_id, '!bundle' => $bundle)));
      }
    }
    _crl_helpers_field_copy($source_field, $target_field, $entity_id, $entity_type);
  }
  // Entity ID was not given. Iterate over all entities given bundle.
  else if(!is_null($bundle)){
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', $entity_type)
      ->entityCondition('bundle', $bundle)
      ->addMetaData('account', user_load(1));
    $result = $query->execute();

    if (isset($result[$entity_type])) {
      drush_log(dt('Found !count entities.', array('!count' => count($result[$entity_type]))), 'ok');
      $choice = drush_choice(array(1 => 'Yes'), 'Are you sure?');
      if (!$choice) {
        return drush_set_error('USER_ABORT', dt('User aborted'));
      }

      foreach($result[$entity_type] as $bundle_entity_id => $bundle_entity) {
        _crl_helpers_field_copy($source_field, $target_field, $bundle_entity_id, $entity_type);
      }
    }
    else {
      drush_log(dt('No entities were found when querying all entities of bundle !bundle', array('!bundle' => $bundle)), 'warning');
    }
  }
  else {
    $bundles = array_values($source_field['bundles'][$entity_type]);

    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', $entity_type)
      ->entityCondition('bundle', $bundles, 'IN')
      ->addMetaData('account', user_load(1));
    $result = $query->execute();

    if (isset($result[$entity_type])) {
      drush_log(dt('Found !count entities.', array('!count' => count($result[$entity_type]))), 'ok');
      $choice = drush_choice(array(1 => 'Yes'), 'Are you sure?');
      if (!$choice) {
        return drush_set_error('USER_ABORT', dt('User aborted'));
      }

      foreach($result[$entity_type] as $bundle_entity_id => $bundle_entity) {
        _crl_helpers_field_copy($source_field, $target_field, $bundle_entity_id, $entity_type);
      }
    }
  }

}

function _crl_helpers_field_copy($source_field, $target_field, $entity_id, $entity_type) {
  $entity = entity_load_single($entity_type, $entity_id);
  // Try to preserve the original updated timestamp.
  // @see crl_helpers_node_presave()
  if (isset($entity->changed)) {
    $entity->manual_changed_timestamp = $entity->changed;
  }
  $entity_wrapper = entity_metadata_wrapper($entity_type, $entity);
  if(isset($entity_wrapper->{$source_field['field_name']})) {
    $value = $entity_wrapper->{$source_field['field_name']};
    // We dont need to populate empty values.
    if (!empty($value)) {
      // Some fields get will be loaded as full entities when accessed through value().
      // In this case we use raw() to get just the nid for example.
      if(is_object($value)) {
        $value = $value->raw();
      }
      // Only save the entity if the data in the source and target field differ.
      if ($entity_wrapper->{$source_field['field_name']}->value() != $entity_wrapper->{$target_field['field_name']}->value()) {
      	$entity_wrapper->{$target_field['field_name']}->set($value);
        $entity_wrapper->save();
        drush_log(dt('Entity ID !id saved', array('!id' => $entity_id)), 'ok');
      }
      else {
        drush_log(dt('Entity ID !id not saved. No difference between source and target field.', array('!id' => $entity_id)), 'ok');
      }
    }
  }
  else {
    drush_log(dt('Could not find source field in Entity ID !id with title "!title saved"', array('!id' => $entity_id, '!title' => $entity_wrapper->title->value())), 'ok');
  }
}
