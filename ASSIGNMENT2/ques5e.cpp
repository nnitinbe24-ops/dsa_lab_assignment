#include <iostream>
using namespace std;

void setSymmetric(int sym[], int n) {
    cout << "Enter lower triangle (including diagonal) row-wise:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> sym[k++];
        }
    }
}

void displaySymmetric(int sym[], int n) {
    cout << "Symmetric Matrix:\n";
    int k = 0; 

   
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j <= i; j++) {
            cout << sym[k++] << " ";
        }
       
        for (int j = i+1; j < n; j++) {
            
            int kk = 0;
            for (int r = 0; r < n; r++) {
                for (int c = 0; c <= r; c++) {
                    if (r == j && c == i) {
                        cout << sym[kk] << " ";
                    }
                    kk++;
                }
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int size = n*(n+1)/2; 
    int sym[size];

    setSymmetric(sym, n);
    displaySymmetric(sym, n);

    return 0;
}