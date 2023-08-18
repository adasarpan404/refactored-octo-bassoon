#include <bits/stdc++.h>

using namespace std;

int binarySearch(int a[], int search, int size)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == search)
            return mid;

        if (a[mid] > search)
            high = mid - 1;
        if (a[mid] < search)
            low = mid + 1;
    }
    return -1;
}
int main()
{
    int a[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof a / sizeof a[0];
    int pos = binarySearch(a, 40, size);
    cout << (pos != -1 ? "Element found at position " + to_string(pos + 1) : "Element not found") << endl;
    pos = binarySearch(a, 45, size);
    cout << (pos != -1 ? "Element found at position " + to_string(pos + 1) : "Element not found") << endl;
    return 0;
}