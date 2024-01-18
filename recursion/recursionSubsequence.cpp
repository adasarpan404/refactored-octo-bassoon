#include <iostream>
#include <vector>

using namespace std;

void printAllSubsets(int currentIndex, vector<int> &currentSubset, int array[], int size)
{
    if (currentIndex == size)
    {
        cout << "{";
        for (auto element : currentSubset)
        {
            cout << element << " ";
        }
        if (currentSubset.empty())
        {
            cout << "}";
        }
        else
        {
            cout << "\b}";
        }
        cout << endl;
        return;
    }
    currentSubset.push_back(array[currentIndex]);
    printAllSubsets(currentIndex + 1, currentSubset, array, size);

    currentSubset.pop_back();
    printAllSubsets(currentIndex + 1, currentSubset, array, size);
}

int main()
{
    int array[] = {1, 2, 3, 4};
    vector<int> currentSubset;
    printAllSubsets(0, currentSubset, array, 4);

    return 0;
}
