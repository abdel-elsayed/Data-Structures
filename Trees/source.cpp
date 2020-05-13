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
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

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

// Driver Code 
int main()
{
	Node*NewRoot = NULL;
	Node *root = new Node(212);
	root->left = new Node(70);
	root->right = new Node(5);
	root->left->right = new Node(63);
	root->left->right->left = new Node(12);
	root->left->right->right = new Node(1231);
	root->right->right = new Node(96543234);
	root->right->right->left = new Node(343434);

	cout << "Maximum element is "
		<< findMax(root)->data << endl;
	system("pause");
	return 0;
}
