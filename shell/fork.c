/***************************************************
*	file name:	fork.c
*	Author:		C. Zhao
*	Date:		Aug.. 16, 2020
*	Class:		CS3513
*	Purpose:	Create two processes: each 	
*			complete a task.
************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	int pid; //process id
	pid = fork();//create a new process
	if( pid == 0)//child process
	{
		printf("\nMy id is: %i\n", (long)getpid());
		printf("\nMy parent id is %i\n", getppid());
		//system("ls");
		execl("/bin/ls", "ls", 0);
	}
	else{//parent process
		wait();//wait for child process termination
		printf("\nMy id is %i\n", (long)getpid());
		printf("\nMy child id is %d\n", pid);
		system("who");
	}
	
	return 0;
}
