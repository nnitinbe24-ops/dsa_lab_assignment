#include <iostream>
#include <stack>
using namespace std;


void inputArray(int arr[], int n) {
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}


void nearestSmaller(int arr[], int n, int ans[]) {
    stack<int> s;

    for (int i = 0; i < n; i++) {
        
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }

        
        s.push(arr[i]);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100], ans[100];  
    inputArray(arr, n);
    nearestSmaller(arr, n, ans);

    cout << "Nearest Smaller Elements: ";
    printArray(ans, n);

    return 0;
}