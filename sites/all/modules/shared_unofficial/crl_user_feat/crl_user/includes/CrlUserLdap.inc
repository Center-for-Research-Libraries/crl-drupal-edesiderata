<?php


/**
 * Class to perform some read/write tasks against a CRL LDAP directory.
 */
class crlLdap {

  // General connection properties.
  // @todo: Make some of this configurable and injected.
  protected $ldapServer = '192.168.1.61';
  protected $ldapPort = 10389;
  protected $adminDn = 'uid=admin,ou=system';
  protected $adminPass = 'gd1eX=qWw~yb34';
  // Bound connection resource cache.
  protected $ds;
  protected $bindSuccess = FALSE;
  // Properties specific to user storage/schema in LDAP.
  protected $baseUserDn = 'ou=users,ou=system';
  protected $userRdn = 'uid';
  protected $instRdn = 'o';
  protected $infoRdn = 'description';
  protected $baseGroupDn = 'ou=groups,ou=system';
  protected $groupRdn = 'uniquemember';
  // Cache any user data that we have queried.
  private $users = array();
  // Decalre the general attribute fields that can be synced to an LDAP info
  // field
  protected $infoFields = array('field_profile_inst_other', 'field_phone', 'field_profile_title', 'field_profile_roles', 'field_profile_interests');

  /**
   * Constructor. Initiate a connection resource to LDAP.
   */
  public function __construct() {
    // Allow the server value to be configurable.
    $this->ldapServer = variable_get('crl_user_ldap_server', $this->ldapServer);
    // Connect and bind to LDAP server.
    $this->ds = ldap_connect($this->ldapServer, $this->ldapPort);
    ldap_set_option($this->ds, LDAP_OPT_PROTOCOL_VERSION, 3);
    $this->bindSuccess = ldap_bind($this->ds, $this->adminDn, $this->adminPass);
    if (!$this->bindSuccess) {
      throw new LdapException('Could not connect to the LDAP server.');
    }
  }

  /**
   * Get a list of users that are associated with an institution.
   *
   * @param string $inst_id
   *   Optional. An sfid for an institution to serach for assocaited users. If
   *   left blank the method will return ALL users.
   * @return array
   *   An associative array in the form username => sfid for all users that
   *   meet the criteria set with the $inst_id param.
   */
  public function getInstUsers($inst_id = NULL) {
    $results = array();
    // If we hvae an inst ID our search should filter on that specifically.
    if ($inst_id) {
      $sr = ldap_search($this->ds, $this->baseUserDn, $this->instRdn .'=' . $inst_id);
    }
    // Otherwise, fetch all users.
    else {
      $sr = ldap_search($this->ds, $this->baseUserDn, $this->userRdn .'=*');
    }
    // Loop through the results.
    if ($sr) {
      $entries = ldap_get_entries($this->ds, $sr);
      if ($entries['count']) {
        foreach ($entries as $key => $entry) {
          if (is_numeric($key) && !empty($entry[$this->userRdn][0])) {
            $inst = !empty($entry[$this->instRdn][0]) ? $entry[$this->instRdn][0] : NULL;
            $results[mb_strtolower($entry[$this->userRdn][0])] = $inst; // username => sfid
          }
        }
      }
      return $results;
    }
    // There was a problem getting the list.
    return FALSE;
  }

  /**
   * Get a list of users that are in a specific group.
   *
   * @param string $groupname
   *   A group name to search.
   * @return array
   *   An indexed array of usernames that are in the requested group.
   */
  public function getGroupUsers($groupname) {
    $results = array();
    $sr = ldap_search($this->ds, $this->baseGroupDn, 'cn=' . $groupname);
    if ($sr) {
      $entries = ldap_get_entries($this->ds, $sr);
      if (isset($entries[0][$this->groupRdn])) {
        if (empty($entries[0][$this->groupRdn]) || (isset($entries[0][$this->groupRdn]['count']) && empty($entries[0][$this->groupRdn]['count']))) {
          return $results;
        }
        foreach ($entries[0][$this->groupRdn] as $key => $user_dn) {
          if (is_numeric($key)) {
            $user_dn_exploded = ldap_explode_dn($user_dn, 1);
            if (!empty($user_dn_exploded[0])) {
              $results[] = mb_strtolower($user_dn_exploded[0]);
            }
          }
        }
        return $results;
      }
    }
    // There was a problem fetching the group users or no users.
    return array();
  }


