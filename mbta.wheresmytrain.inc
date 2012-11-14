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
        $arrivals[] = array(
                        'Destination' => $trip->Destination,
                        'Arrival Time' => $prediction->Seconds,
        );
      }
    }
  }
  
  $header = array(
    array(
      'data' => 'Destination',
      'field' => 'Destination',
      'sort' => 'asc',
     ),
    array(
      'data' => 'Arrival Time',
      'field' => 'Arrival Time',
      'sort' => 'asc',
    ),
  );

  return theme('table', $header, $arrivals);

}
