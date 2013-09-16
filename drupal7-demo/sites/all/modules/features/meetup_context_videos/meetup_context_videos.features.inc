<?php
/**
 * @file
 * meetup_context_videos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function meetup_context_videos_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
