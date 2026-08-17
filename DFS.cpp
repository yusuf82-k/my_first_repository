#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 10;
vector<int> adj[MAX];
bool visited[MAX];
void iterativeDFS(int startNode)
{
    stack<int>s;
    s.push(startNode);
    while(!s.empty()){
        int curr=s.top();
        s.pop();
        if(!visited[curr]){
            cout<<curr<<" ";
            visited[curr]=true;
        }
       for(int i=0;i<adj[curr].size();i++){
              int neighbour=adj[curr][i];
              if(!visited[neighbour]){
                s.push(neighbour);
              }
       }
    }
}


int main() {
    // Adding edges (Directed Graph)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(4);
    adj[3].push_back(0); // Cycle back to 0
    adj[4].push_back(5);
    adj[5].push_back(6);
    // Node 7 has no edges (Disconnected)

    cout << "Iterative DFS Traversal:\n";

    // Loop through all possible nodes (0 to 7) 
    // to handle disconnected components
    for (int i = 0; i <= 7; i++) {
        if (!visited[i]) {
            cout << "[Starting new component at " << i << "]: ";
            iterativeDFS(i);
            cout << endl;
        }
    }

    return 0;
}