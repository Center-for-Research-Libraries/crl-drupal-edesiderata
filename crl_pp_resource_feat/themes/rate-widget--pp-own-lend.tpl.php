<?php
if ($mode == RATE_FULL || $mode == RATE_DISABLED) {
  print '<p>' . $title . '</p>';
  if (!empty($display_options['description']) && $mode == RATE_FULL) {
    print '<p class="rate-description">' . $display_options['description'] . '</p>';
  }
}

if ($mode == RATE_FULL || $mode == RATE_COMPACT) {
  print '<div class="vote-user-wrapper">';
  //if (!empty($your_vote)) {
    print '<span class="vote-results ' . $your_vote_class . '">' . $your_vote . '</span><br />';
  //}
  print '<div class="vote-results">' . theme('item_list', array('items' => $buttons)) . '</div>';
  print '<div class="rate-info"></div>';
  print '</div>';
}

print '<div class="vote-summary-wrapper">';
print '<span class="vote-results">' . $count_text .  '</span>';
print '<div class="vote-results">' . theme('item_list', array('items' => $item_results)) . '</div>';
print '</div>';
