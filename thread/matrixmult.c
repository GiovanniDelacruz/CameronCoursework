/**************************************************
 *Programmer:	Giovanni Delacruz
 *Instructor:	Dr. Zhao
 *Course:	Operating Systems
 *Program:	Matrix Multiplication using threads
 *Due:		23 October 2020
 *Purpose:	This program allows the user to enter
 *		two matrix dimensions and populate
 *		the matrix with custom values. If the
 *		multiplication is legal, it will 
 *		perform half of the multiplication
 *		using a posix thread and the other half 
 *		using regular program execution.
 *		Once finished, it will display the 
 *		result.
************************************************* */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int a [99][99];		//array for 1st matrix
int b [99][99];		//array for 2nd matrix
int c[99][99]; 		//array to store product of both matricies

char rc[10];		//stores user matrix dimensions from KB
char rc2[10];		//stores user matrix dimensions from KB
int r1,c1,r2,c2,ic,jc;	//tokeinzes and converts KB input to row-columns

void *matrix_thread( void *); //prototype for thread used to multiply



int main(int argc, char *argv[]){
	pthread_t tid;	//thread id

	int ic,jc,kc;	//row-column counters
	char *p;	//used for tokenizing 1st input
	char *p2;	//used for tokenizing 2nd input
	restart:	//code jump label
	matrix1:	//code jump label

	printf("Enter Rows and Columns in AxB format for matrix 1: ");
	scanf("%s",rc);		//prompt user to enter matrix dimensions
	p=strstr(rc,"x");	//separating the dimensions with an 'x'
	if(p==NULL){		//checks if 'x' was not entered
		goto matrix1;	
	}
	char *cds=strtok(rc,"x");   
        if(cds==NULL){		//checks if rows was not entered
		goto matrix1;
	}
	
	r1=atoi(cds);		//convert string value to int, store row
        cds = strtok(NULL,"x");
	if(cds==NULL){		//checks if columns was not entered
		goto matrix1;
	}
	c1 = atoi(cds);		//convert string value to int, store col
	printf("\nRows: %i  Columns: %i  For Matrix 1.\n\n", r1, c1);
	//the code prints out the rows and columns that were entered

	//then it prompts the user to enter each matrix value
	for(ic=0;ic<r1;ic++){
        	for(jc=0;jc<c1;jc++){
            		printf("Enter a[%d][%d] :",ic,jc);
            		scanf("%d",&a[ic][jc]);
        	}
    	}


	//the last code was for matrix 1, the following is for matrix 2
	matrix2:
        printf("Enter Rows and Columns in AxB format for matrix 2: ");
        scanf("%s",rc2);
        p2=strstr(rc2,"x");
        if(p2==NULL){		//check for 'x'
                goto matrix2;
        }
        char *cds2=strtok(rc2,"x");
        if(cds2==NULL){		//check for row value
                goto matrix2;
        }

        r2=atoi(cds2);		//convert row value to int
        cds2 = strtok(NULL,"x");
        if(cds2==NULL){		//check for column value
                goto matrix2;
        }
        c2 = atoi(cds2);	//convert col value to int
        printf("\nRows: %i  Columns: %i  For Matrix 2.\n\n", r2, c2);

	//print matrix 2 row and column values
        for(ic=0;ic<r2;ic++){		//prompt user to enter each matrix value
                for(jc=0;jc<c2;jc++){
                        printf("Enter b[%d][%d] :",ic,jc);
                        scanf("%d",&b[ic][jc]);
                }
        }

	if(c1!=r2){	//check for legal matrix multiplication, restart prog if illegal
		printf("\nThis matrix multiplication is ILLEGAL,\nplease re-enter columns and rows for matrices\n\n");
		goto restart;
	}else{	
	//if good, then clear third array to prepare for matrix multiplication

	for(ic=0;ic<r1;ic=ic+2){
		for(jc=0;jc<c2;jc=jc+2){
			c[ic][jc]=0;
		}
	
	}
	

	//create a thread for multipliying half of the matricies		
	pthread_create(&tid, NULL, matrix_thread, NULL);
	//loop for performing partial of the matrix multiplication
	for(ic=0;ic<r1;ic=ic+2){
		for(jc=0;jc<c2;jc++){
			for(kc=0;kc<c1;kc++){
				c[ic][jc]+=a[ic][kc]*b[kc][jc];
			}
		}
	}
	pthread_join(tid, NULL);	//join thread
}
	printf("\nResult of matrix multiplication\n");
	//use loop to print matrix multiplication results of third matrix
	for(ic = 0; ic < r1; ic++)
	{
		for(jc = 0; jc <c2; jc++)
		{
			printf("%d\t", c[ic][jc]);
		}

		printf("\n");

	}

	return 0;
}


//matrix multiplication pthread function
//performs half of the matrix multiplication of the problem
void *matrix_thread( void* param)
{
        int ic,jc,kc;
        for(ic=1;ic<r1;ic=ic+2){
                for(jc=0;jc<c2;jc++){
                        for(kc=0;kc<c1;kc++){
				c[ic][jc] += a[ic][kc] * b[kc][jc];

                        }
                }
        }


	//once task is finished, terminate thread process
        pthread_exit(NULL);
}

