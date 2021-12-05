# VM Ubuntu C/C++ Oracle
This VM is for C/C++ Developer that develop the main code connect to Oracle Database and need an playground.



### ssh connection
```
#normal server
ssh dev@server

#GCP ssh connection
gcloud beta compute ssh --zone "us-central1-a" "vm-ubuntu"  --project "dev"

#GCP: Listing bucket
$ gsutil ls
$ gsutil ls gs://<BUCKET_NAME>/
$ gsutil cp gs://<BUCKET_NAME>/oracle-database-xe-21c_1.0-2_amd64.deb .

```
### Pre-setup
```
#check OS Update
$ sudo apt update -y
$ apt list --upgradable
```

### Install video and AudiLib utils (command line different video format conversion)
```
$ sudo apt install ffmpeg -y &&
$ sudo apt install lame -y
```

### Dev utility
```
# process monitor
$ sudo apt install htop -y

$ sudo apt install curl -y 
$ sudo apt install wget -y

#compress and uncompress
$ sudo apt install zip unzip -y

#Copy text to clipboard
$ sudo apt install xclip -y

#Exec Parallel command
$ sudo apt install parallel -y

#Parsing JSON on CLI 
$ sudo apt install jq -y

#Install ab - Command Load Test tool with Apache util
$ sudo apt install apache2-utils -y

#Install Code version control git
###------------------------------------------
$ sudo apt install git -y
git config --global color.ui true
git config --global user.name "user"
git config --global user.email "name@gmail.com"
ssh-keygen -t rsa -b 4096 -C "name@gmail.com"
git config credential.helper store
git config --global credential.helper store # use --global to set the default preference to all repo.
# Use should also specify caching expire,
git config --global credential.helper 'cache --timeout 7200'

# create security connection with you code repo
# github security connect ssh with linux ubuntu
# https://help.github.com/en/articles/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent
#Generate a Key
cat ~/.ssh/id_rsa.pub
# pase the result in your git setting https://github.com/settings/keys
ssh -T git@github.com

#copy the key
xclip -sel clip < ~/.ssh/id_rsa.pub

#pass in Github key setup
https://github.com/settings/keys

# other version control.
$ sudo apt install mercurial -y
$ sudo apt install subversion -y
```

### Install C/C++ compiler.
```
=============== C & C++ =============== 
# C/C++ Development
$ sudo apt install build-essential -y
# (1 hour 30 min for compiled the library)
# (1 hour 30 min for compiled the program)
$ sudo apt install cmake -y
# RESTapi framework for C++
# https://microsoft.github.io/cpprestsdk/index.html
$ sudo apt-get install libcpprest-dev -y

# Install Java for Oracle applications
$ sudo apt install default-jre -y && sudo apt install default-jdk -y


# install pip for python 2.7 (came install by default in Ubuntu)
$ sudo apt install python-pip -y
# python3 -m http.server 8080
```


