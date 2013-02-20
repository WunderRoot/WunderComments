<?php
/**
 * @file
 * comments_letters.mailhandler_mailbox.inc
 */

/**
 * Implements hook_default_mailhandler_mailbox().
 */
function comments_letters_default_mailhandler_mailbox() {
  $export = array();

  $mailbox = new stdClass();
  $mailbox->disabled = TRUE; /* Edit this to true to make a default mailbox disabled initially */
  $mailbox->api_version = 2;
  $mailbox->mail = 'comments_letters_gmail';
  $mailbox->admin_title = 'GMail for Letters to the Editor';
  $mailbox->settings = array(
    'type' => 'imap',
    'folder' => 'LettersToEditor',
    'domain' => 'gmail-imap.l.google.com',
    'port' => '993',
    'name' => 'example@gmail.com',
    'pass' => 'example',
    'extraimap' => '/ssl/novalidate-cert',
    'limit' => '0',
    'encoding' => 'UTF-8',
    'flag_after_read' => 1,
    'delete_after_read' => 1,
    'fromheader' => 'From',
    'security' => '0',
    'replies' => '0',
    'retrieve' => 'MailhandlerPhpImapRetrieve',
  );
  $export['test_gmail'] = $mailbox;

  return $export;
}
