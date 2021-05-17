#include <iostream>
#include <cstdlib>
using namespace std;

int Array[20];

void fillArray();
void printArray();
void mirrorImage();

int main()
{
	fillArray();
	printArray();
	mirrorImage();
	printArray();
}

void fillArray()
{
	for(int i = 0; i<= 19; i++)
	{
	Array[i] = 100 + rand() % 201;
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
	if(count % 4 == 0)
	 {
	 cout << endl;
	 }
	}
}

void mirrorImage()
{
	int temp, temp2;
	 for(int i = 0; i < 10; i++)
	 {
	 temp = Array[10+i];
	 temp2 = Array[10-i];
	 Array[10-i] = temp;
	 Array[10+i] = temp2;
	 }
	int temp3 = Array[0];
	for(int i = 0; i <= 19; i++)
	{
	Array[i-1] = Array[i];
	}
	Array[19] = temp3;	

}


