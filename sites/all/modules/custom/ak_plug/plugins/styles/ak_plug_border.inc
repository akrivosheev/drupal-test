<?php

/**
 * @file
 * Definition of the 'border' panel style.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Red border style'),
  'description' => t('This rendering style displays each pane with a red border.'),
  'render region' => 'ak_plug_border_style_render_region',
  'hook theme' => array(
    'red-border' => array(
      'variables' => array('content' => NULL),
      'path' => drupal_get_path('module', $module) . '/plugins/styles',
      'template' => 'red-border',
    ),
  ),
);

/**
 * Render callback.
 */
function theme_ak_plug_border_style_render_region($vars) {
  drupal_add_css(drupal_get_path('module', 'ak_plug') . '/css/new.css');
  $panes = $vars['panes'];
  $output = theme('red-border', array('content' => $panes));
  return $output;
}
