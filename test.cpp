#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n, -1);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        x--;
        for (int j = x; j < n; j++)
        {
            if (a[j] == -1)
                a[j] = x + 1;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
// Super FX