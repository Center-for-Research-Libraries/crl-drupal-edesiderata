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

}
