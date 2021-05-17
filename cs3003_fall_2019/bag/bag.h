/* *************************************************************
*	Name:		Giovanni Delacruz
*	File name:	bag.cpp
*	Class:		CS3003
*	Date:		Aug. 27, 2019
*	Description:	This file defines a bag class.  it has the
 			following atributes/methods:
			bag() constructor
			bag(int) explicit constructor
			add() adding an item to bad
			remove() removing an item from bag
			print() print all items
			full() return true if the bag is full
			empty() return true if the bag is empty
			size() return the number of items
			reset()reset the bag empty
			array store items
			counter counting items in the bag
************************************************************* */
#include <iostream>
#include <stdlib.h>
#define SIZE 10
using namespace std;
#ifndef BAG_H
#define BAG_H
class bag
{
	public:
		bag();
		bag(int);
		bool add(int);
		bool remove();
		void print();
		bool empty();
		bool full();
		int size();
		void reset();
		int get_back();
	private:
		int arr[SIZE];
		int counter;
};
#endif

