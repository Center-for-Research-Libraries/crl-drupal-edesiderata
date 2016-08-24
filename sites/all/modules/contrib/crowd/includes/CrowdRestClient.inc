<?php


/**
 * @file
 * This is a restful service class for the Atlassian SSO solution crowd.
 *
 * @author
 * Ryan Jacobs, John P. Warren, Andrew Nagy
 */


/**
 * Provides a crowd REST service connection.
 */
class CrowdRestClient implements CrowdServiceInterface {

  /**
   * General connection properties that apply to all methods.
   */
  protected $request_url;
  protected $request_headers;
  protected $max_redirects;
  protected $timeout;

  /**
   * Constructor.
   *
   * Defines the base connection URL and other common properties.
   */
  function __construct() {
    // Create the full url for remote requests.
    $server_address = variable_get('crowd_server', '');
    // If the address does not specify the protocol, default to https.
    $url_prefix = strpos($server_address, 'http://') !== FALSE ? 'http://' : 'https://';
    $url_suffix = str_ireplace($url_prefix, '', $server_address);
    $this->request_url = $url_prefix . $url_suffix . ':' . variable_get('crowd_port', '443') . '/' . trim(variable_get('crowd_uri', ''), '/');
    $this->request_headers = array(
      'Accept' => 'application/json',
      'Content-Type' => 'application/xml',
      // Add the authentication details directly into the headers. We could add
      // these details to the request_url and have drupal_http_request() move
      // them to the header for us, but that could introduce URL
      // encoding/decoding problems.
      'Authorization' => 'Basic ' . base64_encode(variable_get('crowd_application', '') . ':' . variable_get('crowd_application_password', '')),
    );
    // Set default values for connection configuration.
    $this->max_redirects = 3;
    $this->timeout = 120.0;
  }

