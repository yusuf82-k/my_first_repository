#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int  a,b;
        cin>>a>>b;
        int ans;
         if(a<=b)
         ans=-1;
         else
         ans=min(b,a-b);
         cout<<ans<<endl;
    }

    return 0;
}