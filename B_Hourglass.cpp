#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {B
        ll s,k,m;
        cin>>s>>k>>m;
        ll rem=m%k;
  
        ll time=min(k,s);
        ll ans=time-rem;
        if(ans<0)
        ans=0;
        cout<<ans<<endl;
        
    }
    return 0;
}