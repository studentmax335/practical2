
#include <iostream>
#include <vector>
using namespace std;

// Structure to store product details
struct Product {
    int id;
    string name;
    string manufacturer;
    float price;
    int rating;   // quality rating out of 5
};

// Function to display products
void displayProducts(const vector<Product>& products) {
    cout << "\nProduct Details:\n";
    cout << "ID\tName\tManufacturer\tPrice\tRating\n";
    for (const auto &p : products) {
        cout << p.id << "\t" << p.name << "\t" 
             << p.manufacturer << "\t" 
             << p.price << "\t" << p.rating << endl;
    }
}

// (a) Bubble Sort: Increasing order of Product ID
void bubbleSortById(vector<Product>& products) {
    int n = products.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (products[j].id > products[j+1].id) {
                swap(products[j], products[j+1]);
            }
        }
    }
}

// (b) Selection Sort: Increasing order of Product Price
void selectionSortByPrice(vector<Product>& products) {
    int n = products.size();
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (products[j].price < products[minIndex].price) {
                minIndex = j;
            }
        }
        swap(products[i], products[minIndex]);
    }
}

// (c) Insertion Sort: Decreasing order of Product Rating
void insertionSortByRating(vector<Product>& products) {
    int n = products.size();
    for (int i = 1; i < n; i++) {
        Product key = products[i];
        int j = i - 1;

        // "less than" for descending order
        while (j >= 0 && products[j].rating < key.rating) {
            products[j+1] = products[j];
            j--;
        }
        products[j+1] = key;
    }
}

int main() 
{
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    vector<Product> products(n);

    


// Input product details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of product " << i+1 << ":\n";
        cout << "Product ID: ";
        cin >> products[i].id;
        cout << "Name: ";
        cin >> products[i].name;
        cout << "Manufacturer: ";
        cin >> products[i].manufacturer;
        cout << "Price: ";
        cin >> products[i].price;
        cout << "Rating (1-5): ";
        cin >> products[i].rating;
    }

    cout << "\n--- Sorted by Product ID (Bubble Sort) ---";
    bubbleSortById(products);
    displayProducts(products);

    cout << "\n--- Sorted by Product Price (Selection Sort) ---";
    selectionSortByPrice(products);
    displayProducts(products);

    cout << "\n--- Sorted by Product Rating (Insertion Sort, Descending) ---";
    insertionSortByRating(products);
    displayProducts(products);

    return 0;
}

// ----------- Bubble Sort -----------
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ----------- Bubble Sort -----------
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


// ----------- Selection Sort -----------
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        // find index of minimum element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}


