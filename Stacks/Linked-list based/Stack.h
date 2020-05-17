#pragma once
#include "linkedList.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
class linkedList_Stack { // linked list Stack class
private:
	linkedList<T> itemList;
	int size = 0;
	int max = 100;
public:
	linkedList_Stack() {};
	bool isEmpty() { return size == 0; };
	bool isFull() { return size == max; };
	int getLength() { return size; };
	void Push(T);
	bool Pop();
	void display();
};


/////////////////////////////////////////////////  Implementation   ///////////////////////////////////////////////////////

template <class T>
void linkedList_Stack<T>::Push(T item)
{
	try {
		if (isFull())
			throw runtime_error("the Stack is full, cant add anymore to it");

		itemList.Insert(item);
		size++;
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}
}

template <class T>
bool linkedList_Stack<T>::Pop()
{

	if (isEmpty())
	{
		return false;
	}
	T item;
	size--;
	item = itemList.popLast();
	cout << item << " has been Popped!\n";
	return true;
}

template <class T>
void linkedList_Stack<T>::display() {

	try {
		if (isEmpty())
			throw runtime_error("the stack is empty, nothing to display");
		itemList.displayList();
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}

}
