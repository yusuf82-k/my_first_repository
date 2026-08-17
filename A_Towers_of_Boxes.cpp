#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n,m,d;
        cin>>n>>m>>d;
        if(m>d){
            cout<<n<<endl;
            continue;
        }
        int x=d/m+1;
        int ans=(n+x-1)/x;
        cout<<ans<<endl;
    }
    return 0;
}