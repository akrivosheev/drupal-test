<?php

/**
 * @file
 * Description of the plugin.
 */

$plugin = array(
  'title' => t('AK plug content type plugin'),
  'description' => t('The output a custom text.'),
  'render callback' => 'ak_plug_text_content_type_render',
  'category' => t('Custom panes'),
  'single' => TRUE,
);

/**
 * Render callback for the content type.
 */
function ak_plug_text_content_type_render($subtype, $conf, $args, $context) {

  $block = new stdClass();
  $block->module = t('test_form');
  $block->title = t('Contact form');
  $block->content = drupal_get_form('ak_contact_form');
  return $block;
}
