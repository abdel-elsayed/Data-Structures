#include <iostream>
#include <string>

using namespace std;

template <class T>
struct node { 
	int value;
	node *next;
	node<T> () {};
	node<T> (T item) {
		value = item;
		next = nullptr;
	}
};

template <class T>
class linkedList {
private:
	node<T>* head;
	node<T>* tail;
public:
	linkedList() {
		head = NULL;
		tail = NULL;
	};
	void insert(T x); //inserts a new node containing x at the end of the list
	void print(); //prints out the whole list
	void remove(T x); //removes the node that has x from the list
	void search(T x); //search for the node that has the passes value
	void reverse(); //reverses the order of the list

};

template <class T>
void linkedList<T>::insert(T x) {
	node<T> *t = head;
	node<T> *n = new node<T>;
	n->value = x;
	n->next = NULL;
	if (head != NULL) {
		
		tail->next = n;
		tail = n;
	}
	else {
		head = n;
		tail = n;
	}

}
template <class T>
void linkedList<T>::print() {
	node<T> *t = head;
	cout << "|" << "HEAD" << "|---";
	while (t&& t!=tail->next) {
		cout <<'>' << " | " << t->value << " |---";
		t = t->next;
	}
	cout << ">|Tail|";
}

template<class T>
void linkedList<T>::remove(T x) {
	if (head == NULL) {
		cout << "\nLinked List is empty\n";
		return;
	}
	else if (head->value == x) { //if the node at the beggining
		node<T> *temp = head;
		head = head->next;
		cout << temp->value << endl;
		delete temp;
		return;
	}
	else if (tail->value == x) // if the node is at the end of the list
	{
		node<T> *temp = tail;
		node<T> *prev = head;
		while (prev->next != temp)
		{
			prev= prev->next;
		}
		tail = prev;
		cout << temp->value << endl;
		temp->next = NULL;
		delete temp;
		return;
	}

	node<T> *temp = head, *parent = head;

	while (temp != NULL && temp->value != x) {
		parent = temp;
		temp = temp->next;
	}

	if (temp == NULL) {
		cout << endl << x << " not found in list\n";
		return;
	}

	parent->next = temp->next;
	delete temp;
}

template <class T>
void linkedList<T>:: search(T x) {
	node<T> *t = head;
	int found = 0;
	int index = 0;
	while (t != NULL) {
		if (t->value == x) {
			cout << "\nFound at index: " << index;
			found = 1;
			break;
		}
		t = t->next;
		index++;
	}
	if (found == 0) {
		cout << "\nNot Found";
	}
}

template<class T>
void linkedList<T>::reverse() {
	node<T> *current = head;
	node<T> *prev = NULL, *next = NULL;

	while (current != NULL) {
		// Store next 
		next = current->next;

		// Reverse current node's pointer 
		current->next = prev;

		// Move pointers one position ahead. 
		prev = current;
		current = next;
	}
	tail = head;
	head = prev;
}
