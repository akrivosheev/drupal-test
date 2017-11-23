(function($) {
    Drupal.behaviors.myBehavior = {
        attach: function (context) {
            $(document).ready(function() {
                $("#edit-phone").mask("375999999999");
            });
        }
    };
})(jQuery);
