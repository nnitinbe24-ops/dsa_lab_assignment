/*

ques-->3a
Given an array of n-1 distinct integers in the range of 1 to n, find the missing number
in it in a Sorted Array
(a) Linear time

*/

#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++) total -= arr[i];
    return total;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Missing number: " << findMissingLinear(arr, n);
}