#include <bits/stdc++.h>

using namespace std;

void printResult(vector<vector<int>> ans)
{
    for (auto ele : ans)
    {
        cout << "[ ";
        for (auto it : ele)
        {
            cout << it << " ";
        }
        cout << "]";
        cout << endl;
    }
}
class Solution
{
private:
    void getAllPermutation1(vector<int> nums, vector<vector<int>> &ans, vector<int> ds, int freq[])
    {
        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i] = 1;
                getAllPermutation1(nums, ans, ds, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    void getAllPermutation2(int index, vector<vector<int>> &ans, vector<int> &nums)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            getAllPermutation2(index + 1, ans, nums);
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute1(vector<int> nums)
    {
        vector<vector<int>> result;
        vector<int> ds;
        int freq[nums.size()];
        for (int i = 0; i < nums.size(); i++)
            freq[i] = 0;
        getAllPermutation1(nums, result, ds, freq);
        return result;
    }
    vector<vector<int>> permute2(vector<int> nums)
    {
        vector<vector<int>> result;
        getAllPermutation2(0, result, nums);
        return result;
    }
};

int main()
{
    vector<int> nums{1, 2, 3};
    Solution solution;
    vector<vector<int>> result = solution.permute1(nums);
    cout << " Approach 1" << endl;
    printResult(result);
    cout << " Approach 2" << endl;
    result = solution.permute2(nums);
    printResult(result);
}