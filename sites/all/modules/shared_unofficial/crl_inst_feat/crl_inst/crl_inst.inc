<?php


/**
 * Get the rep name for a specific institution based on SF data.
 *
 * @param string $inst_sfid
 *   The Salesforce ID for the institution for get rep data for.
 * @return string
 *   The "real" name (FirstName LastName) for the rep of the passed inst, or
 *   NULL if a name cannot be verified.
 */
function crl_inst_get_sf_rep($inst_sfid) {
  $value = NULL;
  // We depend on the Crowd Liaison group being mapped to a local Drupal liaison
  // role. This local role is how we dentify which users are the reps for any
  // given institution.
  $mapping = variable_get('crowd_groups', array());
  if (isset($mapping[CRL_USER_LIAISON_CROWD_GROUP])) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'user')
        ->fieldCondition('field_institution', 'value', $inst_sfid, '=')
        ->propertyCondition('status', 1, '=')
        ->addTag('rolequery') // @see crl_inst_query_rolequery_alter()
        ->addMetaData('rids', array($mapping[CRL_USER_LIAISON_CROWD_GROUP]));
    $result = $query->execute();
    if (!empty($result['user'])) {
      // There should always only be one liaison user, so we just grab the first
      // record.
      $reps = entity_load('user', array_keys($result['user']));
      $rep = reset($reps);
      $rep_wrapper = entity_metadata_wrapper('user', $rep);
      if (!empty($rep_wrapper->field_first_name->value()) && !empty($rep_wrapper->field_last_name->value())) {
        $value = $rep_wrapper->field_first_name->value() . ' ' . $rep_wrapper->field_last_name->value();
      }
    }
  }
  return $value;
}


/**
 * Get the net affiliations for a specific institution based on SF data.
 *
 * @param string $inst_sfid
 *   The Salesforce ID for the institution for get affiliation data for.
 * @return array
 *   An indexed array of affiliation sub-types (names) for the passed inst.
 */
function crl_inst_get_sf_net_affiliations($inst_sfid) {
  $value = array();
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'sf_net_affiliation')
      ->propertyCondition('inst_sfid', $inst_sfid, '=')
      ->propertyCondition('status', 'Current', '=')
      ->propertyCondition('type', 'GRN', '=');
  $result = $query->execute();
  if (!empty($result['sf_net_affiliation'])) {
    $affiliations = entity_load('sf_net_affiliation', array_keys($result['sf_net_affiliation']));
    foreach ($affiliations as $affiliation) {
      if (!empty($affiliation->sub_type)) {
        $value[] = $affiliation->sub_type;
      }
    }
  }
  sort($value);
  return $value;
}


/**
 * Respond to CRUD operations on entity data that is related to the main SF inst
 * sync.
 *
 * @param object $entity
 *   The Drupal entity undergoing a CRUD operation (create, update, delete).
 * @param string $type
 *   The entity type undergoing a CRUD operation (user or
 *   sf_net_affiliation).
 */
function crl_inst_related_crud($entity, $type) {
  // If a net affiliation or user is being updated we also want to trigger an
  // update to any related Drupal inst nodes. This is because changes to net
  // affiliations or users my affect the calculated values for some institution
  // fields.
  if ($type == 'user' || $type == 'sf_net_affiliation') {
    $inst_ref_prop = 'inst_sfid';
    if ($type == 'user') {
      $inst_ref_prop = 'field_institution';
      // For users we only do anything if the user is (or was) a know liaison.
      // Currently liaison changes are the only way an inst record would be
      // affected. Removing this check would not hurt anything but this
      // prevents a lot of unecessary inst-related queries from being run during
      // other user saves (which are frequent). This depends on the Crowd
      // Liaison group being mapped to a local Drupal liaison role.
      $mapping = variable_get('crowd_groups', array());
      $liaison_user = user_has_role($mapping[CRL_USER_LIAISON_CROWD_GROUP], $entity) || (!empty($entity->original) && user_has_role($mapping[CRL_USER_LIAISON_CROWD_GROUP], $entity->original));
      if (!$liaison_user) {
        return;
      }
    }
    // We check BOTH the updated and original states of the passed entity in
    // case the field with the inst sfid value has been changed/emptied as
    // part of the crud operation.
    $inst_sfids = array(entity_metadata_wrapper($type, $entity)->{$inst_ref_prop}->value());
    if (!empty($entity->original)) {
      $orig_inst_sfid = entity_metadata_wrapper($type, $entity->original)->{$inst_ref_prop}->value();
      if (!in_array($orig_inst_sfid, $inst_sfids)) {
        $inst_sfids[] = $orig_inst_sfid;
      }
    }
    foreach ($inst_sfids as $inst_sfid) {
      $related_inst_mapping = salesforce_mapping_object_load_by_sfid($inst_sfid);
      if (!empty($related_inst_mapping->entity_id)) {
        $inst_node = node_load($related_inst_mapping->entity_id);
        if ($inst_node) {
          $inst_wrapper = entity_metadata_wrapper('node', $inst_node);
          switch ($type) {
            case 'user':
              $rep = crl_inst_get_sf_rep($inst_sfid);
              $inst_wrapper->field_inst_rep->set($rep);
              break;
            case 'sf_net_affiliation':
              $affiliations = crl_inst_get_sf_net_affiliations($inst_sfid);
              $inst_wrapper->field_inst_net_affiliations->set($affiliations);
          }
          $inst_wrapper->save();
        }
      }
    }
  }
}
