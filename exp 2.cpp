
#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

// Linear Search Function
bool linearSearch(const vector<int>& patients, int id) {
    for (int pid : patients) {
        if (pid == id)
            return true;
    }
    return false;
}

// Binary Search Function
bool binarySearch(const vector<int>& patients, int id) {
    int low = 0, high = patients.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (patients[mid] == id)
            return true;
        else if (patients[mid] < id)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    int n;
    cout << "Enter number of patients: ";
    cin >> n;

    vector<int> patients(n);
    cout << "Enter patient IDs:\n";
    for (int i = 0; i < n; i++) {
        cin >> patients[i];
    }

    int id;
    cout << "Enter patient ID to search: ";
    cin >> id;

    // Linear Search
    if (linearSearch(patients, id))
        cout << "Patient ID " << id << " found using Linear Search.\n";
    else
        cout << "Patient ID " << id << " not found using Linear Search.\n";

    // For Binary Search, the list must be sorted
    sort(patients.begin(), patients.end());

    if (binarySearch(patients, id))
        cout << "Patient ID " << id << " found using Binary Search.\n";
    else
        cout << "Patient ID " << id << " not found using Binary Search.\n";

    return 0;
}
