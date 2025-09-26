#include <bits/stdc++.h>
using namespace std;


void DFS(int node, vector<int> adj[],vector<bool> &visited, vector<int> &ans,vector<int>&level) {
    visited[node] = 1;
    ans.push_back(node);
    
    for (int j = 0; j < adj[node].size(); j++) {
       
          
        
        if (!visited[adj[node][j]]) {
             level[adj[node][j]]=level[node]+1;
            DFS(adj[node][j], adj, visited, ans,level);
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
    vector<int>level(V,0);
    DFS(0, adj,visited, dfsTraversal,level); // Start DFS from node 0

    for (int node : dfsTraversal) {
        cout << node << " ";
    }
    cout << endl;
    for(int i=0;i<V;i++)
    {
        cout<<"Vartex "<<i<<"level"<<level[i]<<endl;
    }

    return 0;
}
