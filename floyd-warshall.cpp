#include <iostream>
#include <vector>

using namespace std;

// Using a large value for Infinity. 
// Be careful not to use INT_MAX to avoid overflow during addition.
const int INF = 1e9;

void floydWarshall(int V, vector<vector<int>>& graph) {
    // Initialize the distance matrix with the input graph weights
    vector<vector<int>> dist = graph;

    // Triple nested loop: Intermediate (k), Source (i), Destination (j)
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, update the value
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the resulting shortest distance matrix
    cout << "Shortest distance matrix between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0,   5,   INF, 10},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(V, graph);

    return 0;
}