#include <iostream>
using namespace std;

int SIZE = 100;

class Queue {
    int items[100];
    int start, end;
    
public:

    Queue() {

        start = 0;
        end = -1;
    }

    bool empty() {

        if (start > end)
            return true;
        return false;
    }

    bool full() {

        if (end == SIZE - 1)
            return true;
        return false;
    }

    void add(int value) {
        if (full()) {

            cout << "Queue is full" << endl;
            return;
        }
        end++;
        items[end] = value;
    }

    int remove() {
        if (empty()) {

            cout << "Queue is empty" << endl;
            return -1;

        }

        int temp = items[start];
        start++;
        return temp;
    }

    int front() {

        if (!empty())
            return items[start];
        return -1;

    }

    int length() {
        return end - start + 1;
    }
};

int findHungryStudents(Queue &students, int sandwiches[], int n) {

    int sandwichIndex = 0;
    int tries = 0;

    while (!students.empty() && sandwichIndex < n) {

        if (students.front() == sandwiches[sandwichIndex]) {

            students.remove();
            sandwichIndex++;
            tries = 0;

        } 
        else {
            int s = students.remove();
            students.add(s);
            tries++;
        }

        if (tries == students.length()) {
            break;
        }
    }
    
    return students.length();
}

int main() {
    Queue studentQueue;
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter student preferences (0 or 1):" << endl;
    for (int i = 0; i < n; i++) {
        int pref;
        cin >> pref;
        studentQueue.add(pref);
    }

    int sandwichList[100];
    cout << "Enter sandwiches:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> sandwichList[i];
    }

    int result = findHungryStudents(studentQueue, sandwichList, n);
    cout << "Students left hungry: " << result << endl;

    return 0;
}