<?php
/**
 * @file
 * crl_user_sf.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crl_user_sf_default_rules_configuration() {
  $items = array();
  $items['rules_crl_user_sf_email_on_external_update'] = entity_import('rules_config', '{ "rules_crl_user_sf_email_on_external_update" : {
      "LABEL" : "CRL User SF email on external update",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "mimemail" ],
      "ON" : { "user_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "account:flag-linked-sf-update" ], "value" : "1" } },
        { "OR" : [
            { "NOT data_is" : {
                "data" : [ "account:field-first-name" ],
                "value" : [ "account-unchanged:field-first-name" ]
              }
            },
            { "NOT data_is" : {
                "data" : [ "account:field-last-name" ],
                "value" : [ "account-unchanged:field-last-name" ]
              }
            },
            { "NOT data_is" : { "data" : [ "account:mail" ], "value" : [ "account-unchanged:mail" ] } },
            { "NOT data_is" : {
                "data" : [ "account:field-institution" ],
                "value" : [ "account-unchanged:field-institution" ]
              }
            },
            { "NOT data_is" : {
                "data" : [ "account:field-profile-title" ],
                "value" : [ "account-unchanged:field-profile-title" ]
              }
            },
            { "NOT data_is" : {
                "data" : [ "account:field-phone" ],
                "value" : [ "account-unchanged:field-phone" ]
              }
            },
            { "NOT data_is" : {
                "data" : [ "account:field-profile-roles" ],
                "value" : [ "account-unchanged:field-profile-roles" ]
              }
            }
          ]
        }
      ],
      "DO" : [
        { "mimemail" : {
            "key" : "email_on_sf_linked_user_update",
            "to" : "rjacobs@crl.edu",
            "reply_to" : [ "" ],
            "subject" : "CRL User: CIS user updated external to CIS",
            "body" : "CUD user [account:name] is linked to CIS but was updated externally to CIS. These updates should be reviewed to determine if any changes should be manually captured within CIS. This user\\u0027s CIS contact record can be accessed directly at: [account:salesforce-mapping-object:salesforce-url]\\r\\n\\r\\nThe following values may be out-of-sync with CIS:\\r\\n\\r\\nFirst Name:\\r\\n[account:field-first-name] (current)\\r\\n[account-unchanged:field-first-name] (original)\\r\\n\\r\\nLast Name:\\r\\n[account:field-last-name] (current)\\r\\n[account-unchanged:field-last-name] (original)\\r\\n\\r\\nEmail:\\r\\n[account:mail] (current)\\r\\n[account-unchanged:mail] (original)\\r\\n\\r\\nInstitution:\\r\\n[account:field-institution] (current)\\r\\n[account-unchanged:field-institution] (original)\\r\\n\\r\\nTitle:\\r\\n[account:field-profile-title] (current)\\r\\n[account-unchanged:field-profile-title] (original)\\r\\n\\r\\nPhone:\\r\\n[account:field-phone] (current)\\r\\n[account-unchanged:field-phone] (original)\\r\\n\\r\\nAdditionally, the user\\u0027s profile roles values may have also been changed. These values are not tracked directly in CIS but they may help inform which CIS roles should be set for this user.\\r\\n\\r\\nRoles:\\r\\n[account:field-profile-roles] (current)\\r\\n[account-unchanged:field-profile-roles] (original)\\r\\n\\r\\n\\u003Chr\\/\\u003E\\r\\n\\r\\nTechnical information: Sys User=[site:current-user:name], Triggering URL=[site:current-page:url], SF URL=[account:salesforce-mapping-object:salesforce-url]",
            "plaintext" : "The plain text version of this message is not available.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
