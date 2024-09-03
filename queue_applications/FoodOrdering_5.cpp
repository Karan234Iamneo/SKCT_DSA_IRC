#include <iostream>
#include <cstring>

#define MAX_NAME_LEN 50
#define MAX_FOOD_ITEMS 20
#define MAX_QUEUE_SIZE 100

struct FoodOrder {
    int orderNumber;
    char customerName[MAX_NAME_LEN];
    char foodItems[MAX_FOOD_ITEMS][MAX_NAME_LEN];
    int foodItemsCount;
};

FoodOrder queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(FoodOrder order) {
    if ((rear + 1) % MAX_QUEUE_SIZE == front) {
        std::cout << "Queue is full\n";
    } else {
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        queue[rear] = order;
        if (front == -1) {
            front = rear;
        }
        std::cout << "Order added to queue\n";
    }
}

void dequeue() {
    if (front == -1) {
        std::cout << "Queue is empty\n";
    } else {
        FoodOrder order = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_QUEUE_SIZE;
        }
        std::cout << "Order number: " << order.orderNumber << std::endl;
        std::cout << "Customer name: " << order.customerName << std::endl;
        std::cout << "Food items: " << std::endl;
        for (int i = 0; i < order.foodItemsCount; i++) {
            std::cout << order.foodItems[i] << std::endl;
        }
    }
}

void display() {
    if (front == -1) {
        std::cout << "Queue is empty\n";
    } else {
        int index = front;
        std::cout << "Order number\tCustomer name\tFood items\n";
        while (index != rear) {
            FoodOrder order = queue[index];
            std::cout << order.orderNumber << "\t\t" << order.customerName << "\t\t";
            for (int i = 0; i < order.foodItemsCount; i++) {
                std::cout << order.foodItems[i] << ", ";
            }
            std::cout << std::endl;
            index = (index + 1) % MAX_QUEUE_SIZE;
        }
        FoodOrder order = queue[index];
        std::cout << order.orderNumber << "\t\t" << order.customerName << "\t\t";
        for (int i = 0; i < order.foodItemsCount; i++) {
            std::cout << order.foodItems[i] << ", ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cin >> choice;
        switch (choice) {
            case 1: {
                FoodOrder order;
                std::cin >> order.orderNumber;
                std::cin >> order.customerName;
                std::cin >> order.foodItemsCount;
                for (int i = 0; i < order.foodItemsCount; i++) {
                    std::cin >> order.foodItems[i];
                }
                enqueue(order);
                break;
            }
            case 2: {
                dequeue();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                break;
            }
            default: {
                std::cout << "Invalid choice\n";
                break;
            }
        }
    } while (choice != 4);
    return 0;
}
