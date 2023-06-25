#include <bits/stdc++.h>

using namespace std;

int countSubsequence(int index, vector<int> &arr, vector<int> &ds, int sum, int s)
{
    if (index == arr.size())
    {
        if (s == sum)
            return 1;
        else
            return 0;
    }
    ds.push_back(arr[index]);
    s += arr[index];
    int l = countSubsequence(index + 1, arr, ds, sum, s);
    ds.pop_back();
    s -= arr[index];
    int r = countSubsequence(index + 1, arr, ds, sum, s);
    return l + r;
}
int main()
{
    vector<int> arr{1, 2, 3, 4, 6, 7}, ds;
    int sum = 7;
    int count = countSubsequence(0, arr, ds, sum, 0);
    cout << count << endl;
    return 0;
}