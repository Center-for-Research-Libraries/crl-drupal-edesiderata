<?php
// This file is essentially the main site header. It is coded as a template
// file for a region so that it can easily be manipulated (shown/hidden) via
// context and delta.
?>

<?php if ($wrapper): ?><div<?php print $attributes; ?>><?php endif; ?>  
  <div<?php print $content_attributes; ?>>
    <div id="header-logo">
      <a class="logo" href="<?php print url('http://www.crl.edu') ?>"></a>
    </div>
    <div class="header-user-tools-back"></div>
    <div id="header-typography">
      <?php if ($site_name || $site_slogan): ?>
      <hgroup>        
        <?php if ($site_name): ?>
        <?php if ($is_front): ?>        
        <h1 class="site-name"><?php print '<a href="' . url('<front>') . '">' . $site_name . '</a>' ?></h1>
        <?php else: ?>
        <h2 class="site-name"><?php print '<a href="' . url('<front>') . '">' . $site_name . '</a>' ?></h2>
        <?php endif; ?>
        <?php endif; ?>
        <?php if ($site_slogan): ?>
        <p class="site-slogan"><?php print $site_slogan; ?></p>
        <?php endif; ?>
      </hgroup>
      <?php endif; ?>
    </div>  
    <div id="header-user-tools">
      <?php print $user_message ?>
    </div>
    <div id="header-menus">
      <?php 
      print $jump_menu;
      print '<div class="main-menu">' . drupal_render($tree_main) . '</div>';
      print '<div class="secondary-menu">' . drupal_render($tree_secondary) . '</div>';
      ?>
    </div>
    
    <?php print $content; ?>
    
  </div>
<?php if ($wrapper): ?></div><?php endif; ?>
