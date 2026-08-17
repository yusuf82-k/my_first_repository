#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    int maxi = 0, ans = 0;
    for (int i : a)
        maxi = max(i, maxi);
    for (int i : a)
        ans += i == maxi; 
    cout << ans << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}