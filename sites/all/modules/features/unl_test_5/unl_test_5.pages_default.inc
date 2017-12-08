<?php
/**
 * @file
 * unl_test_5.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function unl_test_5_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'unl_test';
  $page->task = 'page';
  $page->admin_title = 'Unl Test';
  $page->admin_description = '';
  $page->path = 'test5';
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
  $handler->name = 'page_unl_test__panel';
  $handler->task = 'page';
  $handler->subtask = 'unl_test';
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
  $display->title = 'Unl test';
  $display->uuid = '98891653-530d-4051-b5d4-04f40128e8d2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_unl_test__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-585b00e1-70d0-45af-8042-ebf99c12638d';
  $pane->panel = 'center';
  $pane->type = 'unl_test_links';
  $pane->subtype = 'unl_test_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'text' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '585b00e1-70d0-45af-8042-ebf99c12638d';
  $display->content['new-585b00e1-70d0-45af-8042-ebf99c12638d'] = $pane;
  $display->panels['center'][0] = 'new-585b00e1-70d0-45af-8042-ebf99c12638d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-585b00e1-70d0-45af-8042-ebf99c12638d';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['unl_test'] = $page;

  return $pages;

}
