<?php

/**
 * @file
 * Description of the plugin.
 */

$plugin = array(
  'title' => t('Unl Test content type plugin'),
  'description' => t('The output list of links'),
  'render callback' => 'unl_test_content_type_render',
  'category' => t('Custom panes'),
  'single' => TRUE,
);

/**
 * Render callback for the content type.
 */
function unl_test_content_type_render($subtype, $conf, $args, $context) {
  drupal_add_library('system', 'drupal.ajax');
  ctools_add_js('changeColor', 'unl_test');

  $block = new stdClass();
  $block->module = t('unl_test');
  $block->title = t('Links list');

  $block->content = theme('item_list', array(
    'content' => menu_load_links('main-menu'),
  ));
  $block->content = theme('links', array('links' => menu_main_menu(), 'attributes' => array('class' => 'links main-links')));
  return $block;
}
