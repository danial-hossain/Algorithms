#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;

    for (int j = 0; j < adj[node].size(); j++) {
        if (!visited[adj[node][j]]) {
            DFS(adj[node][j], adj, visited);
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
        adj[v].push_back(u); // Undirected graph
    }

    vector<bool> visited(V, false);
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, adj, visited);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
