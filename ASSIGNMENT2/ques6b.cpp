#include <iostream>
using namespace std;

void readSparse(int mat[100][3]) {
    int rows, cols, terms;
    cin >> rows >> cols >> terms;
    mat[0][0] = rows;
    mat[0][1] = cols;
    mat[0][2] = terms;
    for (int i = 1; i <= terms; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }
}

void addSparse(int a[100][3], int b[100][3], int c[100][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible" << endl;
        return;
    }

    int i = 1, j = 1, k = 1;
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        }
        else if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++; k++;
        }
        else {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++; k++;
        }
    }

    while (i <= a[0][2]) {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++; k++;
    }

    while (j <= b[0][2]) {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++; k++;
    }

    c[0][2] = k - 1;
}

void printSparse(int mat[100][3]) {
    int terms = mat[0][2];
    for (int i = 0; i <= terms; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

int main() {
    int a[100][3], b[100][3], c[200][3];

    cout << "Enter first matrix (rows cols nonZero then triplets):" << endl;
    readSparse(a);

    cout << "Enter second matrix (rows cols nonZero then triplets):" << endl;
    readSparse(b);

    addSparse(a, b, c);

    cout << "Result of Addition in triplet form:" << endl;
    printSparse(c);

    return 0;
}