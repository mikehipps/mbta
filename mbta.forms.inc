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
    'Alewife' => 'Alewife',
    'Andrew' => 'Andrew',
    'Ashmont' => 'Ashmont',
    'Braintree' => 'Braintree',
    'Broadway' => 'Broadway',
    'Central Square' => 'Central Square',
    'Charles/MGH' => 'Charles/MGH',
    'Davis' => 'Davis',
    'Downtown Crossing' => 'Downtown Crossing',
    'Fields Corner' => 'Fields Corner',
    'Harvard Square' => 'Harvard Square',
    'JFK/UMass' => 'JFK/UMass',
    'Kendall/MIT' => 'Kendall/MIT',
    'North Quincy' => 'North Quincy',
    'Park Street' => 'Park Street',
    'Porter Square' => 'Porter Square',
    'Quincy Adams' => 'Quincy Adams',
    'Quincy Center' => 'Quincy Center',
    'Savin Hill' => 'Savin Hill',
    'Shawmut' => 'Shawmut',
    'South Station' => 'South Station',
    'Wollaston' => 'Wollaston',
  );
  return $mbta_stops;
}

