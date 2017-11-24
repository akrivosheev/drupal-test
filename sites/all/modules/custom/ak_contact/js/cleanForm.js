(function($) {
    Drupal.ajax.prototype.commands.clean_form = function(ajax, response, status) {
        jQuery('#ak-contact-form').trigger('reset');
    }
}(jQuery));