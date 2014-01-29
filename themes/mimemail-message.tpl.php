<?php
/**
 * @file
 * CRL theme implementation to format an HTML mail.
 *
 *
 * Available variables:
 * - $recipient: The recipient of the message
 * - $subject: The message subject
 * - $body: The message body
 * - $css: Internal style sheets
 * - $module: The sending module
 * - $key: The message identifier
 *
 * @see template_preprocess_mimemail_message()
 */
?>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <?php if ($css): ?>
            <style type="text/css">
                <!--
                <?php //print $css ?>
                -->
            </style>
        <?php endif; ?>
    </head>
    <body id="mimemail-body" <?php
        if ($module && $key): print 'class="' . $module . '-' . $key . '"';
        endif;
        ?> style="text-align: center; padding: 0px;">
        <table cellpadding="5" cellspacing="5" style="width: 700px; border: 1px solid #ccc; margin: auto;">
            <tr>
                <td style="background: #474b6f; width: 100%;" height="141" align="center" valign="middle">
                    <img src="sites/default/files/edesiderata-mail.png" alt="eDesiderata -Informed Investment in Electronic Resources">
                </td>
            </tr>

            <tr>
                <td style="mso-line-height-rule: exactly; line-height: 28px; text-align: left;">
                    <div id="main">
                        <?php print $body; ?>    
                    </div>
                </td>
            </tr>  
            <tr>
                <td style="background: #2B2A45; width: 100%; text-align:r ight; color: #D1CFBD;" height="100">
                    <p style="padding: 20px;">6050 S. Kenwood Avenue | Chicago, IL 60637-2804 USA<br>
                        Phone: (800) 621-6044 or (773) 955-4545 | Fax: (773) 955-4339</p>

                </td>
            </tr>
        </table>
        <div style="width: 700px; margin: auto; margin-top: 2em; text-align: center; font-size: smaller">
          To ensure that you continue receiving our emails, please add us to your address book or safe list.<br>If you are not interested in receiving any more messages like this please go to the <a href="#">unsubscribe</a> page.</small>
        </div>
    </body>
</html>