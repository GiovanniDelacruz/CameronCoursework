//Program:	Locker Doors Simulation (Program 1)
//Name:		Giovanni Delacruz
//Instructor:	Professor Monian
//Course:	CS3713 Algorithm Analysis (FA20)
//Date:		09-04-2020
//Compile:	c++ prog1.cpp
//Description:	This program will promt the user to enter how many lockers 
//		they wish to simulate. During the simulation, students 
//		will toggle lockers in front of them and every other locker 
//		their student number is divisible  by (student 2 toggles 2,4,6...).
//		Each locker that is toggled during each pass is displayed.
//		After the final pass, each locker status will be displayed
//		and the total amount of open/closed lockers will be 
//		displyed.
//
//		NOTE: During testing, ada could only handle up to 15 lockers
//
//--------------------------------------------------------------------------
#include <iostream>		//basic input/output stream
using namespace std;		//standard namespace

int main(){

//variables
int lockers;
bool doors[lockers];
int doorsOpn;
int count;

//locker input
cout << "How many lockers are in the hallway? " << endl;
cin >> lockers;
cout << "There are " << lockers << " lockers in the hallway. \n" << endl;

//begin simulation
cout << "Ring Ring! Its intermission.\n Kids are entering the hallway...\n";

//set all lockers to closed
for(int h=0; h<=lockers-1;h++){
	doors[h]=0;
}

//begin passes, outer loop manages passes
//inner loop manages student toggle
for(int i=1; i<=lockers; i++){
	count=i;
	cout<<"Pass no: "<<count<<endl;
	for(int j=count;j<=lockers;j+=count){
		if(doors[j]==0){
			doors[j]=1;
			cout<<"Locker: "<<j<<" :Opened \t";
		}else{
			doors[j]=0;
			cout<<"Locker: "<<j<< " :Closed \t";
		}
	} 
	cout << "\n\n";
}

//display results of lockers after final pass
cout<<"\n----------------------------------------\n";
cout<<"CURRENT LOCKER STATUS AFTER FINAL PASS:\n";
for(int k=1; k<=lockers;k++){
	cout << "locker no: " <<k << " ";
	if(doors[k]==0){
		cout << "door status: closed\n";
	}else{
		cout << "door status: open\n";
		doorsOpn++;
	}
}

//display total amount of closed and open lockers
cout << "total amount of lockers currently open: " << doorsOpn << endl;
cout << "total amount of lockers currently closed: " << lockers-doorsOpn<< endl;
cout << "simulation complete.";

//end simulation
return 0;
};
