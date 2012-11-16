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
function _mbta_which_stop_form(&$form_state, $style) {
  drupal_add_js(drupal_get_path('module', 'mbta') . '/js/mbta_wmt.js');
  $form = array();
  $lines = mbta_get_line_list();

  $form['mbta_whichtrain']['intro'] = array(
    '#type' => 'item',
    '#value' => ('Select your train below:'),
    '#weight' => 0,
  );

  $form['mbta_whichtrain']['mbta_whichline'] = array(
    '#attributes' => array(
      'id' => 'mbta-whichline',
    ),
    '#type' => 'select',
    '#title' => t('Which Line'),
    '#options' => $lines,
    '#description' => t('Pick a line.'),
  );

  foreach ($lines as $key => $value) {
    if (!$value) {
      continue;
    }
    $form['mbta_whichtrain']['mbta_whichtrain'][$key] = array(
      '#attributes' => array(
        'id' => 'whichtrain_' . $key,
      ),
      '#type' => 'select',
      '#title' => t($value),
      '#options' => mbta_get_stops_list($key),
      '#description' => t('Pick a train.'),
    );
  }

  $form['mbta_whichtrain']['style'] = array(
    '#type' => 'value',
    '#value' => $style,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#weight' => 100,
    '#attributes' => array(
      'class' => 'whichtrain_submit',
    ),
  );

  $form['#redirect'] = FALSE;
  $form['#attributes']['class'] .= ' mbta-wheresmytrain-form ';

  return $form;
}

function mbta_get_stops_list($line) {
  switch ($line) {
    case 'red':
      return mbta_get_red_line_stops();
      break;
    case 'blue':
      return mbta_get_blue_line_stops();
    case 'orange':
      return mbta_get_orange_line_stops();
    default:
      return;
  }
}

function mbta_get_red_line_stops() {
  $mbta_stops = array(
    '' => '',
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

function mbta_get_blue_line_stops() {
  $mbta_stops = array(
    '' => '',
    'Airport' => 'Airport',
    'Aquarium' => 'Aquarium',
    'Beachmont' => 'Beachmont',
    'Government Center' => 'Government Center',
    'Maverick' => 'Maverick',
    'Orient Heights' => 'Orient Heights',
    'Revere Beach' => 'Revere Beach',
    'State Street' => 'State Street',
    'Suffolk Downs' => 'Suffolk Downs',
    'Suffolk Downs' => 'Suffolk Downs',
    'Wonderland' => 'Wonderland',
    'Wood Island' => 'Wood Island',
  );
  return $mbta_stops;
}

function mbta_get_orange_line_stops() {
  $mbta_stops = array(
    '' => '',
    'Back Bay' => 'Back Bay',
    'Chinatown' => 'Chinatown',
    'Community College' => 'Community College',
    'Downtown Crossing' => 'Downtown Crossing',
    'Forest Hills' => 'Forest Hills',
    'Green Street' => 'Green Street',
    'Haymarket' => 'Haymarket',
    'Jackson Square' => 'Jackson Square',
    'Malden Center' => 'Malden Center',
    'Mass Ave' => 'Mass Ave',
    'North Station' => 'North Station',
    'Oak Grove' => 'Oak Grove',
    'Roxbury Crossing' => 'Roxbury Crossing',
    'Ruggles' => 'Ruggles',
    'State Street' => 'State Street',
    'Stony Brook' => 'Stony Brook',
    'Sullivan' => 'Sullivan',
    'Tufts Medical' => 'Tufts Medical',
  );
  return $mbta_stops;
}

function mbta_get_line_list() {
  $mbta_lines = array(
    '' => '',
    'blue' => 'Blue Line',
    'orange' => 'Orange Line',
    'red' => 'Red Line',
  );
  return $mbta_lines;
}
