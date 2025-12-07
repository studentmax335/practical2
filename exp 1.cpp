
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class AttendanceManager {
private:
    vector<int> attendance;

public:
    AttendanceManager(vector<int> data) {
        attendance = data;
    }

    // a) Compute the average attendance of all students
    double computeAverage() {
        int sum = 0;
        for (int a : attendance)
            sum += a;
        return (double)sum / attendance.size();
    }

    // b) Find student with highest and lowest attendance
    void findHighLow(int &highest, int &lowest) {
        highest = attendance[0];
        lowest = attendance[0];
        for (int a : attendance) {
            if (a > highest) highest = a;
            if (a < lowest) lowest = a;
        }
    }

    // c) Count number of students with zero attendance
    int countZeroAttendance() {
        int count = 0;
        for (int a : attendance)
            if (a == 0) count++;
        return count;
    }

    // d) Find most common attendance (mode)
    int findMode() {
        unordered_map<int, int> freq;
        for (int a : attendance)
            freq[a]++;

        int mode = attendance[0], maxFreq = 0;
        for (auto it : freq) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                mode = it.first;
            }
        }
        return mode;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> data(n);
    cout << "Enter attendance (days present) of each student:\n";
    for (int i = 0; i < n; i++)
        cin >> data[i];

    AttendanceManager am(data);

    cout << "\nAverage Attendance: " << am.computeAverage() << endl;

    int highest, lowest;
    am.findHighLow(highest, lowest);
    cout << "Highest Attendance: " << highest << endl;
    cout << "Lowest Attendance: " << lowest << endl;

    cout << "Number of students with zero attendance: " 
         << am.countZeroAttendance() << endl;

    cout << "Most Common Attendance (Mode): " 
         << am.findMode() << endl;

    return 0;
}


