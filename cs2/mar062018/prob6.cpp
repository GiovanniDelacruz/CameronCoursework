#include <iostream>
using namespace std;

class Wagon{

	private:

		int storage;
		Wagon *next;

	public:

		int getStorage(){
			return storage;
		}

		Wagon *getNext(){
			return next;
		}
		
		void setStorage(int x){
			storage = x;
		}
		
		void setNext(Wagon *y){
			next = y;
		}
};

class Train{

	private:
		Wagon *first;
		int size;

	public:
		Wagon *getFirst(){
			return first;
		}
		
		int getSize(){
			return size;
		}
		
		void setFirst(Wagon *x){
			first = x;
		}
		
		void setSize(int y){
			size = y;
		}
		
		
		Train(){
			first = NULL;
			size = 0;
		}

		void addWagonToFront(int x){
			Wagon * temp = new Wagon;
			(*temp).setStorage(x);			//(*temp) is the name of the wagon
			if(size !=0){
				(*temp).setNext(first);
			}
			first = temp;
			size++;
		}
		
		void addWagonToRear(int y){
			Wagon * temp = new Wagon;
                        (*temp).setStorage(y);                  //(*temp) is the name of the wagon
                        Wagon *temp2 = first;
			if(size !=0){
				for(int i = 0; i <size - 1; i++){
					temp2 = (*temp2).getNext();
				}
                        	(*temp2).setNext(temp);
                        }else{
				first = temp;
			}
			size++;
		}
		
		void removeFrontWagon(){
			if(size !=0){
				Wagon *temp = first;
				first = (*first).getNext();
				delete temp;
				size--;
			} 
	
		}
		void removeLast(){
			if(size !=0){
				Wagon *temp = first;
				for(int i = 0; i < size; i++){
					temp = (*temp).getNext();	
				}
			delete temp;
			size--;
			}
		}
		void addAfter(int x, int y){
			Wagon *temp = new Wagon;
			(*temp).setStorage(y);
			Wagon *temp2 = first;
			(*temp).getStorage();
			while((*temp2).getStorage() != x){
				temp2 = (*temp2).getNext();
				(*temp2).getStorage();
			}
			if((*temp2).getStorage() == x){
				(*temp2).setNext(temp);
			} else{
				first = temp;
			}
			size++;
		}
		void print(){
			cout << "********************************************\nSize is: " << size << endl;
			Wagon *temp = first;
			for(int i = 0; i < size; i++){
				cout <<(*temp).getStorage() << "\t";
				temp = (*temp).getNext();
			}
			cout << "\n********************************************\n";
		}
};




int main(){
	Train obj1;
	for(int i = 0; i < 8; i++){
		obj1.addWagonToFront(10*i);
		obj1.addWagonToRear(100*i+100);
	}
	obj1.print();
	obj1.removeFrontWagon();
	obj1.print();
	obj1.removeFrontWagon();
	obj1.print();
	obj1.removeLast();
	obj1.print();
	obj1.addAfter(700,800);
	obj1.print();
	return 0;
}
