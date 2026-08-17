#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        vector<vector<pair<ll, ll>>> adj(n + 1);
        for (ll i = 0; i < m; i++) {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }

        ll startNode, endNode;
        cin >> startNode >> endNode;

        vector<ll> dist(n + 1, INF);
        dist[startNode] = 0;

        priority_queue<
            pair<ll, ll>,
            vector<pair<ll, ll>>,
            greater<pair<ll, ll>>
        > pq;

        pq.push({0, startNode});

        while (!pq.empty()) {
            auto p = pq.top();  
            pq.pop();

            ll d = p.first;
            ll u = p.second;

            if (d > dist[u]) continue;

            for (auto &edge : adj[u]) {
                ll v = edge.first;
                ll w = edge.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[endNode] == INF) {
            cout << "NO"<<endl;
        } else {
            cout << dist[endNode] << endl;
        }
    }

    return 0;
}
