#include "Queues.h"
int main() {
	linkedList_Queue<char> Q;
	int ch;
	char item;
	
	do {
	cout << "1) Insert element to queue" << endl;
	cout << "2) Dequeue element from queue" << endl;
	cout << "3) Display all the elements of queue" << endl;
	cout << "4) Size of the queue" << endl;
	cout << "5) Exit" << endl;
	cout << "Enter your choice : \n" << endl;
	cin >> ch;
	switch (ch) {
		case 1: 
			cout << "Please insert the item you would like to insert:\n";
			cin >> item;
			Q.enqueue(item);
			break;
		case 2:
			if (!Q.dequeue())
				cout << "can't dequeue anymore!\n";
			break;
		case 3: Q.display();
			break;
		case 4: cout << Q.getLength() << endl;
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
