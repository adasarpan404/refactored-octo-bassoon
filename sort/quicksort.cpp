#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low], i = low, j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high - 1){
            i++;
        }
        while(arr[j]>pivot && j>= low -1){
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if(low<high){
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex+1, high);
    }
}

int main()
{
    vector<int> arr{3, 4, 1, 2, 5, 6, 7, 9, 11, 8};
    quickSort(arr, 0, arr.size());
    for(auto &elem: arr){
        cout<<elem<< " ";
    }

    return 0;
}