#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int INF=1e9;
int main() {
    int t;
    cin >> t;
    while (t--) {
         int n,m;
         cin>>n>>m;
         vector<vector<pair<ll,ll>>>adj(n+1);
         for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
             adj[v].push_back({u,w});

         }
      vector<ll>dist(n+1,INF);
      int source=1;
      dist[source]=0;
      priority_queue<pair<ll,ll>,vector<pair<ll,ll>,greater<pair<ll,ll>>>>pq;
      pq.push({0,source});
    while(!pq.empty()){
        ll d=pq.top().first;
        ll u=pq.top().second;
        pq.pop();
        if(d>dist[u])
        continue;
        for(auto& edge:adj[u]){
            int v=edge.first;
            int w=edge.second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }

    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endl;
    }
    return 0;
}
