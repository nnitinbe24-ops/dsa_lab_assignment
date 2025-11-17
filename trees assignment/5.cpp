#include <iostream>
using namespace std;

class HeapSort {
public:
    void heapify(int arr[], int n, int i, bool isMaxHeap) {
        int extreme = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (isMaxHeap) {
            if (l < n && arr[l] > arr[extreme]) extreme = l;
            if (r < n && arr[r] > arr[extreme]) extreme = r;
        } else {
            if (l < n && arr[l] < arr[extreme]) extreme = l;
            if (r < n && arr[r] < arr[extreme]) extreme = r;
        }

        if (extreme != i) {
            swap(arr[i], arr[extreme]);
            heapify(arr, n, extreme, isMaxHeap);
        }
    }

    void sort(int arr[], int n, bool increasing) {
        bool isMaxHeap = increasing;  
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i, isMaxHeap);

        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0, isMaxHeap);
        }

        if (!increasing) {  
            for (int i = 0; i < n / 2; i++)
                swap(arr[i], arr[n - i - 1]);
        }
    }

    void display(int arr[], int n) {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    HeapSort hs;
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    hs.display(arr, n);

    cout << "Sort in Increasing order:\n";
    hs.sort(arr, n, true);
    hs.display(arr, n);

    int arr2[] = {12, 11, 13, 5, 6, 7};
    cout << "Sort in Decreasing order:\n";
    hs.sort(arr2, n, false);
    hs.display(arr2, n);

    return 0;
}