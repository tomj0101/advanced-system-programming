//Pass Information between child process and parent process 
#include <stdio.h> 
#include <unistd.h>

#include <sys/wait.h>
int main(int argc, char* argv[]){
	int fd[2]; //file descriptor
	//f[0] - read
	//f[1] - write
	if(pipe(fd) == -1){
		printf("An error ocurred with opening the pipe \n");
		return 1;
	}
	int id = fork();
	if(id == 0){
		close(fd[0]);
		int x;
		printf("Input a number: ");
		scanf("%d", &x);
		write(fd[1],&x,sizeof(int));
		close(fd[1]);
	}else{
	
	}
	
	return 0;

}
