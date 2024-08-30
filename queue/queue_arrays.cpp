#include <iostream>
using namespace std;

struct Queue {
    int contents[5];
    int front;
    int count;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->count = 0;
    q->front = 0;
}

// Function to add an element to the queue
void enQueue(struct Queue* q, int element) {
    int index;
    index = (q->count + q->front) % 5;
    if (index == q->front && q->count != 0)
        cout << "Queue is full" << endl;
    else {
        q->count++;
        q->contents[index] = element;
    }
}

// Function to remove an element from the queue
int deQueue(struct Queue* q) {
    int elem;
    if (q->count == 0) {
        cout << "Queue is empty" << endl;
        return -1000;
    }
    elem = q->contents[q->front];
    q->count--;
    q->front = (q->front + 1) % 5;
    return elem;
}

// Function to display the contents of the queue
void display(struct Queue q) {
    int i, index;
    if (q.count == 0) {
        cout << "{}";
    } else {
        for (index = q.front, i = 1; i <= q.count; i++, index++) {
            cout << q.contents[index % 5] << " ";
        }
    }
}

int main() {
    struct Queue p;
    int data;

    initQueue(&p);

    cin >> data;
    enQueue(&p, data);

    cin >> data;
    enQueue(&p, data);

    cin >> data;
    enQueue(&p, data);

    cin >> data;
    enQueue(&p, data);

    cin >> data;
    enQueue(&p, data);

    display(p);
    cout << endl;

    deQueue(&p);
    deQueue(&p);
    display(p);
    cout << endl;

    deQueue(&p);
    deQueue(&p);
    deQueue(&p);
    deQueue(&p);

    return 0;
}
