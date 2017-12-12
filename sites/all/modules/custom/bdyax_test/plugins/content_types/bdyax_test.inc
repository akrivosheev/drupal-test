<?php

/**
 * @file
 * Description of the plugin.
 */

$plugin = array(
  'title' => t('Add content type plugin with TRUE/FALSE'),
  'description' => t('The output a custom text.'),
  'render callback' => 'bdyax_test_text_content_type_render',
  'category' => t('Custom panes'),
  'single' => TRUE,
);

/**
 * Render callback for the content type.
 */
function bdyax_test_text_content_type_render($subtype, $conf, $args, $context) {

  $block = new stdClass();
  $block->module = t('bdyax_test');
  // Get current Time.
  $current_time = time();
  // Check if time even by division by two and the comparison with 0.
  $is_even = $current_time % 2 == 0;
  $content = 'TRUE';
  if ($is_even) {
    $content = 'FALSE';
  }
  $block->content = $content;
  return $block;
}
