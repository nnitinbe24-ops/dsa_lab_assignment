#include <iostream>
using namespace std;

int size = 100;

class Queue {

    int front, back;
    string data[100];

public:

    Queue() {
        front = 0;
        back = -1;
    }

    bool empty() {

        if (front > back) {
            return true;
        } 
        else {

            return false;
        }
    }

    bool full() {

        if (back == size - 1) {
            return true;
        } 
        else {
        
            return false;
        }
    }

    void add(string value) {

        if (full()) {

            cout << "Queue is full" << endl;
            return;
        }

        back = back + 1;
        data[back] = value;
    }


    string remove() {
        if (empty()) {

            cout << "Queue is empty" << endl;
            return "";

        }
        string temp = data[front];
        front = front + 1;

        return temp;
    }
};

void makeBinaryNumbers(int n) {
    Queue q;
    
    q.add("1");

    for (int i = 1; i <= n; i++) {
        string current = q.remove();
        cout << current << " ";

        q.add(current + "0");
        q.add(current + "1");
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Binary numbers from 1 to " << num << " are:" << endl;
    makeBinaryNumbers(num);

    return 0;
}