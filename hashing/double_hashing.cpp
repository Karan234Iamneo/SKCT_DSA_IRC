#include <iostream>
using namespace std;

#define TABLE_SIZE 10

int h[TABLE_SIZE]={NULL};

void insert()
{

 int key,index,i,flag=0,hkey,hash2;
 cin>>key;
 //scanf("%d",&key);
 hkey=key%TABLE_SIZE;
 hash2 = 7-(key %7);
 for(i=0;i<TABLE_SIZE;i++)
 {
    index=(hkey+i*hash2)%TABLE_SIZE;
    if(h[index] == NULL)
    {
        h[index]=key;
        break;
    }
 }
 if(i == TABLE_SIZE)
    cout<<"element cannot be inserted\n";
     //printf("element cannot be inserted\n");
}
void search()
{

 int key,index,i,flag=0,hash2,hkey;
 cin>>key;
 //scanf("%d",&key);
  hkey=key%TABLE_SIZE;
 hash2 = 7-(key %7);
 for(i=0;i<TABLE_SIZE; i++)
 {
    index=(hkey+i*hash2)%TABLE_SIZE;
    if(h[index]==key)
    {
        cout<<"value is found at index "<<index<<"\n";
      //printf("value is found at index %d\n",index);
      break;
    }
  }
  if(i == TABLE_SIZE)
  cout<<"value is not found\n";
    //printf("value is not found\n");
}
void display()
{

  int i;
  for(i=0;i< TABLE_SIZE; i++)
  cout<<"Element at position "<<i<<": "<<h[i]<<"\n";
    //printf("Element at position %d: %d\n",i,h[i]);

}
int main()
{
    int i,n;
    cin >> n;
    //scanf("%d",&n);
    for(i=0;i<n;i++) {
        insert();
    }
    display();
}
