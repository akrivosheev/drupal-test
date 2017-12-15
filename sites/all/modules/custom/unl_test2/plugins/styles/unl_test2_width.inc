<?php

/**
 * @file
 * Definition of the 'border' panel style.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Width style'),
  'description' => t('This rendering style displays all pane with a width'),
  'render region' => 'unl_test2_width_style_render_region',
  'render pane' => 'unl_test2_width_style_render_pane',
  'hook theme' => array(
    'width-region' => array(
      'variables' => array('content' => NULL),
      'path' => drupal_get_path('module', 'unl_test2') . '/plugins/styles',
      'template' => 'width-region',
    ),
    'width-pane' => array(
      'variables' => array('content' => NULL),
      'path' => drupal_get_path('module', 'unl_test2') . '/plugins/styles',
      'template' => 'width-pane',
    ),
  ),
);

/**
 * Render region.
 */
function theme_unl_test2_width_style_render_region($vars) {

  drupal_add_css(drupal_get_path('module', 'unl_test2') . '/css/width.css');
  $panes = $vars['panes'];
  $output = theme('width-region', array('content' => $panes));
  return $output;
}

/**
 * Render pane.
 */
function theme_unl_test2_width_style_render_pane($vars) {
  $output = '';
  if (!empty($vars['content']->content)) {
    $output = theme('panels_pane', array(
      'content' => $vars['content'],
      'pane' => $vars['pane'],
      'display' => $vars['display'],
    ));

    // Just stick a box around the standard theme_panels_pane.
    $output = theme('width-pane', array('content' => $output));
  }
  return $output;
}
