<?php

/**
 * @file
 * Description of the plugin.
 */

$plugin = array(
  'title' => t('AK plug return x nods'),
  'description' => t('The output of option number of nods'),
  'render callback' => 'ak_plug_xnod_content_type_render',
  'edit form' => 'ak_plug_xnod_edit_form',
  'category' => t('Custom panes'),
  'single' => TRUE,
);

/**
 * Render callback for the content type.
 */
function ak_plug_xnod_content_type_render($subtype, $conf, $args, $context) {

  if (empty($conf['text']) || !is_numeric($conf['text']) || $conf['text'] < 0) {
    return;
  }
  $nodes = db_select('node', 'n')
    ->fields('n', array('nid', 'title', 'created'))
    ->condition('n.type', 'book')
    ->range(0, (int) $conf['text'])
    ->execute()
    ->fetchAllAssoc('nid');
  $block = new stdClass();
  $block->module = t('xnod');
  $block->title = $conf['text'] . ' books';
  $result = '';
  foreach ($nodes as $node) {
    $result .= $node->title . "\n" . format_date($node->created, 'custom', 'Y-m-d H:i:s', 'UTC') . '<br>';
  }
  $block->content = $result;
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function ak_plug_xnod_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['text'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of books'),
    '#default_value' => !empty($conf['text']) ? $conf['text'] : '',
  );

  return $form;
}

/**
 * Submit callback for the ak_plug_xnod_edit_form().
 */
function ak_plug_xnod_edit_form_submit($form, &$form_state) {

  $form_state['conf'] = array(
    'text' => $form_state['values']['text'],
  );
}
