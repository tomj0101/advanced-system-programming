//Other practical use of Fork and pipe, divide the sum of array in two process.
//Multiprocess programming
#include <stdio.h> 
#include <unistd.h>

#include <sys/wait.h>
int main(int argc, char* argv[]){
	int arr[] = {1, 2, 3, 4, 1, 2};
	int arrSize = sizeof(arr) / sizeof(int); 
	// sizeof(arr) is the number of byte in the array divide into sizeof(int) number of byte in the 'int'
	int start, end;
	int fd[2];
	//validate if create pipe will fail
	if (pipe(fd) == -1){
		return 1;
	}	
	int id = fork();
	if(id == -1){
		return 2;
	}

	//is a child process?
	if(id == 0){
		start = 0;
		//end = start + 3; for small array is OK but for big array check the size
		end = arrSize / 2;
	
	}else{
		//parent process
		start = arrSize / 2;
		end = arrSize;
	}

	int sum = 0;
	int i;
	for(i = start; i < end; i++){
		sum += arr[i];
	}
	
	printf("calculated partial sum: %d \n",sum);

	//child sending the sum to the parent process
	if(id == 0){
		close(fd[0]);
		if(write(fd[1], &sum, sizeof(sum)) == -1){
			return 3;
		}
		close(fd[1]);
	}else{
		close(fd[1]);
		int sumFromChild;
		if(read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1){
			return 4;
		}
		close(fd[0]);
		printf("Got sum from child : %d \n", sumFromChild);

		int totalSum = sum + sumFromChild;
		printf("Total sum Parent and child is: %d \n", totalSum);
		wait(NULL); //wait for the child process to finish
	}

	return 0;

}
