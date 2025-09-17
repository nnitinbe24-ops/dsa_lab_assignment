#include <iostream>
using namespace std;

void setTriDiagonal(int tri[], int n) {
    cout << "Enter non-zero elements row-wise for Tri-Diagonal Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == j+1 || i+1 == j) {
                cin >> tri[k++];
            }
        }
    }
}

void displayTriDiagonal(int tri[], int n) {
    cout << "Tri-Diagonal Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == j+1 || i+1 == j) {
                cout << tri[k++] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int tri[3*n - 2];
    setTriDiagonal(tri, n);
    displayTriDiagonal(tri, n);

    return 0;
}