<?php

/**
 * Renders the Google Civic voterinfo view.
 * endpoint: mbta/wheresmytrain
 *
 */
function mbta_wheresmytrain($stop) {
  $data = drupal_http_request('http://developer.mbta.com/lib/rthr/red.json');
  $data = $data->data;
  $data = json_decode($data);
  $trips = $data->TripList->Trips;

  foreach($trips as $trip) {

  }
  return $stop;
}