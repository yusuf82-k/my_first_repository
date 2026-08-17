#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int block(vector<int> &a, int i, int x)
{

    auto R = upper_bound(a.begin() + i, a.end(), x, greater<int>());
    return distance(a.begin() + i, R);
}
int main()
{
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        sort(a.rbegin(), a.rend());
        int count = block(a, 0, a[0]);
        if (count == n)
        {
            cout << count << endl;
            continue;
        }
        int prev = count;
        int i = count;

        while (i < n)
        {
            int x = block(a, i, a[i]);
            if (x > prev)
            {
                count += x - prev;
                prev = x;
            }
            i += x;
        }
        cout << count << endl;
    }
    return 0;
}