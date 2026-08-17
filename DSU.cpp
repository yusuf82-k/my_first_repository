#include <bits/stdc++.h>
using ll = long long;
using namespace std;
struct edge{
    int u,v,w;

};
vector<int>parent,size;
int find(int v){
    if(v=parent[v]){
        return v;
    }
    return parent[v]=find(parent[v]);

}
void union_set(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        if(size[a]<size[b])
        {
            swap(a,b);
        }
    }
    parent[b]=a;
    size[a]+=size[b];

}

int main() {
    int t;
    cin >> t;
    while (t--) {
    int n=4;
    vector<edge>graph={
        {1,2,1},
        {1,3,4},
        {2,3,2},
        {2,4,5},
        {2,4,3}
    };
    
    }
    return 0;
}


int main(){

    int n = 4; // vertices
    vector<Edge> edges = {
        {1,2,1},
        {1,3,4},
        {2,3,2},
        {2,4,5},
        {3,4,3}
    };

    parent.resize(n+1);
    sz.resize(n+1,1);

    for(int i=1;i<=n;i++)
        parent[i]=i;

    // sort edges by weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b){
            return a.w < b.w;
         });

    int mst_weight = 0;

    for(auto e : edges){
        if(find_set(e.u) != find_set(e.v)){
            union_set(e.u, e.v);
            mst_weight += e.w;
            cout << e.u << " - " << e.v << endl;
        }
    }

    cout << "MST Weight = " << mst_weight;
}