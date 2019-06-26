<?php

/**
 * @file
 * crl_provider_feat.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crl_provider_feat_default_rules_configuration() {
  $items = array();
  $items['rules_email_on_profile_draft'] = entity_import('rules_config', '{ "rules_email_on_profile_draft" : {
      "LABEL" : "Email on Profile Draft",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--provider" : { "bundle" : "provider" } },
      "IF" : [
        { "data_is" : { "data" : [ "node:field-provider-profile-status" ], "value" : "draft" } },
        { "NOT data_is" : {
            "data" : [ "node-unchanged:field-provider-profile-status" ],
            "value" : "draft"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[user:mail], reilly@crl.edu",
            "subject" : "eDesiderata Provider Profile Drafted: [node:title]",
            "message" : "An editor has indicated that the Profile details are now in a \\u0022drafted\\u0022 state for the following Provider:\\r\\n\\r\\n[node:title] ([node:url])\\r\\n\\r\\nYou are receiving the message because you are either the editor responsible for setting this \\u0022Drafted\\u0022 state or you are a contact responsible for reviewing and publishing drafted profile data. Please note that the Profile details (e.g. the fields in the \\u0022CRL Analysis and Profile\\u0022 tab) are still not public until they are officially marked as \\u0022Published\\u0022.\\r\\n\\r\\nTo view ALL Profiles that currently have pending Profile drafts, please visit: [site:url]admin\\/content-summary\\/providers?status=All\\u0026profile_status=draft",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
