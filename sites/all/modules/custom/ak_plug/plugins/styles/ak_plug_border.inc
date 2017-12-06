<?php

/**
 * @file
 * Definition of the 'border' panel style.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Red border style'),
  'description' => t('This rendering style displays all pane with a red border.'),
  'render region' => 'ak_plug_border_style_render_region',
  'render pane' => 'ak_plug_border_style_render_pane',
  'hook theme' => array(
    'red-border' => array(
      'variables' => array('content' => NULL),
      'path' => drupal_get_path('module', 'ak_plug') . '/plugins/styles',
      'template' => 'red-border',
    ),
    'blue-border' => array(
      'variables' => array('content' => NULL),
      'path' => drupal_get_path('module', 'ak_plug') . '/plugins/styles',
      'template' => 'blue-border',
    ),
  ),
);

/**
 * Render region.
 */
function theme_ak_plug_border_style_render_region($vars) {

  drupal_add_css(drupal_get_path('module', 'ak_plug') . '/css/new.css');
  $panes = $vars['panes'];
  $output = theme('red-border', array('content' => $panes));
  return $output;
}

/**
 * Render pane.
 */
function theme_ak_plug_border_style_render_pane($vars) {

  $output = '';
  $content = $vars['content'];
  $content->css_class .= 'red-border';
  if (!empty($vars['content']->content)) {
    $output = theme('panels_pane', array(
      'content' => $vars['content'],
      'pane' => $vars['pane'],
      'display' => $vars['display'],
    ));

    // Just stick a box around the standard theme_panels_pane.
    $output = theme('blue-border', array('content' => $output));
  }

  return $output;
}
