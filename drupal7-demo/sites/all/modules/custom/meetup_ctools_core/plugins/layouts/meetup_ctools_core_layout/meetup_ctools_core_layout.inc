<?php

/**
 * implementation of hook_panels_layouts
 */
// Plugin definition
$plugin = array(
  'title' => t('Meetup ctools core layout'),
  'category' => t('Meetup - Ctools'),
  'icon' => 'meetup_ctools_core_layout.png',
  'theme' => 'meetup_ctools_core_layout',
  'css' => 'meetup_ctools_core_layout.css',
  'admin css' => 'meetup_ctools_core_layout_admin.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side'),
    'middle' => t('Middle column'),
    'right' => t('Right side'),
    'bottom' => t('Bottom'),
  ),
);
