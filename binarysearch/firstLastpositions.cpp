#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int binarySearch(vector<int> nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            if (target > nums[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int searchPositons = binarySearch(nums, target);
        vector<int> a(2);
        a[0] = searchPositons;
        a[1] = searchPositons;
        while (a[0] > 0 && nums[a[0] - 1] == target)
        {
            a[0]--;
        }
        while (a[1] < nums.size() - 1 && nums[a[1] + 1] == target)
        {
            a[1]++;
        }
        return a;
    }
};
int main()
{
    vector<int> nums{1, 2, 3, 4, 4, 4, 4, 5, 6, 7, 8};
    Solution solution;
    vector<int> a = solution.searchRange(nums, 4);
    cout << a[0] + 1 << "  " << a[1] + 1 << endl;
    return 0;
}