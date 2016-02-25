<?php
/**
 * @file
 * crl_pp_resource_feat.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crl_pp_resource_feat_default_rules_configuration() {
  $items = array();
  $items['rules_convert_to_purchase_proposal'] = entity_import('rules_config', '{ "rules_convert_to_purchase_proposal" : {
      "LABEL" : "Convert to Purchase Proposal nomination",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_flagged_entityform_pp_convert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "flagged-entityform" ],
            "type" : "entityform",
            "bundle" : { "value" : { "purchase_proposal_nomination" : "purchase_proposal_nomination" } }
          }
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "pp_resource",
              "param_title" : "[flagged-entityform:field_title_sort]",
              "param_author" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "node_unpublish" : { "node" : [ "entity-created" ] } },
        { "data_set" : {
            "data" : [ "entity-created:field-contact-name" ],
            "value" : "[flagged-entityform:field-contact-name]"
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-contact-email" ],
            "value" : "[flagged-entityform:field-contact-email]"
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-pp-nominator-institution" ],
            "value" : "[flagged-entityform:field-pp-nominator-institution]"
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-pp-publisher" ],
            "value" : "[flagged-entityform:field-pp-publisher]"
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-pp-subject-area" ],
            "value" : [ "flagged-entityform:field-pp-subject-area" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-pp-notes" ],
            "value" : "[flagged-entityform:field-pp-notes]"
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-pp-piece-count-and-pricing" ],
            "value" : "[flagged-entityform:field-pp-piece-count-and-pricing]"
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-pp-languages" ],
            "value" : "[flagged-entityform:field-pp-languages]"
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-link" ],
            "value" : [ "flagged-entityform:field-link" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-pp-nominator-comments" ],
            "value" : [ "flagged-entityform:field-pp-nominator-comments" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:body" ],
            "value" : [ "flagged-entityform:field-further-description" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-contacts" ],
            "value" : [ "flagged-entityform:field-contacts" ]
          }
        },
        { "entity_save" : { "data" : [ "entity-created" ], "immediate" : "1" } },
        { "data_set" : {
            "data" : [ "flagged-entityform:field-pp-related" ],
            "value" : [ "entity-created" ]
          }
        },
        { "redirect" : { "url" : "[entity-created:edit-url]" } }
      ]
    }
  }');
  $items['rules_email_on_pp_nomination'] = entity_import('rules_config', '{ "rules_email_on_pp_nomination" : {
      "LABEL" : "Email on PP Nomination Submission",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "mimemail", "entityform" ],
      "ON" : { "entityform_insert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "entityform" ],
            "type" : "entityform",
            "bundle" : { "value" : { "purchase_proposal_nomination" : "purchase_proposal_nomination" } }
          }
        }
      ],
      "DO" : [
        { "mimemail" : {
            "key" : "email-pp-nomination",
            "to" : "[entityform:field-contact-email]",
            "bcc" : "mwilke@crl.edu,falba@crl.edu,ashrestha@crl.edu",
            "from_name" : "Mary Wilke",
            "from_mail" : "mwilke@crl.edu",
            "subject" : "CRL Purchase Proposal Nomination",
            "body" : "\\u003Cp\\u003EDear [entityform:field-contact-name],\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EThis e-mail is to confirm your submission for CRL\\u0027s Purchase Proposal Program.\\r\\nYour submission is as follows:\\u003C\\/p\\u003E\\r\\n\\r\\n   \\u003Cp\\u003E\\u003Cstrong\\u003ERequesting Library: \\u003C\\/strong\\u003E[entityform:field_pp_nominator_institution]\\u003Cbr\\u003E\\r\\n     \\u003Cstrong\\u003ETitle: \\u003C\\/strong\\u003E[entityform:field-title-sort]\\u003Cbr\\u003E\\r\\n    \\u003Cstrong\\u003EPublisher, Micropublisher, Vendor or Source:\\u003C\\/strong\\u003E [entityform:field-pp-publisher]\\u003Cbr\\u003E\\r\\n    \\u003Cstrong\\u003EVendor Contact Information:\\u003C\\/strong\\u003E [entityform:field-contacts]\\u003Cbr\\u003E\\r\\n    \\u003Cstrong\\u003EVendor URL:\\u003C\\/strong\\u003E [entityform:field-link:url]\\u003Cbr\\u003E\\r\\n    \\u003Cstrong\\u003EPiece Count and Pricing: \\u003C\\/strong\\u003E[entityform:field_pp_piece_count_and_pricing]\\t\\u003Cbr\\u003E\\r\\n    \\u003Cstrong\\u003ETopic(s) Covered: \\u003C\\/strong\\u003E[entityform:field-pp-subject-area]\\t\\u003Cbr\\u003E\\r\\n    \\u003Cstrong\\u003EYears Covered: \\u003C\\/strong\\u003E[entityform:field-pp-notes]\\u003Cbr\\u003E\\r\\n    \\u003Cstrong\\u003EBackground Information: \\u003C\\/strong\\u003E[entityform:field-further-description:value]\\u003Cbr\\u003E\\r\\n    \\u003Cstrong\\u003EReasons for Consideration:\\u003C\\/strong\\u003E [entityform:field-pp-nominator-comments:value]\\r\\n\\u003Cp\\u003E\\r\\n\\r\\n\\u003Cp\\u003EPlease feel free to respond to this e-mail if you have any questions regarding your submission.\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E\\r\\nBest regards,\\u003Cbr\\u003E\\r\\nMary Wilke\\u003Cbr\\u003E\\r\\nMember Liaison and Outreach Services Director Center for Research Libraries\\u003Cbr\\u003E\\r\\nPhone: 773-955-4545 Ext. 351\\u003C\\/p\\u003E\\r\\n",
            "plaintext" : "Dear [entityform:field-contact-name],\\r\\n\\r\\nThis e-mail is to confirm your submission for CRL\\u0027s Purchase Proposal Program.\\r\\nYour submission is as follows:\\r\\n\\r\\n    Requesting Library: [entityform:field_pp_nominator_institution]\\r\\n    Title: [entityform:field-title-sort]\\r\\n    Publisher, Micropublisher, Vendor or Source: [entityform:field-pp-publisher]\\r\\n    Vendor Contact Information: [entityform:field-contacts]\\r\\n    Vendor URL: [entityform:field-link:url]\\r\\n    Piece Count and Pricing: [entityform:field_pp_piece_count_and_pricing]\\t\\r\\n    Topic(s) Covered: [entityform:field-pp-subject-area]\\t\\r\\n    Years Covered: [entityform:field-pp-notes]\\r\\n   Background Information: [entityform:field_further_description:value]\\r\\n    Reasons for Consideration: [entityform:field-pp-nominator-comments:value]\\r\\n\\r\\n\\r\\nPlease feel free to respond to this e-mail if you have any questions regarding your submission.\\r\\n\\r\\nBest regards,\\r\\nMary Wilke\\r\\nMember Liaison and Outreach Services Director Center for Research Libraries\\r\\nPhone: 773-955-4545 Ext. 351\\r\\n",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
