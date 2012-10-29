<?php

/**
 * @file MBTA Block File
 * This file is responsible for displaying Drupal blocks for the
 * MBTA module.
 */

/**
 * Lists the MBTA Drupal blocks.
 *
 * @return Array
 *   The list of MBTA Drupal blocks.
 */
function mbta_block_list() {
  $blocks['mbta_which_stop']['info'] = t('MBTA Which Stop Block');
  return $blocks;
}

/**
 * Renders the correct block view.
 *
 * @param string $delta
 *   A Drupal block name.
 *
 * @return string
 *   The block (corresponding to $delta) rendered as HTML.
 */
function mbta_block_view($delta) {
  if ($delta == 'mbta_which_stop') {
    drupal_add_css(drupal_get_path('module', 'mbta') . '/css/mbta.css');

    $block['subject'] = t('Which Stop');
    $block['content'] = mbta_block_which_stop();
  }
  return $block;
}

function mbta_block_which_stop() {
  $which_stop = drupal_get_form('mbta_which_stop_form', 'block');
  return $which_stop;
}

