<?php

/**
 * @file
 * Description of the plugin.
 */

$plugin = array(
  'title' => t('Unl Test 2 content type plugin'),
  'description' => t('The output 3 random node'),
  'render callback' => 'unl_test2_content_type_render',
  'category' => t('Custom panes'),
  'single' => TRUE,
);

/**
 * Render callback for the content type.
 */
function unl_test2_content_type_render($subtype, $conf, $args, $context) {

  $nid = 4;
  $node = node_load($nid);
  kpr($node);
  $block = new stdClass();
  $block->module = t('unl_test');
  $block->title = t('Links list');
  $block->content = 'fgddfgdfgdfg';
  return $block;
}
