#include "Header.h"
#include "implementation.cpp"

int main()
{

	TOC <string> arr1;
	cout << ".....Hi there, welcome to 'THE ARRAY IS YOURS' program.....\n ";
	cout << "What would you like to do with your myArray? Enter the corresponding number. Enter 0 to exit." << endl << endl;
	cout << "1. Fill the myArray or add an element" << endl;
	cout << "2. Display elements in the myArray" << endl;
	cout << "3. Check if the myArray is full" << endl;
	cout << "4. Check if the myArray is empty" << endl;
	cout << "5. Insert the element in the myArray." << endl;
	cout << "6. Remove the element from the myArray" << endl;
	cout << "7. Check the position of the chosen element in the myArray" << endl;
	cout << "8. Change chosen element in the myArray" << endl;
	cout << "9. Check the capacity of the myArray " << endl;
	cout << "10. Check how many elements are currently in the myArray" << endl;
	cout << "11. Print the element from the chosen position in the myArray" << endl;
	cout << "12. Sort the myArray and display it" << endl;
	int choice;
	string item;
	string itemToLookFor;
	string elementToBeChanged;
	int indexToDisplay;
	string elementToBeInserted;
	cin >> choice;
	while (1) 
	{
		// to check if the entry is a digit and clear cin if it is not
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "WORNG ENTRY!!!!...please try again and enter an INTEGER: \n";
			cin >> choice;
		}
		if (!cin.fail())
		{
			break;
		}
	} 

	int sortingChoice;

	vector<string> temp;
	vector<string> myVec = arr1.toVector();
	vector<string>::iterator it;

	while (choice != 0)
	{

		switch (choice) {
		case 1:
			addMenu(myVec);
			break;

		case 2: printV(myVec);
			break;
		case 3:
			if (myVec.size() == myVec.max_size())
				cout << "The array is full\n";
			else cout << "The array is not full yet\n";
			break;
		case 4:
			if (myVec.empty()) {
				cout << "The array is empty\n";
			}
			else
				cout << "The array is not empty\n";
			break;
		case 5:
			cout << "How many elements you wish to insert:..";
			int y;
			cin >> y;

			for (int i = 0; i < y; i++)
			{
				cout << "Enter the items that you want to insert..";
				cin >> item;
				temp.push_back(item);
			}
			cout << "Insert the index where you want to insert..";
			int x;
			cin >> x;
			myVec.insert(myVec.begin() + x, temp.begin(), temp.end());
			break;
		case 6:
			cout << "Please enter the index of the element you would like to remove..\n";
			int removeIndex;
			cin >> removeIndex;
			myVec.erase(myVec.begin() + removeIndex);
			break;
		case 7:
			cout << "Please insert the item that you are looking for:...";
			cin >> itemToLookFor;
			it = find(myVec.begin(), myVec.end(), itemToLookFor);

			if (it != myVec.end())
			{
				int index = distance(myVec.begin(), it);
				cout << itemToLookFor << " exists at position " << index << endl;
			}
			else
				cout << "This item is not found!\n";

			break;
		case 8:
			cout << "Please enter the element you want to change....";
			cin >> elementToBeChanged;
			cout << "Please enter the item you wante to be inserted.!!!...";

			cin >> elementToBeInserted;
			it = find(myVec.begin(), myVec.end(), elementToBeChanged);
			if (it != myVec.end())
			{
				int index = distance(myVec.begin(), it);
				myVec[index] = elementToBeInserted;

			}
			else
				cout << "This item is not found!\n";


			break;
		case 9:
			cout << "The capacity of myArray is..." << myVec.capacity() << endl;
			break;

		case 10:
			cout << "myArray currently contains " << myVec.size() << "elements " << endl;
			break;

		case 11:
			cout << "enter the index of the element you would like to display..";
			cin >> indexToDisplay;
			cout << "Position " << indexToDisplay << " contains " << myVec[indexToDisplay] << endl;
			break;
		case 12:
			cout << "Enter 1 for Ascending order and 2 for Descending order:";
			cin >> sortingChoice;
			if (sortingChoice == 1)
			{
				sort(myVec.begin(), myVec.end());
			}
			else if (sortingChoice == 2)
			{
				sort(myVec.begin(), myVec.end(), greater<string>());
			}
			else
				cout << "Wrong Entry!!..\n";
			break;

		default:
			cout << "wrong entry!!";
		}


		cout << "\n\n ";
		cout << "What would you like to do with your myArray? Enter the corresponding number. Enter 0 to exit." << endl << endl;
		cout << "1. Fill the myArray or add an element" << endl;
		cout << "2. Display elements in the myArray" << endl;
		cout << "3. Check if the myArray is full" << endl;
		cout << "4. Check if the myArray is empty" << endl;
		cout << "5. Insert the element in the myArray." << endl;
		cout << "6. Remove the element from the myArray" << endl;
		cout << "7. Check the position of the chosen element in the myArray" << endl;
		cout << "8. Change chosen element in the myArray" << endl;
		cout << "9. Check the capacity of the myArray " << endl;
		cout << "10. Check how many elements are currently in the myArray" << endl;
		cout << "11. Print the element from the chosen position in the myArray" << endl;
		cout << "12. Sort the myArray"<< endl;
		cin >> choice;
		while (1) {
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "WRONG ENTRY!!!..please try again and enter an INTEGER: \n";
				cin >> choice;
			}
			if (!cin.fail())
			{
				break;
			}
		}
	}


		system("pause");
		return 0;
}
