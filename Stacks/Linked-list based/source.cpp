#include "Stack.h"
int main() {
	linkedList_Stack<char> S;
	int ch;
	char item;

	do {
		cout << "1) Insert element to stack" << endl;
		cout << "2) Pop element from stack" << endl;
		cout << "3) Display all the elements of stack" << endl;
		cout << "4) Size of the stack" << endl;
		cout << "5) Exit" << endl;
		cout << "Enter your choice : \n" << endl;
		cin >> ch;
		switch (ch) {
		case 1:
			cout << "Please insert the item you would like to insert:\n";
			cin >> item;
			S.Push(item);
			break;
		case 2:
			if (!S.Pop())
				cout << "can't destack anymore!\n";
			break;
		case 3: S.display();
			break;
		case 4: cout << S.getLength() << endl;
			break;
		case 5: cout << "EXIT\n";
			break;
		default: cout << "Invalid choice\n" << endl;
		}
		cin.ignore();
		cout << endl;
	} while (ch != 5);
	system("pause");
	return 0;
}
