#include <bits/stdc++.h>
using namespace std;

vector<int> BFSGraph(int V,int src, vector<int> adj[],vector<int>&level) {
    queue<int> q;
    vector<bool> visited(V, 0);
    
    q.push(src);
    vector<int> ans;
     visited[src] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for (int j = 0; j < adj[node].size(); j++) {
            if (!visited[adj[node][j]]) {
                  level[adj[node][j]]=level[node]+1;
                visited[adj[node][j]] = 1;
                q.push(adj[node][j]);
            }
        }
    }
    return ans;
}

int main() {
    int V, E;
    cin >> V >> E;
   
    vector<int> adj[V]; 
     vector<int>level(V,0);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    int N;
  cin>>N;

    vector<int> bfsTraversal = BFSGraph(V,N,adj,level);

    for (int node : bfsTraversal) {
        cout << node << " ";
    }
    cout << endl;
   for(int i=0;i<V;i++)
   {
   cout<<"Vertices "<<i<<" Level : "<<level[i]<<endl;
   }
    return 0;
}
