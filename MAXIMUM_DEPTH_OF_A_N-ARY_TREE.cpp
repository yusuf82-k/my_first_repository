#include<bits/stdc++.h>
#include<vector>
#include<queue>
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
int max_depth(Node* root){
    queue<Node*>q;
    unordered_map<Node*,int>depth;
    int maxi=INT_MIN;
    depth[root]=0;
    q.push(root);
    while(!q.empty()){
         Node* curr=q.front();
         q.pop();
         for(Node* ch:curr->children){
            if(ch){
                q.push(ch);
                depth[ch]=depth[curr]+1;
                maxi=max(maxi,depth[ch]);
            }
         }
    }
    return maxi;

}