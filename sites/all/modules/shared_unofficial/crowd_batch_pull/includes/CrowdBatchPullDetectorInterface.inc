<?php


/**
 * @file
 * Interface for a Crowd Batch Pull Detector.
 */


/**
 * Interface for a Crowd Batch Pull Detector
 */
interface CrowdBatchPullDetectorInterface {

  /**
   * Detect which Crowd users have been updated since a certain time.
   *
   * @param int $last_sync
   *   The timestamp of the last update check. Only changes since this timestamp
   *   will be detected.
   * @return array
   *   An indexed array of Crowd usernames that have been updated remotely since
   *   the $last_sync timestamp.
   */
  public function detectUpdated($last_sync);

  /**
   * Detect which Crowd users have had group changes based on the supplied
   * Crowd Group to Drupal roles mapping.
   *
   * @param array $group_map
   *   A mapping between Crowd groups to Drupal roles
   *   ($crowd_groupname => $drupal_rid). Users who are not in sync, based on
   *   this mapping, will be detected as "changed".
   * @return array
   *   An indexed array of Crowd usernames that have had group changes applied
   *   to them in Crowd which are not yet represented locally.
   */
  public function detectGroupChanges($group_map);

  /**
   * Detect which Crowd users have been deleted in Crowd but still remain in
   * Drupal.
   *
   * @return array
   *   An array of Crowd usernames, keyed by matched Drupal uid, that have been
   *   deleted in Crowd but still have a mapped user in Drupal.
   */
  public function detectDeleted();

  /**
   * Detect which Crowd users have been added in Crowd but have not yet been
   * added in Drupal.
   *
   * @return array
   *   An indexed array of Crowd usernames that have been added in Crowd but do
   *   not yet have a mapped user in Drupal.
   */
  public function detectAdded();

  /**
   * Get all Drupal users that are linked to Crowd in the authmap table.
   * 
   * This is largely a utility for other methods on
   * CrowdBatchPullDetectorInterface, but it may still be handy part of the
   * interface for external logic to tap into.
   *
   * @return array
   *   An array of all Crowd usernames that are mapped to a Drupal user, keyed
   *   by Drupal uid.
   */
  public function getAllDrupalUsers($reset = FALSE);

  /**
   * Get all Crowd users.
   * 
   * This is largely a utility for other methods on
   * CrowdBatchPullDetectorInterface, but it may still be handy part of the
   * interface for external logic to tap into.
   *
   * @return array
   *   An indexed array of all Crowd users.
   */
  public function getAllCrowdUsers($reset = FALSE);

}
