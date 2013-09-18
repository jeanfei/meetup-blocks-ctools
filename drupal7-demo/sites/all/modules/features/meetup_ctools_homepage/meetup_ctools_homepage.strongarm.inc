<?php
/**
 * @file
 * meetup_ctools_homepage.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function meetup_ctools_homepage_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'homepage';
  $export['site_frontpage'] = $strongarm;

  return $export;
}
