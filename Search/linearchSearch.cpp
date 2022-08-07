#include<bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int search, pos =-1;
    cout<<"Which element do you want to search";
    cin>>search;
    for(int i=0;i<n;i++){
        if(a[i]== search){
            pos = i+1;
        }
    }
    cout<<pos;
    return 0;
}
