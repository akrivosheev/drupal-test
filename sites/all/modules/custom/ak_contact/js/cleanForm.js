(function($) {
    Drupal.ajax.prototype.commands.clean_form = function(ajax, response, status) {
        jQuery(".form-class").trigger('reset');
    }
}(jQuery));
