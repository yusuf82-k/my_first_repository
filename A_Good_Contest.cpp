#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        cout<<n-min({a,b,c})<<endl;
    }

    return 0;
}