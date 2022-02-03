//Background and foreground process
//CTRL+Z ./main has stopped,is like send SIGSTOP from terminal
//$ fg  #fg command bring the process from foreground, SIGCONT
//$ fg <pid_or_job_id>
//CTRL+C send a signal of SIGKILL
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	int x;
	printf("enter a number: ");
	scanf("%d",&x);
	printf("power of %d is %d \n", x, (x * x));
	return 0;
}
