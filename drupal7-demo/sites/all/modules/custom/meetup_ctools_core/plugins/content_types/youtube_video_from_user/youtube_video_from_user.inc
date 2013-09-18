<?php
/**
 * @file
 * Ctools content type.
 */

/**
 * Implements hook_ctools_content_types().
 */
function meetup_ctools_core_youtube_video_from_user_ctools_content_types() {
  return array(
    'title' => t('Youtube : Video from user'),
    'description' => t('Render list of videos of a user.'),
    'single' => TRUE,
    'category' => array(t('Meetup - Ctools'), 10),
    'edit form' => 'meetup_ctools_core_youtube_video_from_user_edit_form',
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
function meetup_ctools_core_youtube_video_from_user_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  if (!empty($conf)) {
    $youtube_user_id = $conf['youtube_user_id'];
    $params = array();
    $params['author'] = $youtube_user_id;
    $youtube = new Drupal\youtube_api\YoutubeVideoList($params);
    $videos = $youtube->getVideos();

    // Build the content type block.
    $block = new stdClass();
    $block->title = t('Last videos of ' . $youtube_user_id);
    $block->content = theme('item_list', array('items' => $videos));
  }

  return $block;
}



/**
 * 'Edit' callback for the content type.
 * This example just returns a form.
 *
 */
function meetup_ctools_core_youtube_video_from_user_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['youtube_user_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Youtube user id'),
    '#size' => 50,
    '#required' => TRUE,
    '#default_value' => !empty($conf['youtube_user_id']) ? $conf['youtube_user_id'] : '',
  );

  return $form;
}

function meetup_ctools_core_youtube_video_from_user_edit_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
