<?php

/**
 * @file
 *
 * Sample plugin to provide an argument handler for a youtubecontext.
 *
 * Given any argument to the page, youtubecontext will get it
 * and turn it into a piece of data (a "context") just by adding some text to it.
 * Normally, the argument would be a key into some database (like the node
 * database, for example, and the result of using the argument would be to load
 * a specific "context" or data item that we can use elsewhere.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Youtube id"),
  // keyword to use for %substitution
  'keyword' => 'youtube',
  'description' => t('Creates a "youtubecontext" from the arg.'),
  'context' => 'youtube_id_context',
  // 'settings form' => 'simplecontext_arg_settings_form',

  // placeholder_form is used in panels preview, for example, so we can
  // preview without getting the arg from a URL
  'placeholder form' => array(
    '#type' => 'textfield',
    '#description' => t('Enter the youtube id'),
  ),
);

/**
 * Get the simplecontext context using the arg. In this case we're just going
 * to manufacture the context from the data in the arg, but normally it would
 * be an API call, db lookup, etc.
 */
function youtube_id_context($arg = NULL, $conf = NULL, $empty = FALSE) {
  // If $empty == TRUE it wants a generic, unfilled context.
  if ($empty) {
    return ctools_context_create_empty('youtube_context');
  }
  // Do whatever error checking is required, returning FALSE if it fails the test
  // Normally you'd check
  // for a missing object, one you couldn't create, etc.
  if (empty($arg)) {
    return FALSE;
  }
  return ctools_context_create('youtube_context', $arg);
}
