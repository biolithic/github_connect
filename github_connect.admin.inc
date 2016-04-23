<?php

/**
 * @file
 * Administration page callbacks for the GitHub connect module.
 */

/**
 * Implements hook_admin_settings().
 */
function github_connect_admin_settings_form($form_state) {

  $form['github_connect_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Github settings'),
    '#description' => t('Fill in the form below. You will first have to create an application at https://github.com/settings/applications/new. Main URL should be set to your domain name and Callback URL to your domain name /github/register/create (http://example.com/github/register/create). After saving the application you will be given the Client ID and Client secret.'),
  );

  $form['github_connect_settings']['github_connect_client_id'] = array(
    '#title' => t('Client ID'),
    '#type' => 'textfield',
    '#default_value' => config_get('github_connect.settings', 'github_connect_client_id'),
    '#size' => 50,
    '#maxlength' => 50,
    '#required' => TRUE,
  );

  $form['github_connect_settings']['github_connect_client_secret'] = array(
    '#title' => t('Client secret'),
    '#type' => 'textfield',
    '#default_value' => config_get('github_connect.settings', 'github_connect_client_secret'),
    '#size' => 50,
    '#maxlength' => 50,
    '#required' => TRUE,
  );

 $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}


/**
 * Submit handler for module_settings_form().
 */
function github_connect_admin_settings_form_submit($form, &$form_state) {

$config = config('github_connect.settings');
  foreach ($form_state['values'] as $key => $value)
  {
  $config->set($key, $value);
  }

$config->save();
backdrop_set_message(t('The configuration options have been saved.'));
}
?>
