#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 100;
vector<int> adj[MAX];
bool visited[MAX];
int maxDepthFound = 0;

// Reset visited array between different problems
void resetVisited(int n) {
    for (int i = 0; i < n; i++) visited[i] = false;
}

// PROBLEM 1: Path Finding (Recursive DFS)
bool hasPath(int curr, int target) {
    if (curr == target) return true;
    visited[curr] = true;
    for (int neighbor : adj[curr]) {
        if (!visited[neighbor]) {
            if (hasPath(neighbor, target)) return true;
        }
    }
    return false;
}

// PROBLEM 2: Connected Components (Iterative DFS)
int countComponents(int totalNodes) {
    int count = 0;
    for (int i = 0; i < totalNodes; i++) {
        if (!visited[i]) {
            count++;
            // Internal Iterative DFS to mark this component
            stack<int> s;
            s.push(i);
            while (!s.empty()) {
                int curr = s.top(); s.pop();
                if (!visited[curr]) {
                    visited[curr] = true;
                    for (int neighbor : adj[curr]) {
                        if (!visited[neighbor]) s.push(neighbor);
                    }
                }
            }
        }
    }
    return count;
}

// PROBLEM 3: Max Depth (Recursive DFS)
void findMaxDepth(int curr, int currentDepth) {
    visited[curr] = true;
    maxDepthFound = max(maxDepthFound, currentDepth);
    for (int neighbor : adj[curr]) {
        if (!visited[neighbor]) {
            findMaxDepth(neighbor, currentDepth + 1);
        }
    }
}

int main() {
    int n = 7; // Nodes 0 to 6

    // Component 1: 0-1-2-3 (A line)
    adj[0].push_back(1); adj[1].push_back(0);
    adj[1].push_back(2); adj[2].push_back(1);
    adj[2].push_back(3); adj[3].push_back(2);

    // Component 2: 4-5, 4-6 (A small triangle/star)
    adj[4].push_back(5); adj[5].push_back(4);
    adj[4].push_back(6); adj[6].push_back(4);

    // --- Test Problem 1 ---
    resetVisited(n);
    cout << "Path 0 to 3 exists? " << (hasPath(0, 3) ? "Yes" : "No") << endl;
    resetVisited(n);
    cout << "Path 0 to 5 exists? " << (hasPath(0, 5) ? "Yes" : "No") << endl;

    // --- Test Problem 2 ---
    resetVisited(n);
    cout << "Total connected components: " << countComponents(n) << endl;

    // --- Test Problem 3 ---
    resetVisited(n);
    maxDepthFound = 0;
    findMaxDepth(0, 1); // Start at node 0 with depth 1
    cout << "Max depth of first component starting from 0: " << maxDepthFound << endl;

    return 0;
}