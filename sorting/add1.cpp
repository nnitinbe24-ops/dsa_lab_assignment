#include <iostream>
using namespace std;

void countingSort(int arr[], int n){
    int maxVal = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > maxVal) maxVal = arr[i];
    }

    int count[10000] = {0};

    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    int k = 0;
    for(int i = 0; i <= maxVal; i++){
        while(count[i] > 0){
            arr[k++] = i;
            count[i]--;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[1000];
    for(int i = 0; i < n; i++) cin >> arr[i];
    countingSort(arr, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}