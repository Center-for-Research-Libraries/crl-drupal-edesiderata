<?php
/**
 * @file
 * crl_activity_feat.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function crl_activity_feat_taxonomy_default_vocabularies() {
  return array(
    'activity_grouping' => array(
      'name' => 'Activity Grouping',
      'machine_name' => 'activity_grouping',
      'description' => 'Assign an activity and offer to a CRL group.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
