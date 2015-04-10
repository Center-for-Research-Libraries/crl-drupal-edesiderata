<?php

/**
 * @file
 * Default print module template
 *
 * @ingroup print
 */
 //var_dump($print);
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $print['language']; ?>" xml:lang="<?php print $print['language']; ?>">
  <head>
    <?php print $print['head']; ?>
    <?php print $print['base_href']; ?>
    <title><?php print $print['title']; ?></title>
    <?php //print $print['scripts']; ?>
    <?php print $print['sendtoprinter']; ?>
    <?php print $print['robots_meta']; ?>
    <?php print $print['favicon']; ?>
    <?php print $print['css']; ?>
  </head>

  <body>
    <style>
       .field-group-htab {
	  margin: 1em;
	  padding: 1em;
	}
	.fieldset-legend{
	  font-weight:bold;
	  display: block;
	}
	.field-label{ 
	  font-weight: bold; 
	}
        .element-invisible{
	  display:none;
	}
	.field { 
	  padding:0.5em;
	}
	.fieldset-wrapper { 
	  border-width:1px;
	  border-style: dotted;
	  padding:1em;
	  margin-bottom:1em;	
	}
  </style>
       <?php if (!empty($print['message'])) {
      print '<div class="print-message">'. $print['message'] .'</div>';
    } ?>
    <div class="print-logo"><?php //print $print['logo']; ?></div>
    <div class="print-site_name"><?php //print $print['site_name']; ?></div>
    <p />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <div class="print-breadcrumb"><?php print $print['breadcrumb']; ?></div>
    <hr class="print-hr" />
    <div class="print-content"><?php print $print['content']; ?></div>
    <div class="print-footer"><?php print $print['footer_message']; ?></div>
	<fieldset class="field-group-htab">
	<legend><span class="fieldset-legend">Selector's Recommendation</span></legend>
	<div class="fieldset-wrapper"><p><b>Purchase Ranking(1=strongly oppose, 5=strongly favor): </b></br>
	___1 ___2 ___3 ___4 ___5
	</p>
	<p><b>Holding Status</b></br>
	___Do not own </br>
	___Own, can lend</br>
	___Own, cannot lend
	</p></div></fieldset>
    <hr class="print-hr" />
    <div class="print-source_url"><?php print $print['source_url']; ?></div>
    <div class="print-links"><?php print $print['pfp_links']; ?></div>
    <?php print $print['footer_scripts']; ?>
  </body>
</html>
