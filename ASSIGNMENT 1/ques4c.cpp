/*
QUES-->4c
transpose of the matrix
*/

#include <iostream>
using namespace std;

void transposeMatrix(int a[10][10], int r, int c) {
    int t[10][10];


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            t[j][i] = a[i][j];
        }
    }
    cout << "Transpose matrix:\n";


    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << t[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int a[10][10], r, c;

    cout << "Enter rows and cols: ";
    cin >> r >> c;
    cout << "Enter matrix:\n";

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }
    transposeMatrix(a, r, c);
}