#include <stdio.h>

void pointerStep1();
void genericPointer(void *x);


int main(){
pointerStep1();
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
	genericPointer(123);
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
 - DO pass variable by value if you don't want the original value altered.

 DON'T:
 - Don't pass large amounts of data by value if it isn;t necessary, You can run out of Stack space.
 - Don't forget that a variable passed by references should be a pointer. 


 * */


//Type void Pointers
//the void keywork can also be used to create a generic pointer, a pointer that can point to any type of data object.

void genericPointer(void *x){

printf("value of generic pinter %d\n",x);

}
