#/bin/sh

#metric
START_TIME=$SECONDS

date
echo "=== Conversion start ==="
sudo alien --scripts -d oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm
echo "=== Conversion finished ==="

ls -lrt
date 
ELAPSED_TIME=$(($SECONDS - $START_TIME))
echo "The total execition Time is $(($ELAPSED_TIME/60)) min $(($ELAPSED_TIME%60)) sec"
