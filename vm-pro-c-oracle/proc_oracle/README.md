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
###### compile Pro*c file and run
```
source redhat_8_and_oracle_linux_profile
proc dbconn.pc
gcc dbconn.c -o dbconn.bin -L$ORACLE_HOME/lib -lclntsh -m64
./dbconn.bin
``` 


###### Oracle SQL/Admin
```
- owner='schema_name'
SQL> SELECT table_name, owner FROM  all_tables WHERE owner='HR' ORDER BY owner, table_name;
SQL> select * from DEPARTMENTS;
DEPARTMENT_ID DEPARTMENT_NAME		     MANAGER_ID LOCATION_ID
------------- ------------------------------ ---------- -----------
	   10 Administration			    200        1700
	   20 Marketing 			        201        1800
	   30 Purchasing			        114        1700
	   40 Human Resources			    203        2400
	   50 Shipping				        121        1500
	   60 IT				            103        1400
	   70 Public Relations			    204        2700
	   80 Sales				            145        2500
	   90 Executive 			        100        1700
	  100 Finance				        108        1700
	  110 Accounting			        205        1700

```


### References:
Introduction to Pro*C Embedded SQL
http://infolab.stanford.edu/~ullman/fcdb/oracle/or-proc.html

Pro*C/C++ Programmer’s Guide
https://docs.oracle.com/cd/E11882_01/appdev.112/e10825/toc.htm