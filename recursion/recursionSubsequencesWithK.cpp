#include <iostream>
#include <vector>

using namespace std;

void printSubsets(int index, vector<int> &currentSubset, int currentSum, int targetSum, int arr[], int size)
{
    if (index == size)
    {
        if (currentSum == targetSum)
        {
            for (auto it : currentSubset)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    currentSubset.push_back(arr[index]);
    currentSum += arr[index];
    printSubsets(index + 1, currentSubset, currentSum, targetSum, arr, size);

    currentSum -= arr[index];
    currentSubset.pop_back();
    printSubsets(index + 1, currentSubset, currentSum, targetSum, arr, size);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> currentSubset;
    int targetSum = 6;
    printSubsets(0, currentSubset, 0, targetSum, arr, 5);

    return 0;
}
