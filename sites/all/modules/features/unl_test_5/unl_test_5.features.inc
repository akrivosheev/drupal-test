<?php
/**
 * @file
 * unl_test_5.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function unl_test_5_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
