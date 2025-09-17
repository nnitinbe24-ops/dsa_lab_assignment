#include <iostream>
#include <stack>
using namespace std;


void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}


void dailyTemperatures(int temp[], int n, int ans[]) {
    stack<int> s; 

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && temp[s.top()] <= temp[i]) {
            s.pop();
        }

        if (s.empty()) {
            ans[i] = 0;
        } else {
            ans[i] = s.top() - i;
        }

        s.push(i);
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

    int temp[100], ans[100];
    inputArray(temp, n);

    dailyTemperatures(temp, n, ans);
    printArray(ans, n);

    return 0;
}