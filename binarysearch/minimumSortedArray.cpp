#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int pivotElement(vector<int> nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mid < end && nums[mid] > nums[mid + 1])
                return mid;
            if (mid > start && nums[mid] < nums[mid - 1])
                return mid - 1;
            if (nums[mid] <= nums[start])
                end = mid - 1;
            else
                start = mid + 1;
        }

        return -1;
    }

public:
    int minElement(vector<int> nums)
    {
        int pivot = pivotElement(nums);
        return nums[pivot + 1];
    }
};

int main()
{
    vector<int> nums{4, 5, 6, 7, 8, 1, 2};
    Solution solution;
    cout << solution.minElement(nums) << endl;
    return 0;
}