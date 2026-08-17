#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin>>n;
        vector<ll>a(n);
        for(auto &x:a)
        cin>>x;
        if(a[0]==1)
        a[0]++;
        for(int i=1;i<n;i++){
            if(a[i]==1)
            a[i]++;
            if(a[i]%a[i-1]==0)
            a[i]++;
        }
        for(int x:a)
        cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}