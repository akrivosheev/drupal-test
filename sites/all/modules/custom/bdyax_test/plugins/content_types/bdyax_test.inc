<?php

/**
 * @file
 * Description of the plugin.
 */

$plugin = array(
  'title' => t('Add content type plugin with TRUE/FALSE dependent from context'),
  'description' => t('The output a custom text.'),
  'render callback' => 'bdyax_test_text_content_type_render',
  'category' => t('Custom panes'),
  'all contexts' => TRUE,
  'required context' => new ctools_context_required(t('Add context plugin with TRUE/FALSE'), 'bdyax_test'),
  'single' => TRUE,
);

/**
 * Render callback for the content type.
 */
function bdyax_test_text_content_type_render($subtype, $conf, $args, $context) {

  $block = new stdClass();
  $block->module = t('bdyax_test');
  foreach ($context as $item) {
    if ($item->type == 'bdyax_test') {
      $block->content = var_export($item->is_even, TRUE);
      break;
    }
  }
  return $block;
}
