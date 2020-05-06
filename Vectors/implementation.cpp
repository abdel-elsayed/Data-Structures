#include "Header.h"

template <class T>
TOC <T>::TOC(int  size)
{
	capacity = size;
	myArray = new T[capacity];

}

template <class T>
bool TOC <T>::full()
{
	if (num_used == capacity)
		return true;
	return false;
}

template <class T>
bool TOC <T> ::ifempty()
{
	if (num_used == 0)
		return true;
	else
		return false;
}

template <class T>
int TOC<T> ::getCapacity1()
{
	return capacity;
}

template < class T>
int TOC <T> ::currently_used()
{
	return num_used;
}

template  <class T>
T TOC <T> ::get(int target)
{
	if (target < capacity)
	{
		if (target < num_used)
		{
			return myArray[target];
		}
		else
		{
			cout << "This position is Empty.." << endl;
			return 0;

		}
	}
}

template < class T>
void TOC<T> ::add(T x)
{
	if (num_used >= capacity)
	{
		resize();
	}
	myArray[num_used++] = x;
}

template <class T>
int TOC<T> ::position(T target)
{

	for (int i = 0; i < num_used; i++)
	{
		if (myArray[i] == target)
		{
			return i;
			break;
		}
	}
			cout << "OPPPS!!.. didnt find it " << target << " in myArray\n";
}

template <class T>
void TOC<T> ::display()
{
	cout << "The content of the Array are:\n";
	for (int i = 0; i <num_used; i++)
	{
		cout << i << ')' << myArray[i] << "  ";
	}
	cout << endl;
}

template <class T>
void TOC<T>::insertAt(T x, int y)
{
	int tempCapacity = capacity;
	int tempNum_Used = num_used;
	if (num_used > y)
	{
		num_used++;
		for (int x = num_used; x > y; x--)
		{
			myArray[x] = myArray[x - 1];
		}
		myArray[y] = x;
	}

	else
	{
		cout << " sorryyyyyy!!! out of bound!" << endl;
	}

	cout << "The maximum capacity of the array was " << tempCapacity << " and became " << capacity << endl;
	cout << "The current size of the array was " << tempNum_Used << " and became " << num_used << endl << endl;
}

template<class T>
void TOC<T> ::remove(int index)
{

	if (index < num_used)
	{
		num_used -= 1;
		for (int i = index; i < num_used; i++)
		{
			myArray[i] = myArray[i + 1];
		}
	}
	else
	{
		cout << "This index does not exist!.." << endl;
	}
}

template <class T>
void TOC<T>::set(T X)
{
	T y;
	cout << "Please insert the item you want to insert..";
	cin >> y;
	for (int i = 0; i < num_used ; i++)
	{
		if (myArray[i] == X)
		{
			myArray[i] = y;
			break;
		}
	}
	
}


template <class T>
TOC<T> ::~TOC()
{
	delete[] myArray;

}

template <class T> 
void TOC<T>::resize()
{

	cout << "Maximum capacity is reached, array is expanding........" << endl;
	capacity *= 2;

	T* Temp = new T[capacity];
	copy(myArray, myArray + num_used, Temp);
	delete[] myArray;
	myArray = Temp;
}

template<class T>
vector<T> TOC<T>::toVector() const
{
	vector<T> bagContents;

	for (int i = 0; i < num_used; i++)
		bagContents.push_back(myArray[i]);

	return bagContents;
}  // end toVector


template<class T>
void addMenu(vector <T> &myV) {
	int itemNumAdded;
	T itemAdded;
	cout << "How many items do you want to add?\n";
	cin >> itemNumAdded;
	
	while (1) {
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "please try again and enter an integer: \n";
			cin >> itemNumAdded;
		}
		if (!cin.fail())
		{
			break;
		}
	}

	for (int i = 0; i < itemNumAdded; i++)
	{
		cout << "please enter the item..";
		cin >> itemAdded;
		myV.push_back(itemAdded);
	}
}

template <class T>
void printV(vector<T> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v.at(i) << " | ";
}


