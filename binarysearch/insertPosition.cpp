#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> nums, int target)
    {
        int low = 0, high = nums.size();

        if (target > nums[high - 1])
            return high;
        while (low >= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            if (target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main()
{
    vector<int> nums{1, 2, 4, 6, 10, 11, 13, 16};
    Solution solution;
    cout << solution.searchInsert(nums, 3) << endl;
    cout << solution.searchInsert(nums, 8) << endl;
    cout << solution.searchInsert(nums, 13) << endl;
    cout << solution.searchInsert(nums, 19) << endl;
    cout << solution.searchInsert(nums, 4) << endl;
    return 0;
}