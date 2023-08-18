#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int binarySearch(vector<int> &nums, int target, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
    int pivot(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mid < end && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            if (mid > start && nums[mid] < nums[mid - 1])
            {
                return mid - 1;
            }
            if (nums[mid] <= nums[start])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }

public:
    int search(vector<int> &nums, int target)
    {
        int pivotElement = pivot(nums);
        if (pivotElement == -1)
        {
            return binarySearch(nums, target, 0, nums.size() - 1);
        }
        if (nums[pivotElement] == target)
        {
            return pivotElement;
        }
        if (target >= nums[0])
        {
            return binarySearch(nums, target, 0, pivotElement - 1);
        }
        return binarySearch(nums, target, pivotElement - 1, nums.size() - 1);
    }
};
int main()
{
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    Solution solution;
    int pos = solution.search(nums, 5);
    cout << (pos != -1 ? "Element found at position " + to_string(pos + 1) : "Element not found") << endl;
    pos = solution.search(nums, 10);
    cout << (pos != -1 ? "Element found at position " + to_string(pos + 1) : "Element not found") << endl;
    return 0;
}