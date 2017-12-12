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
);

/**
 * Check for access.
 */
function bdyax_test_even_ctools_access_check($conf, $context) {
  // Get current Time.
  $current_time = time();
  // Check if time even by division by two and the comparison with 0.
  $is_even = $current_time % 2 == 0;
  return !$is_even;
}
