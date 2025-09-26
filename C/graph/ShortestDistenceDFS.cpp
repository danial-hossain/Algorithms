#include <bits/stdc++.h>
using namespace std;

// Modified DFS to also record distance from source
void DFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &dist, int depth) {
    visited[node] = 1;
    dist[node] = depth;

    for (int j = 0; j < adj[node].size(); j++) {
        if (!visited[adj[node][j]]) {
            DFS(adj[node][j], adj, visited, dist, depth + 1);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V]; // Adjacency list

    cout << "Enter " << E << " edges (as pairs of vertices):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    // DFS for all-pairs (tree version)
    for (int i = 0; i < V; i++) {
        vector<bool> visited(V, 0);
        vector<int> dist(V, -1); // -1 means unreachable
        DFS(i, adj, visited, dist, 0);

        cout << "DFS (tree) distances from node " << i << ": ";
        for (int d : dist) {
            cout << d << " ";
        }
        cout << endl;
    }

    return 0;
}
