#include <bits/stdc++.h>

using namespace std;

void printSolution(vector<vector<int>> result){
    for(auto ele: result){
        for(auto it: ele){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
class Solution
{
private:
    void findCombination(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        for (int i = index; i < arr.size(); i++)
        {
            if (i != index && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                continue;
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSubset2(vector<int> arr, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(), arr.end());
        findCombination(0, target, arr, ans, ds);
        return ans;
    }
};
int main()
{
    vector<int> arr{10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution solution;

    vector<vector<int>> result = solution.combinationSubset2(arr, target);
    printSolution(result);
    return 0;
}