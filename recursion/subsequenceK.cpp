#include <bits/stdc++.h>

using namespace std;

void printAll(int index, vector<int> &ds, vector<int> &arr, int s, int sum)
{
    if (index == arr.size())
    {
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    ds.push_back(arr[index]);
    s += arr[index];
    printAll(index + 1, ds, arr, s, sum);
    ds.pop_back();
    s -= arr[index];
    printAll(index + 1, ds, arr, s, sum);
}
int main()
{
    vector<int> arr{1, 2, 3, 4};
    int sum = 6;
    vector<int> ds;
    printAll(0, ds, arr, 0, sum);
}