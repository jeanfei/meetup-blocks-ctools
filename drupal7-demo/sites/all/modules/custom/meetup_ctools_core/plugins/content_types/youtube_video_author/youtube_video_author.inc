<?php
/**
 * @file
 * Ctools content type.
 */

/**
 * Implements hook_ctools_content_types().
 */
function meetup_ctools_core_youtube_video_author_ctools_content_types() {
  return array(
    'title' => t('Youtube : Video author'),
    'description' => t('Render information of the video author.'),
    'single' => TRUE,
    'category' => array(t('Meetup - Ctools'), 10),
    'required context' => new ctools_context_required(t('Youtube'), 'youtube_context'),
  );
}


/**
 * Run-time rendering of the body of the block.
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time.
 * @param $args
 * @param $context
 *   Context - in this case we don't have any.
 *
 * @return
 *   An object with at least title and content members.
 */
function meetup_ctools_core_youtube_video_author_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }
  // Get a shortcut to the node.
  $youtube = $context->data->youtube;


  $author = $youtube->getAuthor();
  $author_id = $youtube->getAuthorId();
  $videos_link = l($author_id, $youtube->getVideosUrlOfAuthor());

  // Build the content type block.
  $block = new stdClass();
  $block->title   = t('Author information');
  $block->content = $videos_link;

  return $block;
}
