#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll INF = 1e18;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);

    dist[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    pq.push({0, 1});

    while (!pq.empty())
    {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF)
    {
        cout << -1 << endl;
    }
    else
    {

        vector<int> path;
        for (int v = n; v != -1; v = parent[v])
        {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}