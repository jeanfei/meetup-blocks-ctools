<?php
/**
 * @file
 * meetup_ctools_videos.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function meetup_ctools_videos_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'videos_youtube';
  $page->task = 'page';
  $page->admin_title = 'videos youtube';
  $page->admin_description = '';
  $page->path = 'videos/youtube/%youtube-id';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'youtube-id' => array(
      'id' => 1,
      'identifier' => 'Youtube id',
      'name' => 'youtube_id',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_videos_youtube_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'videos_youtube';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Videos page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'meetup_ctools_core_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%youtube-id:title - %youtube-id:author_name	';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'youtube_video_embed';
    $pane->subtype = 'youtube_video_embed';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['middle'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'middle';
    $pane->type = 'youtube_video_description';
    $pane->subtype = 'youtube_video_description';
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
    $display->content['new-2'] = $pane;
    $display->panels['middle'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'middle';
    $pane->type = 'youtube_video_from_user';
    $pane->subtype = 'youtube_video_from_user';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_youtube_id_1',
      'form_build_id' => 'form-_wyc6-YaEOWWCjGkrj4r4s3XAnHrqoFATyHasnl3m2o',
      'form_token' => 'dje1m3HiPSGLqWb43i7PwrtBZsA_0pFmMDUBm5rW7GI',
      'form_id' => 'meetup_ctools_core_youtube_video_from_user_edit_form',
      'override_title' => 0,
      'override_title_text' => '',
      'youtube_user_id' => 'drupalfacile',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['middle'][2] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'middle';
    $pane->type = 'youtube_video_from_user';
    $pane->subtype = 'youtube_video_from_user';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_youtube_id_1',
      'youtube_user_id' => 'GuinnessWorldRecords',
      'form_build_id' => 'form-xzou2Z7pN8s_2zr7HhxnCuCXgvf7ycu6cVCqi4Q8EZM',
      'form_token' => 'dje1m3HiPSGLqWb43i7PwrtBZsA_0pFmMDUBm5rW7GI',
      'form_id' => 'meetup_ctools_core_youtube_video_from_user_edit_form',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['middle'][3] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'right';
    $pane->type = 'youtube_video_author';
    $pane->subtype = 'youtube_video_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array(
      'type' => 'none',
      'regions' => array(
        'right' => 'right',
      ),
    );
    $display->content['new-5'] = $pane;
    $display->panels['right'][0] = 'new-5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['videos_youtube'] = $page;

  return $pages;

}
