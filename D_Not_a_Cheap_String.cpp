#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n;
        cin >> s >> n;
        int sum = 0;
        vector<int> freq(26, 0);

        for (char c : s)
        {
            freq[c - 'a']++;
            sum += (c - 'a' + 1);
        }

        if (sum <= n)
        {
            cout << s << endl;
            continue;
        }

        int extra = sum - n;
        int sum1 = 0;

        for (int i = 25; i >= 0; i--)
        {
            if (sum1 < extra)
            {

                if (freq[i] > 0)
                {

                    int value = i + 1;
                    int x = freq[i] * value;
                    int rem = extra - sum1;

                    if (x <= rem)
                    {
                        sum1 += x;
                        freq[i] = 0;
                    }

                    else
                    {
                        int q = (rem + value - 1) / value;
                        sum1 = extra;
                        freq[i] -= q;
                    }
                }
            }
            else
                break;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (freq[s[i] - 'a'] > 0)
            {
                cout << s[i];
                freq[s[i] - 'a']--;
            }
        }
        cout << endl;
    }
    return 0;
}