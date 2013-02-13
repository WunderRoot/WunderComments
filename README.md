WunderComments
==============

A labs project to experiment with better approaches to submitting and managing comments on large media sites.


Modules
=======

##1: Comments Letters##

A module to implement a 'Letters to the Editor' feature. This aims for a more formal way of writing to the publication to bring back a sense of responsible comment.

Nodes display a button to invite a reader to send a 'letter to the editor' about the subject, for publication. Clicking this opens a new email message in their mail client, prepopulated with the right email address (including a code for the node in question). The email, once completed is sent to a Gmail inbox. Gmail filters out the spam, and the remaining comments are ingested into the site and applied to the correct nodes. When the email address exists on a user account the comment is attrbiuted to that user account. When the email address is new to the system it creates a user account and sends the user a login and set password link.


More modules coming soon.



Credits
=======

Olli Erinko (@operinko) - development

Steve Parks (@steveparks) - research, concept development, project manager


Funded by WunderRoot / Wunderkraut - Europe's largest Drupal agency.
http://www.wunderroot.com
