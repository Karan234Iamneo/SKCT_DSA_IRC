#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;
 
    Node() {}
    Node(int data): data(data) {}
};
 
// Function to perform inorder traversal on the tree
void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
// Recursive function to insert a key into a BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return new Node(key);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
 
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}
 
// Function to construct balanced BST from the given sorted array.
// Note that the root of the tree is passed by reference here
void convert(vector<int> const &keys, int low, int high, Node* &root)
{
    // base case
    if (low > high) {
        return;
    }
 
    // find the middle element of the current range
    int mid = (low + high) / 2;
 
    // construct a new node from the middle element and assign it to the root
    root = new Node(keys[mid]);
 
    // left subtree of the root will be formed by keys less than middle element
    convert(keys, low, mid - 1, root->left);
 
    // right subtree of the root will be formed by keys more than the middle element
    convert(keys, mid + 1, high, root->right);
}
 
// Function to construct balanced BST from the given unsorted array
Node* convert(vector<int> keys)
{
    // sort the keys first
    sort(keys.begin(), keys.end());
 
    // construct a balanced BST
    Node* root = nullptr;
    convert(keys, 0, keys.size() - 1, root);
 
    // return root node of the tree
    return root;
}

Node* getMinimumKey(Node* curr)
{
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}
void searchKey(Node* &curr, int key, Node* &parent)
{
    // traverse the tree and search for the key
    while (curr != nullptr && curr->data != key)
    {
        // update the parent to the current node
        parent = curr;
 
        // if the given key is less than the current node, go to the left subtree;
        // otherwise, go to the right subtree
        if (key < curr->data) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
}
void deleteNode(Node*& root, int key)
{
    // pointer to store the parent of the current node
    Node* parent = nullptr;
 
    // start with the root node
    Node* curr = root;
 
    // search key in the BST and set its parent pointer
    searchKey(curr, key, parent);
 
    // return if the key is not found in the tree
    if (curr == nullptr) {
        return;
    }
 
    // Case 1: node to be deleted has no children, i.e., it is a leaf node
    if (curr->left == nullptr && curr->right == nullptr)
    {
        // if the node to be deleted is not a root node, then set its
        // parent left/right child to null
        if (curr != root)
        {
            if (parent->left == curr) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
        }
        // if the tree has only a root node, set it to null
        else {
            root = nullptr;
        }
 
        // deallocate the memory
        free(curr);        // or delete curr;
    }
 
    // Case 2: node to be deleted has two children
    else if (curr->left && curr->right)
    {
        // find its inorder successor node
        Node* successor = getMinimumKey(curr->right);
 
        // store successor value
        int val = successor->data;
 
        // recursively delete the successor. Note that the successor
        // will have at most one child (right child)
        deleteNode(root, successor->data);
 
        // copy value of the successor to the current node
        curr->data = val;
    }
 
    // Case 3: node to be deleted has only one child
    else {
        // choose a child node
        Node* child = (curr->left)? curr->left: curr->right;
 
        // if the node to be deleted is not a root node, set its parent
        // to its child
        if (curr != root)
        {
            if (curr == parent->left) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
 
        // if the node to be deleted is a root node, then set the root to the child
        else {
            root = child;
        }
 
        // deallocate the memory
        free(curr);
    }
}
 
int main()
{
    // input keys
    vector<int> keys;
    int ele, no;
    cin>>no;
    for(int i=0;i<no;i++)
    {
        cin>>ele;
        keys.push_back(ele);
    }
    cout<<"Initial BST\n";
    Node* root;
    root=convert(keys);
    inorder(root);
    
    int new_ele;
    cin>>new_ele;
    cout<<"\nBST after inserting a new node "<<new_ele<<"\n";
    keys.push_back(new_ele);
    // construct a balanced binary search tree
    root=convert(keys);
    // print the keys in an inorder fashion
    inorder(root);
    int del;
    cin>>del;
    deleteNode(root, del);
    cout<<"\nBST after deleting node "<<del<<"\n";
    inorder(root);

    return 0;
}
