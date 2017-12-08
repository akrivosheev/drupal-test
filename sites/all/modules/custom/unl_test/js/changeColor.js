(function($) {

Drupal.ajax.prototype.commands.color_links = function(ajax, response, status) {
    var arr = jQuery(".link-list a");
    var random_color = getRandomColor();
    arr.css("color", random_color);

    function getRandomColor() {
        var letters = '0123456789ABCDEF';
        var color = '#';
        for (var i = 0; i < 6; i++) {
            color += letters[Math.floor(Math.random() * 16)];
        }
        return color;
    }
};

setInterval(function() {
    Drupal.ajax.prototype.commands.color_links()
}, 3000);

}(jQuery));
