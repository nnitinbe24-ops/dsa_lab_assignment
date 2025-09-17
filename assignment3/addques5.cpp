#include <iostream>
#include <stack>
using namespace std;


bool canBeSorted(int arr[], int n) {
    stack<int> s;
    int expected = 1; 

    for (int i = 0; i < n; i++) {
        s.push(arr[i]);

    
        while (!s.empty() && s.top() == expected) {
            s.pop();
            expected++;
        }
    }

    
    return (expected == n + 1);
}

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (canBeSorted(arr, n)) {
        cout << "Yes, array B can be sorted." << endl;
    } else {
        cout << "No, array B cannot be sorted." << endl;
    }

    return 0;
}