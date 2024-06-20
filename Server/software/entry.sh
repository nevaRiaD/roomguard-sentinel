#!/bin/bash

DB_USER='etermite';
DB_PASS='etermite123';
DB_NAME='sensor_information';
DB_TABLE='sensor_log';

sensor_location='room';
date=$(TZ=EEST date +'%F %T');
motion_detected=1;

mysql --user=$DB_USER --password=$DB_PASS $DB_NAME << EOF
INSERT INTO $DB_TABLE (location, time, motion_detected) VALUES ("$sensor_location", "$date", $motion_detected);
EOF

echo "Test echo"
