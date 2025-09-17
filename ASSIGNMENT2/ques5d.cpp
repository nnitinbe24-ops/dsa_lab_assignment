#include <iostream>
using namespace std;

void setUpper(int upper[], int n) {
    cout << "Enter non-zero elements row-wise for Upper Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> upper[k++];
        }
    }
}

void displayUpper(int upper[], int n) {
    cout << "Upper Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) cout << upper[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int size = n*(n+1)/2;
    int upper[size];

    setUpper(upper, n);
    displayUpper(upper, n);

    return 0;
}