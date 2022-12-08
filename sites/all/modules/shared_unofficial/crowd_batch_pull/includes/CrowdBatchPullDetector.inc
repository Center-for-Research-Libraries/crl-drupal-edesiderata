<?php


/**
 * Class to detect which users are out-of-sync between Drupal and Crowd.
 */
class CrowdBatchPullDetector implements CrowdBatchPullDetectorInterface {

  /**
   * A Crowd connection object.
   *
   * @var CrowdServiceInterface $crowd
   */
  protected $crowd;

  /**
   * The maximun number of Crowd results per query.
   *
   * @var int $maxCrowdResults
   */
  protected $maxCrowdResults = 10000;

  /**
   * A list of all Drupal users (for internal caching).
   *
   * @var array $allDrupalUsers
   */
  protected $allDrupalUsers = NULL;

  /**
   * A list of all Crowd users (for internal caching).
   *
   * @var array $allCrowdUsers
   */
  protected $allCrowdUsers = NULL;

  /**
   * Constructor.
   */
  public function __construct(CrowdServiceInterface $crowd) {
    $this->crowd = $crowd;
  }

  /**
   * {@inheritdoc}
   */
  public function detectUpdated($last_sync) {
    $updated = array();
    // If last sync is empty then we default to a fetch of all users.
    if (empty($last_sync)) {
      return $this->getAllCrowdUsers();
    }
    // Convert $last_sync to a format that Crowd understands and add a buffer.
    $last_sync = $last_sync - 120;
    $last_sync = date('Y-m-d', $last_sync) . 'T' .  date('G:i', $last_sync);
    $restriction = 'updatedDate > ' . $last_sync;
    $updated = $this->crowd->searchCql('user', $restriction, 0, $this->maxCrowdResults);
    return $updated;
  }

  /**
   * {@inheritdoc}
   */
  public function detectGroupChanges($group_map) {
    $changed_group_users = array();
    $crowd_groups = $this->crowd->getAllGroups();
    foreach (user_roles(TRUE) as $rid => $role_name) {
      $mapped_groups = array_keys($group_map, $rid);
      if ($mapped_groups) {
        // Query for Drupal users in the mapped role.
        $query = "SELECT a.authname FROM {authmap} AS a INNER JOIN {users_roles} AS ur ON a.uid = ur.uid WHERE ur.rid IN (:rids) AND a.module = :authgroup";
        $result = db_query($query, array(':rids' => array($rid), ':authgroup' => 'crowd'));
        $drupal_names = array_map('mb_strtolower', $result->fetchCol());
        $crowd_names = array();
        // The group map supports a many-to-one relationship between Crowd
        // groups and Drupal roles (groups are OR'ed to determine if the mapped
        // role is active). This means that we have to cluster together ALL of
        // the Crowd users, potentailly across multiple groups, that have a map
        // to this Drupal role before doing any diffs.
        foreach ($mapped_groups as $crowd_group) {
          // Sanity-check that the group exists in Crowd.
          if (in_array($crowd_group, $crowd_groups)) {
            $crowd_names_group = array_map('mb_strtolower', $this->crowd->getGroupMembers($crowd_group, 0, $this->maxCrowdResults));
            $crowd_names = array_unique(array_merge($crowd_names, $crowd_names_group));
          }
        }
         // Diff both ways to get ALL changes.
        $group_diff = array_merge(array_diff($drupal_names, $crowd_names), array_diff($crowd_names, $drupal_names));
        // Merge these group chages into our master change list.
        $changed_group_users = array_unique(array_merge($changed_group_users, $group_diff));
      }
    }
    return $changed_group_users;
  }

  /**
   * {@inheritdoc}
   */
  public function detectDeleted() {
    $deleted = array();
    $drupal_names = $this->getAllDrupalUsers();
    $crowd_names = $this->getAllCrowdUsers();
    if ($drupal_names && $crowd_names) {
      $deleted = array_diff($drupal_names, $crowd_names);
    }
    return $deleted;
  }

  /**
   * {@inheritdoc}
   */
  public function detectAdded() {
    $added = array();
    $drupal_names = $this->getAllDrupalUsers();
    $crowd_names = $this->getAllCrowdUsers();
    if ($drupal_names && $crowd_names) {
      $added = array_values(array_diff($crowd_names, $drupal_names));
    }
    return $added;
  }

  /**
   * {@inheritdoc}
   */
  public function getAllDrupalUsers($reset = FALSE) {
    if ($reset || !isset($this->allDrupalUsers)) {
      // Get all Drupal-based Crowd users via a simple query.
      $query = "SELECT u.uid, a.authname FROM {users} AS u INNER JOIN {authmap} AS a ON u.uid = a.uid WHERE a.module = :authgroup";
      $result = db_query($query, array(':authgroup' => 'crowd'));
      $this->allDrupalUsers = array_map('mb_strtolower', $result->fetchAllKeyed());
    }
    return $this->allDrupalUsers;
  }

  /**
   * {@inheritdoc}
   */
  public function getAllCrowdUsers($reset = FALSE) {
    if ($reset || !isset($this->allCrowdUsers)) {
      // Query the whole list of users without any condition.
      // @todo: Testing reveals that this is a VERY slow query. We need to see
      // if there is a better way to do this via the Crowd REST API.
      $this->allCrowdUsers = array_map('mb_strtolower', $this->crowd->searchCql('user', '', 0, $this->maxCrowdResults));
    }
    return $this->allCrowdUsers;
  }

}
