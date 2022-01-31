//Intro to FIFO in C (also aka named pipe)
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#include <fcntl.h> //for open fifo file
int main(int argc, char* argv[]){
	//errno = 0 here
	//create fifo file
	if(mkfifo("myfifo", 0777 ) == -1){
		if(errno == EEXIST){ 
			//errno = 17: here if the file exits
			//EEXIST = 17: EEXIST is a constant, alway the value is 17;
			printf("could no create fifo file \n");
			return 1;
		}
	}

	//open fifo file
	printf("opening... \n");
	int fd = open("myfifo1", O_RDWR); //this return a file descriptior, open for reading/written.
	/*
	try this on Desktop Linux computer:
	int fd = open("myfifo1", O_WRONLY); //this return a file descriptior
	 * */
	printf("opened. \n");
	
	int x = 97;
	if(write(fd, &x, sizeof(x)) == -1){
		return 2;
	}
	printf("written.\n");
	close(fd);
	printf("close.\n");

	//if desktop OS Unix-like this can hands until read, on cloud can close to prevent terminal free.
	//cat myfifo 
	 
	/*
	 I can create the FIFO file using the program mkfifo
	 $ mkfifo myfifo2
	 * */

	/*
	review the program return code after finished execution:
	$ echo $?
	Exit status of Linux/Unix Commands
	0 = executed succesfully
	127 = command not found	
       
       */
	
	return 0;

}
