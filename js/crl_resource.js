(function($) {
  $(document).ready(function(){
    var ref_split = document.referrer.split("/");
    var curr_split = window.location.pathname.split("/");
    // First, make sure our referrer is in the same domain.
    if (window.location.host == ref_split[2]) {
      // See if the referrer is the dashboard or some form of the index. If so,
      // we can use a js browser back option for the back link.
      if (ref_split[3] == "" || typeof(ref_split[3]) == "undefined" || ref_split[3] == "main" || (ref_split[3] == "resources" && ref_split[4].substring(0, 4) == "main")) {
        //$("a#back-to-index").attr("href", "#");
        $("a#back-to-index").click(function() {
          window.history.go(-1);
          return false;
        });
      }
    }
  });
})(jQuery);
