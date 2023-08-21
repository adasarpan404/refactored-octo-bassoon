#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 1;
        int right = num;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid * mid == num)
                return true;
            if (mid * mid < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    cout << (solution.isPerfectSquare(9) ? "It is a perfect square" : "It is not perfect square") << endl;
    cout << (solution.isPerfectSquare(16) ? "It is a perfect square" : "It is not perfect square") << endl;
    cout << (solution.isPerfectSquare(25) ? "It is a perfect square" : "It is not perfect square") << endl;
    cout << (solution.isPerfectSquare(35) ? "It is a perfect square" : "It is not perfect square") << endl;
    cout << (solution.isPerfectSquare(40) ? "It is a perfect square" : "It is not perfect square") << endl;
    cout << (solution.isPerfectSquare(49) ? "It is a perfect square" : "It is not perfect square") << endl;

    return 0;
}