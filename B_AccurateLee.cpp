#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int first_one = -1;
        int last_zero = -1;
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (c == '1')
            {
                if (first_one == -1)
                {
                    first_one = i;
                }
            }
            else
            {
                last_zero = i;
            }
        }
        if (first_one == -1 || last_zero == -1 || last_zero < first_one)
        {
            cout << s << endl;
            continue;
        }
        for (int i = 0; i <first_one; i++)
            cout << s[i];
       // cout << 1;
        for (int i = last_zero; i < n; i++)
            cout << s[i];
        cout << endl;
    }
    return 0;
}