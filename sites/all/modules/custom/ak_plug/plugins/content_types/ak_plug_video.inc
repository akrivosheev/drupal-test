<?php

/**
 * @file
 * Description of the plugin.
 */

$plugin = array(
  'title' => t('AK plug return video'),
  'description' => t('The output of video'),
  'render callback' => 'ak_plug_video_content_type_render',
  'edit form' => 'ak_plug_video_edit_form',
  'category' => t('Custom panes'),
  'single' => TRUE,
);

/**
 * Render callback for the content type.
 */
function ak_plug_video_content_type_render($subtype, $conf, $args, $context) {
  if (empty($conf['link'])) {
    return;
  }
  $block = new stdClass();
  $block->module = t('ak_plug_video');

  $link = ak_plug_convert_video_link($conf['link']);
  if (!$link) {
    return;
  }
  $width = $conf['width'];
  $height = $conf['height'];

  $block->content = "<iframe src=$link width=\"$width\" height=\"$height\" allowfullscreen></iframe>";
  return $block;
}

/**
 * Convert simple link to embed.
 *
 * @param string $url
 *   The url.
 *
 * @return null|string
 *   Null on failure to match, the service's name on success.
 */
function ak_plug_convert_video_link($url) {
  if (preg_match('%youtube|youtu\.be%i', $url)) {
    $youtube_url_keys = array('v', 'vi');
    // Try to get ID from url parameters.
    $key_from_params = ak_plug_parse_url_for_params($url, $youtube_url_keys);
    if ($key_from_params) {
      $youtube_video_id = $key_from_params;
    }
    else {
      $youtube_video_id = ak_plug_parse_url_for_last_element($url);
    }
    $embed = "http://youtube.com/embed/$youtube_video_id?autoplay=1";
    return $embed;
  }
  elseif (preg_match('%vimeo%i', $url)) {
    $vimeo_video_id = ak_plug_parse_url_for_last_element($url);
    $embed = "http://player.vimeo.com/video/$vimeo_video_id?byline=0&amp;portrait=0&amp;autoplay=1";
    return $embed;
  }
  return NULL;
}

/**
 * Find the last element in a url, without any trailing parameters.
 *
 * @param string $url
 *   The url.
 *
 * @return string
 *   The last element of the url
 */
function ak_plug_parse_url_for_last_element($url) {
  $url_parts = explode("/", $url);
  $prospect = end($url_parts);
  $prospect_and_params = preg_split("/(\?|\=|\&)/", $prospect);
  if ($prospect_and_params) {
    return $prospect_and_params[0];
  }
  else {
    return $prospect;
  }

}

/**
 * Get parse url for params.
 *
 * @return null|string
 *   return parse url params
 */
function ak_plug_parse_url_for_params($url, $target_params) {

  parse_str(parse_url($url, PHP_URL_QUERY), $my_array_of_params);
  foreach ($target_params as $target) {
    if (array_key_exists($target, $my_array_of_params)) {
      return $my_array_of_params[$target];
    }
  }
  return NULL;
}

/**
 * Edit form callback for the content type.
 */
function ak_plug_video_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['link'] = array(
    '#type' => 'textfield',
    '#title' => t('link to youtube'),
    '#default_value' => !empty($conf['link']) ? $conf['link'] : '',
  );
  $form['width'] = array(
    '#type' => 'textfield',
    '#title' => t('width of youtube'),
    '#default_value' => !empty($conf['width']) ? $conf['width'] : '',
  );
  $form['height'] = array(
    '#type' => 'textfield',
    '#title' => t('height of youtube'),
    '#default_value' => !empty($conf['height']) ? $conf['height'] : '',
  );

  return $form;
}

/**
 * Submit callback for the ak_plug_xnod_edit_form().
 */
function ak_plug_video_edit_form_submit($form, &$form_state) {

  $form_state['conf'] = array(
    'link' => $form_state['values']['link'],
    'width' => $form_state['values']['width'],
    'height' => $form_state['values']['height'],
  );
}
