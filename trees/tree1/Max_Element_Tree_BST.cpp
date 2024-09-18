#include<iostream>
#include <stdio.h>
#include<stdlib.h>

using namespace std;

// Define the structure of a node in the binary search tree (BST)
struct node
{
    int data;             // Data stored in the node
    struct node *left;    // Pointer to the left child
    struct node *right;   // Pointer to the right child
} *root;                  // Global root pointer, initially NULL

// Function to create a new node with given data
struct node *newnode(int item)
{
    // Allocate memory for the new node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;        // Assign the data
    temp->left = temp->right = NULL;  // Initialize left and right children as NULL
    return temp;
}

// Function to insert a new node with given data into the BST
struct node* insert(struct node* node, int data)
{
    // If the tree is empty, return a new node
    if (node == NULL)
    {
        return newnode(data);
    }

    // If the data is smaller, insert into the left subtree
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    // If the data is larger, insert into the right subtree
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }

    // Return the unchanged node pointer
    return node;
}

// Function to find the maximum element in the BST
int findMax(struct node* root)
{
    // Base case: if the tree is empty, return 0
    if (root == NULL)
        return 0;

    // Assume the root node's value is the maximum
    int res = root->data;

    // Recursively find the maximum in the left and right subtrees
    int lres = findMax(root->left);
    int rres = findMax(root->right);

    // Update the maximum if needed
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;

    // Return the maximum value found
    return res;
}

int main()
{
    int data;

    // Loop to continuously accept input from the user
    do
    {
        cin >> data;  // Input a number
       
        // If the input is positive, insert it into the BST
        if (data > 0)
        {
            root = insert(root, data);
        }

    } while (data > 0);  // Loop terminates when a non-positive number is entered

    // Output the maximum element in the BST
    cout << "Maximum element is " << findMax(root);

    return 0;
}
