<?php

/**
 * @file
 * Describe hooks provided by the Crowd Batch Pull module.
 */


/**
 * Alter the detector class used to detect remote changes.
 *
 * This hook has limited utility as only one module can realistically make use
 * of it at any given time. hook_crowd_batch_pull_detector_object_alter() may be
 * a more robust choice for global modifications.
 *
 * @param string $connection_class
 *   The detector class name that will be used when a detector is instantiated.
 */
function hook_crowd_batch_pull_detector_class_alter(&$detector_class) {
  $connection_class = 'MyExtendedCrowdBatchPullDetector';
}


/**
 * Decorate a detector object used to detect remote changes.
 *
 * @param CrowdBatchPullDetectorInterface $detector
 *   A freshly instantiated detector.
 */
function hook_crowd_batch_pull_detector_object_alter($detector) {
  // Decorate the detector with custom functionality via the
  // MyDecoratedCrowdBatchPullDetector class.
  $detector = new MyDecoratedCrowdBatchPullDetector($detector);
}
