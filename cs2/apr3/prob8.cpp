#include <iostream> 
#include <cstdlib> 
using namespace std; 
 
class DNode{  
private:   
	int element;   
	DNode *next;   
	DNode *prev;  
public:   
	DNode(int x=0,DNode *p1=0,DNode *p2=0){    
		element=x; 
		next=p1; 
		prev=p2;   
	}   
	void setElement(int x){element=x;}   
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
			}    
			size++;            
		}   
		void addRear(int x){     
			DNode *temp=new DNode(x);
			if (size==0){
				head=temp;
				tail=temp;
			} else{
				tail->setNext(temp);
				temp->setPrev(tail);
				tail=temp;
			}
			size++;
  		}   	
		void remove(int x){ 
 			DNode *temp=head;
			for (int i=0; i<size;i++){
				if (x==temp->getElement()){
				  //temp->getNext()->setPrev(temp->getPrev());
				  DNode *temp1=temp->getNext();
				  DNode *temp2=temp->getPrev();
				  if (temp1!=NULL){
					temp1->setPrev(temp2);
				  }else{
					if (temp2!=NULL){
						temp2->setNext(NULL);
						tail=temp2;
					}else{
						head=tail=NULL;
					}
				  }
				  if (temp2!=NULL){
					temp2->setNext(temp1);
				  }else{
					if (temp1!=NULL){
						temp1->setPrev(NULL);
						head=temp1;
					}else{
						head=tail=NULL;
					}
				  }
				 size--;
				 break;
				}else{
					temp=temp->getNext();
				}
			}
  		}   
		void removeFront(){ 
			//work must be done if list not empty
			if (size>0){
			   //decrease size by 1
			   size--;	
			   //case1: one node in list
			   if (size==1){	
				//delete front
				delete head;
				//make front and tail point to NULL
				head=tail=NULL;
			   }else{
			   //case2: more than one node in list
				//make a pointer temp point to the first node
				DNode *temp=head;
				//make front point to the node after the first
				head=head->getNext();
				//delete temp
				delete temp;
			   }
			}
  		}   
		void removeRear(){ 
			//check that the list is not empty
			if(size>0){
				//if there is one node
				if(size == 1){
					//delete tail
					delete tail;
					//make tail and head NULL
					tail=head=NULL;
				//if there is more than one node
				}else{ 
					//create a temp node and set it equal to tail
					DNode *temp = tail;
					//make the tail point to the node before the last
					tail = tail->getPrev();
					//delete temp
					delete temp;
				}
				//reduce size by one
				size--;
			} 
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
      	obj.addFront(10);       
	obj.addFront(20);       
	obj.print();  
	obj.addRear(200);      
	obj.print();  
	obj.remove(10);  
	obj.print();  
	for (int i=0; i<5;i++){   
		obj.addFront(1000*(i+1)); 
		obj.addRear(1050*(i+1));  
	}  
	obj.removeFront();  
	obj.print();  
	obj.removeRear();  
	obj.print();   
 	return 0; 
}
