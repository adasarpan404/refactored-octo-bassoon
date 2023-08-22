#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchInMatrix(vector<vector<int>> matrix, int target)
    {
        int n = matrix.size();

        int i = 0;
        int j = matrix[0].size() - 1;

        while (j >= 0 && i < n)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Solution solution;
    cout << (solution.searchInMatrix(matrix, 10) ? "Element found" : "Element not found") << endl;
    cout << (solution.searchInMatrix(matrix, 14) ? "Element found" : "Element not found") << endl;
    return 0;
}