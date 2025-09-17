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

void printSparse(int mat[100][3]) {
    int terms = mat[0][2];
    for (int i = 0; i <= terms; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

int main() {
    int mat[100][3], trans[100][3];

    cout << "Enter sparse matrix in triplet form (rows cols nonZero then triplets):" << endl;
    readSparse(mat);

    transposeSparse(mat, trans);

    cout << "Transpose in triplet form:" << endl;
    printSparse(trans);

    return 0;
}