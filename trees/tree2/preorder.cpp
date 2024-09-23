//Root,Left,Right
#include<iostream>
using namespace std;
class node
{
	public:
  		int data;
  		node *left;
  		node *right;
};
node  *root=NULL;
void insert(int a)
{
	node *newnode;
  	node *temp;
  	temp=root;
  	newnode= new node;
  	newnode->data=a;
  	newnode->left=NULL;
  	newnode->right=NULL;
  	if(temp==NULL)
    {
    	root=newnode;
    }
  else
  {
  	while(1)
    {
      while(temp->data>newnode->data&&temp->left!=NULL)
        temp=temp->left;
      	if(temp->data>newnode->data&&temp->left==NULL)
        {
        	temp->left=newnode;
          	break;
        }
      while(temp->data<newnode->data&&temp->right!=NULL)
        temp=temp->right;
      	if(temp->data<newnode->data&&temp->right==NULL)
        {
        	temp->right=newnode;
          	break;
        }
    }  
  }
}
int display(node *root)
{
	node *temp=root;
  	if(temp==NULL)
    	return 0;
  	cout<<temp->data<<" ";
  	display(temp->left);
  	display(temp->right);
}
int main()
{
  int a;
  do
  {
    cin>>a;
    if(a<0)
      break;
      insert(a);
  }while(1);
  cout<<"Preorder Traversal:"<<endl;
  display(root);
  return 0;
}
