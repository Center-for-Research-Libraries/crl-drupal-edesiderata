(function($) {
  $(document).ready(function(){
    $('#toggle-saved-search').click(function() {
      $('#toggle-saved-search').fadeOut();
      $('#breadcrumb-saved-search').slideDown();
    });
  });
})(jQuery);
