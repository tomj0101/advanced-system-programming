//Handle signals
//How prevent that when CTRL+Z hit don't stop.
//$ man signal
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_sigtstp(int sig){
	printf("stop not allow\n");
}

void handle_sigtcont(int sig){
        printf("Input Number: \n");
	fflush(stdout); //this make sure the line print on the screen.
}

int main(int argc, char* argv[]){
	//Option 2: historical this provider more portability between different UNIX and Linux version
	/*
	struct sigaction sa;
	sa.sa_handler = &handle_sigtstp;
	sa.sa_flags = SA_RESTART; //this is because we have printf
	sigaction(SIGTSTP, &sa, NULL); //process can't send to background any more
	*/

	//Option 1
	//signal(SIGTSTP,&handle_sigtstp);
	signal(SIGCONT,&handle_sigtcont);
	
	int x;
	printf("enter a number: ");
	scanf("%d",&x);
	printf("power of %d is %d \n", x, (x * x));
	return 0;
}
