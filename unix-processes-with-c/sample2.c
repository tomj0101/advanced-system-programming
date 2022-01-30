//Wait for other process to finished
//Sample2: Count from 1-5 in one process and 6-10 in other process, print number in order
#include <stdio.h> 
#include <unistd.h>

//#include <sys/types.h>
//#include <sys/wait.h>

int main(int argc, char* argv[]){
	//The Child process created by fork, the chield process have the same memory of the parents
	int id = fork(); 
	
	int n;
	if(id == 0){
		n = 1;
	}else{
		n = 6;
	}
	
	if(id !=0){
		//stop the execution until child process completed.
		wait(); //wait in the main process for the child process finished.
		//use header for avoid warning:
		//implicit declaration of function ‘wait’ [-Wimplicit-function-declaration]
	}
		
	int i;
	for(i = n; i < n + 5; i++){
		printf("%d ",i);
		fflush(stdout); //clear (or flush) the output buffer in the screen
	}
	
	if(id != 0){ //just execute if you are in the main process
		printf("\n");
	}	
	return 0;

}
