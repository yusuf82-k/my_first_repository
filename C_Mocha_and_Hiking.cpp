#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (a[1] == 1)
    {
        cout << n + 1 << " ";
        for (int i = 1; i <= n; i++)
        {
            cout << i << (i == n ? "" : " ");
        }
        cout << endl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] == 0 && a[i + 1] == 1)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << j << " ";
            }
            cout << n + 1 << " ";
            for (int j = i + 1; j <= n; j++)
            {
                cout << j << (j == n ? "" : " ");
            }
            cout << endl;
            return;
        }
    }

    if (a[n] == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << n + 1 << endl;
        return;
    }

    cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}