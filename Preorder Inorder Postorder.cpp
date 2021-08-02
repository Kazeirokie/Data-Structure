/* Binary Tree Traversal - Preorder, Inorder, Postorder */

// Preorder  = root,left,right
// Inorder   = left,root,right
// Postorder = left,right,root

#include<iostream>
using namespace std;

// Create Node
struct Node {
	char data;
	struct Node* left;
	struct Node* right;
};

// Function to visit nodes in Preorder
void Preorder(struct Node* root) {
	// base condition for recursion
	// if tree/sub-tree is empty, return and exit
	if (root == NULL) return;

	printf("%i ", root->data); // Print data
	Preorder(root->left);     // Visit left subtree
	Preorder(root->right);    // Visit right subtree
}

// Function to visit nodes in Inorder
void Inorder(Node* root) {
	if (root == NULL) return;

	Inorder(root->left);       // Visit left subtree
	printf("%i ", root->data);  // Print data
	Inorder(root->right);      // Visit right subtree
}

// Function to visit nodes in Postorder
void Postorder(Node* root) {
	if (root == NULL) return;

	Postorder(root->left);    // Visit left subtree
	Postorder(root->right);   // Visit right subtree
	printf("%i ", root->data); // Print data
}

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node* root, int data) {
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
			   10
			   / \
			  9   12
			 / \   \
			7   8   13
	*/
	Node* root = NULL;
	root = Insert(root, 10); root = Insert(root, 9);
	root = Insert(root, 8); root = Insert(root, 12);
	root = Insert(root, 7); root = Insert(root, 13);
	// Print Nodes in Preorder. 
	cout << "Preorder: ";
	Preorder(root);
	cout << "\n";
	// Print Nodes in Inorder
	cout << "Inorder: ";
	Inorder(root);
	cout << "\n";
	// Print Nodes in Postorder
	cout << "Postorder: ";
	Postorder(root);
	cout << "\n";
}