<?php
function crl_alpha_preprocess_block(&$vars) {
  if ($vars['block']->module == 'facetapi' && !empty($vars['block']->subject)) {
    $vars['block']->subject = t('Filter by') . ' <span class="facet-group">' . $vars['block']->subject . '</span>';
  }
}