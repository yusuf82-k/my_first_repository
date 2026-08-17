#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Defining a pair for the priority queue: {distance, node}
typedef pair<int, int> pii;

void dijkstra(int start, int target, int n, vector<vector<pii>>& adj) {
    // distance[i] stores the minimum cost to reach node i
    vector<int> dist(n + 1, 1e9); 
    // parent[i] stores the node that came before i in the shortest path
    vector<int> parent(n + 1, -1);
    
    // Min-priority queue to get the node with the smallest distance
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u; // Track the path
                pq.push({dist[v], v});
            }
        }
    }

    // Printing the result
    if (dist[target] == 1e9) {
        cout << "No path exists." << endl;
    } else {
        cout << "Shortest Distance: " << dist[target] << endl;
        
        // Reconstruct path using the parent array
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << "Path: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
        }
        cout << endl;
    }
}

int main() {
    int nodes = 5, edges = 6;
    vector<vector<pii>> adj(nodes + 1);

    // Adding edges: {destination, weight}
    adj[1].push_back({2, 2});
    adj[1].push_back({4, 1});
    adj[2].push_back({3, 4});
    adj[2].push_back({5, 5});
    adj[4].push_back({3, 3});
    adj[3].push_back({5, 1});

    dijkstra(1, 5, nodes, adj);

    return 0;
}