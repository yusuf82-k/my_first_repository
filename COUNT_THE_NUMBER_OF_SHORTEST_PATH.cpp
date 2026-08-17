#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<long long, int> pli; // {distance, node}

void countShortestPaths(int start, int n, vector<vector<pair<int, int>>>& adj) {
    vector<long long> dist(n + 1, 1e18); // Minimum distance
    vector<long long> count(n + 1, 0);   // Number of shortest paths
    
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    dist[start] = 0;
    count[start] = 1; // There is 1 way to be at the start
    pq.push({0, start});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // 1. Found a STRICTLY shorter path
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                count[v] = count[u]; // Reset count to the parent's count
                pq.push({dist[v], v});
            }
            // 2. Found ANOTHER path of the same minimum length
            else if (dist[u] + weight == dist[v]) {
                count[v] += count[u]; // Add the parent's paths to this node
            }
        }
    }

    // Output results
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 1e18) {
            cout << "Node " << i << ": Unreachable" << endl;
        } else {
            cout << "Node " << i << ": Min Distance = " << dist[i] 
                 << ", Total Shortest Paths = " << count[i] << endl;
        }
    }
}

int main() {
    int nodes = 4;
    vector<vector<pair<int, int>>> adj(nodes + 1);

    // Example: Multiple paths to node 4 with weight 5
    // Path A: 1 -> 2 -> 4 (2 + 3 = 5)
    // Path B: 1 -> 3 -> 4 (2 + 3 = 5)
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 2});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 3});

    countShortestPaths(1, nodes, adj);

    return 0;
}