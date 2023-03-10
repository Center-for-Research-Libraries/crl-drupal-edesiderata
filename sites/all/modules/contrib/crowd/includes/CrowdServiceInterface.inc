<?php


/**
 * @file
 * Interface for a restful service class for the Atlassian SSO solution crowd.
 */


/**
 * Interface providing a crowd REST service connection.
 */
interface CrowdServiceInterface {

  /**
   * Authorize a user through the crowd server.
   *
   * @param string $username
   *   Crowd username
   * @param string $password
   *   User password
   * @param string $ip
   *   The IP address that should be set as a validation factor upon
   *   authorization. If blank the current IP from ip_address() will be used.
   * @return
   *   An associative array of session data including the Crowd token or NULL
   *   if denied.
   * @throws CrowdException
   *   If a specific response cannot be confirmed via the Crowd connection
   *   a CrowdException error is thrown.
   */
  public function authorize($username, $password, $ip = NULL);

  /**
   * Validates a user's session through the Crowd server.
   *
   * @param string $crowd_token
   *   The active Crowd token for the user.
   * @param string $ip
   *   The IP address that should be passed as a validation factor. If blank the
   *   current IP from ip_address() will be used.
   * @return
   *   Boolean TRUE if the user has a valid Crowd session or FALSE if not.
   * @throws CrowdException
   *   If a specific response cannot be confirmed via the Crowd connection
   *   a CrowdException error is thrown.
   */
  public function validateSession($crowd_token, $ip = NULL);

  /**
   * Log the user out from the Crowd server.
   *
   * @param string $crowd_token
   *   The active Crowd token for a user.
   * @return
   *   Boolen TRUE on success and FALSE on failure.
   */
  public function logout($crowd_token);

  /**
   * Get user data based on an active session token.
   *
   * @param string $crowd_token
   *   The active Crowd token for a user.
   * @return
   *   An array containing the user data points or NULL if no user can be
   *   matched to the passed token.
   * @throws CrowdException
   *   If a specific response cannot be confirmed via the Crowd connection
   *   a CrowdException error is thrown.
   */
  public function getUserFromToken($crowd_token);

  /**
   * Get user data based on a username.
   *
   * @param string $username
   *   The username to fetch details for.
   * @return
   *   An array containing the user data points or NULL if no user can be
   *   matched to the passed name.
   * @throws CrowdException
   *   If a specific response cannot be confirmed via the Crowd connection
   *   a CrowdException error is thrown.
   */
  public function getUserFromName($username);

  /**
   * Add a new user to Crowd
   *
   * @param string $username
   *   The username to add.
   * @param array $user_data
   *   An associative array containing the user data (fields) to add, including:
   *   - 'first-name': First name.
   *   - 'last-name': Last name.
   *   - 'email': email address
   *   - 'password': user password
   *   - 'display-name' (optional): Display name.
   *   - 'active' (optional): Whether to set user as active (true/false)
   * @return boolean
   *   TRUE on successful addition.
   * @throws CrowdException
   *   If a specific response cannot be confirmed via the Crowd connection or
   *   there is an error adding the user a CrowdException error is thrown.
   */
  public function addUser($username, $user_data);

  /**
   * Remove an existing user from Crowd
   *
   * @param string $username
   *   The username to remove.
   * @return boolean
   *   TRUE on successful removal.
   * @throws CrowdException
   *   If a specific response cannot be confirmed via the Crowd connection or
   *   there is an error deleting the user a CrowdException error is thrown.
   */
  public function removeUser($username);

  /**
   * Update an existing user in Crowd.
   *
   * @param string $username
   *   The username to update.
   * @param array $user_data
   *   An associative array of user data (fields) to update, should include:
   *   - 'first-name': First name.
   *   - 'last-name': Last name.
   *   - 'email': email address.
   *   - 'display-name': Display name.
   *   - 'active': Whether to set user as active (true/false).
   * @return boolean
   *   TRUE on successful update.
   * @throws CrowdException
   *   If a specific response cannot be confirmed via the Crowd connection or
   *   there is an error updating the user a CrowdException error is thrown.
   */
  public function updateUser($username, $user_data);

