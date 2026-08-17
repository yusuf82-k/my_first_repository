#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, l;
    if (!(cin >> n >> l)) return false; 
    vector<vector<int>> adj(n);
    for (int i = 0; i < l; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> color(n, -1); // -1 means uncolored
    bool bicolorable = true;

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) { // Handle disconnected components
            queue<int> q;
            q.push(i);
            color[i] = 0; // Start coloring with 0

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neighbor : adj[curr]) {
                    if (color[neighbor] == -1) {
                        // Color neighbor with the opposite color (1 - 0 = 1, or 1 - 1 = 0)
                        color[neighbor] = 1 - color[curr];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[curr]) {
                        // Found an edge between two nodes of the same color!
                        return false; 
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}