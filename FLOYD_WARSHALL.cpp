#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll INF = 1e18;

void floydWarshall(ll v, vector<vector<ll>> &dist) {
    for (ll k = 0; k < v; k++) {
        for (ll i = 0; i < v; i++) {
            for (ll j = 0; j < v; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    if (!(cin >> t)) return 0;
    while (t--) {
        ll v, e;
        cin >> v >> e;

        // Initialize matrix with INF and 0 for self-loops
        vector<vector<ll>> dist(v, vector<ll>(v, INF));
        for (ll i = 0; i < v; i++) dist[i][i] = 0;

        for (ll i = 0; i < e; i++) {
            ll u, v_node, w;
            cin >> u >> v_node >> w;
            // Assuming directed graph; for undirected, add dist[v_node][u] = min(...)
            dist[u][v_node] = min(dist[u][v_node], w);
        }

        floydWarshall(v, dist);

        cout << "Shortest distance matrix between every pair of vertices:\n";
        for (ll i = 0; i < v; i++) {
            for (ll j = 0; j < v; j++) {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}