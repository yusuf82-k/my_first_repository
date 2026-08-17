#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Helper function to find the farthest node and its distance from a start node
pair<int, int> bfs(int start, int n, const vector<vector<int>>& adj) {
    vector<int> dist(n + 1, -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    int farthestNode = start;
    int maxDist = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (dist[curr] > maxDist) {
            maxDist = dist[curr];
            farthestNode = curr;
        }

        for (int neighbor : adj[curr]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }
    return {farthestNode, maxDist};
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(a);
    }

    // First BFS to find one end of the longest path
    pair<int, int> p1 = bfs(1, n, adj);
    
    // Second BFS from that end to find the actual diameter
    pair<int, int> p2 = bfs(p1.first, n, adj);

    cout << p2.second << endl;

    return 0;
}