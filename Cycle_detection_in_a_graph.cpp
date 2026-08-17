#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool hasCycleUndirected(int n, vector<int> adj[]) {
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            stack<pair<int, int>> s; // {current, parent}
            s.push({i, -1});
            
            while (!s.empty()) {
                int curr = s.top().first;
                int par = s.top().second;
                s.pop();
                
                if (!visited[curr]) {
                    visited[curr] = true;
                    for (int neighbor : adj[curr]) {
                        if (!visited[neighbor]) {
                            s.push({neighbor, curr});
                        } else if (neighbor != par) {
                            return true; // Found a cycle
                        }
                    }
                }
            }
        }
    }
    return false;
}