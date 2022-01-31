This is the main codebase for CRL's eDesiderata website (edesiderata.crl.edu).

## Deploy New Dev Environment

The codebase will be deployed mainly as an existing site clone to accomodate development with active example content, not as a fresh Drupal install.

1. Clone this codebase into a new project root (web STACK enabled and ideally IDE enabled).
1. Add external/shared dependencies within `sites/all/modules/shared_unofficial`. As long as you are a collaborator on the related custom repos this can be achieved in one step by calling `clone.sh` from this directory.
1. Place a **dev** copy of the files tree inside `sites/default/files`.
1. Import a **dev** copy of the Drupal DB into a local MySQL/MariaDB instance.
1. Wire-up the DB to this Drupal instance inside `sites/default/settings.php`. It's best to start with a copy of `sites/default/default.settings.php` and localize from there. There are no special custom requirements for `settings.php` beyond DB credentials and any dev customizations preferred.
1. Verify site functionality as anon user and login using the user1 (admin) user.
1. Enable any dev tools needed as per preferences.

## Database Preparation Notes

These notes apply to the creation of a dev copy of the site DB based on a live (prod/staging) dump. If this DB copy already exists then these notes are not needed.

If creating a dev DB that will be moved offsite we want to purge member user accounts and related info. Untangling the user list from Crowd in order to perform this purge requires some careful processing.

- The Crowd connection should be disabled. We cannot disable the main Crowd module as it's a dependency of a number of other custom modules that must stay active but we can cripple it's functionality by setting a bogus Crowd server address (such as http://1.1.1.1) at `admin/config/crowd`
- The authmap table should be truncated. This will remove all mappings between local Drupal user accounts and their Crowd counterparts.
- Prepare a VBO view that lists all users that do not contain "@crl.edu" in the user email address. This will allow us to target non-CRL user accounts for bulk processing (deletion). We want to keep the CRL accounts as they tend to be the owners of most site content, and it is good to be able to reference these user-to-node relationships even in dev. The enabled VBO operations (in the VBO user operations field config) should add the "Cancel User" option to the available bulk operations without any sub-options (no enqueue, etc). The pager setting does not matter as VBO allows us to select ALL view items in addition to all items on a page when accessing the view.
- Access the view (best though a page display), select ALL view items (the ALL view items option will appear when invoking the all items on page checkbox in the view output) and execute a Cancellation. On the options page that appears next be sure to select the "Delete the account and make its content belong to the Anonymous user" method as we want a true purge but do not want to accidentally remove any misc content owned by these users.

Other things to check:

- Make sure the `crl_user_sf` module is disabled. This should only be enabled on one production instance.
- Disable and uninstall the "CRL User SF Bridge", "CRL Membership Feature" and "Salesforce Push" modules if they were enabled on the source. These should only be enabled on one production site in a Crowd cluster.
- Disable "Link Checker" if this is a non-prod site (it devours cron resources).
- Turn off caching.
- Double-check that most messages, and other types of email, will not be triggered to normal users from non-production instances.
- Enable native cron handling of non-prod sites if a real crontab entry does not exist (`admin/config/system/cron`).


## LESS Compilation


Install the LESS command line compiler globally with npm by running the following command:

`$ npm install -g less`

Run the command below to compile LESS:

```
lessc sites/all/themes/crl_bootstrap/less/style.less > sites/all/themes/crl_bootstrap/css/style.css
```

## Drupal Core Update process

You may update core using [drush](https://www.drupal.org/docs/7/update/updating-drupal-using-drush).

If you had modified .gitignore or .htaccess, make sure the modifications are reapplied. (Sometimes you can just copy the old files back or revert relevant lines directly in your IDE).

There may also be some core patch files that need to be re-applied in the rood directory. It's best to check the issue that these patch files are linked to in case a resolution has already been merged into the new Drupal core version. If the patch is still relevant it can be applied with the patch command directly, such as:

```
patch -p1 < D7-search-index_errors_on_broken_internal_links-1299530-10-do-not-test.patch
```

## GitHub Branch Rename

If you have an existing copy of this repository in your local environment and you have not yet manually renamed the `master` branch to `main`, please use the following commands:

```
git branch -m master main
git fetch origin
git branch -u origin/main main
git remote set-head origin -a
```
