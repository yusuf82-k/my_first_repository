#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    vector<ll> b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    auto min_a = min_element(a.begin(), a.end());
    auto max_b = max_element(b.begin(), b.end());
    if (*max_b > *min_a)
    {
        swap(*min_a, *max_b);
    }
    if (k % 2 == 0)
    {

        auto max_a = max_element(a.begin(), a.end());
        auto min_b = min_element(b.begin(), b.end());
        if (*max_a > *min_b)
        {
            swap(*max_a, *min_b);
        }
    }

    ll sum = 0;
    for (long long x : a)
        sum += x;
    cout << sum<< endl;
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