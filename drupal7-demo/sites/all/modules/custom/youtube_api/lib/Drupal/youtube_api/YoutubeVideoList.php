<?php

namespace Drupal\youtube_api;

class YoutubeVideoList {
  protected $apiVersion;
  protected $apiFormat;
  protected $author;
  public $information;

  public function __construct($params = array()) {
    $this->apiVersion = (!empty($params['apiVersion'])) ? $params['apiVersion'] : 2;
    $this->apiFormat = (!empty($params['apiFormat'])) ? $params['apiFormat'] : 'json';
    $this->author = (!empty($params['author'])) ? $params['author'] : '';
    $this->information = (!empty($params['id'])) ? $params['id'] : NULL;

    // https://gdata.youtube.com/feeds/api/users/GoldenMoustacheVideo/uploads?v=2&alt=json
    $url = 'https://gdata.youtube.com/feeds/api/users/' . $this->author . '/uploads';

    // Prepare query for request.
    $query = array(
      'v' => $this->apiVersion,
      'alt' => $this->apiFormat,
      'max-results' => 15,
    );
    $url = url($url, array('query' => $query));
    dd('YoutubeVideoList - http request - ' . $url);

    $result = drupal_http_request($url);
    if (!isset($result->error)) {
      $response = $result->data;
      $response = json_decode($response);
      $this->information = $response;
    }
    // dpm($this->information);
  }

  public function getVideos() {
    $videos = array();
    if (!empty($this->information->feed->entry)) {
      foreach ($this->information->feed->entry as $video) {
        $title = $video->title->{'$t'};
        $id = $video->{'media$group'}->{'yt$videoid'}->{'$t'};
        $videos[] = l($title, 'videos/' . $id);
      }
    }
    return $videos;
  }

}
