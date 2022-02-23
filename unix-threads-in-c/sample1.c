/*
 * use the link option on when is using pthread
 * gcc -g -pthread sample1.c -o sample1 && ./sample1
 * */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* routine(){

	printf("Test from threads\n");
	sleep(3);
	printf("Ending Thread\n");
}

int main(int argc, char* argv[]){

	pthread_t t1,t2; //create a struct/variable to storage information for the thread
	pthread_create(&t1, NULL, &routine, NULL); //create the thread
	pthread_create(&t2, NULL, &routine, NULL); //create the thread
	pthread_join(t1,NULL); //similar to wait funtions
	pthread_join(t1,NULL); 

	return 0;
}


