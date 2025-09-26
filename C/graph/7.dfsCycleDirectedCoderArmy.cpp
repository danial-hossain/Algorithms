#include <bits/stdc++.h>
using namespace std;

bool DetectCycle(int node, vector<int> adj[], vector<bool> &path, vector<bool> &visited) {
    visited[node] = 1;
    path[node] = 1;

    for (int j = 0; j < adj[node].size(); j++) {
        // If neighbor node is already present in path, cycle is present
        if (path[adj[node][j]])
            return 1;

        // If neighbor is already visited, skip it
        if (visited[adj[node][j]])
            continue;

        if (DetectCycle(adj[node][j], adj, path, visited))
            return 1;
    }

    path[node] = 0;
    return 0;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> path(V, 0);
    vector<bool> visited(V, 0);

    for (int i = 0; i < V; i++) {
        if (!visited[i] && DetectCycle(i, adj, path, visited))
            return 1;
    }
    return 0;
}
int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V]; // Adjacency list

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
       // adj[v].push_back(u); // Uncomment for an undirected graph
    }

    if (isCyclic(V, adj)) {
        cout << "Graph contains a cycle" << endl;
    } 
      

    return 0;
}
