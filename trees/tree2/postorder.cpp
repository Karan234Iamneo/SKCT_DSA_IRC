#include<bits/stdc++.h>
using namespace std;

struct Node
{
 int data;
  struct Node *left = NULL;
  struct Node *right = NULL;
} *root=NULL,*temp;

void create(int input)
{
 struct Node *new_node= new struct Node;
  new_node->data=input;
  if(root == NULL)
    root=new_node;
  else
  {
    temp = root ;
    while(1)
    {
        if(temp ->data == new_node->data)
         break ;
      if(input<temp->data && temp->left ==NULL)
      {
        temp->left=new_node;
        break;
      }
      else if(input>temp->data && temp->right ==NULL)
      {
        temp->right=new_node;
        break;
      }
      else if(input <temp->data && temp->left!=NULL)
        temp=temp->left;
      else if(input >temp->data && temp->right!=NULL)
        temp=temp->right;
    }
  }
}

void postorder(struct Node *temp)
{
  if(temp==NULL)
    return ;
  else
  {
  postorder(temp->left);
  postorder(temp->right);
  cout<<temp->data<<" ";
  }
}

int main()
{
  int input;
  while(1)
  {
     cin>>input;
    if(input<1)
      break;
    create(input); 
  }
    postorder(root);
    return 0 ;
} 
