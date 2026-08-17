#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll solve()
{
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());

    ll L = sum - y;
    ll R = sum - x;
    ll count = 0;

    for (int i = 0; i < n; i++)
    {
        auto it1 = lower_bound(a.begin() + i + 1, a.end(), L - a[i]);
        auto it2 = upper_bound(a.begin() + i + 1, a.end(), R - a[i]);
        count += distance(it1, it2);
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        cout << solve() << endl;
    return 0;
}