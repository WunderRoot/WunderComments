<?php
/**
 * @file
 * comments_letters.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function comments_letters_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  list($module, $api) = func_get_args();
  if ($module == "mailhandler" && $api == "mailhandler_mailbox") {
    return array("version" => "2");
  }
}
