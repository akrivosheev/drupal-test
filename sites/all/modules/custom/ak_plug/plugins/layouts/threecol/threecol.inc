<?php

/**
 * @file
 * Plugin definition.
 */

$plugin = array(
  'title' => t('Three column'),
  'category' => t('Custom category'),
  'icon' => 'threecol.png',
  'theme' => 'panels_threecol',
  'css' => 'threecol.css',
  'regions' => array(
    '11' => t('Left side first line'),
    '12' => t('Middle column first line'),
    '13' => t('Right side first line'),
    '21' => t('Left side second line'),
    '22' => t('Middle column second line'),
    '23' => t('Right side second line'),
    '31' => t('Left side third line'),
    '32' => t('Middle column third line'),
    '33' => t('Right side third line'),
  ),
);
