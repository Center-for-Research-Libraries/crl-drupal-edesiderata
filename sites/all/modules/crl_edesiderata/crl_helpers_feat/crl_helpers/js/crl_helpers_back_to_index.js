(function($) {
  $(document).ready(function(){
    var ref_split = document.referrer.split("/");
    var curr_split = window.location.pathname.split("/");
    // First, make sure our referrer is in the same domain.
    if (window.location.host == ref_split[2]) {
      // See if the referrer is the dashboard or some form of the index. This is
      // tied to aliases, which might not be the most efficient way to do things
      // but it's a quick and dirty solution.
      if (ref_split[3] == "" || // Dashboard
        typeof(ref_split[3]) == "undefined" || // Dashboard
        ref_split[3] == "main" || // Dashboard
        (ref_split[3] == "resources" && ref_split[4].substring(0, 4) == "main") || // A resource index
        (ref_split[3] == "providers" && ref_split[4].substring(0, 4) == "main") || // A provider index
        ref_split[3] == "me") { // meDes
        // If we pass the conditions above we can make the "back" href more
        // specific based on the actaul referrer. We also add a click event that
        // will check if it's safe to go one step further and use the actual
        // browser histroy (that will further maintain scroll position, etc.).
        $("a#back-to-index").attr('href', document.referrer);
        $("a#back-to-index").click(function() {
          // If we have a fragment set we can't trust the history (it may point
          // to same page).
          if (!window.location.hash) {
            window.history.go(-1);
            return false;
          }
        });
      }
    }
  });
})(jQuery);
