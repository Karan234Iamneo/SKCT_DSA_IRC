//Left,Root,Right
#include<iostream>
#include<stdlib.h>
using namespace std;
struct btree
{
  int data;
  struct btree *left;
  struct btree *right;
};
struct btree *root,*temp;
void create(int n)
{
  temp = (struct btree*)malloc(sizeof(struct btree));
  temp->data = n;
  temp->right = temp->right = NULL;
}
void insert(struct btree *t) 
{
  if(t->data < temp->data && t->right != NULL)
  {
    insert(t->right);
  }
  else if(t->data < temp->data && t->right == NULL)
  {
    t->right = temp;
  }
  else if(t->data > temp->data && t->left != NULL)
  {
    insert(t->left);
  }
  else if(t->data > temp->data && t->left == NULL)
  {
    t->left = temp;
  }
}
void inorder(struct btree *t)
{
  if(root == NULL)
  {
    cout<<"No element";
  }
  if(t->left!=NULL)
  {
    inorder(t->left);
  }
  cout<<t->data<<" ";
  if(t->right != NULL)
  {
    inorder(t->right);
  }
}

int main()
{
  int n,input;
  root = 0;
  while(1)
  {
    cin>>input;
    if(input<0)
      break;
    else
    {
      create(input);
      if(root == NULL)
        root = temp;
      else
        insert(root);
    }
  }
  cout<<"Inorder Traversal:"<<endl;
  inorder(root);
}
