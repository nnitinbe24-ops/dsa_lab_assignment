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

void transposeSparse(int mat[100][3], int trans[100][3]) {
    int rows = mat[0][0];
    int cols = mat[0][1];
    int terms = mat[0][2];

    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = terms;

    int k = 1;
    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= terms; j++) {
            if (mat[j][1] == i) {
                trans[k][0] = mat[j][1];
                trans[k][1] = mat[j][0];
                trans[k][2] = mat[j][2];
                k++;
            }
        }
    }
}

void multiplySparse(int a[100][3], int b[100][3], int c[100][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Multiplication not possible" << endl;
        return;
    }

    int bt[100][3];
    transposeSparse(b, bt);

    c[0][0] = a[0][0];
    c[0][1] = b[0][1];
    int k = 1;

    for (int i = 1; i <= a[0][2]; i++) {
        for (int j = 1; j <= bt[0][2]; j++) {
            if (a[i][1] == bt[j][1]) {
                int r = a[i][0];
                int cc = bt[j][0];
                int val = a[i][2] * bt[j][2];

                int found = 0;
                for (int x = 1; x < k; x++) {
                    if (c[x][0] == r && c[x][1] == cc) {
                        c[x][2] += val;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    c[k][0] = r;
                    c[k][1] = cc;
                    c[k][2] = val;
                    k++;
                }
            }
        }
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

    multiplySparse(a, b, c);

    cout << "Result of Multiplication in triplet form:" << endl;
    printSparse(c);

    return 0;
}