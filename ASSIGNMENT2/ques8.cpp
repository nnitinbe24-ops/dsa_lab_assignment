#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int distinctCount = 0;
    for (int i = 0; i < n; i++) {
        bool alreadySeen = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                alreadySeen = true;
                break;
            }
        }
        if (!alreadySeen) {
            distinctCount++;
        }
    }
    return distinctCount;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = countDistinct(arr, n);
    cout << "Number of distinct elements: " << result << endl;

    return 0;
}