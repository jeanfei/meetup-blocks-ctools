# Meetup : Blocks vs page_manager / panels / ctools

## Informations
* start date : 2013-09-18
* Provide sources of Drupal demo

## Requirements
* php 5.3.x
* mysql 5.x
* more info on [drupal.org](https://drupal.org/requirements)


## Installation
1. Create a file on blocks/sites/default/settings.local.php (see example below)
2. Create a file on ctools/sites/default/settings.local.php (see example below)

```php
<?php

/**
 * @file
 * Drupal site-specific local overrides configuration file.
 */
$databases = array (
  'default' =>
  array (
    'default' =>
    array (
      'database' => 'database-name',
      'username' => 'mysql-username',
      'password' => 'mysql-password',
      'host' => 'localhost',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);
```

2. Install the project with meetup blocks installation profile with one of the following solution :
    1. Basic web install in domain.tld/install.php (select meetup_blocks profile during installation)
    2.1 cd blocks; drush site-install --account-pass='admin' --site-name='Meetup - Blocks demo' -y
    2.2 cd ctools; drush site-install --account-pass='admin' --site-name='Meetup - Ctools demo' -y
