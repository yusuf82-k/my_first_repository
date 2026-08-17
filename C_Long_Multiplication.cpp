#include<bits/stdc++.h>
using ll=long long;
using namespace std;

void solve() {
    string x, y;
    cin >> x >> y;
    int n = x.length();
    
    bool found_first_diff = false;
    
    for (int i = 0; i < n; i++) {
        // Find the first position where digits are different
        if (x[i] != y[i]) {
            if (!found_first_diff) {
                // For the very first difference, ensure x[i] gets the larger digit
                // This makes x the "larger" number overall
                if (x[i] < y[i]) {
                    swap(x[i], y[i]);
                }
                found_first_diff = true;
            } else {
                // For all subsequent differences, we want to make the smaller
                // number (y) as large as possible to minimize the gap.
                // So, x[i] should get the smaller digit and y[i] the larger one.
                if (x[i] > y[i]) {
                    swap(x[i], y[i]);
                }
            }
        }
    }
    
    cout << x << "\n" << y << "\n";
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