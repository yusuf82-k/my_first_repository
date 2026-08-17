#include <iostream>
#include <vector>

using namespace std;

// The maximum value of n as per the problem constraints
const int MAX_N = 200000;
long long dp[MAX_N + 1];

// Function to precompute the sums
void precompute() {
    // temp_digit_sum[i] stores the sum of digits of the number i
    vector<int> temp_digit_sum(MAX_N + 1, 0);
    
    dp[0] = 0;
    for (int i = 1; i <= MAX_N; i++) {
        // Digit sum of i = (last digit) + (digit sum of the rest of the number)
        // This is a DP-like way to calculate digit sums efficiently
        temp_digit_sum[i] = (i % 10) + temp_digit_sum[i / 10];
        
        // Total sum up to i = (Total sum up to i-1) + (digit sum of i)
        dp[i] = dp[i - 1] + temp_digit_sum[i];
    }
}

int main() {
    // Faster I/O is necessary for tight time limits
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}