//Pass Information between child process and parent process
//In developer machine, active man commands like  'man fork' , run the next command.
/*
$ sudo unminimize 
*/
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
	if(id == -1){
		printf("An error ocurred with opening the fork \n");
		return 4;
	}
	if(id == 0){
		//child process
		close(fd[0]);
		int x;
		printf("Input a number: ");
		scanf("%d", &x);
		if(write(fd[1],&x,sizeof(int)) == -1){
			printf("An error ocurred with writing to the pipe \n");
			return 2;
		}
		close(fd[1]);
	}else{
		//parent process
		close(fd[1]);
		int y;
		if(read(fd[0],&y,sizeof(int)) == -1){
			printf("An error ocurred with reading to the pipe \n");
			return 3;
		}
		close(fd[0]);
		printf("Got from child process: %d \n",y);	
	}
	
	return 0;

}
