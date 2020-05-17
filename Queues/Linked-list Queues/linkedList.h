#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

template <class T>
struct Node {
	T value;
	Node* next;
	Node<T>() {};
	Node<T>(T item) {
		value = item;
		next = NULL;
	}
};


template<class T>
class linkedList {

private:
	Node<T>* head;
	Node<T>* tail;

public:
	linkedList() {
		head=nullptr;
		tail=nullptr;
	}
	void displayList(); 
	void  Insert(T); 
	T popLast();
	bool isEmpty() { return (head == NULL && tail == NULL); }
	~linkedList();
};


template <class T>
void linkedList<T>::Insert(T item)
{
	try { // to check if there is enough memory in the heap 
		Node<T>* temp = new Node<T>(item);
		if (isEmpty())
		{
			head = temp;
			tail = temp;
			head->next = head;
			return;
		}
		tail->next = temp;
		tail = temp;
		tail->next = head;

	}
	catch (bad_alloc &badAlloc)
	{
		cout << "bad_alloc caught, not enough memory: " << badAlloc.what() << endl;
	}
}

template <class T>
T linkedList<T>::popFirst() {

	try {
		if (isEmpty())
		{
			throw logic_error("the list is empty");
		}
		else if (head == tail) // if the list has one node left in it 
		{
			T value = head->value;
			delete head;
			head = nullptr;
			tail = nullptr;
			return value;
		}
		Node<T>* temp = head; // if the list has more than one node
		T value = head->value;
		head = head->next;
		tail->next = head;
		delete temp;
		return value;
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}


}

template <class T>
void linkedList<T>::displayList() {
	int index = 0;
	
	cout << "~~~~~~\n" << "|" << "HEAD" << "|";
	if (head == NULL)
	{
		cout << "the list is empty\n";
		return;
	}
	if (head == tail)
	{
		index++;
		cout << "--->";
		cout << index << ")| " << head->value << " |";
		cout << "---";
		cout << "> NULL\n~~~~~~";
	}
	else 
	{	
		Node<T>* current = head;

		while (current->next != head)
		{
			
			cout << "--->";
			cout << ++index << ")| " << current->value << " |";
			cout << "---";
			current = current->next;
		} 
		cout << "--->";
		cout << ++index << ")| " << current->value << " |";
		cout << "---";
		current = current->next;
		cout << "> NULL\n~~~~~~";
	}
}


template<class T>
linkedList<T>::~linkedList()
{
	Node<T>* current = head;
	if (head!=tail) {
		do
		{
			head = head->next;
			current->next = nullptr;
			delete current;
			current = head;
			tail->next = head;
		} while (current->next != head);
	}
	
	delete current;
}												
