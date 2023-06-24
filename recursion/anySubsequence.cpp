#include <bits/stdc++.h>

using namespace std;
bool printAny(int index, vector<int> &arr, vector<int> &ds, int sum, int s)
{
    if (index == arr.size())
    {
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    ds.push_back(arr[index]);
    s += arr[index];
    if (printAny(index + 1, arr, ds, sum, s) == true)
        return true;
    ds.pop_back();
    s -= arr[index];
    if (printAny(index + 1, arr, ds, sum, s) == true)
        return true;
    return false;
}
int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    int sum = 7;
    vector<int> ds;
    printAny(0, arr, ds, sum, 0);
}