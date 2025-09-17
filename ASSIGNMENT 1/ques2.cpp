/* 
QUES=2
Design the logic to remove the duplicate elements from an Array and after the
deletion the array should contain the unique elements

*/

#include <iostream>
using namespace std;

int arr[100], n;

void inputArray() {

    cout << "Enter number of elements: ";
    cin >> n;


    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void removeDuplicates() {
    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            if (arr[i] == arr[j]) {

                for (int k = j; k < n - 1; k++) arr[k] = arr[k + 1];
                n--;
                j--;

            }
        }
    }
}

void displayArray() {


    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

}

int main() {
    inputArray();
    removeDuplicates();
    displayArray();
}