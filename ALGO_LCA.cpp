#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int LOG = 20; // 2^19 > 500,000 (adjust based on N)

vector<vector<int>> adj;
vector<vector<int>> up; // up[u][j] stores the (2^j)-th ancestor of node u
vector<int> depth;

// Step 1: Precompute depth and immediate parents via DFS
void dfs(int u, int p, int d) {
    depth[u] = d;
    up[u][0] = p; // 2^0 = 1st ancestor is the immediate parent

    // Fill the binary lifting table for u
    for (int j = 1; j < LOG; j++) {
        if (up[u][j - 1] != -1) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        } else {
            up[u][j] = -1; // No ancestor exists at this height
        }
    }

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

// Step 2: Query LCA of nodes u and v in O(log N)
int get_lca(int u, int v) {
    // Ensure u is deeper than or equal to v
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    // 1. Lift u up to the same depth as v
    int diff = depth[u] - depth[v];
    for (int j = LOG - 1; j >= 0; j--) {
        if ((diff >> j) & 1) {
            u = up[u][j];
        }
    }

    // If v was an ancestor of u, then u is now equal to v
    if (u == v) return u;

    // 2. Lift both u and v simultaneously until they are just below the LCA
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[u][j] != -1 && up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }

    // The parent of u (or v) is now the LCA
    return up[u][0];
}

int main() {
    int n = 7; // Number of nodes (1 to 7)
    adj.assign(n + 1, vector<int>());
    depth.assign(n + 1, 0);
    up.assign(n + 1, vector<int>(LOG, -1));

    // Sample Tree edges
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    //      /
    //     7
    adj[1] = {2, 3}; adj[2] = {1, 4, 5};
    adj[3] = {1, 6}; adj[4] = {2};
    adj[5] = {2, 7}; adj[6] = {3};
    adj[7] = {5};

    // Precompute binary lifting table starting from root (node 1)
    dfs(1, -1, 0);

    cout << "LCA(4, 7) = " << get_lca(4, 7) << "\n"; // Output: 2
    cout << "LCA(7, 6) = " << get_lca(7, 6) << "\n"; // Output: 1
    cout << "LCA(5, 2) = " << get_lca(5, 2) << "\n"; // Output: 2

    return 0;
}




//completely understood the code
