#/bin/sh

#metric
START_TIME=$SECONDS

date
echo "=== Conversion start ==="
sudo alien --scripts -d oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm
echo "=== Conversion finished ==="

sudo chmod 777 oracle-database-xe-21c_1.0-2_amd64.deb

ls -lrt
date 
ELAPSED_TIME=$(($SECONDS - $START_TIME))
echo "The total execution Time is $(($ELAPSED_TIME/60)) min $(($ELAPSED_TIME%60)) sec"
