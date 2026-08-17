#include <iostream>
#include <vector>

using namespace std;

bool isCyclicDirected(int v, vector<int> adj[], vector<bool>& visited, vector<bool>& recStack) {
    visited[v] = true;
    recStack[v] = true; // Mark as part of the current path

    for (int neighbor : adj[v]) {
        // If neighbor is in current recursion stack, cycle exists
        if (recStack[neighbor]) {
            return true;
        }
        // If neighbor is not visited, recurse
        if (!visited[neighbor]) {
            if (isCyclicDirected(neighbor, adj, visited, recStack))
                return true;
        }
    }

    recStack[v] = false; // Backtrack: remove from current path
    return false;
}
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isCyclicDirectedIterative(int start, int V, vector<int> adj[]) {
    vector<int> state(V, 0); // 0 = Unvisited, 1 = Visiting, 2 = Visited
    stack<int>s;

    s.push(start);

    while (!s.empty()) {
        int u = s.top();

        if (state[u] == 0) {
            state[u] = 1; // Mark as Visiting (on current path)
        } else {
            state[u] = 2; // Mark as Visited (fully explored)
            s.pop();
            continue;
        }

        for (int v : adj[u]) {
            if (state[v] == 1) return true; // Cycle detected: back edge to active node
            if (state[v] == 0) s.push(v);
        }
    }
    return false;
}