//Exec command in C
#include <stdio.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[]){
	//execlp("ping","ping","-c","3","google.com",NULL);
	//remplace all memory, execution line by the command executed, printf will not be printed.
	//printf("Success\n");
	
	int id = fork();
	if(id == -1){return 1;}
	if(id == 0){
		//child process
		int file = open("pingResult1.txt", O_WRONLY | O_CREAT, 0777); //Permission 0777 = the first zero is very important to said this is octal value, and not decimal 
		if(file == -1){
				return 2;
		}
		printf("Print information before redirect STDOUT to pingResult1.txt using dup2 \n");

		//int file2 = dup2(file,1);//redirect the stdout from screen to pingResult.txt files and all the other linea.
		int file2 = dup2(file, STDOUT_FILENO); //dup, dup2, dup3 - duplicate a file descripto
		close(file); //for avoid have two file descriptor open

		int err = execlp("ping","ping","-c","3","google.com",NULL);
		if(err == -1){
			printf("cuild not find exec program");
			return 2;
		}
		printf("this should not print in the terminal ***** \n ");
	}else{
		//parent proces
		int wstatus;

		//wait(NULL); //wait for all the child process
		wait(&wstatus);
		printf("Success exec %d \n",wstatus);
	}

	/*
	File Descriptior        file
	      0                STDIN
	      1                STDOUT
	      2                STDERR

	      3                pingResult.txt
	 * */
	return 0;
}
