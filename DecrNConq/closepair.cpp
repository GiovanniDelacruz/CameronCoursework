//Libraries
#include <iostream>
#include <stdlib.h>
#include <time.h>

//predefined value for size of array
#define SIZE 10

//standard namespace
using namespace std;

//variable for closestpair recursion
int num;

//---------------------------------------------------
//function prototypes

//print array
void printarr(int arr[]);

//initializes array with random integers
void init(int arr[]);

//recursively find closest pair with distance
void closestpair(int arr[], int, int, int, int, int);

//print recursion results
void print(int arr[], int, int, int);
//--------------------------------------------------

//comparison function for qsort
int cmp(const void * a, const void *b){
	return(*(int *)a-*(int *)b);
}


//main portion of code
int main(){
	//variables for program
	int l;		//left side index for arr[]
	int r;		//right side index for arr[]
	int x;		//index of point 1
	int y;		//index of point 2
	int dist;	//distance between the two

	//randomize seed
	srand((int)time(NULL));
	int arr[SIZE];	//create array of 10 integers
	init(arr);	//fill array with random values
	l=0;		//left index set to zero
	r=SIZE-1;	//right index set to end of array
	x=l;		//set default point to 0
	y=l+1;		//set default point next to x
	dist=1001;	//distance set larger to 100 for recursion
			//when recursion takes place, distance will be
			//less than 100 for sure
	printarr(arr);	//print array values before sort and before recursion
	
	qsort(arr, SIZE, sizeof(int), cmp);	
	//the array is sorted to make the recursion call more efficient
	//at most, it shall perform n-2 recursive calls
	
	closestpair(arr,l,r,x,y,dist);	//recursive call
	cout <<"\n"<<num;		//finished
	return 0;
}

//Function Definition that initializes all values of the array
void init(int arr[SIZE]){
	for(int i=0;i<SIZE;i++){	//use loop to access each index
		arr[i]= 1+rand()%100;	//fill index with random value
		
	}
}

//Function Definition that recursively searches for the closest two integers
//and returns their distance
void closestpair(int arr[],int left, int right,int x,int y, int dist){
	//base case, the array has been searched and all that remains is 
	//one value
	if(left==right){
	        print(arr,x,y,dist);//print results because array has been searched
		return;		//end recursion
	
	//recursion case
	}else{	
		num = arr[left];//set aside left most value
		//check if the difference between left and its neighbor is current
		//smallest distance
		if((arr[left+1]-num)<dist){//if so, update points and distance
			x = left;
			y = left+1;
			dist = arr[y]-arr[x];
		}
		//recursively call function without leftmost index
		closestpair(arr,left+1,right,x,y,dist);
	}
}

//Function Definition used upon exit of closestpair recursion, prints results
void print(int arr[SIZE], int x,int y, int dist){
	//print closest pair x, y and the distance between the two
	cout << "\nClosest Pair: (" << arr[x] << ","<< arr[y]<<")\n";
	cout << "Distance: "<< dist<<endl;
}

//Function Definition used to print array
void printarr(int arr[SIZE]){
        cout << "\nResults\nArray: ";
        for(int i=0; i<SIZE;i++){	//use loop to generate all array values
                cout << arr[i]<<" ";
        }
	cout << endl;

}
