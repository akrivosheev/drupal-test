<?php

/**
 * @file
 * Description of the plugin.
 */

$plugin = array(
  'title' => t('Add context plugin with TRUE/FALSE'),
  'description' => t('The output true or false dependent from time'),
  'context' => 'bdyax_test_context_plugin',
  'keyword' => 'bdyax_test',
  'context name' => 'bdyax_test',
);

/**
 * Render callback for the content type.
 */
function bdyax_test_context_plugin($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('bdyax_test');
  // Get current Time.
  $current_time = time();
  // Check if time even by division by two and the comparison with 0.
  $is_even = $current_time % 2 == 0;
  $context->is_even = $is_even;
  return $context;
}
