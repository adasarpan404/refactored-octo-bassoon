#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums{10, 9, 7, 8, 5, 6, 4, 3, 1, 2};
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size() - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
    for (auto &ele : nums)
    {
        cout << ele << " ";
    }
    return 0;
}