#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct Edge
{
    int u, v, w;
};

int main()
{

    int t;
    cin>>t;
    while(t--){
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
 vector<int> dist(V, INF);
    int source=0;
    dist[source] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool NegativeCycle = false;
    for (int j = 0; j < E; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            NegativeCycle = true;
            break;
        }
    }

    if (NegativeCycle)
    {
        cout << "possible" << endl;
    }
    else
    {
        cout << "not possible" << endl;
    }
    }
    return 0;
}