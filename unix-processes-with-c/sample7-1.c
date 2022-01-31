//Communication between FIFO and process
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#include <fcntl.h> //for open fifo file

#include <time.h>
int main(int argc, char* argv[]){
	//## Create FIFO
	//$ mkfifo sum
	//$ file sum
	//sum: fifo (named pipe)	
	int arr[5];
	srand(time(NULL));
	int i;
	for(i=0;i<5;i++){
		arr[i] = rand() % 100; //% 100 for set number up to 99 
	
	}

	//## Open FIFO

	int fd = open("sum", O_WRONLY);
	if(fd == -1){
		return 1;
	}

	//## Write FIFO
	for(i =0; i<5; i++){
		if(write(fd, &arr[i], sizeof(int)) == -1){
			return 2;
		}
		printf("Wrote %d\n",arr[i]);
	}
	/*
	You can write or read all as one without need to iterated the array
	#1 - remove the for.
	#2 - send the complete arr.

	if(write(fd, &arr, sizeof(int) * 5) == -1){
                        return 2;
          }
	 * */
	close(fd);
	
	return 0;

}
