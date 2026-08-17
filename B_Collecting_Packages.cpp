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
        cin >> n;
        vector<pair<int, int>> a(n + 1);
        a[0].first=0;
        a[0].second=0;
        for (int i = 1; i <=n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(), a.end());
     //   int x = 0, y = 0;
      //  bool flag = true;
        string s = "";
        for (int i = 1; i <= n; i++)
        {
            int dis_x = (a[i].first - a[i - 1].first);
            int dis_y = (a[i].second - a[i - 1].second);
            if (dis_y < 0)
            {
                s = "-1";
                break;
            }
            while (dis_x--)
            {
                s += 'R';
            }
            while (dis_y--){
                s += 'U';
            } 
        }
        if (s == "-1")
        {
            cout << "NO" << endl;
        }
        else{
            cout<<"YES"<<endl;
            cout << s << endl;
        }
    }
    return 0;
}