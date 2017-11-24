(function($) {
    Drupal.ajax.prototype.commands.clean_form = function(ajax, response, status) {
        jQuery(".ak-contact-username-email-form-class").trigger('reset');
    }
}(jQuery));
