/* *************************************************************************************
*	file name:  bin_search.cpp
************************************************************************************** */

#include<iostream>
#include<stdlib.h> //rand() used
#define SIZE 100

using namespace std;

void init(int []);	
void print(int[]);	
int compare(const void *, const void *); //for qsort
bool bin_search(int[], int, int, int);

int main(){
	srand(time(NULL));
	int list[SIZE];
	init(list);
	print(list);
	cout<<"\n\n\n";
	cout<<"sorted list: \n";
	qsort(list, SIZE, sizeof(int), compare);
	print(list);
	int key = 1+rand()%100;
	cout <<"\nrandom key to search for: " <<key <<endl;
	if(bin_search(list, 0, SIZE-1, key)){
		cout << "found" <<endl;
	}else{
		cout <<"\nnot found"<< endl;
	}
	return 0;

}

void init(int a[]){
	for(int i=0; i<SIZE; i++){
		a[i]=1+rand()%100;
	}
}

void print(int a[]){
	for(int i=0;i<SIZE;i++){
		cout <<a[i]<<endl;
	}
}

int compare( const void* a, const void* b){
	const int* x =(int*) a;
	const int* y =(int*) b;

	if(*x > *y){
		return 1;
	}else if(*x < *y){
		return -1;
	}else{
		return 0;
	}
}

bool bin_search(int list[], int left, int right, int key){
	int mid;
	if(left >right){
		return false;
	}else{
		mid = (left+right)/2; //can use left+right/2 for bigger comparisons
		if(list[mid]==key){
			return true;
		}else if(list[mid] >key){
			bin_search(list,left,mid-1,key);
			bin_search(list,left,mid+1,key);
		}
	}
}