  /**
   * Get a list of all users.
   *
   * @return array
   *   An indexed array of all usernames.
   */
  public function getAllUsers() {
    // The getInstUsers() method can be used without an argument to get all
    // users, but we need to re-organize the return value to make a nice indexed
    // array of username values.
    $all_users_raw = $this->getInstUsers();
    if ($all_users_raw) {
      $all_users = array();
      foreach ($all_users_raw as $name => $value) {
        $all_users[] = $name;
      }
      return $all_users;
    }
    return FALSE;
  }

  /**
   * Update a Drupal user with LDAP-specific attribute data.
   *
   * @param string $username
   *   The ldap username to query for the update.
   * @param mixed $account
   *   A wrapped or unwrapped Drupal user entity to update.
   * @param boolean $save
   *   Whether-or-not to trigger a save operation directly on the passed
   *   $account variable once its field values have been updated. Setting to
   *   FALSE can be useful if the caller is responsible for the save action and
   *   this method is only needed to calculate the changes.
   * @return array
   *   Returns an array of field values that have been updated on $account.
   *   These are in the formal Drupal field array structure that could be passed
   *   to user_save() (as an $edit value) or in other Drupal specific field
   *   logic.
   */
  public function updateUserFromLdap($username, $account, $save = FALSE) {
    // We can work with either a wrapped or unwrapped $account object.
    $wrapper = get_class($account) == 'EntityDrupalWrapper' ? $account : entity_metadata_wrapper('user', $account);
    // Fetch and organize all of our values by field name.
    $info = $this->getInfo($username);
    $inst = $this->getInst($username);
    $all_field_values = $info + array('field_institution' => $inst);
    $set_values = array();
    foreach ($all_field_values as $field_name => $value) {
      $current_value = $wrapper->{$field_name}->value();
      if (isset($wrapper->{$field_name}) && $current_value != $value) {
        try {
          $wrapper->{$field_name}->set($value);
          $set_values[$field_name] = $wrapper->value()->{$field_name};
        }
        catch (EntityMetadataWrapperException $e) {
          // See if the exception is because we are nullifying a required value.
          // If so we do our own more detailed logging.
          $field_info = $wrapper->{$field_name}->info();
          if (empty($value) && !empty($field_info['required'])) {
            watchdog('crl user', 'Cannot nullify required field %field for user %user.', array('%field' => $field_name, '%user' => $wrapper->value()->name), WATCHDOG_WARNING);
          }
          else {
            throw $e; // Re-throw.
          }
        }
      }
    }
    if ($save && $set_values) {
      $wrapper->save();
    }
    return $set_values;
  }

  /**
   * Update LDAP-specific attribute data from a Drupal user account.
   *
   * @param string $username
   *   The ldap username to update.
   * @param object $account
   *   A wrapped or unwrapped Drupal user entity to query for the updates.
   * @return boolean
   *   Returns TRUE on a successful update and FALSE on a failed or incomplete
   *   update.
   */
  public function updateLdapFromUser($username, $account) {
    // We can work with either a wrapped or unwrapped $account object.
    $wrapper = get_class($account) == 'EntityDrupalWrapper' ? $account : entity_metadata_wrapper('user', $account);
    $info_values = array();
    foreach ($this->infoFields as $field_name) {
      $value = $wrapper->{$field_name}->value();
      $info_values[$field_name] = $value;
    }
    $info_success = $this->setInfo($username, $info_values);
    $inst_success = $this->setInst($username, $wrapper->field_institution->value());
    return $info_success && $inst_success;
  }

