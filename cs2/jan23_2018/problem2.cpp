//------------------------------------------------------------------------------------
//Programmer: 		Giovanni Delacruz
//Course:		Computer Science II
//Instructor: 		Dr.Drissi
//Date: 		1/23/2018
//
//------------------------------------------------------------------------------------
//
//Purpose: 		This program calls up multiple functions to find the perimeter,
//			area, and the cost of a fence around a user-specified dimension.
//			It will also calculate the square and cubes of numbers leading
//			up to a user-specified number.
//------------------------------------------------------------------------------------
#include <iomanip>
#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------------
//function prototypes
int circumferenceRct(int sideA, int sideB);
int areaRct(int sideA, int sideB);
double totalCost(int sideA, int sideB);
void squareAndCubes(int number);
//----------------------------------------------------------------------------------
int main()
	{
 	int sideA, sideB, number;
	cout << "what is the length of your rectangular fence in meters? ";
	cin >> sideA;
	cout << "\nwhat is the width of your rectangular fence in meters? ";
	cin >> sideB;
	cout << "\nthe total perimeter of your fenced area is: " << circumferenceRct(sideA, sideB) << " meters." << endl;
	cout << "\nthe total area of your fence encompasses is: " << areaRct(sideA, sideB) << " meters squared." << endl;
	cout << "\nthe total cost for this project will be: $ " << showpoint << fixed << setprecision(2) <<  totalCost(sideA, sideB) << endl << endl;
 	cout << "What number would you like to find the squares and cubes leading up to? ";
	cin >> number;
	squareAndCubes(number);
 	return 0;
	}
//----------------------------------------------------------------------------------
//Function implemmentation
int circumferenceRct(int sideA, int sideB)
	{
 	return 2 * sideA + 2 * sideB;
	}
int areaRct(int sideA, int sideB)
	{
	return sideA * sideB;
	}
double totalCost(int sideA, int sideB)
	{
	return circumferenceRct(sideA, sideB) * 145.00 + 650.00;
	} 
void squareAndCubes(int number)
	{
	cout << "number\tsquare\tcube" << endl << "-----------------------------" << endl;
	for(int x = 1; x <= number; x++)
		{
		cout << x << "\t" << x * x << "\t" << x * x * x << endl;
		}
	}
