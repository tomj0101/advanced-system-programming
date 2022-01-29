# Oracle Pro*C/C++
Config file
```
sudo vim /opt/oracle/product/21c/dbhomeXE/precomp/admin/pcscfg.cfg
sudo vim $ORACLE_HOME/precomp/admin/pcscfg.cfg
---
#redhat 8
#sys_include=(/usr/lib/gcc/x86_64-redhat-linux/8/include,/usr/include,/usr/include/linux,$ORACLE_HOME/precomp/public)
#ubuntu 
sys_include=(/usr/lib/gcc/x86_64-linux-gnu/11/include,/usr/include,/usr/include/linux,$ORACLE_HOME/precomp/public)
ltype=short
define=__x86_64__
code=ansi
---
```
###### compile Pro*c file
```
proc iname=sample2.pc oname=sample2.c parse=none code=ANSI_C
gcc -c -o sample2 sample2.c
``` 
