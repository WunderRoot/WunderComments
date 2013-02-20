<?php
/**
 * @file
 * comments_letters.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function comments_letters_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'comments_letters_importer';
  $feeds_importer->config = array(
    'name' => 'Letters to the Editor importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'MailhandlerFetcher',
      'config' => array(
        'filter' => 'MailhandlerFilters',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'MailhandlerParser',
      'config' => array(
        'available_commands' => 'status',
        'authenticate_plugin' => 'MailhandlerAuthenticateDefault',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommentProcessor',
      'config' => array(
        'input_format' => 'filtered_html',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'toaddress',
            'target' => 'nid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'from-name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'from-address',
            'target' => 'mail',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'subject',
            'target' => 'subject',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'message_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          6 => array(
            'source' => 'body_text',
            'target' => 'comment',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'authenticated_uid',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'udate',
            'target' => 'created',
            'unique' => FALSE,
          ),
        ),
        'author' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gmail_comment_importer'] = $feeds_importer;

  return $export;
}
