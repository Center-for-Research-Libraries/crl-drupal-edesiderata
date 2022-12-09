<?php


/**
 * Custom REST client that adds attribute handling.
 */
class CrlUserCrowdRestClient extends CrowdRestClient {
  
  /**
   * Get attributes from Crowd
   */
  public function getAttributesFromName($username) {
    $response = $this->apiHttpRequest('user/attribute', array('query' => array('username' => $username)));
    // Check for success.
    if ($response->code == '200') {
      $raw_attributes = $this->decodeResponseData($response->data);
      // Simplify so that we have key => value pairs.
      $attributes = array();
      foreach ($raw_attributes['attributes'] as $raw_attribute) {
        $attributes[$raw_attribute['name']] = $raw_attribute['values'][0];
      }
      return $attributes;
    }
    // Check for a confirmed case where the username could not be matched to a
    // user.
    if ($response->code == '404') {
      return NULL;
    }
    // Failure to get a confirmed result is an exception.
    throw new CrowdException('REST getAttributesFromName method error.', NULL, NULL, $response);
  }
  
  /**
   * Set attributes in Crowd
   */
  public function updateUserAttributes($username, $attribute_data) {
    $XML = new SimpleXMLElement("<?xml version='1.0' encoding='utf-8'?><attributes></attributes>");
    foreach ($attribute_data as $key => $value) {
      $a = $XML->addChild('attribute');
      $a->addAttribute('name', htmlspecialchars($key, ENT_NOQUOTES, 'UTF-8'));
      $v = $a->addChild('values');
      $v->addChild('value', htmlspecialchars($value, ENT_NOQUOTES, 'UTF-8'));
    }
    $check = $XML->asXML();
    $response = $this->apiHttpRequest('user/attribute', array('query' => array('username' => $username)), $XML->asXML(), 'POST');
    // Check for success 204. All other error codes are considered exceptions.
    if ($response->code == '204') {
      return TRUE;
    }
    throw new CrowdException('REST updateUserAttributes method error.', NULL, NULL, $response);
  }

  /**
   * {@inheritdoc}
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
    // CRL CUSTOMIZATION
    // We need to connect to Crowd via Pantheon tunnels and direct IP
    // connections which will break certficiate validation. Allow cert
    // verifications to be ignoted. WITH THESE SETTINGS WE SHOULD ONLY USE
    // DIRECT IP ADDRESSING FOR CROWD.
    // @see https://gist.github.com/pounard/6a40174d93925687b00a30cf1ab253fd
    //$options['context'] = stream_context_create();
    //stream_context_set_option($options['context'], 'ssl', 'verify_host', false);
    //stream_context_set_option($options['context'], 'ssl', 'verify_peer', false);
    //stream_context_set_option($options['context'], 'ssl', 'verify_peer_name', false);
    //stream_context_set_option($options['context'], 'ssl', 'allow_self_signed', true);
    $context = stream_context_create(array(
      'ssl' => array(
        'verify_peer' => FALSE,
        'verify_peer_name' => FALSE,
        //'verify_depth' => 5,
        //'allow_self_signed' => TRUE,
        //'verify_host' => FALSE,
      )
    ));
    $options['context'] = $context;
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

}
