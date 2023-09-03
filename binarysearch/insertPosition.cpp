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
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            cout << mid << " " << low << " " << high << " " << endl;
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
    vector<int> nums{11, 13, 15, 16, 17, 19};
    Solution solution;
    cout << solution.searchInsert(nums, 14);
    return 0;
}