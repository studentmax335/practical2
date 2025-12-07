#include <iostream>
using namespace std;

// Structure to store call details
struct Call {
    int customerID;
    int callTime;
};

class CallQueue {
private:
    Call arr[100];      // fixed size array (you can increase size)
    int front;
    int rear;
    int size;

public:

    CallQueue() {
        front = -1;
        rear = -1;
        size = 100;
    }

    // Check if queue is empty
    bool isQueueEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isQueueFull() {
        return (rear == size - 1);
    }

    // Add call to queue
    void addCall(int id, int time) {
        if (isQueueFull()) {
            cout << "Queue is full! Cannot add more calls.\n";
            return;
        }

        if (front == -1) front = 0;   // first insertion
        rear++;
        arr[rear].customerID = id;
        arr[rear].callTime = time;

        cout << "Call added successfully.\n";
    }

    // Answer first call
    void answerCall() {
        if (isQueueEmpty()) {
            cout << "No calls to answer. Queue is empty.\n";
            return;
        }

        cout << "Answering call:\n";
        cout << "Customer ID: " << arr[front].customerID
             << ", Call Time: " << arr[front].callTime << " mins\n";

        if (front == rear) {
            // Queue becomes empty  4 5 3 8
            front = rear = -1;
        } else {
            front++;
        }
    }

    // View all calls without removing
    void viewQueue() {
        if (isQueueEmpty()) {
            cout << "Queue is empty. No calls waiting.\n";
            return;
        }

        cout << "Current Calls in Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << "Customer ID: " << arr[i].customerID
                 << ", Call Time: " << arr[i].callTime << " mins\n";
        }
    }
};

int main() {
    CallQueue q;
    int choice;

    do {
        cout << "\n--- Call Center Queue Menu ---\n";
        cout << "1. Add Call\n";
        cout << "2. Answer Call\n";
        cout << "3. View Queue\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, time;
            cout << "Enter Customer ID: ";
            cin >> id;
            cout << "Enter Call Time (in minutes): ";
            cin >> time;
            q.addCall(id, time);
        }
        else if (choice == 2) {
            q.answerCall();
        }
        else if (choice == 3) {
            q.viewQueue();
        }
        else if (choice == 4) {
            if (q.isQueueEmpty())
                cout << "Yes, the queue is empty.\n";
            else
                cout << "No, the queue has calls.\n";
        }
        else if (choice == 5) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}


