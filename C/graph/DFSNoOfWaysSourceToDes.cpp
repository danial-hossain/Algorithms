#include <bits/stdc++.h>
using namespace std;

int countPathsDFS(int node, int dest, vector<int> adj[], vector<bool> &visited) {
    if (node == dest) return 1;

    visited[node] = true;
    int totalPaths = 0;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            totalPaths += countPathsDFS(neighbor, dest, adj, visited);
        }
    }

    visited[node] = false; // Backtrack
    return totalPaths;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    int src, dest;
    cin >> src >> dest;

    vector<bool> visited(V, false);
    int numPaths = countPathsDFS(src, dest, adj, visited);

    cout << "Number of different paths from " << src << " to " << dest << ": " << numPaths << endl;

    return 0;
}
