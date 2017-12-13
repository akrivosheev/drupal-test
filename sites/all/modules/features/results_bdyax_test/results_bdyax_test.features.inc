<?php
/**
 * @file
 * results_bdyax_test.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function results_bdyax_test_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
