<?php

/**
 * Renders the MBTA where's my train view.
 * endpoint: mbta/wheresmytrain
 *
 */
function mbta_wheresmytrain() {
  $stop = $_GET['stop'];
  $data = drupal_http_request('http://developer.mbta.com/lib/rthr/red.json');

  $data = $data->data;
  $data = json_decode($data);
  $trips = $data->TripList->Trips;
  $arrivals = array();
  foreach ($trips as $trip) {
    foreach ($trip->Predictions as $prediction) {
      
      if ($prediction->Stop == $stop) {
        $arrivals[$trip->Destination][] = $prediction->Seconds;
      }
    }
  }

  return theme_item_list($arrivals, 'Where\'s My Train');
}
