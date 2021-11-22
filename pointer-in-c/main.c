#include <stdio.h>

#include <stdlib.h> //pid_t

void pointerStep1();
void genericPointer(void *x);
void checkAllocationMemory();
void processAndSignals(void);


int main(){
	//pointerStep1();
	checkAllocationMemory();
	processAndSignals();
return 0;
}

void pointerStep1(){
	int rate = 19;
	int *p_rate = &rate;
	printf("rate value = %d \n" , rate);
	printf("rate mem address= %lu \n", &rate);
	printf("p_rate value -> mem address of rate = %lu \n",p_rate);
	printf("p_rate value -> get value from mem address of rate = %d \n",*p_rate);
	passingPointerToFunction(&rate);
	//genericPointer(123);
	//genericPointer(1.56); for this work should create the function like this
	//void genericPointer(void *x, char type), then use switch(type), finally call genericPointer(1.56,'f');

}

/*

rate value = 19 
rate mem address= 140725010815668 
p_rate value -> mem address of rate = 140725010815668 
p_rate value -> get value from mem address of rate = 19

 * */
//passing by ref
void passingPointerToFunction(int *rate){

	printf("\n\nvalue passed to rate = %d\n",*rate);

}

//passing by value
int func1(int rate){

return rate + 10;
}


/*
 DO:
 - DO pass variable by 	int BLOCKSIZE;


//Type void Pointers
//the void keywork can also be used to create a generic pointer, a pointer that can point to any type of data object.

void genericPointer(void *x){

printf("value of generic pinter %d\n",x);

}

/*check if allocation successful*/
#define BLOCKSIZE 30000
void checkAllocationMemory(){
	void *ptr1;
	ptr1 = malloc(BLOCKSIZE);
	if(ptr1 != NULL){
		printf("allocation of %d bytes successful. \n", BLOCKSIZE);
	}else{
		printf("attemp to allocate %d bytes failed. \n", BLOCKSIZE);
		exit(1);
	}
}

void processAndSignals(void){
	pid_t pid, ppid;
	pid = getpid();
	ppid = getppid();
	printf("My pid = %d and my Parent's pid = %d \n", pid, ppid);

}