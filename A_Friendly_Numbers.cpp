#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin>>x;
        if(x%9!=0){
        cout<<0<<endl;
        continue;
        }
        x/=9;
        ll rem=x;
        vector<ll>factor={11,111,1111,11111,111111,1111111,11111111,111111111};
        for(int i=7;i>=0;i--){
             rem=rem%factor[i];
        }
           if(rem<10)
           cout<<10<<endl;
           else
           cout<<0<<endl;
      
    }
    return 0;
}