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
        <table cellpadding="5" cellspacing="20" style="border: 1px solid #d7d4e3; margin: auto; width: 90%">
            <tr>
                <td style="background: #fff; width: 100%; padding-bottom: 20px; border-bottom: 1px solid #d7d4e3;" align="left" valign="middle">
                    <a href="#"><img src="sites/default/files/mail-head.png" width="410" height="117" alt="eDesiderata -Informed Investment in Electronic Resources" style="border: none; outline: none;"></a>
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
                <td style="background: #fff; width: 100%; padding-top: 20px; border-top: 1px solid #d7d4e3;" align="left" valign="middle">
                    <a href="#"><img src="sites/default/files/mail-foot.png" width="400" height="101" alt="Center for Research Libraries" style="border: none; outline: none;"></a>                                     

                </td>
            </tr>
        </table>
        <div style="width: 90%; margin: auto; margin-top: 2em; text-align: center; font-size: smaller">
          To ensure that you continue receiving our emails, please add us to your address book or safe list.
          <?php if (isset($mydes_unsubscribe_message)) { print '<br/>' . $mydes_unsubscribe_message; } ?>
        </div>
    </body>
</html>