#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a{4, 3, 2, 1, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 9, 8, 7, 6, 5};

    for (int i = 0; i < a.size(); i++)
    {
        int min = i;
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(a[i], a[min]);
        }
    }

    for (auto &ele : a)
    {
        cout << ele << " ";
    }
}