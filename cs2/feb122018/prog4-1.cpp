#include <iostream>
#include <cstdlib>
using namespace std;

class SimpleArray
{
private:
int Array[20];
static int size;				//you do not need to keep using 20, instead use size
public:

SimpleArray()
	{
	for(int i = 0; i < size; i++)
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
	for(int i = 1; i < size; i++)
		{
		if(Array[i] < mini)
			{
			mini = Array[i];
			}
		}
	cout <<endl <<"min: "<< mini << endl;
	}
	friend void max(SimpleArray);	//	------->			gives max authority to access the class
};
SimpleArray::size=20;				//need to give size a value directly after class
void SimpleArray :: print()
	{
	for(int i = 0; i < size; i ++)
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
	for(int i = 0; i<size;i++)
		{
		Arr[i] = temp.Array[i];		//-----> 			it can now access the private array
		}
	int maxi = Arr[0];
	for(int i = 1; i < size; i++)
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
	cout << "size equals: " << simpleArray::size << endl;
	SimpleArray obj1;
	obj1.print();
	obj1.min();
	max(obj1);
	return 0;
	}
