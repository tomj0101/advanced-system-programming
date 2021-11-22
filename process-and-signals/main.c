#include <stdio.h>

#include <stdlib.h> //pid_t


void startPID(void);
void startFork(void);
void zombieProcesses(void);

int main(){
    startPID();
	startFork();
	 zombieProcesses();
    return 0;
}
void startPID(void){
	pid_t pid, ppid;
	pid = getpid();
	ppid = getppid();
	printf("My pid = %d and my Parent's pid = %d \n", pid, ppid);

	/* if you run in the same terminal the proccess id changes but the parent don't changes

	My pid = 1515208 and my Parent's pid = 935052 
	My pid = 1515209 and my Parent's pid = 935052 

	$ps 935052
	PID TTY      STAT   TIME COMMAND
 	935052 pts/0    Ss     0:00 /bin/bash

	ps u # -u userlist:Select by effective user ID (EUID) or name.  This selects the processes whose effective user name or ID is in userlist 
	ps aux #lis all process for all user,session
	
	*/

}

/*Staring another process using fork*/
void startFork(void){
    pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("Child: pid = %u. Parent's pid = %u \n", getpid(), getppid());
	}
}

/*A zombie process is a process that has terminated, but whose parent has not read 
the exit value set by the child. when the parent process terminates,
the zombie process will be removed from the Operating system process table.	

a way to prevent is using wait();
*/
//prevent zombie process using wait()
void zombieProcesses(void){
	pid_t pid;
	int status;
	pid = fork();
	if(pid<0){
		printf("Error: fork() returned %u. \n",pid);
		exit(1);
	}else{
		printf("Parent:pid = %u. Chil's pid = %u \n", getpid(), pid);
		sleep(10);

		pid = wait(&status);
		printf("Parent:pid = %u. Chil's pid = %u \n", getpid(), pid);
		if(WIFEXITED(status) !=0){
			printf("exited with status %d \n", WEXITSTATUS(status));
		}else{
			printf("exited abnormally. \n");
		}
	}

}