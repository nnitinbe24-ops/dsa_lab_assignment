#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n){
    int left = 0, right = n - 1;

    while(left < right){
        int minIndex = left;
        int maxIndex = right;

        if(arr[minIndex] > arr[maxIndex]){
            int temp = arr[minIndex];
            arr[minIndex] = arr[maxIndex];
            arr[maxIndex] = temp;
        }

        for(int i = left + 1; i < right; i++){
            if(arr[i] < arr[minIndex]) minIndex = i;
            if(arr[i] > arr[maxIndex]) maxIndex = i;
        }

        int temp = arr[left];
        arr[left] = arr[minIndex];
        arr[minIndex] = temp;

        if(maxIndex == left) maxIndex = minIndex;

        temp = arr[right];
        arr[right] = arr[maxIndex];
        arr[maxIndex] = temp;

        left++;
        right--;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[1000];
    for(int i = 0; i < n; i++) cin >> arr[i];
    improvedSelectionSort(arr, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}