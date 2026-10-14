#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    ll min_val = -1;
    
    for (int i = 1; i <= n; ++i) {
         ll a;
        cin >> a;
        sum += a;
        ll current_avg = sum / i;
        
        if (i == 1) {
            min_val = current_avg;
        } else {
            min_val = min(min_val, current_avg);
        }
        cout << min_val << (i == n ? "" : " ");
    }
    cout <<endl;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}