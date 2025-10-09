#include <iostream>
using namespace std;

int SIZE = 100;

class Queue {
    int data[100];
    int first, last;

public:

    Queue() {
        first = 0;
        last = -1;
    }

    bool empty() {

        if (first > last)
            return true;
        return false;
    }

    bool full() {
        if (last == SIZE - 1)
            return true;
        return false;
    }

    void add(int value) {

        if (full()) {
            cout << "Queue is full" << endl;
            return;
        }
        last++;
        data[last] = value;
    }

    int remove() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int temp = data[first];
        first++;
        return temp;
    }

    int front() {

        if (!empty())
            return data[first];
        return -1;

    }
};

class Stack {
    int data[100];
    int topIndex;

public:

    Stack() {
        topIndex = -1;
    }

    bool empty() {

        return topIndex == -1;
    }


    bool full() {

        return topIndex == SIZE - 1;
    }


    void push(int value) {

        if (full()) {
            cout << "Stack is full" << endl;
            return;
        }
        topIndex++;
        data[topIndex] = value;
    }

    int pop() {

        if (empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return data[topIndex--];
    }

    int top() {

        if (!empty())
            return data[topIndex];
        return -1;
    }
};

bool canBeSorted(Queue &q, int n) {

    Stack tempStack;
    int nextNumber = 1;

    while (!q.empty()) {

        int current = q.remove();

        if (current == nextNumber) {
            nextNumber++;
        } else {
            if (!tempStack.empty() && tempStack.top() < current) {
                return false;
            }
            tempStack.push(current);
        }

        while (!tempStack.empty() && tempStack.top() == nextNumber) {
            tempStack.pop();
            nextNumber++;
        }
    }

    while (!tempStack.empty()) {

        if (tempStack.top() != nextNumber)
            return false;
        tempStack.pop();
        nextNumber++;
    }

    return nextNumber - 1 == n;
}

int main() {
    Queue myqueue;
    int count, num;

    cout << "How many numbers? ";
    cin >> count;

    cout << "Enter numbers:" << endl;
    
    for (int i = 0; i < count; i++) {
        cin >> num;
        myqueue.add(num);
    }

    if (canBeSorted(myqueue, count))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}