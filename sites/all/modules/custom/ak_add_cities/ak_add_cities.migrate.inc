<?php

/**
 * @file
 * File.
 */

/**
 * Implements hook_migrate_api().
 */
function ak_add_cities_migrate_api() {
  return array(
    'api' => 2,
    'groups' => array(
      'cities' => array(
        'title' => 'Cities',
      ),
      'countries' => array(
        'title' => 'Countries',
      ),
    ),
    'migrations' => array(
      'Cities' => array(
        'class_name' => 'CitiesMigration',
        'group_name' => 'cities',
      ),
      'Countries' => array(
        'class_name' => 'CountriesMigration',
        'group_name' => 'countries',
      ),
    ),
  );
}
