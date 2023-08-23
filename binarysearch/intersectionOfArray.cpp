#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binarySearchCount(vector<int> &arr, int target)
    {
        int left = 0, right = arr.size() - 1;
        int count = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)
            {
                count++;
                arr.erase(arr.begin() + mid);
                break;
            }
            else if (arr[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return count;
    }
    vector<int> intersect(vector<int> nums1, vector<int> nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        for (int num : nums1)
        {
            int countInNums2 = binarySearchCount(nums2, num);
            if (countInNums2 > 0)
            {
                result.push_back(num);
            }
        }

        return result;
    }
};
int main()
{
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> result = solution.intersect(nums1, nums2);

    cout << "Intersection: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}