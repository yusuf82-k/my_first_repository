class Solution{
    public:
    int maxDept(Node* root){
        if(!root)
        return 0;
        queue<Node*>q;
        q.push(root);
        int depth=0;
        while(!q.empty()){
            int size=q.size();
             depth++;
             for(int i=0;i<size;i++){
                Node* curr=q.front();
                q.pop();
                for(auto ch:curr->children){
                    if(ch)
                    q.push(ch);
                }
             }
        }
        return depth;
    }
};
int maxDepth( Node* root){
    if(!root)
    return 0;
    int maxi=INT_MIN;
    for(auto N:root->children){
        int depth=maxDepth(N);
        maxi=max(maxi,depth);
    }
    return 1+maxi;
}