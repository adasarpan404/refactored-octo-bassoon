#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int countLessOrEqual(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), count = 0, row = n - 1, col = 0;
        while (row >= 0 && col < n)
        {
            if (matrix[row][col] <= target)
            {
                count += row + 1;
                col++;
            }
            else
            {
                row--;
            }
        }
        return count;
    }

public:
    int kthSmallest(vector<vector<int>> matrix, int k)
    {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int count = countLessOrEqual(matrix, mid);
            if (count < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;

    int result = solution.kthSmallest(matrix, k);

    cout << "Kth smallest element: " << result << endl;

    return 0;
}