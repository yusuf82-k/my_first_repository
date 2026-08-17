#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 100;
vector<int> adj[MAX];
bool visited[MAX];

void resetVisited(int n) {
    for (int i = 0; i < n; i++) visited[i] = false;
}

// PROBLEM 1: Path Finding (Iterative)
bool hasPathIterative(int start, int target) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        if (curr == target) return true;

        if (!visited[curr]) {
            visited[curr] = true;
            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) s.push(neighbor);
            }
        }
    }
    return false;
}

// PROBLEM 2: Connected Components (Iterative)
int countComponentsIterative(int totalNodes) {
    int count = 0;
    for (int i = 0; i < totalNodes; i++) {
        if (!visited[i]) {
            count++;
            stack<int> s;
            s.push(i);
            while (!s.empty()) {
                int curr = s.top(); s.pop();
                if (!visited[curr]) {
                    visited[curr] = true;
                    for (int n : adj[curr]) if (!visited[n]) s.push(n);
                }
            }
        }
    }
    return count;
}

// PROBLEM 3: Max Depth (Iterative)
// We use a pair to store {node, depth}
int findMaxDepthIterative(int startNode) {
    stack<pair<int, int>> s;
    s.push({startNode, 1});
    int maxD = 0;

    while (!s.empty()) {
        pair<int, int> curr = s.top();
        s.pop();

        int u = curr.first;
        int d = curr.second;

        if (!visited[u]) {
            visited[u] = true;
            maxD = max(maxD, d);

            for (int neighbor : adj[u]) {
                if (!visited[neighbor]) {
                    s.push({neighbor, d + 1});
                }
            }
        }
    }
    return maxD;
}

int main() {
    int n = 7; 

    // Component 1: 0-1-2-3
    adj[0].push_back(1); adj[1].push_back(0);
    adj[1].push_back(2); adj[2].push_back(1);
    adj[2].push_back(3); adj[3].push_back(2);

    // Component 2: 4-5, 4-6
    adj[4].push_back(5); adj[5].push_back(4);
    adj[4].push_back(6); adj[6].push_back(4);

    // --- Test Problem 1 ---
    resetVisited(n);
    cout << "Path 0 to 3 exists? " << (hasPathIterative(0, 3) ? "Yes" : "No") << endl;

    // --- Test Problem 2 ---
    resetVisited(n);
    cout << "Total connected components: " << countComponentsIterative(n) << endl;

    // --- Test Problem 3 ---
    resetVisited(n);
    cout << "Max depth starting from 0: " << findMaxDepthIterative(0) << endl;

    return 0;
}