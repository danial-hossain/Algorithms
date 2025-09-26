#include <bits/stdc++.h>
using namespace std;
void leaf(int node,vector<int>adj[])
{
   if(adj[node].size()==1)
   {
    cout<<node<<" ";
   }
}
void DFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ans) {
    visited[node] = 1;
    ans.push_back(node);

    for (int j = 0; j < adj[node].size(); j++) {
        if(!visited[adj[node][j]])
        {
              leaf(adj[node][j],adj);
        }
        if (!visited[adj[node][j]]) {
            DFS(adj[node][j], adj, visited, ans);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V]; // Adjacency list

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Uncomment for an undirected graph
    }

    vector<bool> visited(V, 0);
    vector<int> dfsTraversal;

    DFS(0, adj, visited, dfsTraversal); // Start DFS from node 0

    for (int node : dfsTraversal) {
    //    cout << node << " ";
    }
    cout << endl;

    return 0;
}
