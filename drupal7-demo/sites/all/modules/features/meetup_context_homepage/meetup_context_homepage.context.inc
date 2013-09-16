<?php
/**
 * @file
 * meetup_context_homepage.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function meetup_context_homepage_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'Provides list of blocks in the homepage';
  $context->tag = 'homepage';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'meetup_blocks_core-video_list_drupalfacile' => array(
          'module' => 'meetup_blocks_core',
          'delta' => 'video_list_drupalfacile',
          'region' => 'content',
          'weight' => '-10',
        ),
        'meetup_blocks_core-video_list_goldenmoustachevideo' => array(
          'module' => 'meetup_blocks_core',
          'delta' => 'video_list_goldenmoustachevideo',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Provides list of blocks in the homepage');
  t('homepage');
  $export['homepage'] = $context;

  return $export;
}
