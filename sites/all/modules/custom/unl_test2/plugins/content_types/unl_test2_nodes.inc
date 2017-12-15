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

  $result = db_select('node', 'n')
    ->fields('n', ['nid'])
    ->condition('status', 1)
    ->execute()
    ->fetchAllAssoc('nid');
  $content = '';
  if (isset($result)) {
    $nodes = entity_load('node', array_rand($result, 3));
    $content = drupal_render(
      node_view_multiple(
        $nodes
      )
    );

  }
  $block = new stdClass();
  $block->module = t('unl_test2');
  $block->title = t('3 nodes Title');
  $block->content = $content;
  return $block;
}
