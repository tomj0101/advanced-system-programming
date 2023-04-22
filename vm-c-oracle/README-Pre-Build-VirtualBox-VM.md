# Pre-Built Developer VMs (for Oracle VM VirtualBox)
Download a ready VirtualBox machine and start you Pro*C or C with Client Development.
```
https://www.oracle.com/downloads/developer-vm/community-downloads.html
Name:
    Database App Development VM

Contents:
    - Oracle Linux 7
    - Oracle Database 19.3 Linux x86-64
    - Oracle XML DB
    - Oracle SQL Developer
    - Oracle SQL Developer Data Modeler
    - Oracle Application Express
    - Hands-On-Labs (accessed via the Toolbar Menu in Firefox)	

Links:
    https://www.oracle.com/database/technologies/databaseappdev-vm.html

Oracle Database 23c Free - Developer Release VirtualBox Appliance
    - Oracle Linux 8.7
    - Oracle Database 23.2 Free - Developer Release for Linux x86-64
    - Oracle REST Data Services 23.1
    - Oracle SQLcl 23.1
    - Oracle APEX 22.2

    $ wget https://download.oracle.com/otn_software/virtualbox/dd/Oracle_Database_23c_Free_Developer_Appliance.ova

    Oracle_Database_23c_Free_Developer_Appliance.ova    size: 7GB

    Requirements
    - At least 4GB RAM.
    - At least 20GB of free space (Note: virtualization works best with contiguous space so it is a good idea if on Windows to run a defrag program, and make sure you are using NTFS for your file system to handle large files on Windows.)


Default credentials
Oracle SID: free         --- Instance: SELECT sys_context('USERENV','INSTANCE_NAME') AS Instance FROM dual; 
PLuggable DB: freepdb1   --- DB:       SELECT sys_context('USERENV','DB_NAME') AS Database_Name FROM dual;
ALL PASSWORD ARE: oracle

Smple schemas Preloaded: (HR, OE, PM, IX, BI, AV, SH)

Ports:
	8080
	1521	

```

