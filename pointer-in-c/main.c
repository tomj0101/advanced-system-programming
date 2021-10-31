#include <stdio.h>

void pointerStep1();

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
