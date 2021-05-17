#include <iostream>
#include <cstdlib>
using namespace std;

class SimpleArray
{
private:
int Array[20];

public:

SimpleArray()
	{
	for(int i = 0; i < 20; i++)
		{
		Array[i] = 400+rand()%101;
		}
	}

void print();
int getArr(int i)
	{
	return Array[i];
	}
void min()
	{
	int mini = Array[0];
	for(int i = 1; i < 20; i++)
		{
		if(Array[i] < mini)
			{
			mini = Array[i];
			}
		}
	cout <<endl <<"min: "<< mini << endl;
	}
};

void SimpleArray :: print()
	{
	for(int i = 0; i < 20; i ++)
		{
		if(i % 5 == 0)
			{
			cout << endl;
			}
		cout << Array[i] << "\t";
		}
	}

void max(SimpleArray temp)
	{
	int Arr[20];
	for(int i = 0; i<20;i++)
		{
		Arr[i] = temp.getArr(i);
		}
	int maxi = Arr[0];
	for(int i = 1; i < 20; i++)
		{
		if(Arr[i] > maxi)
			{
			maxi = Arr[i];
			}
		}
	cout << endl << "max:" <<  maxi << endl;
	}
int main()
	{
//	srand(time(0));
	SimpleArray obj1;
	obj1.print();
	obj1.min();
	max(obj1);
	return 0;
	}
