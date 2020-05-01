#pragma once
#include <iostream>
#include <exception>
#include <string>

/////////////////////////////////////////		struct node		///////////////////////////////////////
using namespace std;
template <class T>
struct node {
	node* next;
	T data;
	node* prev;
	node<T>() {};
	node<T>(T item) {
		data = item;
		next = NULL;
		prev = NULL;
	}
};
/////////////////////////////////////////		linkedList class	///////////////////////////////////////
template <class T>
class linkedList // circular doubly linked list
{
private:
	node<T>* head = NULL;
	node<T>* tail = NULL;
	int length = 0;
public:
	linkedList() {};

	bool isEmpty() { return head = tail = NULL; };
	node<T>* getAt(int);
	void insertFront(T);
	void insertBack(T);
	void insertAt(T,int);
	void print();
	void popFront();
	void popBack();
	void popAt(int index);
	bool remove(T);

};
/////////////////////////////////////////		insertFront		///////////////////////////////////////
template <class T>
void linkedList<T>::insertFront(T newItem)
{
	if (head == NULL)
	{
		head = new node<T>(newItem);
		tail = head;
		head->next = head;
		head->prev = head;
		length++;
		return;
	}else if (head == tail)
	{
		node<T>* temp = new node<T>(newItem);
		temp->next = head;
		head = temp;
		tail->prev = head;
		head->prev = tail;
		tail->next = head;
		length++;
		return;
	}
	node<T>* temp = new node<T>(newItem);
	temp->next = head;
	head->prev = temp;
	head = temp;
	head->prev = tail;
	tail->next = head;	
	length++;
}

/////////////////////////////////////////		insertBack		///////////////////////////////////////
template <class T>
void linkedList<T>::insertBack(T newItem)
{
	if (head == NULL)
	{
		head = new node<T>;
		head->data = newItem;
		tail = head;
		head->next = head;
		head->prev = head;
		length++;
		return;
	}
	else if (head == tail)
	{
		node<T>* temp = new node<T>;
		temp->data = newItem; 
		temp->prev = tail;
		tail = temp;
		head->next = tail;
		tail->prev = head;
		head->prev = tail;
		tail->next = head;
		length++;
		return;
	}
	node<T>* temp = new node<T>;
	temp->data = newItem;
	temp->prev = tail;
	tail->next = temp;
	tail = temp;
	head->prev = tail;
	tail->next = head;
	length++;
}

/////////////////////////////////////////		getAt		///////////////////////////////////////

template<class T>
node<T>* linkedList<T>::getAt(int index)
{
	node<T> *current = head;
	if (index < 1 || index > length)
	{
		return 0;
	}

	for (int i = 1; i < index && current; i++)
	{
		current = current->next;
	}
	return current;
}

/////////////////////////////////////////		insertAt		///////////////////////////////////////

template <class T>
void linkedList<T>::insertAt(T item, int index)
{
	node<T> *temp = getAt(index-1);
	node<T> *newNode= new node<T>(item);
	try {
		if (index == 1) //insert at the front of the list 
		{
			insertFront(item);
			return;
		}
		if (index == length+1) // insert at the end of the list 
		{
			insertBack(item);
			return;
		}
		if (!temp || index > length+1) // check for out of bounds
		{
			throw runtime_error("OOOPS!!Cant insert a node in this location");
		}		
		newNode->next = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next->prev = newNode;
		return;
	}
	catch (exception& e)
	{
		cout << e.what() << index << endl;
	}
}

/////////////////////////////////////////		print		///////////////////////////////////////
template <class T>
void linkedList<T>::print() {
	if (head == NULL) {
		cout << "List is Empty!";
		return;
	}
	node<T> *t = head;
	cout << "|" << "HEAD" << "|---";
	
	while (t->next != head) {
		cout << '>' << " | " << t->data << " |<---";
		t = t->next;
	}
	cout << '>' << " | " << t->data << " |---";
	cout << ">|Tail|";
}
/////////////////////////////////////////		popFront		///////////////////////////////////////
template <class T>
void linkedList<T>::popFront() {
	T item;
	try {
		if (head == NULL)
		{
			cout << "the List is empty and Cannot pop anymore!\n";
			return;
		}
		if (head == tail) {
			item = head->data;
			head->next = NULL;
			head->prev = NULL;
			delete head;
			head = NULL;
			tail = NULL;
			cout << "The item popped is: " << item << endl;
			length--;
			return;
		}
		node<T> *temp = head;
		item = head->data;
		head = head->next;
		head->prev = tail;
		tail->next = head;
		temp->next = NULL;
		temp->prev = NULL;
		delete temp;
		cout << "The item popped is: " << item << endl;
		length--;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	
}

/////////////////////////////////////////		popBack		///////////////////////////////////////

template <class T>
void linkedList<T>::popBack() {
	T item;
	try {
		if (head == NULL)
		{
			cout << "the List is empty and Cannot pop anymore!\n";
			return;
		}
		if (head == tail) {
			item = head->data;
			head->next = NULL;
			head->prev = NULL;
			delete head;
			head = NULL;
			tail = NULL;
			cout << "The item popped is: " << item << endl;
			length--;
			return;
		}
		node<T> *temp = tail;
		item = tail->data;
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
		temp->next = NULL;
		temp->prev = NULL;
		length--;
		delete temp;
		cout << "The item popped is: " << item << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

}

/////////////////////////////////////////		popAt		///////////////////////////////////////

template <class T>
void linkedList<T>::popAt(int index) {

	if (head == NULL)
	{
		cout << "the List is empty and Cannot pop anymore!\n";
		return;
	}
	if (index == 1) //pop at the front of the list 
	{
		popFront();
		return;
	}
	if (index == length) //pop at the end of the list 
	{
		popBack();
		return;
	}
	if (index > 1 && index < length)
	{
		T item;
		node<T> *temp = getAt(index);
		item = temp->data;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		temp->next = NULL;
		temp->prev = NULL;
		cout << "The item popped is: " << item << endl;
		length--;
		delete temp;
		return;
	}

	cout << "this index is out of range!";	
}

