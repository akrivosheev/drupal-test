<?php

/**
 * @file
 * Description of the plugin.
 */

$plugin = array(
  'title' => t('AK plug return video'),
  'description' => t('The output of video'),
  'render callback' => 'ak_plug_video_content_type_render',
  'edit form' => 'ak_plug_video_edit_form',
  'category' => t('Custom panes'),
  'single' => TRUE,
);

/**
 * Render callback for the content type.
 */
function ak_plug_video_content_type_render($subtype, $conf, $args, $context) {
  if (empty($conf['link'])) {
    return;
  }
  $block = new stdClass();
  $block->module = t('ak_plug_video');
  $result = ak_plug_convert_youtube($conf['link'], $conf['width'], $conf['height']);
  $block->content = $result;
  return $block;
}

/**
 * Converter.
 */
function ak_plug_convert_youtube($string, $width = 200, $height = 130) {
  return preg_replace(
    "/\s*[a-zA-Z\/\/:\.]*youtu(be.com\/watch\?v=|.be\/)([a-zA-Z0-9\-_]+)([a-zA-Z0-9\/\*\-\_\?\&\;\%\=\.]*)/i",
    "<iframe src=\"//www.youtube.com/embed/$2\" width=\"$width\" height=\"$height\" allowfullscreen></iframe>",
    $string
  );
}

/**
 * Edit form callback for the content type.
 */
function ak_plug_video_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['link'] = array(
    '#type' => 'textfield',
    '#title' => t('link to youtube'),
    '#default_value' => !empty($conf['link']) ? $conf['link'] : '',
  );
  $form['width'] = array(
    '#type' => 'textfield',
    '#title' => t('width of youtube'),
    '#default_value' => !empty($conf['width']) ? $conf['width'] : '',
  );
  $form['height'] = array(
    '#type' => 'textfield',
    '#title' => t('height of youtube'),
    '#default_value' => !empty($conf['height']) ? $conf['height'] : '',
  );

  return $form;
}

/**
 * Submit callback for the ak_plug_xnod_edit_form().
 */
function ak_plug_video_edit_form_submit($form, &$form_state) {

  $form_state['conf'] = array(
    'link' => $form_state['values']['link'],
    'width' => $form_state['values']['width'],
    'height' => $form_state['values']['height'],
  );
}
