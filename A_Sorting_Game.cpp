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
        int one = 0;
        int zero = 0;
        vector<int> ones;
        vector<int> zeros;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                one++;
                ones.push_back(i + 1);
            }
            else
            {
                zero++;
                //  zeros.push_back(i+1);
            }
        }
        if (one == 0 || zero == 0)
        {
            cout << "Bob" << endl;
            continue;
        }
        if (ones[0] == n - one + 1)
        {
            cout << "Bob" << endl;
            continue;
        }
        int count = 0;
        for (int i = n - one; i < n; i++)
        {
            if (s[i] == '0')
            {
                count++;
                zeros.push_back(i + 1);
            }
        }
        cout<<"Alice"<<endl;
        cout<<2*count<<endl;
        for (int i = 0; i < count; i++)
            cout << ones[i] << " ";
        for (int i = 0; i < count; i++)
            cout << zeros[i] << " ";
        cout << endl;
    }
    return 0;
}