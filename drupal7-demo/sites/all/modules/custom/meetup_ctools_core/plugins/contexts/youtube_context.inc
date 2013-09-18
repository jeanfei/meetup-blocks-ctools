<?php


/**
 * @file
 * Sample ctools context type plugin that shows how to create a context from an arg.
 *
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Youtube context"),
  'description' => t('A single "youtube" context, or data element.'),
  'context' => 'meetup_ctools_core_context_create_youtube_context',  // func to create context
  'context name' => 'youtube_context',
  'keyword' => 'youtube_context',

  // Provides a list of items which are exposed as keywords.
  'convert list' => 'youtube_context_convert_list',
  // Convert keywords into data.
  'convert' => 'youtube_context_convert',

  'placeholder form' => array(
    '#type' => 'textfield',
    '#description' => t('Enter some data to represent this "youtube context".'),
  ),
);

/**
 * Create a context, either from manual configuration or from an argument on the URL.
 *
 * @param $empty
 *   If true, just return an empty context.
 * @param $data
 *   If from settings form, an array as from a form. If from argument, a string.
 * @param $conf
 *   TRUE if the $data is coming from admin configuration, FALSE if it's from a URL arg.
 *
 * @return
 *   a Context object/
 */
function meetup_ctools_core_context_create_youtube_context($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('youtube_context');
  $context->plugin = 'youtube_context';

  if ($empty) {
    return $context;
  }

  $video_id = $data;
  $params = array();
  $params['id'] = $video_id;
  $youtube = new Drupal\youtube_api\YoutubeVideo($params);

  $author_name = $youtube->getAuthor();
  $author_id = $youtube->getAuthorId();
  $title = $youtube->getTitle();

  $context->data = new stdClass();
  $context->data->title = $title;
  $context->data->youtube_id = $video_id;
  $context->data->author_name = $author_name;
  $context->data->author_id = $author_id;
  $context->data->youtube = $youtube;

  return $context;
}


/**
 * Provide a list of sub-keywords.
 *
 * This is used to provide keywords from the context for use in a content type,
 * pane, etc.
 */
function youtube_context_convert_list() {
  return array(
    'title' => t('Youtube video title'),
    'youtube_id' => t('Youtube video id'),
    'author_name' => t('Youtube author name'),
    'author_id' => t('Youtube author username'),
  );
}

/**
 * Convert a context into a string to be used as a keyword by content types, etc.
 */
function youtube_context_convert($context, $type) {
  switch ($type) {
    case 'title':
      return $context->data->title;
    case 'youtube_id':
      return $context->data->youtube_id;
    case 'author_name':
      return $context->data->author_name;
    case 'author_id':
      return $context->data->author_id;
  }
}

