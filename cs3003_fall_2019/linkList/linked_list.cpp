//#include "linked_list.h"

linked_list::linked_list()
{
	head = NULL;
	cnt = 0;
}

char linked_list::menu(){
	char choice;
	
	cout << "\t\tMENU\n";
	cout <<"\t 1\tINSERT NODE\n";
        cout <<"\t 2\tREMOVE NODE\n";
        cout <<"\t 3\tSEARCH NODE\n";
        cout <<"\t 4\tMODIFY NODE\n";
        cout <<"\t 5\tPRINT NODE\n";
        cout <<"\t 6\tEXIT\n";

	cout <<"\nEnter your choice: ";
	cin >> choice;

	return choice;
}

bool linked_list::insert(Node * n)
{
	if (head == NULL)
	{
		head = n;
		cnt++;
		return true;
	}
	else{
		n -> next = head; //the -> dereferences the pointer to refer to a specific value in node structure
		head = n;
		cnt++;
		return true;
	}
}

void linked_list::print_list()
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout<<temp -> data <<" ";
		temp = temp -> next;
	}
	cout<<endl;
}

bool linked_list::search(int key){
	Node *temp = head;
	while(temp != NULL){
		if(temp -> data == key){
			cout <<"FOUND" <<endl;
			return true;
		}
		temp = temp -> next; 			//go to next node
	}						//end of while loop
	cout <<"\nNOT FOUND\n";
	return false;
}

int linked_list::size(){
	return cnt;
}

bool linked_list::remove(int key){
	if(head != NULL && head -> data == key){		//will crash if not in this order: head != null && head -> data == key
		Node *temp = head;
		head = head -> next;
		delete temp;
		cnt--;
		return true;				//may need to decrement cnt
	}else{
		Node *pre, *cur;
		pre = head;
		cur = pre ->next;
		while(cur != NULL && cur -> data != key){
			pre = cur;
			cur = cur -> next;
		}
		if(cur != NULL){
			pre -> next = cur -> next;
			cout<<"REMOVED"<<endl;
			delete cur;
			cnt--;
			return true;
		}else{
			cout<<"DOES NOT EXIST"<<endl;
			return false;
		}					//skip the node pointed by cur
	}
}

linked_list::~linked_list(){
	Node *temp;
	cout<<"\nstart destroying...\n";
	while(head!=NULL){
		temp=head;
		head=head->next;
		delete temp;
	}
	cout<<"\nThe list is destroyed\n";
}

void linked_list::copy_list(Node *another){
	Node *ori_move, *copy_move;
	if(another==NULL){
		cout<<"\nempty\n";
	}else{
		head = new Node;
		head->data=another->data;
		ori_move=another;
		copy_move=head;
		while(ori_move->next!=NULL){
			ori_move=ori_move->next;
			copy_move->next=new Node;
			copy_move=copy_move->next;
			copy_move->data=ori_move->data;
			copy_move->next=NULL;
		}
	}
}

//linked_list::linked_list(linked_list& real){
//	Node* duplicate;	create node pointer to access linked_list
//	duplicate=real.head;	set the pointer to the address of the head node
//	head=duplicate;		set current head node of new list to the duplicate
//	cnt=real.cnt;			increment count of new list
//	real.copy_list(duplicate);	begin moving the list over
//}

linked_list::linked_list(linked_list *real){
        if((*real).head==NULL){
		this -> head = NULL;
		cout <<"\nEmpty Nothing Copied\n";
	}else{
		Node *other, *copy_move;
		this -> head = new Node;
		head -> data = real -> head -> data;
		head -> next = NULL;
		other = real -> head;
		copy_move = this -> head;
		while(other -> next != NULL){
			other = other -> next;
			copy_move -> next= new Node;
			copy_move = copy_move -> next;
			copy_move -> data = other-> data;
			copy_move -> next = NULL;
		}
	}
}


