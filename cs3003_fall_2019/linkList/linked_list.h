#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct Node
{
	string first_name, last_name;
	int id;
	//int data;
	Node* next;
};

class linked_list
{
	public:
	char menu();
	linked_list();		//constructor
	bool insert(Node *);	//inserts node into linked list
	void print_list(); 	//prints list
	bool search(int);	//searches for key
	int size();		//returns list size
	bool remove(int);	//removes specified data from the list
	~linked_list();		//destructor for linked list constructor (unlinks list at the end of the program)
	void copy_list(Node*);	//copies one linked list to another
	//linked_list(linked_list&);
	linked_list(linked_list*);//constructor for copying lists to a new list
	

	private:
	Node *head;
	int cnt;
};
#include "linked_list.cpp"
#endif
