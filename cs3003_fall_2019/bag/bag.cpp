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
	private:
		int arr[SIZE];
		int counter;
};

bag::bag(){					//basic constructor
	counter = 0;
}
bag::bag(int a){				//explicit constructor, makes a bag with an item inside of it
	arr[0] = a;
	counter++;
}
bool bag::add(int a){				//this function will insert an item into the bag and increase the total count of items within the bag
	arr[counter] =a;
	counter++;
}
bool bag::remove(){				//this function generates a random index to remove an item from the array.
	int rmvdNbr;
	rmvdNbr=rand()%10+1;
	cout <<endl << "removed "<< arr[rmvdNbr] << " from the bag." <<endl;
	arr[rmvdNbr] =0;			//afterwards, it notifies the user that "x" has been removed and proceeds to insert a "0" in its place
	for(int i=rmvdNbr;i<SIZE;i++){
			arr[i]=arr[i+1];	//and then it closes the gap that was created upon the removal of "x" and decrements the count
		}
	counter-=1;;
}
void bag::print(){
	cout << "\nitems in bag: "<< endl;	//this function prints out all items in the bag
	for(int i=0; i<counter; i++){
		if(arr[i]!=0){
			cout << arr[i]<<endl;
		}
	}
}
bool bag::empty(){				//this function returns a "1" if the bag is empty and a "0" if it is not empty
	int temp =0;
	for(int i=0;i<counter;i++){
		if(arr[i]=!0){
			temp++;
		}
	} 
	if(temp>0){
	
		return false;
	}else{
		
		return true;
	}
}
bool bag::full(){				//this function is like the "empty" function, but checks for a full bag
	if(counter ==10){
		
		return true;
	}else{
		
		return false;
	}

}
int bag::size(){				//this function returns the total amount of items contained in the bag
	return counter;

}

void bag::reset(){				//this function completely empties the bag
	for(int i=0; i<SIZE; i++){
		arr[i]=0;
	
	}
	counter=0;
	cout << endl << "\nThe bag has been reset!!!" << endl;
}

#endif
