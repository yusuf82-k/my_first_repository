#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int n = s.size();
        ll sum = 0;

        for (int i=0;i<n;i++)
            sum += s[i]- '0';

        if (sum <10)
        {
            cout << 0 << endl;
            continue;
        }
        ll total = sum - 9;
        vector<int> v;
        v.push_back((s[0] - '0') - 1);
        for (int i = 1; i < n; i++)
            v.push_back(s[i] - '0');
        sort(v.begin(), v.end(),greater<int>());
        ll curr = 0;
        int ans = 0;
        for (int x : v)
        {
            curr+= x;
            ans++;
            if (curr >= total)
                break;
        }
        cout << ans << endl;
    }
}