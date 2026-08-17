#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll testcase;
    cin >> testcase;
    for(ll tt = 1; tt <= testcase; tt++) {
        ll n, m, s, t;
        cin >> n >> m >>s>>t;
        
        vector<vector<pair<ll, ll>>> adj(n);
        for(ll i = 0; i < m; i++) {
            ll u, v, w; 
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<ll> dist(n, INF);
        dist[s] = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        
        pq.push({0, s});
        
        while(!pq.empty()){
            ll d = pq.top().first;
            ll u = pq.top().second;
            pq.pop();
            
            if(d > dist[u]) continue;
            
            for(auto &x : adj[u]){
                ll v = x.first;
                ll w = x.second;
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        cout << "Case #" << tt << ": ";
        if(dist[t] == INF) cout << "unreachable" << endl;
        else cout << dist[t] << endl;
    }
    return 0;
}