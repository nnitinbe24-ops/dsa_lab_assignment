#include <iostream>
using namespace std;

int partitionArr(int arr[], int l, int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<=pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;
    return i+1;
}

void quickSort(int arr[], int l, int r){
    if(l<r){
        int p=partitionArr(arr,l,r);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,r);
    }
}

int main(){
    int n; cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++) cin>>arr[i];
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}