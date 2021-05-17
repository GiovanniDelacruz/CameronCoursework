#include <iostream>
#include <cstdlib>
using namespace std;

class DynamicArray{

	private:
		int *storage;
		int capacity;
		int size;
	public:
		DynamicArray(){
			capacity = 5;
			size = 0;
			storage = new int[capacity];				//new allocates memory
		}
		void print(){
			cout << "*******************************************\n";
			cout << "Capacity: " << capacity << "\t" << "Size: " << size << endl;
			for (int i =0; i < size; i++){
				cout << storage[i] << "\t";
				//cout << *(storage+1) << "\t"; ---------------> this is the pointer way to write the previous line
				if (i%5==4) cout << endl;	
			}
			cout << "\n*******************************************\n";
		}
		void addElement(int x){
			if(size == capacity){
				int *temp = new int[capacity +5];
				for(int i = 0; i < size; i++){
					temp[i] = storage[i];
					//*(temp+i) = *(storage+i);------------> pointer notation
				}
			capacity = capacity +5;
			delete []storage;			// free the memory allocated for storage
			storage = temp;
			}
			storage[size] = x;
			size +=1;
		}
//		void removeElement(int x){
//			int count = 0;
//			int count2=0;
//			if(size == capacity-5){
//				int *temp = new int[capacity-5];
//				for(int i = 0; i < size; i++){
//				temp[i] = storage[i];
//				}
//			capacity -= 5;
//			delete [] storage;
//			storage = temp;
//			}
//			for(int i = 0; i < size; i ++){
//			if(storage[i] == x){
//				 storage[i] = 10001;
//				 count2++; 
//				}
//			}
//			capacity-=count2;
//			int *temp2 = new int[capacity];
//			for(int i = 0; i<size; i++){
//			if(storage[count] == 10001) count++;
//			temp2[i] = storage[count];
//			count++;
//			}
//			delete []storage;
//			storage = temp2;
//		
//		}

void removeElement(int x){
        for(int i = 0; i < size; i++){
                if(storage[i] == x){
                        int j = i;
                        while(j < size-1){
                        storage[j] = storage[j+1];
			j++;                        
			}
                        i = size;
                        size--;
                }
        }
	if(size==capacity-5){
	int *temp = new int[capacity-5];
	for(int i = 0; i < size; i++){
		temp[i] = storage[i];
	}
	delete []storage;
	capacity-=5;
        storage = temp;

	}
}

};

int main(){
	int x1;
	DynamicArray obj;
	for(int i = 0; i < 22; i++){
		obj.addElement(rand()&201);
		if(i%4==3) obj.print();
	}
	obj.print();
	cout << "what would you like to remove?";
	cin >> x1;
	obj.removeElement(x1);
	obj.print();
	
	cout << "what would you like to remove?";
        cin >> x1;
        obj.removeElement(x1);
        obj.print();
	
	cout << "what would you like to remove?";
        cin >> x1;
        obj.removeElement(x1);
        obj.print();

	cout << "what would you like to remove?";
        cin >> x1;
        obj.removeElement(x1);
        obj.print();
	
	
	return 0;
}
