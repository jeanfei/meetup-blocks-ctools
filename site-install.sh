#!/bin/sh

echo "Start - Installing meetup blocks demo"
cd blocks; drush site-install meetup_blocks_profile --account-pass='admin' --site-name='Meetup - Blocks demo' -yv
echo "End - Installing meetup blocks demo"
cd ..

echo "-----------------------------"
echo "Start - Installing meetup ctools demo"
cd ctools; drush site-install meetup_ctools_profile --account-pass='admin' --site-name='Meetup - Ctools demo' -yv
echo "End - Installing meetup ctools demo"
