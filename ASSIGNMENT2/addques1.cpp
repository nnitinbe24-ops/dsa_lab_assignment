#include <iostream>
#include <cmath>
using namespace std;

void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int countPairsWithDiffK(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] - arr[j]) == k) {
                count++;
            }
        }
    }
    return count;
}

void displayResult(int count, int k) {
    cout << "Number of pairs with difference " << k << " = " << count << endl;
}

int main() {
    int n, k;
    cin >> n;
    int arr[n];
    inputArray(arr, n);
    cin >> k;
    int result = countPairsWithDiffK(arr, n, k);
    displayResult(result, k);
    return 0;
}