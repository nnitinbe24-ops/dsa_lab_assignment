#include <iostream>
using namespace std;

void setLower(int lower[], int n) {
    cout << "Enter non-zero elements row-wise for Lower Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> lower[k++];
        }
    }
}

void displayLower(int lower[], int n) {
    cout << "Lower Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << lower[k++] << " ";
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
    int lower[size];

    setLower(lower, n);
    displayLower(lower, n);

    return 0;
}