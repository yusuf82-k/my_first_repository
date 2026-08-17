#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string a, s;
    cin >> a >> s;
    int i = a.length() - 1;
    int j = s.length() - 1;
    vector<int> b;

    while (j >= 0)
    {
        if (i >= 0)
        {
            int a_digit = a[i] - '0';
            int s_digit = s[j] - '0';

            if (s_digit >= a_digit)
            {

                b.push_back(s_digit - a_digit);
                i--;
                j--;
            }
            else
            {

                if (j == 0)
                {
                    cout << -1 << endl;
                    return;
                }
                int s_val = (s[j - 1] - '0') * 10 + s_digit;
                int res = s_val - a_digit;

                if (res >= 0 && res <= 9 )
                {
                    b.push_back(res);
                    i--;
                    j -= 2;
                }
                else
                {
                    cout << -1 << endl;
                    return;
                }
            }
        }
        else
        {

            b.push_back(s[j] - '0');
            j--;
        }
    }

    if (i >= 0)
    {
        cout << -1 << endl;
        return;
    }

    int k = b.size() - 1;
    while (k > 0 && b[k] == 0)
        k--;
    while (k >= 0)
        cout << b[k--];
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}