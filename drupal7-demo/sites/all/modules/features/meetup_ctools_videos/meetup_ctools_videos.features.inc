<?php
/**
 * @file
 * meetup_ctools_videos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function meetup_ctools_videos_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
