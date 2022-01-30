//Create fork process.
#include <stdio.h> //note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
//#include <string.h>
//#include <stdlib.h>
#include <unistd.h> //for have the fork, this is a UNIX, Linux library only

int main(int argc, char* argv[]){
	int id = fork(); 
	printf("Sample 1.1 id %d \n",id);
	//if the id is 0 you are in the child process, if not zero you are in the main process
	if(id == 0){
		printf("you are in the child process \n");
	}else{
		printf("you are in the main process \n");
	}
	//getchar(); this is causing child process keep alive
	
	
	if(id !=0){ //main process
		getchar(); //this will causing child process go defunct: [sample1] <defunct>, Ok for check this example
	}
	return 0;

}
