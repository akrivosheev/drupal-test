<?php

/**
 * @file
 * Description of the plugin.
 */

$plugin = array(
  'title' => t('AK plug content type plugin'),
  // Название плагина, отображаемое при его выборе.
  'description' => t('The output a custom text.'),
  // Описание плагина, отображаемое при его выборе.
  'render callback' => 'ak_plug_text_content_type_render',
  // Форма с настройками плагина.
  'category' => t('Custom panes'),
  // Категория, в которой будет находиться плагин.
  'single' => TRUE,
  // Флаг, указывающий является ли плагин подтипом другого.
);

/**
 * Render callback for the content type.
 */
function ak_plug_text_content_type_render($subtype, $conf, $args, $context) {

  // Если в настройках плагина не ввели текст, то ничего не выводим.
  if (empty($context) || empty($context->data)) {
    return;
  }

  return 'Something';
}
