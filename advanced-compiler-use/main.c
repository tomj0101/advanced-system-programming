// gcc main.c && ./a.out 
#include <stdio.h>

void preprosesor(void);
int main(void){
    preprosesor();
    return 0;
}

/*

viewing Macro Expansion
gcc -E main.c | more
gcc -E main.c > main.pre

# 20 "main.c"
int main(void){
    printf("The MAX is %d and the HALOF(10) is %d\n",500, ((10) / 2));
    printf("LARGER(79,33) is %d\n",(79>33?79:33));
    printf("55" " is equal to %d. \n",55);;

    return 0;
}

*/

//define Preprocesor Directive
#define MAX 500
#define PRINT_FILE_SCREEN printf

//create function macros with #define
#define HALOF(value) ((value) / 2)
#define LARGER(x,y) (x>y?x:y)
#define SQUARE(x) x*x

//Macro function with more code
/*Macro function vs real function
real function: can do your code small because if you call 100, just one function is define.

macro function: your program will have more speed, but the 100 times you call the macro, the code will generated duplicity.
*/
#define OUT(x) printf(#x " is equal to %d. \n",x);
void preprosesor(void){
    printf("======== %s ========\n",__func__);
    PRINT_FILE_SCREEN("The MAX is %d and the HALOF(10) is %d\n",MAX, HALOF(10));
    PRINT_FILE_SCREEN("LARGER(79,33) is %d\n",LARGER(79,33));
    OUT(55);

}

//In linux the Standard directory is /usr/include and usr/local/include
//for adding extra path use -I
//gcc -Wall -I ~/include/oracle main.c -o main
void includeDirective(void){

}

//Control condition #if, #elif, #else and #endif
#if ENGLAND == 1
#include "england.h"
#endif

#if DEBUG ==1
//debugging code here
#endif

/*
Predefined Macros
__FILE__, __LINE__, __DATE__, __TIME__, __func__
*/

/*
Command line argument:
./main test
int main(int argc, char *argv[]){
    if(argc > 1){
        printf("%s",argv[1])
    }

}
*/

/*Reading command-line Argments Using getopt()
int option;
while((option = getopt(argc, argv, "abi:o:z")) != EOF){
    switch(option){
        case a:
        ....
    }
}

*/

//External variable and modular programming.
extern float interest_rate;

/*

make utily
CC = gcc
CFLAGS = -Wall -ggdb # All warnings and debugging
*/

//Using Shared Library = shared = dynamically linked libraries
