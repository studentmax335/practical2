
#include <iostream>
#include <string>
using namespace std;

// Book structure
struct Book {
    int bookID;
    string title;
    string author;
    bool available;   // true = Available, false = Not Available
};

// Node for linked list
struct Node {
    Book data;
    Node* next;
    
};

// Head pointer for the list
Node* head = nullptr;

// Function to add a new book at end.
void addBook(int id, string title, string author, bool avail) 
{
   

    if (head == nullptr) {
        head = new Node{{id, title, author, avail}, nullptr};
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = new Node{{id, title, author, avail}, nullptr};
    }
}

// Remove a book by ID
void removeBook(int id) {
    if (head == nullptr) return;

    if (head->data.bookID == id) {
        Node* del = head;
        head = head->next;
        delete del;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->data.bookID != id)
        temp = temp->next;

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    
}

// Search by title or author (exact match here for simplicity)
void searchBook(string key) {
    Node* temp = head;
    
    while (temp) {
        if (temp->data.title == key || temp->data.author == key) {
            cout << "Found Book: " << temp->data.bookID << " | "
                 << temp->data.title << " | " << temp->data.author << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "No book found.\n";
}

// Update availability using ID
void updateBook(int id, bool avail) {
    Node* temp = head;
    while (temp) {
        if (temp->data.bookID == id) {
            temp->data.available = avail;
            cout << "Book updated.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Book not found.\n";
}
// Sort books by ID (simple bubble sort on linked list)
void sortBooksByID() {
    if (!head) return;
    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (i->data.bookID > j->data.bookID) {
                swap(i->data, j->data);
            }
        }
    }
}

// Display all books
void displayBooks() {
    Node* temp = head;
    cout << "BookID | Title | Author | Status\n";
    while (temp) {
        cout << temp->data.bookID << " | " 
             << temp->data.title << " | "
             << temp->data.author << " | "
             << (temp->data.available ? "Available": "Not Available") << "\n";
        temp = temp->next;
    }
    cout << "--------------------------\n";
}

// Main demo
int main() 
{
    addBook(101, "C++ Basics", "Bjarne", true);
    addBook(55, "Data Structures", "Narasimha", true);
    addBook(75, "Algorithms", "CLRS", false);

    cout << "Initial list:\n";
    displayBooks();

    cout << "After sorting by ID:\n";
    sortBooksByID();
    displayBooks();

    cout << "Searching for 'CLRS':\n";
    searchBook("CLRS");

    cout << "Updating book 55 availability to false:\n";
    updateBook(55, false);
    displayBooks();

    cout << "Removing book 101:\n";
    removeBook(101);
    displayBooks();

    return 0;
}

