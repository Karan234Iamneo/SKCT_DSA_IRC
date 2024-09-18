#include<bits/stdc++.h>
using namespace std ;

class Node 
{
    public :
	int data ;
	Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL ;
	}
}*root = NULL , *temp ;

void create(int input)
{
    Node *new_node = new Node(input) ;
    
    if(root == NULL)
        root = new_node ;
    else
    {
        temp = root ;
        while(true)
        {
            if(new_node->data == temp->data)
                break ;
            else if(new_node->data > temp->data && temp->right == NULL)
            {
                temp->right = new_node ;
                break ;
            }
            else if(new_node->data < temp->data && temp->left == NULL)
            {
                temp->left = new_node ;
                break ;
            }
            else if(new_node->data > temp->data)
                temp = temp->right ;
        
            else if(new_node->data < temp->data)
                temp = temp->left ;
        }
    }
}

int maxDepth(Node* node)
{
    if (node == NULL)
        return 0 ;
    else
    {
        int lDepth = maxDepth(node->left) ;
        int rDepth = maxDepth(node->right) ;
     
        if (lDepth > rDepth)
            return(lDepth + 1) ;
        else return(rDepth + 1) ;
    }
}

int main()
{
    int input ;
    while(true)
    {
        cin >> input ;
        if(input<1) break ;
        create(input) ;
    }
    cout << maxDepth(root) ;    

	return 0 ;
}