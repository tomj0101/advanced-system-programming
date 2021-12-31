#include <stdio.h>
int main(){
	int a = 4;
	int b = 78;
	int c = 33;
	a = 1;
	b = a; 
	printf("Result a=%d, b=%d, c=%d \n",a,b,c);
	printf("Press Any Key to Continue\n");  
	getchar();  
	return 0;
}