### Oracle DB verify
```
    $ tnsping free

    TNS Ping Utility for Linux: Version 23.0.0.0.0 - Developer-Release on 22-APR-2023 03:51:20

    Copyright (c) 1997, 2023, Oracle.  All rights reserved.

    Used parameter files:
    /opt/oracle/product/23c/dbhomeFree/network/admin/sqlnet.ora


    Used TNSNAMES adapter to resolve the alias
    Attempting to contact (DESCRIPTION = (ADDRESS = (PROTOCOL = TCP)(HOST = localhost)(PORT = 1521)) (CONNECT_DATA = (SERVER = DEDICATED) (SERVICE_NAME = FREE)))
    OK (10 msec)

    $ sqplus hr/oracle
    $ sqplus hr/oracle@freepdb1

    Pro*C Important Path:
    echo $ORACLE_HOME
    /opt/oracle/product/23c/dbhomeFree

    $ ls /opt/oracle/product/23c/dbhomeFree/precomp
        admin  doc  lib  mesg  public

    $ ls /opt/oracle/product/23c/dbhomeFree/precomp/lib
        cobsqlintf.o  env_precomp.mk  ins_precomp.mk  ottclasses.zip

    $ ls /opt/oracle/product/23c/dbhomeFree/precomp/public/
        bndsel.cob  oraca5.cob  oraca.cob  oraca.h  sql2oci.h  sqlca5.cbt  sqlca.cbt  SQLCA.COB  SQLCA.H   sqlda.h  sqlkpr.h
        oraca5.cbt  oraca.cbt   ORACA.COB  ORACA.H  sqlapr.h   sqlca5.cob  sqlca.cob  sqlca.h    sqlcpr.h  SQLDA.H  sqlucs2.h

    $ ls /opt/oracle/product/23c/dbhomeFree/precomp/admin
        ic_pcbcfg.cfg  ic_pcscfg.cfg  ottcfg.cfg  pcbcfg.cfg  pcscfg.cfg  shrept.lst 
    
    $ cat ~/.bash_profile 
        # .bash_profile

        # Get the aliases and functions
        if [ -f ~/.bashrc ]; then
            . ~/.bashrc
        fi

    $ cat ~/.bashrc 
        # .bashrc

        # Source global definitions
        if [ -f /etc/bashrc ]; then
            . /etc/bashrc
        fi

        # User specific environment
        if ! [[ "$PATH" =~ "$HOME/.local/bin:$HOME/bin:" ]]
        then
            PATH="$HOME/.local/bin:$HOME/bin:$PATH"
        fi
        export PATH

        # Uncomment the following line if you don't like systemctl's auto-paging feature:
        # export SYSTEMD_PAGER=

        # User specific aliases and functions

        if test "m$JAVAENV" = "m"
        then
        export TMZ="GMT" 
        export JAVA_HOME=`ls -d /home/oracle/java/jdk* 2>/dev/null`
        if test "m$JAVA_HOME" = "m"
        then
        export JAVA_HOME=/opt/oracle/product/23c/dbhomeFree/jdk
        fi
        export PATH=$JAVA_HOME/bin:/home/oracle/bin:/home/oracle/sqlcl/bin:/home/oracle/sqldeveloper:/home/oracle/datamodeler:$PATH:/home/oracle/sqlcl/bin:/home/oracle/sqldeveloper:/home/oracle/bin
        export JAVAENV=true
        fi

        if test "m$JAVAENV" = "m"
        then
        export TMZ="GMT" 
        export JAVA_HOME=`ls -d /home/oracle/java/jdk* 2>/dev/null`
        if test "m$JAVA_HOME" = "m"
        then
        export JAVA_HOME=/opt/oracle/product/23c/dbhomeFree/jdk
        fi
        export PATH=$JAVA_HOME/bin:/home/oracle/bin:/home/oracle/sqlcl/bin:/home/oracle/sqldeveloper:/home/oracle/datamodeler:$PATH:/home/oracle/sqlcl/bin:/home/oracle/sqldeveloper:/home/oracle/bin
        export JAVAENV=true
        fi

        #LD_LIBRARY_PATH
        #set up db for su login and gnome terminal use so LD_LIBRARY_PATH pure for gnome and user does not have to . oraenv
        #do I still get ui issues "m1" = "m0" ie is it really an issue of these 10 lines ( and install). -a "m1" = "m0"
        pstree -s $$ | egrep "\-su-|gnome-terminal" >/dev/null 2>&1
        export GNOME_CHECK=$?
        if test "m$DBENV" = "m" -a "m$GNOME_CHECK" = "m0" 
        then
        export TMP=/tmp
        export TMPDIR=$TMP
        export ORACLE_UNQNAME=FREE
        export ORACLE_BASE=/opt/oracle
        export ORACLE_HOME=/opt/oracle/product/23c/dbhomeFree
        export ORACLE_SID=FREE
        #LD_LIBRARY_PATH
        export PATH=/home/oracle/bin:/home/oracle/LDLIB:$ORACLE_HOME/bin:/usr/sbin:$PATH
        #during install set LD_LIBRARY_PATH otherwise rely on LDLIB wrappers and ~/bin/sql sqlplus and modeller
        if test -f /tmp/1/buildTimeStillInstalling
        then
        export LD_LIBRARY_PATH=$ORACLE_HOME/lib
        fi
        export CLASSPATH=$ORACLE_HOME/jlib:$ORACLE_HOME/rdbms/jlib
        export DBENV=true
        #export SQL_OR_SQLPLUS=sql -oci
        export SQL_OR_SQLPLUS=sqlplus
        fi
        if test "m$DONOTSETTWO_TASK" = "m"
        then
        export TWO_TASK=FREEPDB1
        fi

        $ proc --version

            Pro*C/C++: Release 23.0.0.0.0 - Developer-Release on Sat Apr 22 04:15:12 2023
            Version 23.2.0.0.0

            Copyright (c) 1982, 2023, Oracle and/or its affiliates.  All rights reserved.

            System default option values taken from: /opt/oracle/product/23c/dbhomeFree/precomp/admin/pcscfg.cfg




```


