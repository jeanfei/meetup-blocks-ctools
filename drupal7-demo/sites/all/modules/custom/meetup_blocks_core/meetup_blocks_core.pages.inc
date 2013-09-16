<?php

/**
 * Retrieves video youtube
 * @param  string $video_id video id
 * @return html             embed of the video
 */
function meetup_blocks_core_video($video_id = NULL) {
  dd('Generate video content');
  $youtube = meetup_blocks_core_video_load($video_id);

  // Set title of the page.
  $title = $youtube->getTitle();
  drupal_set_title($title);

  // Get embed, published date, and description of the video.
  $embed = $youtube->getEmbed();
  $published_date = $youtube->getPublishedDate();
  $description = $youtube->getDescription();

  $content = '<div class="video-embed">' . $embed . '</div>';
  $content .= '<p class="video-published">Publié le ' . $published_date . '</p>';
  $content .= '<p class="video-description">' . $description . '</p>';

  return $content;
}
