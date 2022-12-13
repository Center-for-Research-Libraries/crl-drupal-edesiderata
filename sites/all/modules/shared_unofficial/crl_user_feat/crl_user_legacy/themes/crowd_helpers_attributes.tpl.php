<html>
  <head>
    <style type="text/css">
      body { 
        font-family: sans-serif;
        font-size: smaller;
      }
    </style>
  </head>
  <body>
    <?php if (!empty($variables['change_text'])) {
      print '<h3>My Email Address</h3>';
      print '<p>' . $variables['email'] . '</p>';
      if (!empty($variables['inst_text'])) {
        print '<h3>My CRL Member Institution Affiliation</h3>';
        print '<p>' . $variables['inst_text'] . '</p>';
      }
      print '<p><a target="_parent" href="' . $variables['change_url'] . '"><button>' . $variables['change_text'] . '</button></a></p>';
    }
    ?>
  </body>
</html>