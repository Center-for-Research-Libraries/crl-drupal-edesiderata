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
    'grouping' => array(
      'name' => 'Grouping',
      'machine_name' => 'grouping',
      'description' => 'Assign view rights to a CRL group.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -10,
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
