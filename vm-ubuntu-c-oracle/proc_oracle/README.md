# Oracle Pro*C/C++
Config file
###### sudo vim /opt/oracle/product/21c/dbhomeXE/precomp/admin/pcscfg.cfg
###### sudo vim $ORACLE_HOME/precomp/admin/pcscfg.cfg
```
sys_include=($ORACLE_HOME/precomp/public,$ORACLE_HOME/sdk/include,/usr/include,usr/lib/gcc/x86_64-linux-gnu/11/include)
code=ansi

```
###### compile Pro*c file
```
proc iname=sample2.pc oname=sample2.c parse=none code=ANSI_C
gcc -I $ORACLE_HOME/sdk/include -o sample2 sample2.c
``` 
