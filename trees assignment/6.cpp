#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[100];
    int size;
    bool isMax;  // true = max-heap, false = min-heap

public:
    PriorityQueue(bool type = true) {
        size = 0;
        isMax = type;
    }

    void swapVal(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }

    bool compare(int a, int b) {
        return isMax ? (a > b) : (a < b);
    }

    void insert(int val) {
        size++;
        arr[size] = val;
        int i = size;

        while (i > 1 && compare(arr[i], arr[i / 2])) {
            swapVal(arr[i], arr[i / 2]);
            i = i / 2;
        }
    }

    void heapify(int i) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int best = i;

        if (left <= size && compare(arr[left], arr[best]))
            best = left;
        if (right <= size && compare(arr[right], arr[best]))
            best = right;

        if (best != i) {
            swapVal(arr[i], arr[best]);
            heapify(best);
        }
    }

    void remove() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Removed element: " << arr[1] << endl;
        arr[1] = arr[size];
        size--;
        heapify(1);
    }

    int top() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[1];
    }

    void display() {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(true); // true = max-heap, false = min-heap

    pq.insert(10);
    pq.insert(30);
    pq.insert(20);
    pq.insert(5);
    pq.insert(40);

    cout << "Priority Queue (Max-Heap): ";
    pq.display();

    cout << "Top element: " << pq.top() << endl;

    pq.remove();

    cout << "After deletion: ";
    pq.display();

    PriorityQueue pq2(false); // Min-Heap
    pq2.insert(10);
    pq2.insert(30);
    pq2.insert(20);
    pq2.insert(5);
    pq2.insert(40);

    cout << "\nPriority Queue (Min-Heap): ";
    pq2.display();

    pq2.remove();
    cout << "After deletion: ";
    pq2.display();

    return 0;
}