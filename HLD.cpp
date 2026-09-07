#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];

int parent[MAXN];
int depth[MAXN];
int subtree[MAXN];
int heavy[MAXN];

int head[MAXN];
int pos[MAXN];

int value[MAXN];

int cur_pos = 0;

/*--------------------------------------------------
                SEGMENT TREE
--------------------------------------------------*/

int seg[4 * MAXN];

// Build segment tree
void build(int node, int l, int r, vector<int>& base) {

    if (l == r) {
        seg[node] = base[l];
        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid, base);
    build(node * 2 + 1, mid + 1, r, base);

    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

// Range sum query
int query(int node, int l, int r, int ql, int qr) {

    // Completely outside
    if (qr < l || r < ql)
        return 0;

    // Completely inside
    if (ql <= l && r <= qr)
        return seg[node];

    int mid = (l + r) / 2;

    int left = query(node * 2, l, mid, ql, qr);
    int right = query(node * 2 + 1, mid + 1, r, ql, qr);

    return left + right;
}

// Point update
void update(int node, int l, int r, int index, int val) {

    if (l == r) {
        seg[node] = val;
        return;
    }

    int mid = (l + r) / 2;

    if (index <= mid)
        update(node * 2, l, mid, index, val);
    else
        update(node * 2 + 1, mid + 1, r, index, val);

    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}


/*--------------------------------------------------
             FIRST DFS: FIND HEAVY CHILD
--------------------------------------------------*/

void dfs(int u, int p) {

    parent[u] = p;
    subtree[u] = 1;

    int max_subtree = 0;
    heavy[u] = -1;

    for (int v : adj[u]) {

        if (v == p)
            continue;

        depth[v] = depth[u] + 1;

        dfs(v, u);

        subtree[u] += subtree[v];

        // Find child having maximum subtree size
        if (subtree[v] > max_subtree) {
            max_subtree = subtree[v];
            heavy[u] = v;
        }
    }
}


/*--------------------------------------------------
             SECOND DFS: CREATE CHAINS
--------------------------------------------------*/

void decompose(int u, int h, vector<int>& base) {

    // Current node belongs to chain whose head is h
    head[u] = h;

    // Give current node a position in the array
    pos[u] = ++cur_pos;

    // Put node's value into base array
    base[cur_pos] = value[u];


    // Continue through heavy edge
    if (heavy[u] != -1) {

        decompose(heavy[u], h, base);
    }


    // Start new chains for light children
    for (int v : adj[u]) {

        if (v == parent[u] || v == heavy[u])
            continue;

        decompose(v, v, base);
    }
}


/*--------------------------------------------------
              HLD PATH QUERY
--------------------------------------------------*/

int pathQuery(int u, int v, int n) {

    int answer = 0;

    while (head[u] != head[v]) {

        // Make u the deeper chain
        if (depth[head[u]] < depth[head[v]])
            swap(u, v);

        // Query from u up to the head of its chain
        answer += query(
            1,
            1,
            n,
            pos[head[u]],
            pos[u]
        );

        // Move u to the parent of its chain head
        u = parent[head[u]];
    }


    // Now u and v are in the same chain

    if (depth[u] > depth[v])
        swap(u, v);

    // Query between u and v
    answer += query(
        1,
        1,
        n,
        pos[u],
        pos[v]
    );

    return answer;
}


/*--------------------------------------------------
                  MAIN
--------------------------------------------------*/

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;


    // Read node values
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }


    // Read edges
    for (int i = 1; i < n; i++) {

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    /*----------------------------------------------
              HLD PREPROCESSING
    ----------------------------------------------*/

    depth[1] = 0;

    // First DFS
    dfs(1, 0);


    // base array after HLD
    vector<int> base(n + 1);


    // Second DFS
    decompose(1, 1, base);


    /*----------------------------------------------
              BUILD SEGMENT TREE
    ----------------------------------------------*/

    build(1, 1, n, base);


    /*----------------------------------------------
                    QUERIES
    ----------------------------------------------*/

    int q;
    cin >> q;

    while (q--) {

        int type;
        cin >> type;


        // Path sum query
        if (type == 1) {

            int u, v;
            cin >> u >> v;

            cout << pathQuery(u, v, n) << '\n';
        }


        // Point update
        else if (type == 2) {

            int node, newValue;
            cin >> node >> newValue;

            value[node] = newValue;

            // Update the corresponding position
            update(
                1,
                1,
                n,
                pos[node],
                newValue
            );
        }
    }

    return 0;
}