//Send string through a pipe
//Bug, should be fix tomorrow! :)
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <sys/types.h>
#include <unistd.h>

#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[]){

	int fd[2];
	if(pipe(fd) == -1){
		return 1;
	}

	int pid = fork();
	if(pid < 0){
		return 2;
	}

	if(pid == 0){
		//child process
		close(fd[0]);
		char str[200];
		printf("Input string: ");
		fgets(str, 200, stdin);
		str[strlen(str) - 1] = '\0';
		
		int n = strlen(str) + 1; //the + 1 is for the last charater of string NULL

		//there is no address for strlen() is evalue in the CPU, no in the memory
		if(write(fd[1], &n, sizeof(int)) < 0){
			return 4;
		}
		//if(write(fd[1], str, sizeof(char) * (strlen(str)+1)) < 0){
		if(write(fd[1], str, sizeof(char) * n) < 0){
			return 3;
		}
		close(fd[1]);
	
	}else{
		//parent process
		close(fd[1]);
		char str[200];
		int n;

		if(read(fd[0], &n, sizeof(int)) < 0){
			return 5;
		}
		if(read(fd[0], str, sizeof(char) * n)){
			return 6;
		}
		wait(NULL);
		printf("Received: %s \n",str);
		close(fd[0]);
		wait(NULL);
	
	
	}
	return 0;
}
