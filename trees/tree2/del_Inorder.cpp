#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;
 
    Node() {}
    Node(int data): data(data) {}
};
 
void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node* getMinimumKey(Node* curr)
{
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}
Node* insert(Node* root, int key)
{
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}
 
void searchKey(Node* &curr, int key, Node* &parent)
{

    while (curr != nullptr && curr->data != key)
    {
        parent = curr;

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
    Node* parent = nullptr;
 
    Node* curr = root;
    searchKey(curr, key, parent);
    if (curr == nullptr) {
        return;
    }
    if (curr->left == nullptr && curr->right == nullptr)
    {
        if (curr != root)
        {
            if (parent->left == curr) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
        }
        else {
            root = nullptr;
        }

        free(curr);        
    }
 
    else if (curr->left && curr->right)
    {
        Node* successor = getMinimumKey(curr->right);

        int val = successor->data;
        deleteNode(root, successor->data);
        curr->data = val;
    }
 
    else {
        Node* child = (curr->left)? curr->left: curr->right;
 
        if (curr != root)
        {
            if (curr == parent->left) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
 
        else {
            root = child;
        }
        free(curr);
    }
}
 
int main()
{
    int size;
    cin>>size;
    int keys[size];
    
    for(int i=0;i<size;i++)
    {
        cin>>keys[i];
    }
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
    cout << "Before deletion of key value: ";

    inorder(root);
    int delkey;
    cin>>delkey;
    deleteNode(root, delkey);
    cout<<"\nAfter deleting key value " << delkey << ": ";

    inorder(root);
 
    return 0;
}
