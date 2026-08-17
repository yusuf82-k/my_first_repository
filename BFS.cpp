#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>> &adj, int n) {
    vector<bool> vis(n, false);
    queue<int> q;

    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}
