#include <iostream>
using namespace std;

int SIZE = 100;

class Queue {

    int numbers[100];
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
        numbers[end] = value;
    }

    int remove() {

        if (empty()) {

            cout << "Queue is empty" << endl;
            return -1;
        }
        int temp = numbers[start];
        start++;
        return temp;
    }

    int size() {

        return end - start + 1;
    }

    void show() {

        if (empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = start; i <= end; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }

    int get(int pos) {

        return numbers[start + pos];
    }

    void put(int pos, int value) {

        numbers[start + pos] = value;
    }
};

void sortTheQueue(Queue &q) {

    int n = q.size();
    for (int i = 0; i < n; i++) {

        int small = i;

        for (int j = i + 1; j < n; j++) {

            if (q.get(j) < q.get(small)) {
                small = j;
            }
        }
        int temp = q.get(i);
        q.put(i, q.get(small));
        q.put(small, temp);
    }
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

    cout << "Before sorting: ";
    myqueue.show();

    sortTheQueue(myqueue);

    cout << "After sorting: ";
    myqueue.show();

    return 0;
}