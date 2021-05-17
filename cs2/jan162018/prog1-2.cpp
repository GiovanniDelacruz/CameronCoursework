#include <iostream>
#include <cstdlib>
using namespace std;

int Array[20];

void fillArray();
void printArray();
int minArray();
int maxArray();
void partialSum();

int main()
{
	fillArray();
	printArray();
	partialSum();
	printArray();
	cout << "The minimal element is: " << minArray() << endl;
	cout << "The maximal element is: " << maxArray() << endl;
}

void fillArray()
{
	for(int i = 0; i<= 19; i++)
	{
	Array[i] = 200 + rand() % 251;
	}
}

void printArray()
{
	cout << endl;
	int count = 0;
	for(int i = 0; i <= 19; i++)
	{
	cout << Array[i] << "\t";
	count++;
	if(count % 5 == 0)
	 {
	 cout << endl;
	 }
	}
}

void partialSum()
{
	for(int i = 1; i <= 19; i++)
	{
	Array[i] = Array[i]+Array[i-1];
	}
}

int minArray()
{
	int min = Array[0];
	for(int i = 0; i <= 19; i++)
	{
	if(Array[i] < min)
	 {
	 min = Array[i];
	 }
	}
	return min;

}

int maxArray()
{
	int max = Array[0];
	for(int i = 0; i <= 19; i++)
	{
	 if(Array[i] > max)
	 {
	 max = Array[i];
	 }
	}
	return max;
}
