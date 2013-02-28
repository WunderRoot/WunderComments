Introduction
============

Letters To Editor module is a proof-of-concept solution to comment-spam.
It utilizes the exising spam-filters of GMail and forces users to send an email in order to comment.

Dependencies
============
ctools, feeds, feeds_comment_processor, feeds_tamper
These are for importing the feed objects as comments, Tamper is used to get the node-id from the "To:" address.

mailhandler mailhandler_php_imap
These are for enabling the use of a GMail address as a Feed to be imported periodically.

job_scheduler
This enables running feed imports automatically with cron.

Requirements
============
PHP compiled with imap support.

Installation
============
After enabling the module, you will have to edit a few things to get up and running.

1) Set up GMail with labels and filters.
  - Filter criteria for To-address should have: your_email_address_before_@"+"% AND gmail.com
    - This enables filtering of emails such as testemail+drupal123@gmail.com for labeling to the correct folder.
    - Tick the boxes "Skip inbox (archive)" and "Use label: " and pick a label to use.

2) admin/structure/mailhandler/list/comments_letters_gmail/edit
  - Change the username and password to match your gmail settings.
  - Change the Folder to match your chosen GMail Label.

3) The importer itself should *not* require modifications.
  - But it does require one manual run before it starts running automatically on cron.

4) import/comments_letters_importer
  - Make sure Mailbox is set to "GMail for Letters to the Editor".
  - If you only want to allow emails that come from already registered users, tick the box "Skip messages that fail authentication".
  - By default, we automatically post comments from authenticated users.
  - By default, we leave comments from anonymous users to wait for moderation.
    - This can be changed by editing the "Default commands (anonymous users)" part of the import page to:
      status: 1 instead of status: 0
    - The change is remembered for following imports. If it needs to be changed at some point, run a manual import with the new value.
