//introduction to Signals
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

#include <signal.h>

int main(int argc, char *argv){
	int pid = fork();
	if(pid == -1){
		return 1;
	}
	
	if(pid == 0){
		//child process
		int count = 0;

		//this will cause both parent keep waiting and child process keep printing
		//process will need to kill -9 <pid> in the terminal
		//you can do this with signals
		while(1){
			printf("count value %d \n", count);
			++count;
			//usleep(50000); //usleep - suspend execution for microsecond intervals
		
		}
	
	}else{
		int t; //time in second provide by user
		do{
			kill(pid, SIGSTOP); //pause the process execution
			printf("Enter from 1-x second, enter 0(zero) to exit\n");
			printf("Please provide the time in second: ");
			scanf("%d",&t);

			if(t > 0){
				kill(pid, SIGCONT); //resume/continue with the process execution
				sleep(t);
				kill(pid, SIGSTOP);
			}
		
		}while(t > 0);

		kill(pid, SIGKILL); //*** send the signal tio kill the child process
		printf("child process was kill");

		wait(NULL);
	}

}
