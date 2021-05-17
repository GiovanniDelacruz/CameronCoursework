//------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
using namespace std;

//------------------------------------------------------------------------------

class DynamicArray{
private:
	int size;
	int capacity;
	double* array;
	double* lstArr;
	double* fstArr;
	double* nxtArr;
	double* prvArr;
	int segSize;
	int seg;
public:

//default constructor
//------------------------------------------------------------------------------
	DynamicArray(){
		capacity = 20;
		size = 0;
		array = new double [capacity];
		fstArr=NULL;
		lstArr=NULL;
		nxtArr=NULL;
		prvArr=NULL;
		seg=1;
	}
//------------------------------------------------------------------------------

//functions
//------------------------------------------------------------------------------
	void addElement(double num){
		if(size == capacity){
			double *temp = new double[capacity +10];
			for(int i = 0; i < size; i++){
				temp[i] = array[i];
			}
		capacity += 10;
		delete []array;
		}
	array[size] = num;
	size +=1;
	}
	void removeElement(double num){
        for(int i = 0; i < size; i++){
                if(array[i] == num){
                        int j = i;
                        while(j < size){
                        array[j] = array[j+1];
                        j++;
			}
                        i = size;
                        size--;
                }
        }

}
	void segmentation(int x){
		segSize = size/x;
		if(seg==1){
			double* temp= new double[segSize];
			for(int i = 0; i < segSize; i++){
				temp[i] = array[i]; 
			}
			lstArr=temp;
			fstArr=temp;
			for(int i = 0; i < x; i++){
				 double* temp2 = new double[segSize];
				for(int j = 0; j < segSize; j++){
					temp2[j] = array[j+segSize*i];
				}
				nxtArr=temp2;
				lstArr=nxtArr;
				prvArr=lstArr;
				temp2=prvArr;
				lstArr=temp2;
				

			}
		seg = x;
		}
	delete []array;
	}
	void merge(){
		
		double*temp = fstArr;
		for(int i = 0; i < seg; i++){
			for(int j = 0; j < segSize; j++){
				array[i*segSize+j]=temp[j];
			}
		temp=nxtArr;	
		}	
	seg=1;	
		
	}
	void print(){
		if(seg==1){
		cout << "---------------------------------" << endl;
		cout << "\n\n";
		for(int i = 0; i < size; i++){
			cout << array[i]<< "\n";
		}
		cout << "capacity: " << capacity << "\nsize: " << size << "\n\n";
		cout << "segments: " << seg << "\n\n";
		cout << "--------------------------------" << endl;
		}if(seg>1){
		cout << "segments: " << seg << "\n\n";
                double* temp = fstArr;
                for(int i = 1; i <= seg; i++){
                        cout << "segment: " << i << endl;
                        for(int j = 0; j < segSize; j++){
                                cout << temp[j] << " ";
                        }
                        cout << "\n\n";
                        temp = nxtArr;
                }
		}
	}
};


int main(){
DynamicArray r;
r.addElement(8.8);
r.addElement(7.8);
r.addElement(9.8);
r.addElement(4.8);
r.addElement(3.8);
r.addElement(2.8);
r.addElement(1.8);

r.print();
r.removeElement(7.8);
r.print();
r.segmentation(2);
r.print();
r.merge();
r.print();
return 0;
}
