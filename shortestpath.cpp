#include <bits/stdc++.h>
using ll = long long;
using namespace std;
pair<int, int> bfs(const vector<vector<int>> &adj, int source)
{
    int n = adj.size();

    vector<int> dist(n + 1);
    vector<bool> visited(n + 1, false);
    int maxi = INT_MIN;
    int farthest = source;
    queue<int> q;
    q.push(source);
    dist[source] = 0;
    visited[source] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                visited[x] = true;
                dist[x] = dist[curr] + 1;
                if (dist[x] > maxi)
                {
                    farthest = x;
                    maxi = dist[x];
                }
            }
        }
    }
    return {farthest, maxi};
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}