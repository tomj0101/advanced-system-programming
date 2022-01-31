//Getting exit status code
#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>

//WIFEXITED and WEXITSTATUS are macros usually defined in 
// /usr/include/sys/wait.h and these macros should have been expanded
// during the compilation stage
#include <sys/wait.h>
int main(int argc, char *argv[]){
	
	int id = fork();
	if(id == -1){
		//exit(1); //is the same of return 1;
		return 1;
	}
	if(id == 0){
		//child process
		int err = execlp("ping","ping","-c","3","google.com",NULL);
		if(err == -1){
			printf("could not find program to execute! \n");
			return 2;
		}
		printf("this should not print in the terminal if all go GOOD ***** \n ");
	}else{
		//parent proces
		int wstatus;
		wait(&wstatus); //wait for all the child process
		if(WIFEXITED(wstatus)){
			int statusCode = WEXITSTATUS(wstatus);
			if(statusCode == 0){
				printf("Success status code %d \n",statusCode);
			}else{
				printf("Error in return of child program, status code %d\n",statusCode);
			}
		}
	}
	return 0;
}