  /**
   * Get a user's inst value from LDAP. This is a simple attribute-specific
   * wrapper for self::getAttribute();
   *
   * @param string $username
   *   The username to lookup an inst value for.
   * @return string
   *   Returns the user's institution SFID. Returns 'other' if the inst value
   *   is unset or is blank.
   */
  public function getInst($username) {
    $inst_raw = $this->getAttribute($username, $this->instRdn);
    if (!empty($inst_raw['count'])) {
      return empty($inst_raw[0]) ? 'other' : $inst_raw[0];
    }
    return 'other';
  }

  /**
   * Set a user's inst value in LDAP. This is a simple attribute-specific
   * wrapper for self::setAttribute();
   *
   * @param string $username
   *   The username to set an inst value for.
   * @param string $inst
   *   The inst value to set for this user (an SFID).
   * @return boolean
   *   Returns TRUE on a successful update or FALSE on failure.
   */
  public function setInst($username, $inst) {
    return $this->setAttributes($username, array($this->instRdn => $inst));
  }

  /**
   * Get a user's general info attribute values from LDAP.
   *
   * @param string $username
   *   The username to lookup values for.
   * @return array
   *   An associative array of user info values keyed by field name.
   */
  public function getInfo($username) {
    // Our profile fields are always language neutral.
    $values = array();
    $info_ldap = $this->getAttribute($username, $this->infoRdn);
    return !empty($info_ldap['count']) ? (array) json_decode($info_ldap[0]) : array();
  }

  /**
   * Set user's general info attribute values in LDAP. This places the values in
   * a JSON encoded format in a single LDAP attribute.
   *
   * @param string $username
   *   The username to set value for.
   * @param string $values
   *  An associative array of user info values to set keyed by field name.
   * @return boolean
   *   Returns TRUE on a successful update or FALSE on failure.
   */
  public function setInfo($username, $values) {
    $info_encoded = json_encode($values);
    return $this->setAttributes($username, array($this->infoRdn => $info_encoded));
  }

  /**
   * Update the CRL hosts value that tracks which sites the user has
   * logged-into.
   *
   * @param string $username
   *   The username to add a new host value for. If empty the current Drupal
   *   user will be used.
   * @param string $crl_host
   *   The host value to to add. If empty and the $username matches the current
   *   Drupal user, the current site host will be used. The value must end in
   *   .crl.edu.
   * @return boolean
   *   Returns TRUE on a successful update or FALSE on failure or if the host
   *   value already existed for the user (i.e. nothing to do).
   */
  public function updateHosts($username = NULL, $crl_host = NULL) {
    global $user;
    if (is_null($username)) {
      $username = $user->name;
    }
    if (is_null($crl_host) && $username == $user->name) {
      global $base_url;
      $crl_host = parse_url($base_url, PHP_URL_HOST);
    }
    $crl_host = trim(strtolower($crl_host));
    if (!preg_match('/.*\.crl\.edu$/', $crl_host)) {
      return FALSE;
    }
    return $this->addAttributeValues($username, 'destinationindicator', $crl_host) ? TRUE : FALSE;
  }

  /**
   * Get a general attribute value for a user in LDAP.
   *
   * @param string $username
   *   The username to get a value for.
   * @param string $attribute_rdn
   *   The RDN (relative to the LDAP user entry) for the requested attribute or
   *   NULL to request all attributes.
   * @param boolean $reset
   *   Whether-or-not to reset any values already fetched in the local cache.
   * @return array()
   *   Returns the attribute value(s) if found or an empty array on failure.
   */
  public function getAttribute($username, $attribute_rdn = NULL, $reset = FALSE) {
    if ($this->bindSuccess) {
      $attribute_rdn = trim(strtolower($attribute_rdn));
      // See if we can get the user info via the cache. If not, do a new query
      // to LDAP.
      if (empty($this->users[$username]) || $reset) {
        $sr = ldap_search($this->ds, $this->baseUserDn, $this->userRdn . '=' . $username);
        if ($sr) {
          $entries = ldap_get_entries($this->ds, $sr);
          if ($entries['count']) {
            $this->users[$username] = $entries[0];
          }
        }
      }
      if (!empty($this->users[$username])) {
        if ($attribute_rdn) {
          return !empty($this->users[$username][$attribute_rdn]) ? $this->users[$username][$attribute_rdn] : array();
        }
        else {
          return $this->users[$username];
        }
      }
    }
    // There was a problem fetching the inst value or it is not defined.
    return array();
  }