### Install Oracle Database XE (Oracle 18c XE )
```
# download 2.3 GB of Oracle XE install
$ mkdir software && cd software

# click in download using the browser for active the session, then pause the download and continue in the terminal
[ Oracle Database 21c Express Edition for Linux x64 ( OL8 )]
https://www.oracle.com/database/technologies/xe-downloads.html

# download from the terminal
$ wget https://download.oracle.com/otn-pub/otn_software/db-express/oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm?AuthParam=1638683626_b792d9b05eb61a0190315b759484187c
$ mv 'oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm?AuthParam=1638683626_b792d9b05eb61a0190315b759484187c' 'oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm'


# Pre-Configuration before install
$ sudo vim /etc/hosts
```
10.128.0.6  odb-1.localdomain  odb-1 # Oracle Database server
```

$ sudo apt install alien libaio1 unixodbc

# take 2 hours to convert from rpm to deb oracle
$ nohup sudo alien --scripts -d oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm &

# review if is executing
$ ps -ef|grep rpm2cpio
$ cat nohup.out|wc -l
$ ps -ef|grep "sudo alien --scripts -d oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm"

$ sudo pico /sbin/chkconfig
---
#!/bin/bash
# Oracle 21c  XE installer chkconfig hack for Ubuntu
file=/etc/init.d/oracle-xe
if [[ ! `tail -n1 $file | grep INIT` ]]; then
    echo >> $file
    echo '### BEGIN INIT INFO' >> $file
    echo '# Provides: OracleXE' >> $file
    echo '# Required-Start: $remote_fs $syslog' >> $file
    echo '# Required-Stop: $remote_fs $syslog' >> $file
    echo '# Default-Start: 2 3 4 5' >> $file
    echo '# Default-Stop: 0 1 6' >> $file
    echo '# Short-Description: Oracle 21c Express Edition' >> $file
    echo '### END INIT INFO' >> $file
fi
update-rc.d oracle-xe defaults 80 01
---

$ sudo chmod 755 /sbin/chkconfig  

$ sudo pico /etc/sysctl.d/60-oracle.conf
---
# Oracle 11g XE kernel parameters 
fs.file-max=6815744  
net.ipv4.ip_local_port_range=9000 65000  
kernel.sem=250 32000 100 128 
kernel.shmmax=536870912 
----

$ sudo cat /etc/sysctl.d/60-oracle.conf 

$ sudo service procps start

$ sudo sysctl -q fs.file-max

$ sudo pico /etc/rc2.d/S01shm_load
---
#!/bin/sh
case "$1" in
start)
    mkdir /var/lock/subsys 2>/dev/null
    touch /var/lock/subsys/listener
    rm /dev/shm 2>/dev/null
    mkdir /dev/shm 2>/dev/null
*)
    echo error
    exit 1
    ;;

esac 
---

$ sudo ln -s /usr/bin/awk /bin/awk 
$ sudo mkdir /var/lock/subsys 
$ sudo touch /var/lock/subsys/listener

###### Install Oracle ###### 
#1. Install the oracle DBMS using the command:
$ sudo dpkg --install oracle-database-xe-21c_1.0-2_amd64.deb
output:
(Reading database ... 88918 files and directories currently installed.)
Preparing to unpack oracle-database-xe-21c_1.0-2_amd64.deb ...
ln: failed to create symbolic link '/bin/awk': File exists
Unpacking oracle-database-xe-21c (1.0-2) ...
Setting up oracle-database-xe-21c (1.0-2) ...
[INFO] Executing post installation scripts...
[INFO] Oracle home installed successfully and ready to be configured.
To configure Oracle Database XE, optionally modify the parameters in '/etc/sysconfig/oracle-xe-21c.conf' and then execute '/etc/init.d/oracle-xe-21c configure'
 as root.
Processing triggers for libc-bin (2.28-10) ...
Processing triggers for systemd (241-7~deb10u8) 


#2.Configure Oracle using the command:
$ sudo /etc/init.d/oracle-xe-21c configure 
password for SYS/SYSTEM/PDBADMIN admin123, don't use this in production :)
output:
Connect to Oracle Database using one of the connect strings:
     Pluggable database: vm-ubuntu-developer/XEPDB1
     Multitenant container database: vm-ubuntu-developer
Use https://localhost:5500/em to access Oracle Enterprise Manager for Oracle Database XE

#3.Setup environment variables by editting your .bashrc file:
$ vim ~/.bashrc

#4.Add the following lines to the end of the file:
```
# Oracle Env setup
export ORACLE_HOME=/opt/oracle/product/21c/dbhomeXE

export ORACLE_SID=XE

############### export NLS_LANG=`$ORACLE_HOME/bin/nls_lang.sh`

export ORACLE_BASE=/opt/oracle

export LD_LIBRARY_PATH=$ORACLE_HOME/lib:$LD_LIBRARY_PATH

export PATH=$ORACLE_HOME/bin:$PATH

```

# update bashrc
$ source ~/.bashrc

#5.Load the changes by executing your profile:Connect to Oracle Database using one of the connect strings:
     Pluggable database: vm-ubuntu-developer/XEPDB1
     Multitenant container database: vm-ubuntu-developer
Use https://localhost:5500/em to access Oracle Enterprise Manager for Oracle Database XE
. ~/.bashrc

#6.Start the Oracle 21c XE:
$ sudo service oracle-xe-21c status
$ sudo service oracle-xe-21c start
$ sudo service oracle-xe-21c status

#7.Add user YOURUSERNAME to group dba using the command:
sudo usermod -a -G dba $USER

###### Oracle basic setup for work ###### 
#1. Start the Oracle XE 21c server using the command:
sudo service oracle-xe start

#2. Start command line shell as the system admin using the command:
sqlplus sys as sysdba
SQL> select sysdate from dual;

SYSDATE
---------
05-DEC-21

#3. Create a regular user account in Oracle using the SQL command
alter session set "_oracle_script"=true;   # just do that in dev env.
create user dev1 identified by dev1;

# Replace USERNAME and PASSWORD with the username and password of your choice. Please remember this username and password. If you had error executing the above with a message about resetlogs, then execute the following SQL command and try again:
alter database open resetlogs;

#4. Grant privileges to the user account using the SQL command:
grant connect, resource to dev1;

#5. Exit the sys admin shell using the SQL command:
exit;

#6. Start the commandline shell as a regular user using the command:
sqlplus



# Resource:
[Answers 2]
https://askubuntu.com/questions/566734/how-to-install-oracle-11gr2-on-ubuntu-14-04


```


