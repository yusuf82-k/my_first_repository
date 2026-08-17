#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Solve 0-1 Knapsack using 1D DP array.
 * We iterate backwards through the weight to ensure 
 * each item is used at most once.
 */
int solve_knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }
    return dp[W];
}

int main() {
    int n, W;
    
    // First line: Number of items and Max Capacity
    if (!(cin >> n >> W)) return 0;

    vector<int> values(n), weights(n);

    // Read values and weights
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    cout << solve_knapsack(W, weights, values, n) << endl;

    return 0;
}