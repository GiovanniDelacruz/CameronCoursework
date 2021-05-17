//BINARYHEX_MAIN.CPP
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//Programmer:	Giovanni Delacruz
//Instructor:	Dr. Zhao
//Course:	CS3013 Fall20
//Date:		9/11/2020
//Program:	binaryhex
//Compile:	c++ binaryhex_main.cpp
//Language:	c++
//----------------------------------------------------------------------
//Purpose:	This Program will generate 0-255 in decimal, binary, 
//		and hexadecimal and display them side by side.
//----------------------------------------------------------------------
//----------------------------------------------------------------------

#include "binaryhex.h"
#include <iostream>
using namespace std;

int main(){
			
	int SIZE=8;			//size of array
	int s[SIZE];			//initialize array for storing bits
	int count=0;			//counter
	int m, n;			//integers used for hex conversion

	int i=0;
	while(i<8){			//reset bit array
		s[i]=0;
		i++;
	}
	
	i=0;

	//title formatting
	cout<<"WELCOME TO THE BINARY AND HEX CONVERTER!\n\npress enter twice to continue...";
	cin.ignore();
	cin.get();
	cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"THIS PROGRAM PRINTS 0-255 IN DECIMAL, BINARY, AND HEXADECIMAL SO YOU DON'T HAVE TO!\n\npress enter twice to start...";
	cin.ignore();
	cin.get();
	cout<<"\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
	cout << "DECIMAL\tBINARY\t\tHEXADECIMAL\n";
	cout<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
	//generate 0-255 integers in a loop
	while(i<256){
	cout<<i<<"\t";
	generate_bin_string(s,i,SIZE);		//while on number i, convert to binary
	print_binary(s,count,SIZE);		//print binary i
	convert_bin_hex(s,n,m);			//convert the binary result to hex and print
	i++;
	}

}
