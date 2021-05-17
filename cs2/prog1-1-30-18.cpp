#include <iostream>
#include <cstdlib>
using namespace std;
class Array5{
	private:
		int storage[5];
		int size;
	public:
		Array5 (int x);
		Array5(){
			size=0;
		}
		Array5(int x, int y, int z){
			storage[0]=x;
			storage[1]=y;
			storage[2]=z;
			size=3;
		}
		Array5(int a, int b)
		{
		size = 3;
		storage[0] = a;
		storage[1] = b;
		storage[2] = a + b;
		}

		int getSize(){return size;}
		void setSize(int x){size=x;}
		int getStorage(int index){
			return storage[index];
		}
		void setStorage(int index, int val){
			if (index<size){
				storage[index]=val;
				
			}
		}
		void addElement(int val){
			storage[size++]=val;
		}
		void print(){
			cout<<"**************************\n";
			cout<<"The size is: "<<size<<endl;
			cout<<"The elements are: \n";
			for (int i=0; i<size; i++){
				cout<<storage[i]<<"\t";
			}
			cout<<"\n**************************\n";
		}
		int mini()
		{
		int min = storage[0];
		for(int i = 1; i < size; i++)
			{
			if(storage[i] < storage[i-1])
				{
				min = storage[i];
				}
			}
		return min;
		}

	        int maxi()
                {
                int max = storage[0];
                for(int i = 1; i < size; i++)
                        {
                        if(storage[i] > storage[i-1])
                                {
                                max = storage[i];
                                }
                        }
                return max;
                }
		int sumi()
		{
		int sum = 0;
		for(int i = 0; i < size; i++)
                        {
                        sum = sum + storage[i];
                        }
                return sum;

		}
};        
                Array5 :: Array5 (int x) {
                if(x > 5)
                {
                x = 5;
                }
                size = x;
                for(int i = 0; i < size; i++){
                storage[i] = rand();
}

}
Array5	oranges(Array5 x, Array5 y){
	Array5 temp;
	int size1, size2;
	size1=x.getSize();
	size2=y.getSize();
	if (size1<size2){
		for (int i=0; i<size1; i++){
			temp.setStorage(i,x.getStorage(i)+y.getStorage(i));
		}
		for (int j=size1; j<size2; j++){
			 temp.setStorage(j,y.getStorage(j));
		}
		temp.setSize(size2);
	}else{
		 for (int i=0; i<size2; i++){
                        temp.setStorage(i,x.getStorage(i)+y.getStorage(i));
                }
                for (int j=size2; j<size1; j++){
                         temp.setStorage(j,x.getStorage(j));
                }
		temp.setSize(size1);

	}
	return temp;
}

int main(){
	srand(time(0));
	Array5 test(1,2,3);
	test.print();
	cout << test.mini() << endl;
	cout << test.maxi() << endl;
	cout << test.sumi() << endl;
//	Array5 potato;
	//potato.setSize(0);
//	potato.print();
//	potato.setStorage(0,100);
//	potato.addElement(2000);
//	potato.setStorage(5,7);
//	potato.print();
//	Array5 tomato1(10,20,30);
//       tomato1.print();
//	Array5 tomato(1,2,3);
//	tomato.print();
//	tomato.addElement(50);
//	tomato.print();
//	cout<<"HERE WE ARE:\n";
//	oranges(tomato, tomato1).print();
//	Array5	myCollection[10];
//	for (int i=0;i<10;i++){
//		Array5 temp(300+rand()%200,300+rand()%200,300+rand()%200);
//		myCollection[i]=temp;
//	}
//	myCollection[2].addElement(5555);
//	for (int i=0;i<10; i++){
//		myCollection[i].print();
//	}
	return 0;
}
