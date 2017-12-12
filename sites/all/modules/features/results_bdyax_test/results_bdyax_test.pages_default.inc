<?php
/**
 * @file
 * results_bdyax_test.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function results_bdyax_test_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'test3';
  $page->task = 'page';
  $page->admin_title = 'test3';
  $page->admin_description = '';
  $page->path = 'test3';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_test3__panel';
  $handler->task = 'page';
  $handler->subtask = 'test3';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'test3';
  $display->uuid = 'a1951605-9240-4a4c-9317-4fd31c50a4e2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_test3__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b63b84c2-906e-4b22-9e01-567cde2562b1';
  $pane->panel = 'center';
  $pane->type = 'bdyax_test';
  $pane->subtype = 'bdyax_test';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'bdyax_test',
        'settings' => NULL,
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b63b84c2-906e-4b22-9e01-567cde2562b1';
  $display->content['new-b63b84c2-906e-4b22-9e01-567cde2562b1'] = $pane;
  $display->panels['center'][0] = 'new-b63b84c2-906e-4b22-9e01-567cde2562b1';
  $pane = new stdClass();
  $pane->pid = 'new-f9c6eccd-0033-479e-aa3b-a4dabace9eb8';
  $pane->panel = 'center';
  $pane->type = 'bdyax_test';
  $pane->subtype = 'bdyax_test';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f9c6eccd-0033-479e-aa3b-a4dabace9eb8';
  $display->content['new-f9c6eccd-0033-479e-aa3b-a4dabace9eb8'] = $pane;
  $display->panels['center'][1] = 'new-f9c6eccd-0033-479e-aa3b-a4dabace9eb8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b63b84c2-906e-4b22-9e01-567cde2562b1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['test3'] = $page;

  return $pages;

}
