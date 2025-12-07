
#include <iostream>
#include<string>
using namespace std;

#define MAX 10  // Maximum queue size

class PrintSpooler {
private:
    string queue[MAX];
    string processed[MAX];
    int front, rear, count;      // circular queue tracking
    int processedCount;

public:
    PrintSpooler() {
        front = 0;
        rear = -1;
        count = 0;
        processedCount = 0;
    }

    bool isFull() {
        return count == MAX;
    }

    bool isEmpty() {
        return count == 0;
    }

    // a) Add Print Job
    void addJob(string job) {
        if (isFull()) {
            cout << "Queue is full! Cannot add more jobs.\n";
            return;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = job;
        count++;
        cout << "Job \"" << job << "\" added.\n";
    }

    // b) Process Job (FIFO)
    void processJob() {
        if (isEmpty()) {
            cout << "No jobs to process.\n";
            return;
        }
        string job = queue[front];
        front = (front + 1) % MAX;
        count--;

        processed[processedCount++] = job;
        cout << "Printing job: " << job << endl;
    }

    // c) Cancel a specific job
    void cancelJob(string job) {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        int foundIndex = -1;
        int i = front;

        for (int j = 0; j < count; j++) {
            if (queue[i] == job) {
                foundIndex = i;
                break;
            }
            i = (i + 1) % MAX;
        }

        if (foundIndex == -1) {
            cout << "Job \"" << job << "\" not found.\n";
            return;
        }

        cout << "Cancelling job: " << job << endl;

        // Shift jobs forward for cancellation
        while (foundIndex != rear) {
            int next = (foundIndex + 1) % MAX;
            queue[foundIndex] = queue[next];
            foundIndex = next;
        }

        rear = (rear - 1 + MAX) % MAX;
        count--;
    }

    // d) Display Queue
    void displayQueue() {
        if (isEmpty()) {
            cout << "No pending jobs.\n";
            return;
        }

        cout << "Pending Print Jobs:\n";
        int i = front;
        for (int j = 0; j < count; j++) {
            cout << "- " << queue[i] << endl;
            i = (i + 1) % MAX;
        }
    }

    // e) Display Processed Jobs
    void displayProcessed() {
        if (processedCount == 0) {
            cout << "No jobs printed yet.\n";
            return;
        }
        cout << "Processed Jobs:\n";
        for (int i = 0; i < processedCount; i++)
            cout << "- " << processed[i] << endl;
    }
};

int main() {
    PrintSpooler ps;
    int choice;
    string job;

    do {
        cout << "\n===== PRINT SPOOLER MENU =====\n";
        cout << "1. Add Print Job\n";
        cout << "2. Process Next Job\n";
        cout << "3. Cancel Print Job\n";
        cout << "4. Display Pending Jobs\n";
        cout << "5. Display Processed Jobs\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter job name: ";
            cin.ignore();
            getline(cin, job);
            ps.addJob(job);
            break;
        case 2:
            ps.processJob();
            break;
        case 3:
            cout << "Enter job to cancel: ";
            cin.ignore();
            getline(cin, job);
            ps.cancelJob(job);
            break;
        case 4:
            ps.displayQueue();
            break;
        case 5:
            ps.displayProcessed();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

