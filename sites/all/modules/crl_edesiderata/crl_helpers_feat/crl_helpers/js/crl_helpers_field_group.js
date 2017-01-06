// Helper behaviors for field gorup.
(function($) {
  Drupal.behaviors.crlHelpersFieldGroup = {
    attach: function(context) {
      // Upon click add a horizontal tab's ID to the current fragment so that
      // back navigation will retain the current open tab state.
      $('li.horizontal-tab-button a').click(function () {
        var targetHash = $(this).attr('href');
        if (document.location.hash != targetHash) {
          var targetId = targetHash.replace(/^#/, '');
          var targetElem = $(targetHash);
          targetElem.attr('id', targetId + '-horizontal-tab-no-jump');
          document.location.hash = targetId;
          targetElem.attr('id', targetId);
        }
      });
    }
  }
})(jQuery);