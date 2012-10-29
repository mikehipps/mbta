<?php

/**
 * @file MBTA Drupal form handling.
 */

/**
 * Sets the MBTA Address Form structure--used to build the form.
 *
 * @param string $style
 *  The style of form to display: either 'page' or 'block'
 * @return Array
 *   The MBTA Address Form structure.
 */
function _mbta_which_stop_form($style) {
  $form = array();

  $form['mbta_whichtrain']['intro'] = array(
    '#type' => 'item',
    '#value' => ('Select your train below:'),
    '#weight' => 0,
  );

  $form['mbta_whichtrain']['mbta_whichtrain'] = array(
    '#type' => 'select',
    '#title' => t('Which Train'),
    '#options' => mbta_get_stops_list(),
    '#description' => t('Pick a train.'),
  );

  $form['mbta_whichtrain']['style'] = array(
    '#type' => 'value',
    '#value' => $style,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#weight' => 100,
  );

  $form['#redirect'] = FALSE;
  $form['#attributes']['class'] .= ' mbta-wheresmytrain-form ';

  return $form;
}

function mbta_get_stops_list() {
  $mbta_stops = array(
    0 => 'Alewife',
    1 => 'Andrew',
    2 => 'Andrew',
    3 => 'Ashmont',
    4 => 'Braintree',
    5 => 'Broadway',
    6 => 'Central Square',
    7 => 'Charles/MGH',
    8 => 'Davis',
    9 => 'Downtown Crossing',
    10 => 'Fields Corner',
    11 => 'Harvard Square',
    12 => 'JFK/UMass',
    13 => 'Kendall/MIT',
    14 => 'North Quincy',
    15 => 'Park Street',
    16 => 'Porter Square',
    17 => 'Quincy Adams',
    18 => 'Quincy Center',
    19 => 'Savin Hill',
    20 => 'Shawmut',
    21 => 'South Station',
    22 => 'Wollaston',
  );

  return $mbta_stops;
}