  /**
   * {@inheritdoc}
   */
  public function authorize($username, $password, $ip = NULL) {
    // Make sure what have an IP.
    if (empty($ip)) {
      $ip = ip_address();
    }
    $XML = new SimpleXMLElement("<?xml version='1.0' encoding='utf-8'?><authentication-context></authentication-context>");
    $XML->addChild('username', htmlspecialchars($username, ENT_NOQUOTES, 'UTF-8'));
    $XML->addChild('password', htmlspecialchars($password, ENT_NOQUOTES, 'UTF-8'));
    $vfs = $XML->addChild('validation-factors');
    $vf = $vfs->addChild('validation-factor');
    $vf->addChild('name', 'remote_address');
    $vf->addChild('value', $ip);
    $response = $this->apiHttpRequest('session', array(), $XML->asXML(), 'POST');
    // Check for success.
    if ($response->code == '201') {
      $data = $this->decodeResponseData($response->data);
      // We must have a token in the data.
      if (empty($data['token'])) {
        throw new CrowdException('REST authorize method error. Successfully authenticated to Crowd but no SSO token could be found.', NULL, NULL, $response);
      }
      return $data;
    }
    // Check for confirmed failure.
    if ($response->code == '400' || $response->code == '403') {
      return NULL;
    }
    // Failure to get a confirmed result is an exception.
    throw new CrowdException('REST authorize method error.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
   */
  public function validateSession($user_token, $ip = NULL) {
    // Make sure what have an IP.
    if (empty($ip)) {
      $ip = ip_address();
    }
    $XML = new SimpleXMLElement("<?xml version='1.0' encoding='utf-8'?><validation-factors></validation-factors>");
    $vf = $XML->addChild('validation-factor');
    $vf->addChild('name', 'remote_address');
    $vf->addChild('value', $ip);
    $response = $this->apiHttpRequest('session/' . rawurlencode($user_token), array(), $XML->asXML(), 'POST');
    if ($response->code == '200') {
      // Make sure we have a specific username returned.
      $data = $this->decodeResponseData($response->data);
      if (empty($data['user']['name'])) {
        throw new CrowdException('REST validate_session method error. Successfully validated user session but no matching username could be found.', NULL, NULL, $response);
      }
      return TRUE;
    }
    // Check for confirmed failure.
    if ($response->code == '400' || $response->code == '404') {
      return FALSE;
    }
    // Failure to get a confirmed result is an exception.
    throw new CrowdException('REST validateSession method error.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
   */
  public function logout($user_token) {
    $response = $this->apiHttpRequest('session/' . rawurlencode($user_token), array(), NULL, 'DELETE');
    if ($response->code == '204') {
      return TRUE;
    }
    // Crowd does not appear to offer specific error codes to differentiate
    // non-success cases. If no confirmed success, just return FALSE.
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function getUserFromToken($user_token) {
    $response = $this->apiHttpRequest('session/' . rawurlencode($user_token), array('query' => array('expand' => 'user')));
    // Check for success.
    if ($response->code == '200') {
      $crowd_user = $this->decodeResponseData($response->data, 'user');
      // For legacy support need a 'username' key in addition to 'name'.
      $crowd_user['username'] = $crowd_user['name'];
      return $crowd_user;
    }
    // Check for a confirmed case where the token could not be matched to a
    // user.
    if ($response->code == '404') {
      return NULL;
    }
    // Failure to get a confirmed result is an exception.
    throw new CrowdException('REST getUserFromToken method error.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
   */
  public function getUserFromName($username) {
    $response = $this->apiHttpRequest('user', array('query' => array('username' => $username, 'expand' => 'attributes')));
    // Check for success.
    if ($response->code == '200') {
      $crowd_user = $this->decodeResponseData($response->data);
      // For legacy support need a 'username' key in addition to 'name'.
      $crowd_user['username'] = $crowd_user['name'];
      return $crowd_user;
    }
    // Check for a confirmed case where the username could not be matched to a
    // user.
    if ($response->code == '404') {
      return NULL;
    }
    // Failure to get a confirmed result is an exception.
    throw new CrowdException('REST getUserFromName method error.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
   */
  public function addUser($username, $user_data) {
    $user_data = $this->preprocessUserData($user_data);
    $XML = new SimpleXMLElement("<?xml version='1.0' encoding='utf-8'?><user></user>");
    $XML->addAttribute('name', htmlspecialchars($username, ENT_NOQUOTES, 'UTF-8'));
    $XML->addAttribute('expand', 'attributes');
    $XML->addChild('first-name', htmlspecialchars($user_data['first-name'], ENT_NOQUOTES, 'UTF-8'));
    $XML->addChild('last-name', htmlspecialchars($user_data['last-name'], ENT_NOQUOTES, 'UTF-8'));
    $XML->addChild('display-name', htmlspecialchars($user_data['display-name'], ENT_NOQUOTES, 'UTF-8'));
    $XML->addChild('email', htmlspecialchars($user_data['email'], ENT_NOQUOTES, 'UTF-8'));
    $XML->addChild('active', $user_data['active']);
    $XML->addChild('attributes', '');
    $pass = $XML->addChild('password');
    $pass->addChild('value', htmlspecialchars($user_data['password'], ENT_NOQUOTES, 'UTF-8'));
    $response = $this->apiHttpRequest('user', array(), $XML->asXML(), 'POST');
    // Check for success 201. All other error codes are considered exceptions.
    if ($response->code == '201') {
      return TRUE;
    }
    throw new CrowdException('REST addUser method error.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
   */
  public function removeUser($username) {
    $response = $this->apiHttpRequest('user', array('query' => array('username' => $username)), NULL, 'DELETE');
    // Check for success 204. All other error codes are considered exceptions.
    if ($response->code == '204') {
      return TRUE;
    }
    throw new CrowdException('REST removeUser method error.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
   */
  public function updateUser($username, $user_data) {
    $user_data = $this->preprocessUserData($user_data);
    $XML = new SimpleXMLElement("<?xml version='1.0' encoding='utf-8'?><user></user>");
    $XML->addAttribute('name', htmlspecialchars($username, ENT_NOQUOTES, 'UTF-8'));
    $XML->addAttribute('expand', 'attributes');
    $XML->addChild('first-name', htmlspecialchars($user_data['first-name'], ENT_NOQUOTES, 'UTF-8'));
    $XML->addChild('last-name', htmlspecialchars($user_data['last-name'], ENT_NOQUOTES, 'UTF-8'));
    $XML->addChild('display-name', htmlspecialchars($user_data['display-name'], ENT_NOQUOTES, 'UTF-8'));
    $XML->addChild('email', htmlspecialchars($user_data['email'], ENT_NOQUOTES, 'UTF-8'));
    $XML->addChild('active', $user_data['active']);
    $response = $this->apiHttpRequest('user', array('query' => array('username' => $username)), $XML->asXML(), 'PUT');
    // Check for success 204. All other error codes are considered exceptions.
    if ($response->code == '204') {
      return TRUE;
    }
    throw new CrowdException('REST updateUser method error.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
   */
  public function updateUserPassword($username, $password) {
    $XML = new SimpleXMLElement("<?xml version='1.0' encoding='utf-8'?><password></password>");
    $XML->addChild('value', htmlspecialchars($password, ENT_NOQUOTES, 'UTF-8'));
    $response = $this->apiHttpRequest('user/password', array('query' => array('username' => $username)), $XML->asXML(), 'PUT');
    // Check for success 204. All other error codes are considered exceptions.
    if ($response->code == '204') {
      return TRUE;
    }
    throw new CrowdException('REST updatePassword method error.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
   */
  public function getUserGroups($name) {
    $response = $this->apiHttpRequest('user/group/nested', array('query' => array('username' => $name)));
    // Check for success.
    if ($response->code == '200') {
      $results = $this->decodeResponseData($response->data, 'groups');
      // We just want the "name" part of each result.
      $processed_results = array();
      foreach ($results as $key => $value) {
        $processed_results[] = $value['name'];
      }
      return $processed_results;
    }
    // Check for a case where the user is not found.
    if ($response->code == '404') {
      return NULL;
    }
    // Failure to get a confirmed result is an exception.
    throw new CrowdException('REST getUserGroups method error. Cound not fetch group data from Crowd.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
   */
  public function addUserToGroup($username, $groupname) {
    $XML = new SimpleXMLElement("<?xml version='1.0' encoding='utf-8'?><group></group>");
    $XML->addAttribute('name', htmlspecialchars($groupname, ENT_NOQUOTES, 'UTF-8'));
    $response = $this->apiHttpRequest('user/group/direct', array('query' => array('username' => $username)), $XML->asXML(), 'POST');
    // Check for success 201. Note that code 409 signifies that the user is
    // already a member of the group, which is also a successful response. All
    // other error codes are considered exceptions.
    if ($response->code =='201' || $response->code == '409') {
      return TRUE;
    }
    throw new CrowdException('REST addUserToGroup method error.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
   */
  public function removeUserFromGroup($username, $groupname) {
    $response = $this->apiHttpRequest('user/group/direct', array('query' => array('username' => $username, 'groupname' => $groupname)), NULL, 'DELETE');
    // Check for success 204. All other error codes are considered exceptions.
    if ($response->code == '204') {
      return TRUE;
    }
    throw new CrowdException('REST removeUserFromGroup method error.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
   */
  public function getAllGroups() {
    $XML = new SimpleXMLElement("<?xml version='1.0' encoding='utf-8'?><property-search-restriction></property-search-restriction>");
    $prop = $XML->addChild('property');
    $prop->addChild('name', 'active');
    $prop->addChild('type', 'BOOLEAN');
    $XML->addChild('match-mode', 'EXACTLY_MATCHES');
    $XML->addChild('value', 'true');
    $response = $this->apiHttpRequest('search', array('query' => array('entity-type' => 'group')), $XML->asXML(), 'POST');
    // Check for success.
    if ($response->code == '200') {
      $results = $this->decodeResponseData($response->data, 'groups');
      // We just want the "name" part of each result.
      $processed_results = array();
      foreach ($results as $key => $value) {
        $processed_results[] = $value['name'];
      }
      return $processed_results;
    }
    // Confirmed bad request.
    if ($response->code == '400') {
      return NULL;
    }
    // Failure case.
    throw new CrowdException('REST getAllGroups method error. Cound not fetch group data from Crowd.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
   */
  public function getGroupMembers($group_name, $start_index = 0, $max_results = 1000) {
    $response = $this->apiHttpRequest('group/user/direct', array('query' => array('groupname' => $group_name, 'start-index' => $start_index, 'max-results' => $max_results)));
    // Check for success.
    if ($response->code == '200') {
      $results = $this->decodeResponseData($response->data, 'users');
      // We just want the "name" part of each result.
      $processed_results = array();
      foreach ($results as $key => $value) {
        $processed_results[] = $value['name'];
      }
      return $processed_results;
    }
    // Check for case where group is not found.
    if ($response->code == '404') {
      return NULL;
    }
    // Failure to get a confirmed result is an exception.
    throw new CrowdException('REST getGroupMembers method error.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
   */
  public function searchCql($entity_type, $restriction, $start_index = 0, $max_results = 1000) {
    $response = $this->apiHttpRequest('search', array('query' => array('entity-type' => $entity_type, 'restriction' => $restriction, 'start-index' => $start_index, 'max-results' => $max_results)));
    // Check for success.
    if ($response->code == '200') {
      $results = $this->decodeResponseData($response->data, $entity_type . 's');
      // We just want the "name" part of each result.
      $processed_results = array();
      foreach ($results as $key => $value) {
        $processed_results[] = $value['name'];
      }
      return $processed_results;
    }
    // Check for confirmed error case.
    if ($response->code == '400') {
      return NULL;
    }
    // Failure to get a confirmed result is an exception.
    throw new CrowdException('REST searchSql method error. Cound not fetch data from Crowd.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
   */
  public function validateConnection() {
    // The Crowd API does not offer a direct way to validate the connection but
    // we can simply do a generic group list request and validate a successful
    // response. Note that a group search should never legitimately result in a
    // response code that can be ambiguous (e.g. a 404 that could mean NULL but
    // could also result from a misconfigured endpoint).
    $XML = new SimpleXMLElement("<?xml version='1.0' encoding='utf-8'?><property-search-restriction></property-search-restriction>");
    $prop = $XML->addChild('property');
    $prop->addChild('name', 'active');
    $prop->addChild('type', 'BOOLEAN');
    $XML->addChild('match-mode', 'EXACTLY_MATCHES');
    $XML->addChild('value', 'true');
    try {
      $response = $this->apiHttpRequest('search', array('query' => array('entity-type' => 'group')), $XML->asXML(), 'POST');
    }
    catch (Exception $e) {
      return FALSE;
    }
    // Check very explicitly for success.
    if ($response->code == '200') {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Make a call to the Crowd REST API.
   *
   * This is largely a wrapper for drupal_http_request() with some generic error
   * handling. For automated testing this method could be overriden with some
   * kind of logic to mock Crowd responses.
   *
   * @param string $path
   *   Path to resource EXCLUDING the base API path defined in the Crowd
   *   confgiuration.
   * @param array $options
   *   An associative array of additional options in the format expected by
   *   url().
   * @param array $data
   *   Data to pass in the body of the request.
   * @param string $method
   *   Method to initiate the call, such as GET or POST. Defaults to GET.
   * @return object
   *   The api response as delivered by drupal_http_request().
   * @throws CrowdException
   *   If the response code is not an expected http code of 2xx or 4xx we
   *   thrown a CrowdException error.
   */
  protected function apiHttpRequest($path, $options = array(), $data = NULL, $method = 'GET') {
    // Build the request, including path and headers.
    $options += array('external' => TRUE);
    $url = url($this->request_url . '/' . $path, $options);
    $options = array(
      'method' => $method,
      'data' => $data,
      'headers' => $this->request_headers,
      'max_redirects' => $this->max_redirects,
      'timeout' => $this->timeout,
    );
    // Send the request and check for generic errors.
    $response = drupal_http_request($url, $options);
    // Both 2xx and 4xx response codes are used by Crowd to communicate the
    // results of specific requests, and can generally be interpreted as a
    // "correct" responses. One generic exception to this is a 401 which
    // signifies an application-level authentication error
    if (preg_match('/^(2|4)[0-9]{2}$/', $response->code) && $response->code != 401) {
      return $response;
    }
    // If we don't have a workable response code we won't be able to deliver
    // any confirmed results (regardless of the request method used).
    throw new CrowdException('Could not connect to the Crowd server.', NULL, NULL, $response);
  }

  /**
   * Helper to decode Crowd data returned in a service response.
   *
   * @param string $data
   *   A string containing the response body that was received from a service
   *   request.
   * @param string $group
   *   The part of the decoded data to return (a keyed element from the
   *   response).
   * @return array
   *   An associative array with the decoded data.
   */
  protected function decodeResponseData($data, $group = NULL) {
    // We are expecting json in the response.
    $decoded = drupal_json_decode($data);
    if ($group) {
      return isset($decoded[$group]) ? $decoded[$group] : NULL;
    }
    return $decoded;
  }

  /**
   * Helper to preprocess user data that will be written to Crowd on an insert
   * or update.
   *
   * @param arrat $user_data
   *   An associative array for user data to write.
   * @return array
   *   An associative of processed user data.
   */
  protected function preprocessUserData($user_data) {
    // Calculate display name if it's not specified.
    if (empty($user_data['display-name'])) {
      $user_data['display-name'] = $user_data['first-name'] . ' ' . $user_data['last-name'];
    }
    // Calculate active status (which may be specified in various ways but needs
    // to be passed to Crowd as a string).
    $user_data['active'] = isset($user_data['active']) && (!$user_data['active'] || $user_data['active'] === 'false') ? 'false' : 'true';
    return $user_data;
  }

}


/**
 * Provides a specific Crowd exception class that can be used for managing
 * errors encountered while dealing with the Crowd service layer.
 */
class CrowdException extends Exception {

  // Store the full response object for logging purposes.
  protected $response;

  /**
   * Constructor.
   */
  public function __construct($message, $code = 0, $previous = NULL, $response = NULL) {
    parent::__construct($message, $code, $previous);
    $this->response = $response;
    // The exception's error code should be tied to the specific http response
    // code when possible.
    $this->code = empty($this->response->code) ? $this->getCode() : $this->response->code;
  }

  /**
   * Small utility for error logging that will incorporate data from the
   * request response.
   */
  public function logResponse() {
    $code = empty($this->response->code) ? $this->getCode() : $this->response->code;
    $error = empty($this->response->error) ? "Unknown error" : $this->response->error;
    watchdog_exception('crowd', $this, 'Crowd Exception: !message | Response message: %error | Response code: %code  | Thrown from: %function (line %line of %file).', array('%error' => $error, '%code' => $code));
  }

}


/**
 * Legacy support for old class and method naming conventions.
 *
 * @Deprecated
 */
class crowd_rest_client extends CrowdRestClient {

  protected $request_method;
  protected $request_data;

  public function validate_session($user_token, $ip = NULL) {
    return $this->validateSession($user_token, $ip);
  }

  public function crowd_is_logged_in($user_token) {
    return $this->validateSession($user_token);
  }

  public function user_get($user_token) {
    return $this->getUserFromToken($user_token);
  }

  public function list_groups() {
    return $this->getAllGroups();
  }

  public function list_user_groups($name) {
    return $this->getUserGroups($name);
  }

}
