#include "Queues.h"

///////////////////////////////////////////////////   LINEAR(non-circular)-QUEUE   ////////////////////////////////////////////////////////
template <class T>
void linear_Queue<T>::enqueue(T item)
{
	try {
		if (isFull())
		{
			throw runtime_error("The Queue is Full, Cant Enqueue Anymore");
		}
		if (itemList == NULL)
		{
			itemList = new T[max];
		}
		itemList[size++] = item;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

template <class T>
T linear_Queue<T>::dequeue()
{
	T item;
	try {
		if (isEmpty())
		{
			throw runtime_error("The Queue is Empty, Cant Dequeue anymore");
		}

		item = itemList[0];
		for (int i = 0; i < size - 1; i++)
		{
			itemList[i] = itemList[i + 1];
		}
		size--;
		return item;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}


template <class T>
void linear_Queue<T>::display()
{
	try {
		if (isEmpty())
		{
			throw runtime_error("Array is empty, nothing to display");
		}

		for (int i = 0; i < size; i++)
		{
			cout << i << ") " << itemList[i] << "\t";
		}
	}
	catch (exception& e) {
		cout << e.what();
	}
}


////////////////////////////////////////////////////////   CIRCULAR QUEUE   /////////////////////////////////////////////////
template <class T>
void circular_Queue<T>::enqueue(T item)
{
	try {
		if (isFull())
		{
			throw runtime_error("The Queue is Full, Cant Enqueue Anymore");
		}
		itemList[(rear + 1) % max] = item;
		rear = (rear + 1) % max;
		size++;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

template <class T>
T circular_Queue<T>::dequeue()
{
	T item;
	try {
		if (isEmpty())
		{
			throw runtime_error("The Queue is Empty, Cant Dequeue anymore");

		}
		else if (front == rear) {
			item = itemList[front];
			rear = -1;
			size--;
			return item;
		}
		else {
			item = itemList[front];
			front = (front + 1) % max;
			size--;
			return item;
		}

	}
	catch (exception& e)
	{
		cout << e.what() << endl;

	}
}

template <class T>
void circular_Queue<T>::display()
{
	try {
		if (isEmpty())
		{
			throw runtime_error("Array is empty, nothing to display");
		}
		int temp = front;
		while (temp != rear)
		{
			cout << itemList[temp] << " ";
			temp = (temp + 1) % max;
		}
		cout << itemList[temp] << " ";
	}
	catch (exception& e) {
		cout << e.what();
	}
}
