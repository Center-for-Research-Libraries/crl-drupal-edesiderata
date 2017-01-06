<?php
function crl_alpha_preprocess_block(&$vars) {
  // Customize the facet filters block title markup.
  if ($vars['block']->module == 'facetapi' && !empty($vars['block']->subject)) {
    $vars['block']->subject = t('Filter by') . ' <span class="facet-group">' . $vars['block']->subject . '</span>';
  }
  // Allow any attributes from the block definition to be added to the parent
  // block container.
  if (!empty($vars['block']->attributes) && !empty($vars['attributes_array'])) {
    $vars['attributes_array'] = array_merge_recursive($vars['attributes_array'], $vars['block']->attributes);
  }
}
