#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 100

int main(int argc, char *argv[]){
	char* msg_from_server = "Server IPC Shared memory";
	int size_of_msg = strlen(msg_from_server);

	//printf("%d \n",size_of_msg);	
	
	int shmid;
	key_t key;
	char *shm;
	char *s;

	key = 1167;

	shmid = shmget(key, SHSIZE, IPC_CREAT | 0666);
	if(shmid < 0){
		perror("shmget");
		exit(1);

	}
	
	shm = shmat(shmid, NULL, 0);

	if(shm == (char *)-1){
		perror("shmat");
		exit(1);
	}
	
	memcpy(shm, msg_from_server, size_of_msg);
	
	s = shm;
	s += size_of_msg;

	*s = 0;
	while(*shm != '*')
		sleep(1);

	return 0;
}
/*
man shmop
shmat, shmdt - System V shared memory operations.

Compile both server and client:
cc -o sm_server.o sm_server.c && cc -o sm_client.o sm_client.c
./sm_server.o
./sm_client.o


#list
ipcs -m

#list with PID
ipcs -mp

#remove
ipcrm -M <KEY>
ipcrm -M 1167

 Symbolic notation	Numeric notation	English
-r--r--r--		0444			read
-r-xr-xr-x		0555			read & execute
-rw-rw-rw-		0666			read & write
-rwxr-----		0740			owner can read, write, & execute; group can only read; others have no permissions
 * */
