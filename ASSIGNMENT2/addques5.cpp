#include <iostream>
using namespace std;

void duplicateTwo(int arr[], int n) {
    int countTwo = 0;
    for (int i=0; i < n; i++) {

        if (arr[i] == 2) countTwo++;
    }
    int i = n - 1;
    int j = n + countTwo - 1;
    while (i >= 0 && j >= 0) {

        if (j < n) arr[j] = arr[i];
        if (arr[i] == 2) {
            j--;
            if (j < n) arr[j] = 2;
        }

        i--; j--;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];

    duplicateTwo(arr, n);

    for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";

    }
    return 0;
    
}