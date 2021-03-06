<?php

/**
 * Renders the MBTA where's my train view.
 * endpoint: mbta/wheresmytrain
 *
 */
function mbta_wheresmytrain() {
  $stop = $_GET['stop'];
  $line = $_GET['line'];
  $data = drupal_http_request("http://developer.mbta.com/lib/rthr/$line.json");

  $data = $data->data;
  $data = json_decode($data);
  $trips = $data->TripList->Trips;
  $arrivals = array();


  foreach ($trips as $trip) {
    foreach ($trip->Predictions as $prediction) {
      if ($prediction->Stop == $stop) {
        $time = $prediction->Seconds;
        $arrivals[$trip->Destination][] = $time;
        sort($arrivals[$trip->Destination]);
      }
    }
  }

  ksort($arrivals);

  return theme('wheres_my_train', $arrivals, 'Arrivals');
}
