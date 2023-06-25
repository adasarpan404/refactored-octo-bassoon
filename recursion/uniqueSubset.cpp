#include <bits/stdc++.h>

using namespace std;

void printAns(vector<vector<int>> result)
{
    for (auto ele : result)
    {
        for (auto it : ele)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}
class Solution
{
private:
    // Recursively finds subsets with duplicates
    void findSubset(int index, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        ans.push_back(ds);
        for (int i = index; i < arr.size(); i++)
        {
            if (i != index && arr[i] == arr[i - 1])
                continue;
            ds.push_back(arr[i]);
            findSubset(i + 1, arr, ans, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubset(0, nums, ans, ds);
        return ans;
    }
};
int main()
{
    vector<int> arr{1, 2, 2};
    Solution solution;
    vector<vector<int>> ans = solution.subsetWithDup(arr);
    printAns(ans);
    return 0;
}