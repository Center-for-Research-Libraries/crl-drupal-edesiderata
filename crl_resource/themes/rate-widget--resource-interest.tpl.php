<?php 
if ($display_options['description']) {
  print '<p>' . $display_options['description'] . '</p>';
}

$yes_button = '<a class="rate-button button" id="rate-button-100" rel="nofollow" href="' . htmlentities($links[0]['href']) . '" title="' . $links[0]['text'] . '">' . '<span class="crl-icon-small thumbsup-icon"></span>' . $links[0]['text'] . '</a>';
$no_button = '<a class="rate-button button" id="rate-button-101" rel="nofollow" href="' . htmlentities($links[1]['href']) . '" title="' . $links[1]['text'] . '">' . '<span class="crl-icon-small thumbsdown-icon"></span>' . $links[1]['text'] . '</a>';
print '<p class="interest-input">' . $yes_button . ' ' . $no_button . '</p>';

if ($info) {
  print '<p class="rate-info interest-vote">' . $info . '</p>';
}
