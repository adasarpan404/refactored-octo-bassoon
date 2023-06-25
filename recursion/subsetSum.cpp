#include <bits/stdc++.h>

using namespace std;

void findCombination(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (index == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if (arr[index] <= target)
    {
        ds.push_back(arr[index]);
        findCombination(index, target - arr[index], arr, ans, ds);
        ds.pop_back();
    }
    findCombination(index + 1, target, arr, ans, ds);
}
int main()
{
    vector<int> arr{1, 2, 3, 4};
    int sum = 6;
    vector<int> ds;
    vector<vector<int>> ans;
    findCombination(0, sum, arr, ans, ds);
    for (auto ele : ans)
    {
        for (auto it : ele)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}