<?php

/**
 * @file
 * Description of the plugin.
 */

$plugin = array(
  'title' => t('Unl Test content type plugin'),
  'description' => t('The output list of links'),
  'render callback' => 'unl_test_content_type_render',
  'edit form' => 'unl_test_edit_form',
  'category' => t('Custom panes'),
  'single' => TRUE,
);

/**
 * Render callback for the content type.
 */
function unl_test_content_type_render($subtype, $conf, $args, $context) {
  drupal_add_library('system', 'drupal.ajax');
  drupal_add_library('system', 'jquery.form');
  $block = new stdClass();
  $block->module = t('unl_test');
  $block->title = t('Links list');
  $ajax_link = l(t('change color'), 'color_links/nojs', array(
    'attributes' => array(
      'class' => array('use-ajax'),
      'title' => 'Change color',
    ),
  )
  );
  $block->content = theme('unl_test', array('content' => menu_load_links('main-menu'), 'ajax_link' => $ajax_link));
  return $block;
}
