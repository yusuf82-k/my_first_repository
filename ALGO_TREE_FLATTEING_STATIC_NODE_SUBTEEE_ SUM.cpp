#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;

vector<int> adj[MAXN];
int val[MAXN];
int tin[MAXN], tout[MAXN];
int flat_val[MAXN];
long long pref[MAXN];
int timer = 0;

// Step 1: Flatten the tree using DFS
void dfs(int u, int p) {
    tin[u] = ++timer;
    flat_val[timer] = val[u];
    
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = timer;
}

int main() {
    int n = 5;
    
    // Node values (1-indexed)
    val[1] = 5; val[2] = 3; val[3] = 2; val[4] = 4; val[5] = 1;

    // Tree structure:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    adj[1] = {2, 3}; adj[2] = {1, 4, 5};
    adj[3] = {1};    adj[4] = {2}; adj[5] = {2};

    // 1. Run DFS to compute Euler Tour intervals
    dfs(1, 0);

    // 2. Build Prefix Sum Array in O(N)
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + flat_val[i];
    }

    // 3. Subtree Queries in O(1)
    
    // Subtree sum of node 2 (contains nodes 2, 4, 5 -> 3 + 4 + 1 = 8)
    int u = 2;
    long long sum_node_2 = pref[tout[u]] - pref[tin[u] - 1];
    cout << "Subtree sum of node 2: " << sum_node_2 << endl;

    // Subtree sum of node 1 (entire tree -> 5 + 3 + 2 + 4 + 1 = 15)
    u = 1;
    long long sum_node_1 = pref[tout[u]] - pref[tin[u] - 1];
    cout << "Subtree sum of node 1: " << sum_node_1 << endl;

    return 0;
}