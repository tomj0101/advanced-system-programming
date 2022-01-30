//Process ID
#include <stdio.h> 
#include <unistd.h>

#include <sys/wait.h>
int main(int argc, char* argv[]){
	int id = fork(); 
	char *msg = (id == 0)?"I'm Child":"I'm Parent";
	if(id == 0){
		//child process will sleep, parent will finish and child will assign a new parent ID
		sleep(1);
	}
	printf("%s - Current ID: %d, Parent ID: %d \n",msg, getpid(), getppid());	
	
	if(id != 0){ //just execute if you are in the main process
		printf("\n");
	}	

	if(wait(NULL) == -1){
		printf("No children to wait for \n");
	
	}

	return 0;

}
