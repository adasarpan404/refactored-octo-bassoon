#include<bits/stdc++.h>

using namespace std;

void printAll(int index, vector<int> &ds, vector<int> arr){
    if(index==arr.size()){
        for(auto it: ds){
            cout<<it<< " ";
        }
        cout<<endl;
        return;
    }
    printAll(index+1, ds, arr);
    ds.push_back(arr[index]);
    printAll(index+1, ds, arr);
    ds.pop_back();
    
}
int main(){
    vector<int> arr{1,2,3};
    vector<int> ds;
    printAll(0, ds, arr);
}