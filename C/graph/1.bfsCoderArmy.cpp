#include <bits/stdc++.h>
using namespace std;

vector<int> BFSGraph(int V, vector<int> adj[]) {
    queue<int> q;
    vector<bool> visited(V, 0);
    
    q.push(0);
    visited[0] = 1;
    
    vector<int> ans;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for (int j = 0; j < adj[node].size(); j++) {
            if (!visited[adj[node][j]]) {
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

    vector<int> adj[V]; // Adjacency list

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Uncomment for an undirected graph
    }

    vector<int> bfsTraversal = BFSGraph(V, adj);

    for (int node : bfsTraversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
