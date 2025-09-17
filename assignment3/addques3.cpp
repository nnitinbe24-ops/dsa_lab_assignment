#include <iostream>
#include <stack>
using namespace std;


void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}


void nextGreater(int arr[], int n, int ans[]) {
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
      
        while (!s.empty() && s.top() <= arr[i]) {
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
    cin >> n;

    int arr[100], ans[100];  

    inputArray(arr, n);
    nextGreater(arr, n, ans);
    printArray(ans, n);

    return 0;
}