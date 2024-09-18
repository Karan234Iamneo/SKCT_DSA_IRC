#include<iostream>
using namespace std;

// Define a class node to represent each node in the binary search tree (BST)
class node
{
	public:
  		int data;  // Stores the data of the node
  		node *left;  // Pointer to the left child of the node
  		node *right; // Pointer to the right child of the node
};

// Initialize the root of the tree as a global variable, initially set to NULL
node *root = NULL;

// Function to insert a new node into the binary search tree
void insert(int a)
{
	node *newnode;  // Pointer for the new node to be inserted
  	node *temp;     // Temporary pointer for traversing the tree
  	temp = root;    // Start traversal from the root
  	newnode = new node;  // Dynamically allocate memory for the new node
  	newnode->data = a;   // Assign data to the new node
  	newnode->left = NULL;  // Initialize left child of the new node to NULL
  	newnode->right = NULL; // Initialize right child of the new node to NULL
  	
  	// Case 1: If the tree is empty, the new node becomes the root
  	if(temp == NULL)
    {
    	root = newnode;
    }
  else
  {
  	// Case 2: The tree is not empty, so we need to find the appropriate position for the new node
  	while(1)
    {
        // Traverse to the left subtree if the new node's data is smaller than the current node's data
        while(((temp->data) > (newnode->data)) && (temp->left != NULL))
        {
            temp = temp->left;  // Move left if there is a left child
        }
      	
        // Insert the new node as the left child if the left position is empty
      	if(((temp->data) > (newnode->data)) && (temp->left == NULL))
        {
        	temp->left = newnode;  // Attach new node to the left
          	break;  // Exit the loop after insertion
        }
        
        // Traverse to the right subtree if the new node's data is larger than the current node's data
        while(((temp->data) < (newnode->data)) && (temp->right != NULL))
        {
            temp = temp->right;  // Move right if there is a right child
        }
      	
        // Insert the new node as the right child if the right position is empty
      	if(((temp->data) < (newnode->data)) && (temp->right == NULL))
        {
        	temp->right = newnode;  // Attach new node to the right
          	break;  // Exit the loop after insertion
        }
    }  
  }
}

// Recursive function to perform in-order traversal and display the tree
int display(node *root)
{
	node *temp = root;  // Start traversal from the root
  	
  	// Base case: if the tree is empty, return 0
  	if(temp == NULL)
  	{
    	return 0;
  	}
  	
  	// Recursive call to traverse the left subtree
  	display(temp->left);
  	
  	// Print the data of the current node
  	cout << temp->data << " ";
  	
  	// Recursive call to traverse the right subtree
  	display(temp->right);
}

// Main function to drive the program
int main()
{
  int a;  // Variable to store input values
  
  // Input loop to insert values into the BST
  do
  {
    cin >> a;  // Take input from the user
    if(a < 0)  // Negative value breaks the input loop
    {
      break;
    }
    insert(a);  // Insert the value into the binary search tree
  } while(1);  // Infinite loop, terminated by a negative input
  
  // Output the values in the tree in in-order traversal
  cout << "Tree values are:" << endl;
  display(root);  // Display the tree
  return 0;
}