  /**
   * Set specific attributes for a user in LDAP overwriting any existing values.
   *
   * @param string $username
   *   The username to set a value for.
   * @param array $edits
   *   An array of edits to save in the form $attribute_rdn => $value. The
   *   $attribute_rdn is the RDN (relative to the LDAP user entry) for a specifc
   *   attribute. The values passed will OVERWRITE ALL existing values for the
   *   attribute.
   * @return boolean
   *   Returns TRUE on success or FALSE if the attribute could not be set.
   */
  public function setAttributes($username, $edits = array()) {
    $current_values = $this->getAttribute($username);
    // Break the edits into replacement and addition actions based on the
    // current data.
    $to_add = $to_replace = array();
    foreach ($edits as $attribute_rdn => $value) {
      if (!empty($current_values[$attribute_rdn])) {
        $to_replace[$attribute_rdn] = $value;
      }
      else {
        $to_add[$attribute_rdn] = $value;
      }
    }
    // Write the changes.
    if ($to_replace && ldap_mod_replace($this->ds, $this->userRdn . '=' . $username . ',' . $this->baseUserDn, $to_replace)) {
      $to_replace = array();
      // Clear local cache.
      $this->clearUserCache($username);
    }
    if ($to_add && ldap_mod_add($this->ds, $this->userRdn . '=' . $username . ',' . $this->baseUserDn, $to_add)) {
      $to_add = array();
      // Clear local cache.
      $this->clearUserCache($username);
    }
    if (count($to_replace) + count($to_add) === 0) {
      return TRUE;
    }
    // There was a problem updating the value.
    return FALSE;
  }


  /**
   * Add an attribute value for a user in LDAP. This will retain any existing
   * values for the same attribute.
   *
   * @param string $username
   *   The username to get a value for.
   * @param string $attribute_rdn
   *   The RDN (relative to the LDAP user entry) for the attribute to add values
   *   to.
   * @param array $values
   *   The values to add to the attribute.
   * @return boolean
   *   Returns boolean TRUE on success and FALSE if the value could not be
   *   added.
   */
  public function addAttributeValues($username, $attribute_rdn, $values) {
    $values = (array) $values;
    $current_values = $this->getAttribute($username, $attribute_rdn);
    // Check to see if any of our passed values are already on the user
    // record. Tryng to add them again can cause errors.
    foreach ($values as $key => $value) {
      $current_key = array_search($value, $current_values);
      if ($current_key !== FALSE && is_numeric($current_key)) {
        unset($values[$key]);
      }
    }
    // Re-key the values as ldap_mod_add() requires sequential keys starting
    // from 0.
    $values = array_values($values);
    // Write the updates.
    if ($values && ldap_mod_add($this->ds, $this->userRdn . '=' . $username . ',' . $this->baseUserDn, array($attribute_rdn => $values))) {
      // Clear local cache.
      $this->clearUserCache($username);
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Clear locally cached user info. This is needed whenever changes are written
   * to LDAP.
   *
   * @param string $username
   *   The username to clear from the cache or leave empty to clear the whole
   *   cache.
   */
  protected function clearUserCache($username = NULL) {
    if (is_null($username)) {
      $this->users = array();
    }
    else {
      unset($this->users[$username]);
    }
  }

}

/**
 * Provides a specific LDAP exception class that can be used for managing
 * errors encountered while dealing with the LDAP service layer.
 */
class LdapException extends Exception {

  /**
   * Small utility for error logging.
   */
  public function logResponse() {
    watchdog_exception('crl user', $this);
  }

}
