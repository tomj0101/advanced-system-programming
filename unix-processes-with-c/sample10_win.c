//I didn't test this code yet, I need to turnon my personal windows laptop (I have more than 3 months without even login)
#include <stdio.h>

#include <sys/types.h>
//#include <unistd.h> this is the header for Linux
#include <process.h> //header for windows :)
#include <errno.h>

#include <sys/wait.h>
int main(int argc, char *argv[]){

	//_execlp("ping","ping","google.com",NULL); //the ..l is for list of parameters AND the ..p = used the path variable that load in the terminal.	
	//_execvp("ping",arr): the ..v= take a vector as parameters.
	
	//_execvpe("ping",arr, env): the ..e use a enviroments also vector.
	/*
	_execl(
		"C:\\Windows\\System32\\ping.exe",
		"C:\\Windows\\System32\\ping.exe",
		"google.com",
		NULL);
	*/
	int err = errno;
	printf("THIS LINE IS NOT PRINT");//this line will not print, _execl overwrite everything
	return 0;
}
