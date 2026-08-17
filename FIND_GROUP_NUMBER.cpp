#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n, m;
    cin >> n >> m;
   
     vector<bool> visited(n + 1, false);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int maxi = 1;

    for (int i = 1; i <= n; i++)
    {
        
        int cnt = 1;
        if (!visited[i])
        {
          
            visited[i]=true;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
              
                    for (auto x : adj[curr])
                    {   if(!visited[x]){
                        cnt++;
                        visited[x]=true;
                         q.push(x);
                    }
                      
                       
                    }
                
            }
            maxi = max(maxi, cnt);
        }
    }
    cout << maxi << endl;
}
}