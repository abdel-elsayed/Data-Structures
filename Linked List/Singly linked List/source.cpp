#include "linkedList.h"

int main()
{
	linkedList<int> linky;
	int choice, x;

	do {
		cout << "Please enter a selection:";
		cout << "\n1. Insert";
		cout << "\n2. Delete";
		cout << "\n3. Search";
		cout << "\n4. Print";
		cout << "\n5. Reverse"; 
		cout << "\n0. Exit";
		cout << "\n\nEnter you choice : ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "\nEnter the element to be inserted : ";
			cin >> x;
			linky.insert(x);
			break;
		case 2:
			linky.print();
			cout << "\nEnter the element to be removed : ";
			cin >> x;
			linky.remove(x);
			break;
		case 3:
			std::cout << "\nEnter the element to be searched : ";
			std::cin >> x;
			linky.search(x);
			break;
		
		case 4:
			linky.print();
			break;
		
		case 5:
			cout << "The reversed list: \n";
			linky.reverse();
			linky.print();
			cout << "\n";
			break;
		}cout << endl;
		
	} while (choice != 0);

	system("pause");
	return 0;
}

