<?php
/**
 * @file
 * meetup_context_videos.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function meetup_context_videos_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'videos';
  $context->description = 'Provides list of blocks in videos page';
  $context->tag = 'videos';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'videos/*' => 'videos/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'meetup_blocks_core-author' => array(
          'module' => 'meetup_blocks_core',
          'delta' => 'author',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'meetup_blocks_core-statistics' => array(
          'module' => 'meetup_blocks_core',
          'delta' => 'statistics',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'meetup_blocks_core-youtube' => array(
          'module' => 'meetup_blocks_core',
          'delta' => 'youtube',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Provides list of blocks in videos page');
  t('videos');
  $export['videos'] = $context;

  return $export;
}