### Install VSCODE and few Developer Extensions
```
    $ cd /etc/yum.repos.d
    $ sudo vim vscode.repo
        [vscode]
        name=vscode
        baseurl=https://packages.microsoft.com/yumrepos/vscode/
        enabled=1
        gpgcheck=1
        gpgkey=https://packages.microsoft.com/keys/microsoft.asc

    $ sudo yum install code


ref: https://blogs.oracle.com/wim/post/installing-visual-studio-code-on-oracle-linux-7


    $ sudo yum install code
        vscode                                                                                                           11 MB/s |  34 MB     00:03    
        Last metadata expiration check: 0:00:19 ago on Sat 22 Apr 2023 04:17:56 AM UTC.
        Dependencies resolved.
        ================================================================================================================================================
        Package                      Architecture                   Version                                       Repository                      Size
        ================================================================================================================================================
        Installing:
        code                         x86_64                         1.77.3-1681292829.el7                         vscode                         120 M

        Transaction Summary
        ================================================================================================================================================
        Install  1 Package

        Total download size: 120 M
        Installed size: 331 M
        Is this ok [y/N]: y
        Downloading Packages:
        code-1.77.3-1681292829.el7.x86_64.rpm                                                                            15 MB/s | 120 MB     00:07    
        ------------------------------------------------------------------------------------------------------------------------------------------------
        Total                                                                                                            15 MB/s | 120 MB     00:07     
        vscode                                                                                                           14 kB/s | 983  B     00:00    
        Importing GPG key 0xBE1229CF:
        Userid     : "Microsoft (Release signing) <gpgsecurity@microsoft.com>"
        Fingerprint: BC52 8686 B50D 79E3 39D3 721C EB3E 94AD BE12 29CF
        From       : https://packages.microsoft.com/keys/microsoft.asc
        Is this ok [y/N]: y
        Key imported successfully
        Running transaction check
        Transaction check succeeded.
        Running transaction test
        Transaction test succeeded.
        Running transaction
        Preparing        :                                                                                                                        1/1 
        Installing       : code-1.77.3-1681292829.el7.x86_64                                                                                      1/1 
        Running scriptlet: code-1.77.3-1681292829.el7.x86_64                                                                                      1/1 
        Verifying        : code-1.77.3-1681292829.el7.x86_64                                                                                      1/1 

        Installed:
        code-1.77.3-1681292829.el7.x86_64                                                                                                             

        Complete!

```


### Samples
```
    $ cd ~/Documents
    $ mkdir Ebank
    $ proc dbconn.pc
    $ gcc dbconn.c -o dbconn.bin
    $ ./dbconn.bin

    -- OR DO ALL IN ONE --
    proc dbconn.pc && gcc dbconn.c -o dbconn.bin && ./dbconn.bin

    $ make -f dbconn.mk


```


### HR Schema & Tables
```
- COUNTRIES
- DEPARTMENTS
- EMPLOYEES
- JOBS
- JOB_HISTORY
- LOCATIONS
- REGIONS
```



### SQLCA Struct
```
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

```



### Error & Solution

Error: CC-S-02015, unable to open include file
```
    $ proc dbconn.pc
    Error:
        Error at line 10, column 9 in file dbconn.pc
        #include<conio.h>
        ........1
        PCC-S-02015, unable to open include file

    Solution:
        sudo vim $ORACLE_HOME/precomp/admin/pcscfg.cfg
        Add this line in `code=ansi` file should be look like this:
            
            sys_include=($ORACLE_HOME/precomp/public,/usr/include,/usr/lib/gcc/x86_64-redhat-linux/4.1.2/include,/usr/lib/gcc/x86_64-redhat-linux/4.4.7/include,/usr/lib/gcc/x86_64-redhat-linux/4.4.4/include,/usr/lib64/gcc/x86_64-suse-linux/4.8/include,/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include)
            sys_include=/usr/lib64/gcc/x86_64-suse-linux/7/include
            sys_include=/usr/lib/gcc/x86_64-redhat-linux/8/include
            sys_include=/usr/lib/gcc/x86_64-linux-gnu/9/include
            sys_include=/usr/lib/gcc/x86_64-linux-gnu/8/include
            ltype=short
            define=__x86_64__
            code=ansi

        Now run again compilation with this commands:

        $ proc dbconn.pc parse=none code=ANSI_C

    
    Root couse: this library don't exits in Linux, better to use one that replace this windows one.



```


Error: 
dbconn.c:(.text+0x242): undefined reference to `sqlcxt'
collect2: error: ld returned 1 exit status
```
gcc dbconn.c -o dbconn.bin -L$ORACLE_HOME/lib -lclntsh -m64
```