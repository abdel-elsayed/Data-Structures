#pragma once
#include "linkedList.h"
#include <iostream>
#include <string>

using namespace std;


template <class T>
class linkedList_Queue { // linked list queue class
private:
	linkedList<T> itemList;
	int size = 0;
	int max = 100;
public:
	linkedList_Queue() {};
	bool isEmpty() { return size == 0; };
	bool isFull() { return size == max; };
	int getLength() { return size; };
	void enqueue(T);
	bool dequeue();
	void display();
};


/////////////////////////////////////////////////  Implementation   ///////////////////////////////////////////////////////

template <class T>
void linkedList_Queue<T>::enqueue(T item)
{
	try {
		if (isFull())
			throw runtime_error("the queue is full, cant add anymore to it");

		itemList.Insert(item);
		size++;
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}
}

template <class T>
bool linkedList_Queue<T>::dequeue()
{

	if (isEmpty())
	{
		return false;
	}
	T item;
	size--;
	item = itemList.popFirst();
	cout << item << " has been dequeued!\n";
	return true;
}

template <class T>
void linkedList_Queue<T>::display() {

	try {
		if (isEmpty())
			throw runtime_error("the queue is empty, nothing to display");
		itemList.displayList();
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}

}
