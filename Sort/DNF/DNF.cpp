#include<bits/stdc++.h>

using namespace std;

void sort012(int a[], int n){
    int low=0;
    int high = n-1;
    int mid = low + (high - low)/2;

    while(mid<=high){
        switch(a[mid]){
            case 0:
                swap(a[low++], a[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(a[mid], a[high--]);
                break;
        }
    }
}

void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort012(a,n);
    printarray(a,n);
    return 0;
}