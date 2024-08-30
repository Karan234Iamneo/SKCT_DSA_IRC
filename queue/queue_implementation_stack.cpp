#include <iostream>
#define MAX_SIZE 1000  // Define the maximum size of the stacks

using namespace std;

int s1[MAX_SIZE];  // Stack 1 array
int s2[MAX_SIZE];  // Stack 2 array
int top1 = -1;  // Top pointer for Stack 1
int top2 = -1;  // Top pointer for Stack 2

// Function to push an element onto Stack 1
void pushStack1(int x) {
    if (top1 == MAX_SIZE - 1) {
        cout << "Stack 1 Overflow" << endl;
    } else {
        s1[++top1] = x;
    }
}

// Function to push an element onto Stack 2
void pushStack2(int x) {
    if (top2 == MAX_SIZE - 1) {
        cout << "Stack 2 Overflow" << endl;
    } else {
        s2[++top2] = x;
    }
}

// Function to pop an element from Stack 1
int popStack1() {
    if (top1 == -1) {
        cout << "Stack 1 Underflow" << endl;
        return -1;
    } else {
        return s1[top1--];
    }
}

// Function to pop an element from Stack 2
int popStack2() {
    if (top2 == -1) {
        cout << "Stack 2 Underflow" << endl;
        return -1;
    } else {
        return s2[top2--];
    }
}

// Function to get the top element from Stack 2
int topStack2() {
    if (top2 == -1) {
        cout << "Stack 2 is Empty" << endl;
        return -1;
    } else {
        return s2[top2];
    }
}

// Function to check if Stack 2 is empty
bool isEmptyStack2() {
    return top2 == -1;
}

int main() {
    int num_operations;
    cin >> num_operations;
    int Q_operation, x;

    for (int i = 0; i < num_operations; i++) {
        cin >> Q_operation;

        if (Q_operation == 1) {
            cin >> x;
            pushStack1(x);
        } else if (Q_operation == 2) {
            if (!isEmptyStack2()) {
                popStack2();
            } else {
                while (top1 != -1) {
                    pushStack2(popStack1());
                }
                if (!isEmptyStack2()) {
                    popStack2();
                }
            }
        } else if (Q_operation == 3) {
            if (!isEmptyStack2()) {
                cout << topStack2() << endl;
            } else {
                while (top1 != -1) {
                    pushStack2(popStack1());
                }
                if (!isEmptyStack2()) {
                    cout << topStack2() << endl;
                }
            }
        }
    }

    return 0;
}
