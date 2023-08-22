#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int findMissingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {0, 1, 3};

    cout << "Missing Number:" << solution.findMissingNumber(nums) << endl;

    vector<int> nums1 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << "Missing Number:" << solution.findMissingNumber(nums1) << endl;
    return 0;
}