  /**
   * Update an existing user's password in Crowd.
   *
   * @param string $username
   *   The username to update.
   * @param array $password
   *   A new password value to set for the user.
   * @return boolean
   *   TRUE on successful update.
   * @throws CrowdException
   *   If a specific response cannot be confirmed via the Crowd connection or
   *   there is an error updating the password a CrowdException error is thrown.
   */
  public function updateUserPassword($username, $password);

  /**
   * Get the crowd groups for a specific user.
   *
   * @param string $name
   *   The crowd username.
   * @return
   *   An array containing all of the given user's groups or NULL if the user
   *   cannot be found.
   * @throws CrowdException
   *   If a specific response cannot be confirmed via the Crowd connection
   *   a CrowdException error is thrown.
   */
  public function getUserGroups($name);

  /**
   * Add a Crowd user to a group.
   *
   * @param string $username
   *   The username to add to a group.
   * @param string $groupname
   *   The groupname to add the user to.
   * @return boolean
   *   TRUE on successful addition.
   * @throws CrowdException
   *   If a specific response cannot be confirmed via the Crowd connection or
   *   there is an error adding the user to the group a CrowdException error is
   *   thrown.
   */
  public function addUserToGroup($username, $groupname);

  /**
   * Remove a Crowd user from a group.
   *
   * @param string $username
   *   The username to remove from a group.
   * @param string $groupname
   *   The groupname to remove the user from.
   * @return boolean
   *   TRUE on successful removal.
   * @throws CrowdException
   *   If a specific response cannot be confirmed via the Crowd connection or
   *   there is an error removing the user to the group a CrowdException error
   *   is thrown.
   */
  public function removeUserFromGroup($username, $groupname);

  /**
   * Get all active groups from the Crowd server.
   *
   * @return
   *   A serial array of the groupnames.
   * @throws CrowdException
   *   If a specific response cannot be confirmed via the Crowd connection
   *   a CrowdException error is thrown.
   */
  public function getAllGroups();

  /**
   * Get the list of users in a specific Crowd group.
   *
   * @param string $group_name
   *   The group name to retrieve members from.
   * @param string $start_index
   *   An optional offset value for the query.
   * @param string $max_results
   *   An optional limit for the query.
   * @return array $results
   *   A numerically keyed array of group members or NULL if the group does
   *   not exist.
   * @throws CrowdException
   *   If a specific response cannot be confirmed via the Crowd connection
   *   a CrowdException error is thrown.
   */
  public function getGroupMembers($group_name, $start_index = 0, $max_results = 1000);

  /**
   * Perform a generic search in Crowd using the Crowd Query Language.
   *
   * @param string $entity_type
   *   The entity type to search (must be either "user" or "group").
   * @param string $restriction
   *   A search restriction expressed in the Crowd Query Language.
   * @param string $start_index
   *   An optional offset value for the query.
   * @param string $max_results
   *   An optional limit for the query.
   * @return array $results
   *   A numerically keyed array of search results or NULL if no results could
   *   be fetched due to an incompatible request.
   * @throws CrowdException
   *   If a specific response cannot be confirmed via the Crowd connection
   *   a CrowdException error is thrown.
   */
  public function searchCql($entity_type, $restriction, $start_index = 0, $max_results = 1000);

  /**
   * Validate a Crowd REST connection.
   *
   * Most REST methods throw errors when there is a connection issue, but it is
   * occasionally useful to directly check the status of the connection. In
   * addition some methods may recieve a "valid" response that won't result in
   * an exception but can be ambiguous (e.g. a 404 could mean a valid set of
   * empty results, but could also result from a misconfigured endpoint). So
   * this method can also be used as a confirmation in such cases.
   *
   * @return boolean
   *   Returns TRUE if the connection can be validated or FALSE if not.
   */
  public function validateConnection();

}
