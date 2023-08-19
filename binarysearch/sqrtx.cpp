#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        int left = 1, right = x, ans;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid)
            {
                left = mid + 1;
                ans = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution solution;
    cout << solution.mySqrt(5) << endl;
    cout << solution.mySqrt(4) << endl;
    cout << solution.mySqrt(9) << endl;
    return 0;
}