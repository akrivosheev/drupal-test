<?php

/**
 * @file
 * Plugin to provide access control based on user themeission strings.
 */

/**
 * Plugins are described by creating a $plugin array which will be used.
 */
$plugin = array(
  'title' => t('Only even'),
  'description' => t('Control access by checking which minutes'),
  'callback' => 'ak_plug_even_ctools_access_check',
);

/**
 * Check for access.
 */
function ak_plug_even_ctools_access_check($conf, $context) {
  // Get current Time.
  $current_time = time();
  // Get current Minute by format time.
  $current_minute = format_date($current_time, 'custom', 'i');
  // Check if minute even by division by two and the comparison with 0.
  $is_even_minute = $current_minute % 2 == 0;
  return $is_even_minute;
}