### Convert oracle rpm to deb with shell scripting (output)
The total execution Time is 20 min 18 sec
```
# Machine hardware
Laptop Dell Latitude E5470Connect to Oracle Database using one of the connect strings:
     Pluggable database: vm-ubuntu-developer/XEPDB1
     Multitenant container database: vm-ubuntu-developer
Use https://localhost:5500/em to access Oracle Enterprise Manager for Oracle Database XE
CPU: Intel CORE i5 (4 cpu)
Memory: 31GB
Swp: 1GB
Disk size: 1TB/1000GB

# Run the conversion (script in the repo)
$ ./convert-oracle-rpm-to-deb.sh 
Sun 05 Dec 2021 12:44:26 PM AST
=== Conversion start ===
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
warning: oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID ad986da3: NOKEY
oracle-database-xe-21c_1.0-2_amd64.deb generated
=== Conversion finished ===
total 4492152
drwxrwxr-x 2 developer developer       4096 Mar  1  2021 ngrok-stable-linux-amd64
-rw-rw-r-- 1 developer developer   71403603 Jun 20 06:45 kafka_2.13-2.8.0.tgz
drwxr-xr-x 8 developer developer       4096 Jun 20 06:46 kafka_2.13-2.8.0
drwxrwxrwx 3 developer developer       4096 Jun 24 19:37 CLion-2021.1.2
-rw-rw-r-- 1 developer developer 2339651768 Dec  5 12:25 oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm
-rwxrwxr-x 1 developer developer        322 Dec  5 12:44 convert-oracle-rpm-to-deb.sh
-rw-r--r-- 1 root      root      2188876652 Dec  5 13:04 oracle-database-xe-21c_1.0-2_amd64.deb
Sun 05 Dec 2021 01:04:44 PM AST
The total execution Time is 20 min 18 sec

```

### Oracle help command
```
# check the database version
$sqlplus
SELECT banner FROM v$version WHERE ROWNUM = 1;
output:
BANNER
--------------------------------------------------------------------------------
Oracle Database 21c Express Edition Release 21.0.0.0.0 - Production

# check the DB instance name
Select * From v$instance;

# list all the table by schema:
select owner, table_name from all_tables order by owner;

# check the ORACLE_SID
select sys_context('userenv','instance_name') from dual; 

# create table space ad user user
alter session set "_oracle_script"=true;   # just do that in dev env.
DROP USER dev1 CASCADE;

CREATE TABLESPACE tbs1 
   DATAFILE 'tbs1_data.dbf' 
   SIZE 1m;

CREATE PROFILE app_user LIMIT 
   SESSIONS_PER_USER          UNLIMITED 
   CPU_PER_SESSION            UNLIMITED 
   CPU_PER_CALL               3000 
   CONNECT_TIME               45 
   LOGICAL_READS_PER_SESSION  DEFAULT 
   LOGICAL_READS_PER_CALL     1000 
   PRIVATE_SGA                15K
   COMPOSITE_LIMIT            5000000; 

GRANT CREATE SESSION TO dev1;

sqlplus dev@XE
   
CREATE USER dev1
    IDENTIFIED BY dev1 
    DEFAULT TABLESPACE tbs1 
    QUOTA 10M ON tbs1 
    TEMPORARY TABLESPACE temp
    QUOTA 5M ON system 
    PROFILE app_user;

# create table
CREATE TABLE DEPT(  
  deptno     number(2,0),  
  dname      varchar2(14),  
  loc        varchar2(13),  
  constraint pk_dept primary key (deptno)  
);

insert into DEPT (DEPTNO, DNAME, LOC)
values(10, 'ACCOUNTING', 'NEW YORK');

insert into DEPT  
values(20, 'RESEARCH', 'DALLAS');

insert into DEPT  
values(30, 'SALES', 'CHICAGO');

references: https://livesql.oracle.com/apex/livesql/file/content_O5AEB2HE08PYEPTGCFLZU9YCV.html
```

