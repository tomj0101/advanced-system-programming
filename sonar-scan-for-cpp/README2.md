# Sonar scan for C & C++
```
Run the server
$ docker-compose up
http://localhost:9000/
default password is admin/admin


Create a Token
User > My Account > Security
http://localhost:9000/account/security/

export SONAR_TOKEN="329f05fe7aca13bfb8fa52cdf0ea36d8f55086d7"

Run the scanner
/var/opt/sonar-scanner-4.7.0.2747-linux/bin/sonar-scanner


docker-compose down
```

### install plugin
```
$ wget https://github.com/SonarOpenCommunity/sonar-cxx/releases/download/cxx-0.9.7/sonar-cxx-plugin-0.9.7.jar  # get sonar-cxx v0.9.7

$ docker ps
CONTAINER ID   IMAGE                       COMMAND                  CREATED          STATUS          PORTS                                       NAMES
938f5f7cfb1f   sonarqube:8.9.2-community   "bin/run.sh bin/sona…"   30 minutes ago   Up 30 minutes   0.0.0.0:9000->9000/tcp, :::9000->9000/tcp   sonar-scan-for-cpp-sonarqube-1
81797f95af8e   postgres:13                 "docker-entrypoint.s…"   30 minutes ago   Up 30 minutes   5432/tcp                                    postgresql


$ sudo docker cp ./sonar-cxx-plugin-0.9.7.jar sonar-scan-for-cpp-sonarqube-1:/opt/sonarqube/extensions/plugins/sonar-cxx-plugin-0.9.7.jar  # install plugin into plugin directory

$ sudo docker exec sonar-scan-for-cpp-sonarqube-1 "ls"

sudo docker restart sonar-scan-for-cpp-sonarqube-1


Ref:
https://github.com/SonarOpenCommunity/sonar-cxx
https://github.com/SonarOpenCommunity/sonar-cxx/wiki/Install-the-Plugin
https://github.com/SonarOpenCommunity/sonar-cxx/releases/tag/cxx-0.9.7

```
### previous requiredment
```
docker, docker-compose
```
