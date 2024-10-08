#include <bits/stdc++.h> 
using namespace std; 

struct QNode { 
	int data; 
	QNode* next; 
	QNode(int d) 
	{ 
		data = d; 
		next = NULL; 
	} 
}; 

struct Queue { 
	QNode *front, *rear; 
	Queue() 
	{ 
		front = rear = NULL; 
	} 

	void enQueue(int x) 
	{ 
		QNode* temp = new QNode(x); 
		if (rear == NULL) { 
			front = rear = temp; 
			return; 
		} 
		rear->next = temp; 
		rear = temp; 
	} 
	void deQueue() 
	{ 
		if (front == NULL) 
			return; 
		QNode* temp = front; 
		front = front->next; 
		if (front == NULL) 
			rear = NULL; 

		delete (temp); 
	} 
}; 
int main() 
{ 

	Queue q; 
	int i,n;
	cin>>n;
	for(i=0;i<n;i++) {
	    int val;
	    cin>>val;
	    q.enQueue(val);
	}
	cout <<(q.front)->data << endl; 
	cout <<(q.rear)->data << endl; 
	q.deQueue(); 
	cout<< (q.front)->data << endl; 
	cout<< (q.rear)->data; 
} 
