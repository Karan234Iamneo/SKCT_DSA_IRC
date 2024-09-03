#include <iostream>
#include <cstring>

#define MAX_TASKS 100005
#define MAX_NAME_LEN 105

struct Task {
    int priority;
    int deadline;
    char name[MAX_NAME_LEN];
};

Task tasks[MAX_TASKS];
int task_count = 0;

void addTask(int priority, int deadline, const char* name) {
    Task newTask;
    newTask.priority = priority;
    newTask.deadline = deadline;
    strcpy(newTask.name, name);
    tasks[task_count] = newTask;
    task_count++;
}

int compareTasks(const Task& taskA, const Task& taskB) {
    if (taskA.deadline != taskB.deadline) {
        return taskA.deadline - taskB.deadline;
    }
    return taskB.priority - taskA.priority;
}

void sortTasks() {
    for (int i = 0; i < task_count - 1; i++) {
        for (int j = 0; j < task_count - i - 1; j++) {
            if (compareTasks(tasks[j], tasks[j + 1]) > 0) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    int priority, deadline;
    char name[MAX_NAME_LEN];

    for (int i = 0; i < n; i++) {
        std::cin >> priority >> deadline >> name;
        addTask(priority, deadline, name);
    }

    sortTasks();

    std::cout << "Executed Tasks:\n";
    for (int i = 0; i < task_count; i++) {
        std::cout << tasks[i].name << std::endl;
    }

    return 0;
}
