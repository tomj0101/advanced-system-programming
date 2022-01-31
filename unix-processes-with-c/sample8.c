//Exec command in C
#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	//execlp("ping","ping","-c","3","google.com",NULL);
	//remplace all memory, execution line by the command executed, printf will not be printed.
	//printf("Success\n");
	
	int id = fork();
	if(id == -1){return 1;}
	if(id == 0){
		//child process
		execlp("ping","ping","-c","3","google.com",NULL);
		printf("this should not print in the terminal ***** \N ")
	}else{
		//parent proces
		wait(NULL); //wait for all the child process
		printf("Success exec \n");
	}
	return 0;
}
