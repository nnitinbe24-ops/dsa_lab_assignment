/* 
ques-->3b

Using binary search

*/
#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] != mid + 1) high = mid - 1;
        else low = mid + 1;
    }
    return low + 1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Missing number: " << findMissingBinary(arr, n);
}