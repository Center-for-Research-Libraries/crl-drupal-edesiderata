<?php
if ($mode == RATE_FULL || $mode == RATE_DISABLED) {
  print '<p>' . $title . '</p>';
  if (!empty($display_options['description']) && $mode == RATE_FULL) {
    print '<p class="rate-description">' . $display_options['description'] . '</p>';
  }
}

if ($mode == RATE_FULL || $mode == RATE_COMPACT) {
  print '<div class="vote-user-wrapper">';
  print '<span class="vote-results ' . $your_vote_class . '">' . $your_vote_status . '</span>';
  print '<div class="rate-user">' . theme('item_list', array('items' => $stars_user)) . '</div>';
  print '<span class="vote-results">' . $your_vote . '</span>';
  print '<div class="rate-info"></div>';
  print '</div>';
}

print '<div class="vote-summary-wrapper">';
print '<span class="vote-results">' . $count_text .  '</span>';
print theme('item_list', array('items' => $stars_all));
print '<span class="vote-results">' . $av_vote . '</span>';
print '</div>';
