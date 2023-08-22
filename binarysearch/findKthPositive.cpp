#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &nums, int k)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] - (mid + 1) >= k)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left + k;
    }
};
int main()
{
    Solution solution;
    vector<int> arr1 = {2, 3, 4, 7, 11};
    int k1 = 5;
    cout << "Kth missing positive integer: " << solution.findKthPositive(arr1, k1) << endl;

    vector<int> arr2 = {1, 2, 3, 4};
    int k2 = 2;
    cout << "Kth missing positive integer: " << solution.findKthPositive(arr2, k2) << endl;

    return 0;
}