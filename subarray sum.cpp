#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Using long long to prevent integer overflow on large sums
typedef long long ll;

// Structure to hold the 4 critical values for Maximum Subarray Sum
struct Node {
    ll sum;  // Total sum of the segment
    ll pref; // Max prefix sum
    ll suff; // Max suffix sum
    ll ans;  // Max subarray sum in this segment
};

// Global arrays for performance (avoids vector overhead)
const int MAXN = 100005;
ll arr[MAXN];
Node tree[4 * MAXN]; // Flat array representation of the Segment Tree

// Helper function to create a single leaf node
Node make_node(ll val) {
    Node res;
    res.sum = val;
    
    // NOTE: If your problem allows EMPTY subarrays (sum = 0), 
    // change these to: max(0LL, val)
    res.pref = val;
    res.suff = val;
    res.ans = val;
    
    return res;
}

// Logic to merge two adjacent segment tree nodes
Node merge(Node L, Node R) {
    Node P;
    P.sum = L.sum + R.sum;
    P.pref = max(L.pref, L.sum + R.pref);
    P.suff = max(R.suff, R.sum + L.suff);
    P.ans = max({L.ans, R.ans, L.suff + R.pref});
    return P;
}

// Build the segment tree out of the input array
// 1-based indexing used for node tracking: Left = 2*node, Right = 2*node + 1
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = make_node(arr[start]);
        return;
    }
    int mid = start + (end - start) / 2;
    build(2 * node, start, mid);         // Left child
    build(2 * node + 1, mid + 1, end);   // Right child
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]); // Combine
}

// Query the maximum subarray sum in range [l, r]
Node query(int node, int start, int end, int l, int r) {
    // Total overlap: current segment is completely within query range
    if (l <= start && end <= r) {
        return tree[node];
    }
    
    int mid = start + (end - start) / 2;
    
    // If the query range lies strictly in one of the halves
    if (r <= mid) {
        return query(2 * node, start, mid, l, r);
    }
    if (l > mid) {
        return query(2 * node + 1, mid + 1, end, l, r);
    }
    
    // Partial overlap: query spans across both halves, fetch both and merge
    Node left_res = query(2 * node, start, mid, l, r);
    Node right_res = query(2 * node + 1, mid + 1, end, l, r);
    return merge(left_res, right_res);
}

// OPTIONAL: Point Update function (in case elements change dynamically)
void update(int node, int start, int end, int idx, ll val) {
    if (start == end) {
        arr[idx] = val;
        tree[node] = make_node(val);
        return;
    }
    int mid = start + (end - start) / 2;
    if (idx <= mid) {
        update(2 * node, start, mid, idx, val);
    } else {
        update(2 * node + 1, mid + 1, end, idx, val);
    }
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

int main() {
    // Optimize standard I/O operations for performance speedup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    if (!(cin >> n >> q)) return 0;
    
    // Reading 1-based index input array
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    // Construct the initial tree
    build(1, 1, n);
    
    // Process 10^5 queries
    while (q--) {
        int type;
        // Some problems include updates. If it's a pure query problem, 
        // you can remove the 'type' check and just run the query logic directly.
        cin >> type; 
        
        if (type == 1) { // Type 1: Range Maximum Subarray Sum Query
            int l, r;
            cin >> l >> r;
            Node res = query(1, 1, n, l, r);
            cout << res.ans << "\n";
        } 
        else if (type == 2) { // Type 2: Point Update (Change element at index to val)
            int idx;
            ll val;
            cin >> idx >> val;
            update(1, 1, n, idx, val);
        }
    }
    
    return 0;
}