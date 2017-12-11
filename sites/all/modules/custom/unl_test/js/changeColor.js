(function($) {

    Drupal.ajax.prototype.commands.color_links = function(ajax, response, status) {

        var arr = jQuery(".links.main-links a");
        var color = response.color;
        arr.css("color", color);
    };

    Drupal.behaviors.unl_test = {
        attach: function (context, settings) {
            setInterval(function() {
                var url = "/color_links/nojs";
                var ajax = new Drupal.ajax(false, false, {url : url});
                ajax.eventResponse(ajax, {});
                }, 3000);
        }
    };
}(jQuery));
