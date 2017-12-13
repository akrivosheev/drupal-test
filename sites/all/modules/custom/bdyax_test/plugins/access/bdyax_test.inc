<?php

/**
 * @file
 * Plugin to provide access control.
 */

/**
 * Plugins are described by creating a $plugin array which will be used.
 */
$plugin = array(
  'title' => t('False on unix even'),
  'description' => t('Control access by checking time'),
  'callback' => 'bdyax_test_even_ctools_access_check',
  'all contexts' => TRUE,
  'required context' => new ctools_context_required(t('Add context plugin with TRUE/FALSE'), 'bdyax_test'),
);

/**
 * Check for access.
 */
function bdyax_test_even_ctools_access_check($conf, $context) {

  $access = FALSE;
  foreach ($context as $item) {
    if ($item->type == 'bdyax_test' && $item->is_even) {
      $access = TRUE;
      break;
    }
  }
  return $access;
}
