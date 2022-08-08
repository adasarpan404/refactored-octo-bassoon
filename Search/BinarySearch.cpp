#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Enter element you want to search";
    int search;
    cin>>search;
    int pos = -1;
    int beg = 0, last = n-1;
    while(beg<last){
        int mid = beg + (last - beg)/2;
        if(a[mid]==search){
            pos = mid;
            break;
        }

        if(a[mid]>search) last = mid - 1;
        else beg = mid+1;
    }
    cout<<pos;
}