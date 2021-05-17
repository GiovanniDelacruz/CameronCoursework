#include <iostream>
#include <stdlib.h>
#include"bag.cpp"
using namespace std;

int main(){
	bag tee;
	srand(time(NULL));

	for(int i=0; i<SIZE; i++){
		tee.add(rand()%100+1);
	}
	cout << "Is the bag full? " << tee.full();

	tee.print();
	tee.remove();
	tee.print();
	cout << "\n the last item in the bag is: " <<tee.get_back()<<endl;
	cout << "is the bag empty? "<<tee.empty()<<endl;
	cout << "the amount of items in the bag is: " <<tee.size()<<endl;
	tee.reset();
	cout << "is the bag empty? "<<tee.empty()<<endl;
	cout << "the amount of items in the bag is: " <<tee.size()<<endl;
	

return 0;
}
