<?php

namespace Drupal\youtube_api;

class YoutubeVideo {
  protected $apiVersion;
  protected $apiFormat;
  protected $id;
  public $information;

  public function __construct($params = array()) {
    $this->apiVersion = (!empty($params['apiVersion'])) ? $params['apiVersion'] : 2;
    $this->apiFormat = (!empty($params['apiFormat'])) ? $params['apiFormat'] : 'json';
    $this->id = (!empty($params['id'])) ? $params['id'] : '';
    $this->information = (!empty($params['id'])) ? $params['id'] : NULL;

    // https://gdata.youtube.com/feeds/api/videos/QPKs25gD2XM?v=2&alt=json
    $base_url = 'https://gdata.youtube.com/feeds/api/videos/';
    $url = $base_url . $this->id;

    // Prepare query for request.
    $query = array(
      'v' => $this->apiVersion,
      'alt' => $this->apiFormat,
    );
    $url = url($url, array('query' => $query));
    dd('http request : ' . $url);

    $result = drupal_http_request($url);
    if (!isset($result->error)) {
      $response = $result->data;
      $response = json_decode($response);
      $this->information = $response;
    }
    // dpm($this->information);
  }


  public function getTitle() {
    if (!empty($this->information->entry->title->{'$t'})) {
      return $this->information->entry->title->{'$t'};
    }
    return '';
  }


  public function getEmbed($params = array()) {
    $width = (!empty($params['width']) && is_numeric($params['width'])) ? $params['width'] : '640';
    $height = (!empty($params['height']) && is_numeric($params['height'])) ? $params['height'] : '360';
    // http://www.youtube.com/embed/QPKs25gD2XM
    $url = 'http://www.youtube.com/embed/' . $this->id;

    return '<iframe width="' . $width . '" height="' . $height . '" src="' . $url . '" frameborder="0" allowfullscreen></iframe>';
  }


  public function getDescription() {
    if (!empty($this->information->entry->{'media$group'}->{'media$description'}->{'$t'})) {
      return $this->information->entry->{'media$group'}->{'media$description'}->{'$t'};
    }
    return '';
  }


  public function getPublishedDate() {
    if (!empty($this->information->entry->{'published'}->{'$t'})) {
      $date = $this->information->entry->{'published'}->{'$t'};
      $date = strtotime($date);
      return date('d/m/Y - H:i', $date);
    }
    return '';
  }


  public function getViewCount() {
    if (!empty($this->information->entry->{'yt$statistics'}->viewCount)) {
      $view_count = $this->information->entry->{'yt$statistics'}->viewCount;
      $result = number_format($view_count, 0, ',', ' ');
      return $result;
    }
    return '';
  }


  public function getNumLikes() {
    if (!empty($this->information->entry->{'yt$rating'}->numLikes)) {
      $num_likes = $this->information->entry->{'yt$rating'}->numLikes;
      $result = number_format($num_likes, 0, ',', ' ');
      return $result;
    }
    return '';
  }


  public function getAuthor() {
    if (!empty($this->information->entry->author[0]->name->{'$t'})) {
      return $this->information->entry->author[0]->name->{'$t'};
    }
    return '';
  }


  public function getAuthorId() {
    if (!empty($this->information->entry->{'media$group'}->{'media$credit'}[0]->{'$t'})) {
      return $this->information->entry->{'media$group'}->{'media$credit'}[0]->{'$t'};
    }
    return '';
  }


  public function getVideosUrlOfAuthor() {
    // https://www.youtube.com/user/DrupalFacile/videos
    $author_id = $this->getAuthorId();
    return 'https://www.youtube.com/user/' . $author_id . '/videos';
  }


  public function getVideosUrl() {
    // https://www.youtube.com/watch?v=QPKs25gD2XM
    return 'https://www.youtube.com/watch?v=' . $this->id;
  }
}
