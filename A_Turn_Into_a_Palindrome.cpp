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
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        int i = 0;
        int j = n - 1;
        int counter = 0;
        while (i < j)
        {
            if (s[i] != s[j])
            {
            
            if (s[i] == c || s[j] == c)
                counter++;

            else
                counter += 2;
            }
            i++;
            j--;
        }
        cout << counter << endl;
    }

    return 0;
}