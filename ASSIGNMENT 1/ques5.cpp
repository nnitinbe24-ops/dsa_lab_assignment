/*
ques-->5
Write a program to find sum of every row and every column in a two-dimensional
array

*/
#include <iostream>
using namespace std;

void sumofRowsandCols(int a[10][10], int r, int c) {


    for (int i = 0; i < r; i++) {
        int sum = 0;

        for (int j = 0; j < c; j++) {
            sum += a[i][j];
        }

        cout << "Row " << i << " sum = " << sum << "\n";
    }
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++) {
            
            sum += a[i][j];
        }
        cout << "Column " << j << " sum = " << sum << "\n";
    }
}

int main() {
    int a[10][10], r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++) {

    for (int j = 0; j < c; j++) {
    cin >> a[i][j];
   sumofRowsandCols(a, r, c);

    }
}
}