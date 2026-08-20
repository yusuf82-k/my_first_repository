#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
long long tree[4 * MAXN];
long long lazy[4 * MAXN];
int a[MAXN];

// Build function to construct the Segment Tree
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// Range Update with Lazy Propagation
void update(int node, int start, int end, int l, int r, int val) {
    // 1. Resolve pending lazy updates for the current node
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    // 2. Out of bounds condition
    if (start > r || end < l) {
        return;
    }

    // 3. Current range is completely inside the update range
    if (l <= start && end <= r) {
        tree[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }

    // 4. Partial overlap: Recurse on children
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);

    // Merge child results
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// Range Query with Lazy Propagation
long long query(int node, int start, int end, int l, int r) {
    // 1. Resolve pending lazy updates for the current node
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    // 2. Out of bounds condition
    if (start > r || end < l) {
        return 0;
    }

    // 3. Current range is completely inside the query range
    if (l <= start && end <= r) {
        return tree[node];
    }

    // 4. Partial overlap: Recurse on children
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 5;
    // Example array (1-indexed)
    vector<int> input_arr = {0, 1, 3, 5, 7, 9}; 
    for (int i = 1; i <= n; i++) {
        a[i] = input_arr[i];
    }

    // Build the Segment Tree
    build(1, 1, n);

    // Query range sum [1, 3] -> 1 + 3 + 5 = 9
    cout << "Query [1, 3]: " << query(1, 1, n, 1, 3) << "\n";

    // Add +2 to elements in range [2, 4]
    update(1, 1, n, 2, 4, 2);

    // Query range sum [1, 3] after update -> 1 + (3+2) + (5+2) = 13
    cout << "Query [1, 3] after update: " << query(1, 1, n, 1, 3) << "\n";

    return 0;
}