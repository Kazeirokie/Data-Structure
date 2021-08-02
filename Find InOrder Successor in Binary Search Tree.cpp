// Lesser data must in LEFT
// Bigger data must in RIGHT
/* C++ program to find Inorder successor in a BST */
#include<iostream>
using namespace std;

// Create empty node
struct Node { 
	int data;
	struct Node* left;
	struct Node* right;
};

//Function to find some data in the tree
Node* Find(Node* root, int data) {
	if (root == NULL) return NULL;
	else if (root->data == data) return root;
	else if (root->data < data) return Find(root->right, data); // Find bigger data to be successor
	else return Find(root->left, data); 
}

//Function to find Node with minimum value in a BST
struct Node* FindMin(struct Node* root) {
	if (root == NULL) return NULL;
	while (root->left != NULL)
		root = root->left; // flow will move to most left to find the lowest data value
	return root;
}

//Function to find Inorder Successor in a BST
struct Node* Getsuccessor(struct Node* root, int data) {
	// Search the Node - O(h)
	struct Node* current = Find(root, data); // Current is the node we point at , refer to main() "Find Inorder successor of the node." 
	if (current == NULL) return NULL;   // Node is not exist
	if (current->right != NULL) {       //Case 1: Node has right subtree
		return FindMin(current->right); // O(h) // If "3" chosen, then, "4" will be successor
	}
	else {   //Case 2: No right subtree  - O(h)
		struct Node* successor = NULL; // Represent right subtree
		struct Node* ancestor = root;
		while (ancestor != current) {
			if (current->data < ancestor->data) { 
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}

//Function to visit nodes in Inorder
void Inorder(Node* root) {
	if (root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	printf("%d ", root->data);  //Print data // Same as cout<<root->data<<" ";
	Inorder(root->right);      // Visit right subtree
}

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node* root, char data) {
	if (root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

int main() {
	/*Code To Test the logic
	  Creating an example tree
			    5
			   / \
			  3   10
			 / \   \
			1   4   11
	*/
	Node* root = NULL;
	root = Insert(root, 5); root = Insert(root, 10);
	root = Insert(root, 3); root = Insert(root, 4);
	root = Insert(root, 1); root = Insert(root, 11);

	//Print Nodes in Inorder
	cout << "Inorder Traversal: ";
	Inorder(root);
	cout << "\n";

	// Find Inorder successor of the node. 
	struct Node* successor = Getsuccessor(root, 3);
	if (successor == NULL) cout << "No successor Found\n";
	else
		cout << "Successor is " << successor->data << "\n";
}
// InOrder Successor must be lesser than parent
// If "4" chosen, then, 5 will be the InOrder Successor
// The flow will be like this... 1 -> 3 -> 4 -> 3(is lesser than 4..rejected) -> 5 -> 10 -> 11
// FindMax will make the flow move to most RIGHT to find the biggest data value
// FindMin will make the flow move to most left to find the lowest data value
