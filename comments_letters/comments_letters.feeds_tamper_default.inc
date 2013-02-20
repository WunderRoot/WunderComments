<?php
/**
 * @file
 * comments_letters.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function comments_letters_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'comments_letters__importer-toaddress-find_replace_regex';
  $feeds_tamper->importer = 'comments_letters_importer';
  $feeds_tamper->source = 'toaddress';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/[^\\d]+/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Get NodeID from To: address';
  $export['comments_letters_importer-toaddress-find_replace_regex'] = $feeds_tamper;

  return $export;
}
