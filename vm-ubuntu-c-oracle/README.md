# VM Ubuntu C/C++ Oracle
This VM is for C/C++ Developer that develop the main code connect to Oracle Database and need an playground.



### ssh connection
```
#normal server
ssh dev@server

#GCP ssh connection
gcloud beta compute ssh --zone "us-central1-a" "vm-ubuntu"  --project "dev"

```
### Pre-setup
```
#check OS Update
sudo apt update -y
apt list --upgradable
```

### Install video and AudiLib utils (command line different video format conversion)
```
sudo apt install ffmpeg -y &&
sudo apt install lame -y
```

### Dev utility
```
# process monitor
sudo apt install htop -y

sudo apt install curl -y 
sudo apt install wget -y

#compress and uncompress
sudo apt install zip unzip -y

#Copy text to clipboard
sudo apt install xclip -y

#Exec Parallel command
sudo apt install parallel -y

#Parsing JSON on CLI 
sudo apt install jq -y

#Install ab - Command Load Test tool with Apache util
sudo apt install apache2-utils -y

#Install Code version control git
###------------------------------------------
sudo apt install git -y
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
sudo apt install mercurial -y
sudo apt install subversion -y
```

### Install C/C++ compiler.
```
=============== C & C++ =============== 
# C/C++ Development
sudo apt install build-essential -y
# (1 hour 30 min for compiled the library)
# (1 hour 30 min for compiled the program)
sudo apt install cmake -y
# RESTapi framework for C++
# https://microsoft.github.io/cpprestsdk/index.html
sudo apt-get install libcpprest-dev -y

# Install Java for Oracle applications
sudo apt install default-jre -y && sudo apt install default-jdk -y


# install pip for python 2.7 (came install by default in Ubuntu)
sudo apt install python-pip -y
# python3 -m http.server 8080
```


### Install Oracle Database XE (Oracle 18c XE )
```
# download 2.3 GB of Oracle XE install
mkdir software && cd software

# click in download using the browser for active the session, then pause the download and continue in the terminal
[ Oracle Database 21c Express Edition for Linux x64 ( OL8 )]
https://www.oracle.com/database/technologies/xe-downloads.html

# download from the terminal
wget https://download.oracle.com/otn-pub/otn_software/db-express/oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm?AuthParam=1638683626_b792d9b05eb61a0190315b759484187c
mv 'oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm?AuthParam=1638683626_b792d9b05eb61a0190315b759484187c' 'oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm'


# Pre-Configuration before install

vi /etc/hosts
10.128.0.6  odb-1.localdomain  odb-1 # Oracle Database server

sudo apt-get install alien libaio1 unixodbc

# take 2 hours to convert from rpm to deb oracle
nohup sudo alien --scripts -d oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm &

# review if is executing
ps -ef|grep rpm2cpio
cat nohup.out|wc -l
ps -ef|grep "sudo alien --scripts -d oracle-database-xe-21c-1.0-1.ol8.x86_64.rpm"

sudo pico /sbin/chkconfig
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

sudo chmod 755 /sbin/chkconfig  

sudo pico /etc/sysctl.d/60-oracle.conf
---
# Oracle 11g XE kernel parameters 
fs.file-max=6815744  
net.ipv4.ip_local_port_range=9000 65000  
kernel.sem=250 32000 100 128 
kernel.shmmax=536870912 
----

sudo cat /etc/sysctl.d/60-oracle.conf 

sudo service procps start

sudo sysctl -q fs.file-max

sudo pico /etc/rc2.d/S01shm_load
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

sudo ln -s /usr/bin/awk /bin/awk 
sudo mkdir /var/lock/subsys 
sudo touch /var/lock/subsys/listener

# Install Oracle
sudo dpkg --install oracle-database-xe-21c_1.0-2_amd64.deb

# Resource:
[Answers 2]
https://askubuntu.com/questions/566734/how-to-install-oracle-11gr2-on-ubuntu-14-04


```


### Convert oracle rpm to deb with shell scripting (output)
The total execition Time is 20 min 18 sec
```
# Machine hardware
Laptop Dell Latitude E5470
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


