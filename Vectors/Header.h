#pragma once
#ifndef _TOCpoiner_header
#define _TOCpoiner_header

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  
static int size = 10;

template < class T >
class TOC
{
private:
	int num_used;
	int capacity;
	T* myArray;
public:
	TOC(int size=10);
	bool full(); // checks if the array is full
	bool ifempty();// checks if the array is empty
	int getCapacity1(); //return the capacity of the array
	int currently_used(); // return the num used in the array
	T get(int y); // takes the index of the element and returns the element
	void set(T x); // change the chosen element in the array
	void add(T x); // adds elements to the array
	int position(T x);// returns the position of the item passed 
	void insertAt(T x, int y); // takes the item to be inserted and the positon where
	void remove(int x);// deletes the element inside the index
	void display();// displays all the content inside the array
	void resize(); //
	vector<T> toVector() const; // change the array to vector 
	~TOC();
};

template <class T>
void addMenu(vector<T>& );

template <class T>
void printV(vector <T>);



#endif
