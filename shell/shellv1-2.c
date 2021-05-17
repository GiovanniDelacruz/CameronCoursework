/********************************************************
*	File name:		shell_v1-2.c
*	Author:			Giovanni Delacruz
*	Original author:	C. Zhao
*	Date:			Sept 17, 2020
*	Class:			CS3513
*	Purpose:		Creates a shell that 
*				
***************************************************** */

#include <stdio.h> //for printf() and scanf()
#include <string.h>//strlen(), strcpy(), strcmp()
#include <unistd.h>//execl()
#include <stdlib.h>//exit()
#define SIZE 80//Max command entry
int main()
{
	//variables
	char cmd[SIZE]; //store cmd from kb
	char* argv[80];	//convert cmd w/args
	int argc;	//argument counter
	char *token;	//pointer used for cmd conversion
	int i;
	char* p; //points to path fetched from system
	char *paths[SIZE];
	char* temp;//store one path temp
	int a;

	while(a<50){
	printf("*");
	a++;
	}
	a=0;
	printf("\n");
	printf("\t\tWELCOME TO MYSHELL");
	printf("\n*\n*\nPlease enter a command in the prompt below following '>>'\n*\n*\n");
	while(a<50){
        printf("*");
	a++;
        }
	printf("\n");


	//Path Fetch
	p = getenv("PATH");
	//print path information
	temp = strtok(p, ":");
	i = 0;
	while(temp)//parsing path into 2_d array
	{
		paths[i] = temp;//store temp to paths
		i++;
		temp = strtok(NULL, ":");
	}
	

	//shell command process
	for(;;) //service loop until the user quits
	{
		printf("\nMYSHELL >>");
		fgets(cmd, 80, stdin);//read data from file(keyboard)
		cmd[strlen(cmd)-1]= '\0';//remove line break

		//check if user wishes to exit		
		if(strcmp(cmd, "exit") == 0)
		{
			printf("\nGoodbye\n");
			exit(0);
		}

		//cmd input conversion to command with arguments
		token = strtok(cmd, " ");//set token not null
		int k=0;		//loop variable
		while(token!=NULL){	//convert cmd to multiple
			argv[k]=token;	//strings
			token = strtok(NULL, " ");
			k++;
		}

		argv[k]=NULL;		//set end of array to null
		argc = k;		//set total # of arguments
		//end of conversion

		if(fork() == 0)//child process
		//load the task to it
		{
			int k;
			for(k = 0; k < i; k++)
			//go through all paths
			{
				char path[SIZE];
				strcpy(path, paths[k]);
				strcat(path, "/");
				strcat(path, argv[0]);//connect path to arguments
				execvp(path, argv);//start new process
			}
			printf("\nCOMMAND NOT FOUND, TRY AGAIN\n");
			exit(1);//terminate child process
		}
		else
			wait();//wait for child process term
		
	}//end of for loop
exit(0);
} //end of main
