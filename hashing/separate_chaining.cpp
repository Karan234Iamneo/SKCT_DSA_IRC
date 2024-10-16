#include <bits/stdc++.h>
using namespace std;
#define size 3
struct node
{
    int data;
    struct node *next;
};

struct node *chain[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(int value)
{
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    int key = value % size;
    if(chain[key] == NULL)
        chain[key] = newNode;
    else
    {
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void print()
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            cout<<temp->data<<" -->";
            //printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    init();
    int i,n,ele;
    cin>>n;
    //scanf("%d",&n);
    for(i=0;i<n;i++) {
        cin>>ele;
        //scanf("%d",&ele);
        insert(ele);
    }
    print();

    return 0;
}
