//communicating between processes using signals
//$ man signal
//https://man7.org/linux/man-pages/man7/signal.7.html
/*
 Answer question to User, if take more than 5sec to answer, then give hint
 * */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <sys/types.h>
#include <unistd.h>

#include <sys/wait.h>

int x = 0;
void handle_sigusr1(int sig){
	if (x == 0){
		printf("\n(HINT) Remeber that multiplication is repetitive addition!\n");
		fflush(stdout);
	}
}


int main(int argc, char* argv[]){

	int pid = fork();
	if(pid == -1){
		return 1;
	}

	if(pid == 0){
		//child process
		sleep(5); //5 second
		kill(getppid(),SIGUSR1);

		
	}else{
		
		//parent process
		
		struct sigaction sa;
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);
		
		printf("what is the result of 3 x 5: ");
		scanf("%d",&x);
		if(x==15){
                        printf("You are right! \n");
                }else{
                        printf("Wrong :( \n");
                }
		wait(NULL); //wait for the parent process to finished
	}


	/*
	User define signal
	SIGUSR1 - 
	SIGUSR2 - 
	 * */	
	return 0;
}
