#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int solve() {
    int rows, cols;
    if (!(cin >> rows >> cols)) return -1;

    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    // dp[i][j] will store the min cost to reach row i, col j from the bottom
    vector<vector<int>> dp(rows, vector<int>(cols));

    // Base case: The bottom row (rows-1) cost is just the grid value
    for (int j = 0; j < cols; j++) {
        dp[rows - 1][j] = grid[rows - 1][j];
    }

    // Fill the table from bottom-to-top
    for (int i = rows - 2; i >= 0; i--) {
        for (int j = 0; j < cols; j++) {
            // Options from the row below
            int down = dp[i + 1][j];
            int down_left = (j > 0) ? dp[i + 1][j - 1] : INF;
            int down_right = (j < cols - 1) ? dp[i + 1][j + 1] : INF;

            dp[i][j] = grid[i][j] + min(min(down, down_left), down_right);
        }
    }

    // The answer is the minimum value in the top row (row 0)
    int result = INF;
    for (int j = 0; j < cols; j++) {
        result = min(result, dp[0][j]);
    }
    return result;
}

int main() {
    int ans = solve();
    if (ans != -1) cout << "Minimum Cost: " << ans << endl;
    return 0;
}