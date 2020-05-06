#include <iostream>
#include <vector>
#include <string>

using namespace std;


template <class T>
class FCFSQueue { // abstract class interface for the First Come First Serve Queue
protected:
	int size, max;
public:
	FCFSQueue() {
		max = 100;
		size = 0;
	}
	bool isEmpty() { return size == 0; };
	bool isFull() { return size == max; };
	int getLength() { return size; };
	virtual void enqueue(T) = 0;
	virtual T dequeue() = 0;
	virtual void display() = 0;
};

template <class T>
class linear_Queue : public FCFSQueue<char> { // linear-array queue that inherits from the FCFSQueue class
private:
	T* itemList;
public:
	linear_Queue()
	{
		itemList = new T[max];
	}
	~linear_Queue() {
		delete itemList;
	}
	void enqueue(T);
	T front() { return itemList[0]; };
	T dequeue();
	void display();
};

template <class T>
class circular_Queue : public FCFSQueue<char> { // circular queue that inherits from the FCFSQueue class
private:
	int front, rear;
	T* itemList;
public:
	circular_Queue() {
		front = 0;
		rear = -1;
		itemList = new T[max];
	};
	void enqueue(T);
	T dequeue();
	void display();
};
