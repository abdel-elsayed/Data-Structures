#include <iostream>

using namespace std;

template <class T>
class stack {
private:
	int capacity;
	int top = -1;
	T *arr;

public:
	bool isEmpty();
	bool isFull();
	T peek() const;
	bool push(T);
	bool pop();
	stack();
	stack(int size); 
	~stack() { delete[] arr; }
	void displayAll();
	int search(const T&);
	int getTopIndex() { return top; }
	int getCapacity() { return capacity - 1; }
};
