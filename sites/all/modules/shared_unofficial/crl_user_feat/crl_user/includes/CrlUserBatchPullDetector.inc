<?php


/**
 * Custom pull detector that uses LDAP queries in place of some very slow Crowd
 * queries.
 */
class CrlUserBatchPullDetector extends CrowdBatchPullDetector {

  // Increase the default limit for results as CRL's user DB is growing larger
  // than 10k
  protected $maxCrowdResults = 20000;
  
  /**
   * Get all Crowd users.
   *
   * @return array
   *   An indexed array of all Crowd users.
   */
  public function getAllCrowdUsers($reset = FALSE) {
    if ($reset || !isset($this->allCrowdUsers)) {
      // A direct query to LDAP is much, much, MUCH faster than trying to query
      // all users through the Crowd API.
      // 
      // UPDATE Nov 2022 - The Crowd API is now fast and reliable when doing a
      // large query, so this is no longer needed. Keeping notes for historical
      // ref.
      // 
      //$this->allCrowdUsers = array_map('mb_strtolower', crl_user_ldap_connect()->getAllUsers());
      // If there is a problem we can revert back to the parent implementation.
      if (empty($this->allCrowdUsers)) {
        return parent::getAllCrowdUsers($reset);
      }
    }
    return $this->allCrowdUsers;
  }

}
