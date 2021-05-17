/************************************************************************
*
*Date: 		9/10/2019
*Course: 	CS3003
*Instructor: 	Dr. Zhao
*Name:		Giovanni Delacruz
*
*THIS PROGRAM:
*		finds the smallest value recursively from a positive integer array
*		finds the largest value recursively from a positive integer array
*		prints the array
*		initializes the array
*		converts any positive integer into its binary equivalent
*
************************************************************************ */


//--------------------------------------------------------------------------
#include <iostream>					//imported libraries
#include <time.h>
#include <stdlib.h>
//--------------------------------------------------------------------------


#define SIZE 10	
using namespace std;


//-------------------------------------------------------------------------
void dec_2_bin(int);					//function prototypes
int find_min(int[], int, int);
void print(int[], int, int);
void init(int[], int);
int find_max(int[],int,int);
//--------------------------------------------------------------------------


//--------------------------------------------------------------------------
int main(){						//main function
	int a[SIZE], num;				//that calls each function
	init(a, SIZE);
	print(a,0, SIZE-1);
	cout << endl;
	cout <<"\nMin: "<<find_min(a,0,SIZE-1);
	cout <<endl;
	cout <<"\nMax: "<<find_max(a,0,SIZE-1);
	cout <<"\nEnter a positive number: ";
	cin >> num;
	dec_2_bin(num);
	cout << endl;
	return 0;
}
//--------------------------------------------------------------------------


//--------------------------------------------------------------------------
void dec_2_bin(int n){					//this function converts
	if(n==0){					//a positive integer
		return ;				//into a binary number
	}else{						//recursively
		dec_2_bin(n/2);
		cout<<" "<< n%2;
	}
}
//--------------------------------------------------------------------------


//--------------------------------------------------------------------------
void init(int a[], int n){				//this function initializes
 	int i; 						//an array with random
	srand(time(NULL));				//integers between
	for(i=0;i<n;i++){				//0-100 recursively
		a[i] =rand()%100;
	}
}
//--------------------------------------------------------------------------


//--------------------------------------------------------------------------

void print(int a[], int left, int right){		//this function prints 
	if(left<=right){				//the contents of the 
		cout <<a[left]<<" ";			//array recursively
		print(a,left+1,right);			//side-by-side
	}
}
//--------------------------------------------------------------------------


//--------------------------------------------------------------------------
int find_max(int a[], int left, int right){		//finds max element of 
	if(left==right){				//the array recursively
		return a[left];
	}else{
		int max= find_max(a,left+1,right);	//initializes max recursion call
		if(max>a[left]){			//compares values
			return max;
		}else{
			return a[left];
		}
	}

}
//--------------------------------------------------------------------------


//--------------------------------------------------------------------------
int find_min(int a[], int left, int right){		//finds min element of
	if(left==right) 				//the array recursively
	{
		return a[left];
	}else{
		int min= find_min(a,left+1,right);	//initializes min recursion call
		if(min<a[left]){			//compares values
			return min;
		}else{
			return a[left];
		}
	}
}
//--------------------------------------------------------------------------

