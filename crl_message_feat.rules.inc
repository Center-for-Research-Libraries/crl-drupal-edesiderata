<?php

/**
 * @file
 * Rules integration for the CRL Message Feature.
 *
 */

/**
 * Implements hook_rules_action_info().
 */
function crl_message_feat_rules_action_info() { 
  $items = array();
  $items['crl_message_feat_process'] = array(
    'label' => t('Send Email with Message Subscribe'),
    'group' => t('Message Subscribe'),
    'parameter' => array(
      'message' => array(
        'type' => 'message',
        'label' => t('Message'),
        'description' => t('The message to be processed and sent using Message subscribe which uses message notify.'),
      )
    ),
    'base' => 'crl_message_feat_rules_process',
  );

  return $items;
}

/**
 * Action: Process and send Message.
 */
function crl_message_feat_rules_process(Message $message) {
      
  $node = node_load($message->field_resource_reference['und'][0]['target_id']);
   //Currently we have not implemented any extra options for message subscribe option.
  if (module_exists('message_subscribe')) {
    // If Message-subscribe exists, let this example module use it.	
   message_subscribe_send_message('node', $node, $message);
  }

}

/**
 * @}
 */
