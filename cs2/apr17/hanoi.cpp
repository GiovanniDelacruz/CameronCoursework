#include <iostream>
using namespace std;

void HanoiTower(int numDisk, char source, char destination, char temp){
	if(numDisk == 1){
		cout << "move disk number " << numDisk << " from " << source<< " to " << destination << endl;
	}else{
		
		HanoiTower(numDisk-1, source, temp, destination);
		cout << "move disk number " << numDisk << " from " << source<< " to " << destination << endl;
		HanoiTower(numDisk-1, temp, destination, source);
	}

}  

int main(){
	cout << "enter the number of disks: ";
	int number;
	cin >> number;
	
	HanoiTower(number, 'S', 'D', 'T');
	
	return 0;

}
