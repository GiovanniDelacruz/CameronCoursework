#include <iostream>
using namespace std;

int main()
	{
	int x =100;
	long int y = 5000;
	float z = 20.05;
	cout << "x = " << x << "\t" << &x << endl;
	cout << "y = " << y << "\t" << &y << endl;
	cout << "z = " << z << "\t" << &z << endl;
	int array1[5]= {20,30,40,50,60};
	for(int i = 0; i < 5; i ++)
		{
		cout << "array1[  " << i << "] =" <<  "\t" << &array1[i] << "\t" << array1 << endl; 	// the name of an array is an address
		}
	cout << array1[10] << "\t" << &array1[10] << endl;
	int * ptr1;											// pointers use the *
	ptr1 = &x;
	cout << &ptr1 << "\t" << ptr1 << "\t" << *ptr1 << endl;
	cout << "array1[  " << 0 << "] =" <<  "\t" << *array1 << "\t" << array1 << endl;
//	cout << ptr1[100000] << endl;
//	array1 = &x;											does not work array is a constant pointer
	
	//Dynamic memory
	int *ptr2 = NULL;
	ptr2 = new int;
	*ptr2 = 777; 
	cout << &ptr2 << "\t" << ptr2 << "\t"  <<*ptr2 << endl;

	int *ptr3 = NULL;
        ptr3 = new int[5];
        *ptr3 = 777;
	*(ptr3+1) = 888;
	*(ptr3+2) = 999;
	ptr3[3] = 666;
	ptr3[4] = 555;
	for(int i = 0; i < 5; i++)
		{
		 cout << &ptr3 << "\t" << ptr3 << "\t"  <<ptr3[i] << endl;
		}
	return 0;
	}
