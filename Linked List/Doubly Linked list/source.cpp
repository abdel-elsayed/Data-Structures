#include "linkedList.h"

int main()
{
	linkedList<int> linky;
	int choice, item ,index;

	do {
		cout << "Please enter a selection:";
		cout << "\n1. InsertFront";
		cout << "\n2. InsertLast";
		cout << "\n3. Insert at specific index";
		cout << "\n4. Pop front item";
		cout << "\n5. Pop back item"; 
		cout << "\n6. Pop at specific index";
		cout << "\n7. Print";
		cout << "\n0. Exit";
		cout << "\n\nEnter you choice : ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "\nEnter the element to be inserted : ";
			cin >> item;
			linky.insertFront(item);
			break;
		case 2:
			cout << "\nEnter the element to be inserted : ";
			cin >> item;
			linky.insertBack(item);
			break;
		case 3:
			
			cout << "\nEnter the element to be inserted : ";
			cin >> item;
			cout << "\nEnter the index: ";
			cin >> index;
			linky.insertAt(item, index);
			break;

		case 4:
			 linky.popFront();
			break;

		case 5:
			linky.popBack();
			break;

		case 6:
			cout << "please insert the index: ";
			cin >> index;
			linky.popAt(index);
			cout << "\n";
			break;

		case 7:

			linky.print();
			cout << "\n";
			break;
		}cout << endl;

	} while (choice != 0);

	system("pause");
	return 0;
}

