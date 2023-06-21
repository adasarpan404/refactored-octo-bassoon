#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a{1,1,1,2,0,2,1,0,0,0,1,2};
    int low = 0, mid = 0, high = a.size()-1;
    while(mid<=high){
        switch(a[mid]){
            case 0: swap(a[low++], a[mid++]);
            break;
            case 1: mid++;
            break;
            case 2: swap(a[mid], a[high--]);
            break;
        }
    }
    for(auto &ele: a){
        cout<<ele<<" ";
    }
}