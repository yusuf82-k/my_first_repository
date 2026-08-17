#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> dp(n + 1, -1e9);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (i >= a) dp[i] = max(dp[i], dp[i - a] + 1);
        if (i >= b) dp[i] = max(dp[i], dp[i - b] + 1);
        if (i >= c) dp[i] = max(dp[i], dp[i - c] + 1);
    }

    cout << dp[n] << endl;
}
//dp[i]=what is best way to make length i
//