#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

typedef long long ll;

typedef vector<ll> vll;

string nl = "\n";

void solve()
{
    int n;
    cin >> n;
    int h[n], a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i] >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (h[i] == a[j])
                ans++;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int testcases;
    bool multi = false;
    if (multi)
    {
        cin >> testcases;
    }
    else
    {
        testcases = 1;
    }
    while (testcases--)
    {
        solve();
    }
    return 0;
}
