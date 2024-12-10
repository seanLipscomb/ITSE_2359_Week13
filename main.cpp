#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

void loadQueue(queue<string>& q) {
    ifstream file("queue.txt");
    string task;
    while (getline(file, task)) {
        q.push(task);
    }
    file.close();
}

void loadStack(stack<string>& s) {
    ifstream file("stack.txt");
    string task;
    while (getline(file, task)) {
        s.push(task);
    }
    file.close();
}

void saveQueue(const queue<string>& q) {
    ofstream file("queue.txt");
    queue<string> temp = q;
    while (!temp.empty()) {
        file << temp.front() << endl;
        temp.pop();
    }
    file.close();
}

void saveStack(const stack<string>& s) {
    ofstream file("stack.txt");
    stack<string> temp = s;
    while (!temp.empty()) {
        file << temp.top() << endl;
        temp.pop();
    }
    file.close();
}

int main() {
    queue<string> taskQueue;
    stack<string> completedTasks;
    int choice;
    string task;

    // Load saved tasks from files
    loadQueue(taskQueue);
    loadStack(completedTasks);

    do {
        // Display menu
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add a task\n";
        cout << "2. View next task\n";
        cout << "3. Complete a task\n";
        cout << "4. View completed tasks\n";
        cout << "5. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline after reading choice

        switch (choice) {
            case 1: // Add a task
                cout << "Enter the task: ";
                getline(cin, task);
                taskQueue.push(task);
                break;

            case 2: // View next task
                if (!taskQueue.empty()) {
                    cout << "Next task: " << taskQueue.front() << endl;
                } else {
                    cout << "No tasks left in the queue.\n";
                }
                break;

            case 3: // Complete a task
                if (!taskQueue.empty()) {
                    completedTasks.push(taskQueue.front());
                    taskQueue.pop();
                    cout << "Task completed.\n";
                } else {
                    cout << "No tasks left to complete.\n";
                }
                break;

            case 4: // View completed tasks
                if (!completedTasks.empty()) {
                    cout << "Completed tasks:\n";
                    stack<string> tempStack = completedTasks;
                    while (!tempStack.empty()) {
                        cout << tempStack.top() << endl;
                        tempStack.pop();
                    }
                } else {
                    cout << "No completed tasks.\n";
                }
                break;

            case 5: // Save and Exit
                saveQueue(taskQueue);
                saveStack(completedTasks);
                cout << "Data saved. Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
