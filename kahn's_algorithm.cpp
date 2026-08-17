#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int v : adj[node]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Check for cycle
    if ((int)topo.size() != V) {
        cout << "Cycle detected! Topological sort not possible\n";
        return 0;
    }

    for (int x : topo)
        cout << x << " ";
    cout << endl;

    return 0;
}
