# VM Ubuntu C/C++ Oracle
This VM is for C/C++ Developer that develop the main code connect to Oracle Database and need an playground.

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


```

### Install C/C++ compiler.
```
=============== C & C++ =============== 
# C/C++ Development
sudo apt install build-essential -y
# (1 hour 30 min for compiled the library)
# (1 hour 30 min for compiled the program)
sudo snap install cmake --classic
# RESTapi framework for C++
# https://microsoft.github.io/cpprestsdk/index.html
sudo apt-get install libcpprest-dev -y
#QT Creator
# Qt: can't find -lGL error.... solution: libgl1-mesa-dev
sudo apt install libgl1-mesa-dev -y

#VIM editor
sudo apt install vim -y
```
