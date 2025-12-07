#include <iostream>
using namespace std;

struct Seat {
    int seatNo;
    bool booked;
    Seat* next;
    Seat* prev;
};

class Theater {
    int rows, seatsPerRow;
    Seat** head;  // Array of head pointers for each row

public:
    Theater(int m, int n) {
        rows = m;
        seatsPerRow = n;
        head = new Seat*[rows];

        // Create circular doubly linked list for each row
        for (int i = 0; i < rows; i++) {
            head[i] = NULL;
            Seat* last = NULL;

            for (int j = 1; j <= seatsPerRow; j++) {
                Seat* newSeat = new Seat;
                newSeat->seatNo = j;
                newSeat->booked = false;
                newSeat->next = newSeat->prev = NULL;

                if (head[i] == NULL) {
                    head[i] = newSeat;
                    head[i]->next = head[i];
                    head[i]->prev = head[i];
                    last = head[i];
                } else {
                    last->next = newSeat;
                    newSeat->prev = last;

                    newSeat->next = head[i];
                    head[i]->prev = newSeat;

                    last = newSeat;
                }
            }
        }

        // Randomly mark some seats as booked (for demo)
        head[0]->booked = true;
        head[1]->next->booked = true;
        head[2]->next->next->booked = true;
    }

    void displayAvailable() 
    {
        cout << "\nAvailable Seats:\n";
        for (int i = 0; i < rows; i++) 
        {
            cout << "Row " << i + 1 << ": ";

            Seat* temp = head[i];
            
            if (!temp) continue;

            do {
                if (!temp->booked)
                    cout << temp->seatNo << " ";
                temp = temp->next;
            } while (temp != head[i]);
            cout << endl;
        }
    }

    void bookSeat() {
        int row, seat;
        cout << "\nEnter row number to book (1-" << rows << "): ";
        cin >> row;
        cout << "Enter seat number to book (1-" << seatsPerRow << "): ";
        cin >> seat;

        if (row < 1 || row > rows || seat < 1 || seat > seatsPerRow) {
            cout << "Invalid seat or row number!\n";
            return;
        }

        Seat* temp = head[row - 1];
        do {
            if (temp->seatNo == seat) {
                if (temp->booked)
                    cout << "Seat already booked!\n";
                else {
                    temp->booked = true;
                    cout << "Seat successfully booked!\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != head[row - 1]);
    }

    void cancelSeat() {
        int row, seat;
        cout << "\nEnter row number to cancel booking (1-" << rows << "): ";
        cin >> row;
        cout << "Enter seat number to cancel booking (1-" << seatsPerRow << "): ";
        cin >> seat;

        if (row < 1 || row > rows || seat < 1 || seat > seatsPerRow) {
            cout << "Invalid seat or row number!\n";
            return;
        }

        Seat* temp = head[row - 1];
        do {
            if (temp->seatNo == seat) {
                if (!temp->booked)
                    cout << "Seat was not booked!\n";
                else {
                    temp->booked = false;
                    cout << "Booking cancelled successfully!\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != head[row - 1]);
    }
};

int main() {
    int m, n, choice;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of seats per row: ";
    cin >> n;

    Theater t(m, n);

    do {
        cout << "\n==== Theater Ticket Booking System ====\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book a Seat\n";
        cout << "3. Cancel a Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            t.displayAvailable();
            break;
        case 2:
            t.bookSeat();
            break;
        case 3:
            t.cancelSeat();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}


