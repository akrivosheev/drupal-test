(function($) {

Drupal.ajax.prototype.commands.color_links = function(ajax, response, status) {
    alert('ГАУ!!!');
    debugger;
    var arr = jQuery(".item-link");

    $.each( arr, function ( index, value ) {
        var b = 4;
        var c = 6;
        // alert( index + ": " + value );
        value.style.color = 'red';
    });

    jQuery(".unl-test-change-color").trigger('reset');
}

}(jQuery));


