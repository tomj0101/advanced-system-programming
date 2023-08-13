# Sonar scan for C & C++
```
Download Sonarqube community
https://www.sonarsource.com/open-source-editions/sonarqube-community-edition/
wget https://binaries.sonarsource.com/Distribution/sonarqube/sonarqube-10.1.0.73491.zip
unzip sonarqube-10.1.0.73491.zip


cd ~/Documents/Software/Sonar/sonarqube-10.1.0.73491/bin/linux-x86-64
./sonar.sh start

```

### previous requiredment
```
make sure to have the lasted version of java for the version of sonar you are using.
sudo apt update && sudo apt upgrade -y
sudo apt-get install openjdk-19-jdk

$ java -version
    openjdk version "19.0.2" 2023-01-17
    OpenJDK Runtime Environment (build 19.0.2+7-Ubuntu-0ubuntu322.04)
    OpenJDK 64-Bit Server VM (build 19.0.2+7-Ubuntu-0ubuntu322.04, mixed mode, sharing)


export JAVA_HOME=/usr/lib/jvm/java-1.19.0-openjdk-amd64/
export PATH=$PATH:$JAVA_HOME/bin



```



### docker file
```
docker build -t tom/sonarcpp:1.0 .
docker run -d --name sonarqube -p 9000:9000 -p 9092:9092 tom/sonarcpp:1.0

docker pull timx/sonarqube-cxx
docker run -d --name sonarqube-cxx -p 9000:9000 -p 9092:9092 timx/sonarqube-cxx
docker run --name sonarqube-cxx -p 9000:9000 -p 9092:9092 timx/sonarqube-cxx



-----
FROM sonarqube:8.9-community
COPY sonar-custom-plugin-1.0.jar /opt/sonarqube/extensions/
```