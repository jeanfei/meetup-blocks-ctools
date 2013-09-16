#!/bin/sh

# Installing meetup_blocks_profile profile
meetup_blocks_profile() {
  echo "Start - Installing meetup blocks demo"
  cd drupal7-demo; drush site-install meetup_blocks_profile --account-pass='admin' --site-name='Meetup - Blocks demo' --locale='fr' -y
  echo "End - Installing meetup blocks demo"
}

# Installing meetup_context_profile profile
meetup_context_profile() {
  echo "Start - Installing meetup context demo"
  cd drupal7-demo; drush site-install meetup_context_profile --account-pass='admin' --site-name='Meetup - Context demo' --locale='fr' -y
  echo "End - Installing meetup context demo"
}

# Installing meetup_ctools_profile profile
meetup_ctools_profile() {
  echo "Start - Installing meetup ctools demo"
  cd drupal7-demo; drush site-install meetup_ctools_profile --account-pass='admin' --site-name='Meetup - Ctools demo' --locale='fr' -y
  echo "End - Installing meetup ctools demo"
}


# Prompt for user
while true; do
  echo
  echo "Installation profile"
  echo "1. Installing Drupal7 meetup blocks demo"
  echo "2. Installing Drupal7 meetup context demo"
  echo "3. Installing Drupal7 meetup ctools demo"
  # echo "4. Installing Drupal8 meetup layout demo"
  echo

  if [ -z $1 ]
  then
    read -p "Your selection : " selection
  else
    selection=$1
  fi

  case $selection in
      1 ) meetup_blocks_profile; break;;
      2 ) meetup_context_profile; break;;
      3 ) meetup_ctools_profile; break;;
      * ) echo "Please select a valid choice.";;
    esac
done
