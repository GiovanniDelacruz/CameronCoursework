#include <iostream>
#include <cstdlib>
using namespace std;

class DNode{
	private:
		int element;
		DNode *next;
		DNode *prev;
	public:
		DNode(int x = 0, DNode *p1=0,DNode *p2= 0){
			element = x;
			next = p1;
			prev = p2;
		}
		
		void setElement(int x){element= x;}
		int getElement(){return element;}   
		void setNext(DNode *x){next=x;}                 
			DNode* getNext(){return next;}   
		void setPrev(DNode *x){prev=x;}                 
			DNode* getPrev(){return prev;}
};

class DList{ 
	private:   
		DNode *head;   
		DNode *tail;   
		int size;  
	public:   
		DList(){    
			head=NULL;    
			tail=NULL;    
			size=0;   
		}            
		void addFront(int x){    
			DNode *temp=new DNode(x);    
			if (size==0){     
				head=temp;     
				tail=temp;    
			} else {     
				(*temp).setNext(head);     
				head->setPrev(temp);     
				head=temp;    
			}    size++;            
		}   
		void addRear(int x){     
 			DNode *temp = new DNode(x);
			if(size==0){
				head=temp;
				tail=temp;
			}else{
				(*tail).setNext(temp);
				temp->setPrev(tail);
				tail = temp;
			}	size++;
  		}   
		void remove(int x){ 
 
  		}   
		void removeFront(){ 
 		
 	 	}  
		 void removeRear(){ 
 
  		}   
		void print(){    
			DNode *temp=head;    
			for (int i=0;i<size;i++){     
				cout<<temp->getElement()<<"\t";     
				temp=temp->getNext();    
			}    
			cout<<"\n\n";   
		} 
}; 
int main(){  
	DList obj;  
	obj.addFront(5);

