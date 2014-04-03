(function($) {
  // When the document load be sure to show or hide the lend option based
  // on the current own option.
  $(document).ready(function(){
    $('.pp-own .vote-yes').closest('.pp-vote').find('.pp-lend').show();
    $('.pp-own .vote-no').closest('.pp-vote').find('.pp-lend').hide();
    $('.pp-own .vote-pending').closest('.pp-vote').find('.pp-lend').hide();
  });
})(jQuery);

(function($) {
  // When own options are clicled be sure to show or hide the lend option
  // based on which choice was selected.
  Drupal.behaviors.conditionalRateWidget = {
    attach: function(context, settings) {
      $('.pp-own a.rate-button-yes').click(function() {
        $(this).closest('.pp-vote').find('.pp-lend').slideDown();
      });
      $('.pp-own a.rate-button-no').click(function() {
        $(this).closest('.pp-vote').find('.pp-lend').slideUp();
      });
    }
  };
  Drupal.attachBehaviors("a.rate-button");
})(jQuery);

