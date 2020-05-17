#include<iostream> 
using namespace std;

class Node
{
public:
	int data;
	Node* left, *right;

	/* Constructor that allocates a new
	node with the given data and NULL
	left and right pointers. */
	Node() {};
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
// returns a pointer to the tree
Node * create() {

	Node* temp = new Node;
	cout << "Enter the data inside the node\nOr enter -1 for Null\n";
	int x;
	cin >> x;
	if (x == -1)
		return NULL;
	
	temp->data = x;
	cout << "Left Child of "<<temp->data<<":\n"; 
	temp->left = create();

	cout << "Right Child of " << temp->data << ":\n";
	temp->right = create();

	return temp;
}

// Returns a pointer to node with maximum   
// value in a given Binary Tree
Node* findMax(Node* root)
{
	// Base case  
	if (!root)
		return NULL;

	Node* current = root;
		
	Node* MaxLeft = findMax(root->left);
	
	Node* MaxRight = findMax(root->right);

	if (MaxLeft) {
		if (MaxLeft->data > current->data)
			current = MaxLeft;
	}
	if (MaxRight) {
		if (MaxRight->data > current->data)
			current = MaxRight;
	}
	return current;
}

// checks if the binary tree is a BST or not
bool isBinarySearchTree(Node* root, int minVal, int maxVal) {
	
	if (root == NULL) // base case 
		return true;

	if ( root->data > minVal && root->data <= maxVal
		&& isBinarySearchTree(root->left, minVal, root->data) // check the right branch
		&& isBinarySearchTree(root->right, root->data, maxVal)) // check the left branch
		return true;

	return false;
}
// Driver Code 
int main()
{
	char entry;
	Node*NewRoot = NULL;

	do {

		cout << "What kind of a tree would you like to create?\nOR ENTER 0 TO EXIT\n";
		cout << "1 for a regular tree\n";
		cout << "2: check if it is a binary search tree\n";
		cout << "3: find maximum value in the tree\n";
			cin >> entry;
			switch (entry) {
			case '1':
				NewRoot = create();
				break;
			case '2':
				if(isBinarySearchTree(NewRoot, INT_MIN, INT_MAX))
					cout << "YES\n"<< endl;
				if (!isBinarySearchTree(NewRoot, INT_MIN, INT_MAX))
					cout << "NO\n" << endl;
				break;

			case '3': 
				cout << "Maximum value is " << findMax(NewRoot)->data << endl;
				break;

			default:
				entry = 0;
				break;
			}
	} while (entry!=0);

	system("pause");
	return 0;
}
 
