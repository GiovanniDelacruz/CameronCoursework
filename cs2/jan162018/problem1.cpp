//Programmer: Giovanni Delacruz
//Instructor: Dr. Drissi
//Course: Computer Science II
//Date: January 16, 2018
//
//Purpose: This program will use multiple functions to create an array
//with random elements and perform a partial sum on the all elements
//in the array. It will then print the array and print the max and min
//of the array.
//
//*********************************************************************
//
#include <iostream>
#include <cstdlib>
using namespace std;
//
//********************************************************************
//function prototypes

void fillArray(int Array[], int SIZE);	//fills the array with integers between 200-450

void printArray(int Array[], int SIZE);	//prints the array

int minArray(int Array[], int SIZE);	//returns the smallest element in the Array

int maxArray(int Array[], int SIZE);	//returns the largest element in the Array

void partialSum(int Array[], int SIZE);	//performs a partial sum each element in the Array

//*********************************************************************
//main

int main(){

	const int SIZE = 20;
	int Array1[SIZE];
	srand(time(0));
	
	fillArray(Array1, SIZE);
	printArray(Array1, SIZE);
	partialSum(Array1, SIZE);
	printArray(Array1, SIZE);
	cout << "The minimal element is: " << minArray(Array1, SIZE) << endl;
	cout << "The maximal element is: " << maxArray(Array1, SIZE) << endl;
	return 0;
}

//*********************************************************************
//functions

void fillArray(int Array[], int SIZE)
{
	for(int i = 0; i <= SIZE - 1; i++)
	{
	 Array[i] = 200 + (rand() % (450 - 200 + 1));
	}
}

void printArray(int Array[], int SIZE)
{
	cout << endl;
	int count = 0;
	for(int i = 0; i <= SIZE - 1; i++)
	{
	 cout << Array[i] << "\t";
	 count++;
	 if(count % 5 == 0)
	 {
	  cout << endl;
	 }
	}
}

int minArray(int Array[], int SIZE)
{
	int min = Array[0];
	for(int i = 0; i <= SIZE - 1; i++)
	{
	 if(Array[i] < min)
	 {
	 min = Array[i];
	 }
	}
	return min;
}

int maxArray(int Array[], int SIZE)
{
	int max = Array[0];
	for(int i = 0; i <= SIZE - 1; i++)
	{
	 if(Array[i] > max)
	 {
	 max = Array[i];
	 }
	}
	return max;
}

void partialSum(int Array[], int SIZE)
{
	for(int i = 1; i <= SIZE - 1; i++)
	{
	Array[i] = Array[i] + Array[i-1];
	}
}
