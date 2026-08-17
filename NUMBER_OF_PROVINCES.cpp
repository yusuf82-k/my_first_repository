#include <bits/stdc++.h>
using namespace std;
int findCircleNum(vector<vector<int>>& isConnected){
     int n=isConnected.size();
     vector<bool> visited(n + 1, false);
      int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        
      
        if (!visited[i])
        {
          cnt++;
            visited[i]=true;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
              
                    for (int j=1;j<=n;j++)
                    {   
                        if(isConnected[i][j]){
                             if(!visited[j]){
                                 visited[j]=true;
                                 q.push(j);
                             }
                        }
                    }
                       // friends[x] = true;
                       
                    }
                
            }
            
        }
           cout<<cnt<<endl;
    }



int main()
{

}
