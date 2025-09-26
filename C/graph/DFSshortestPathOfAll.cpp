#include <bits/stdc++.h>
using namespace std;

// Modified DFS to also record distance and parent
void DFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &dist, vector<int> &parent, int depth) {
    visited[node] = true;
    dist[node] = depth;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            parent[neighbor] = node; // Set parent before recursive call
            DFS(neighbor, adj, visited, dist, parent, depth + 1);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter " << E << " edges (as pairs of vertices):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < V; i++) {
        vector<bool> visited(V, false);
        vector<int> dist(V, -1);
        vector<int> parent(V, -1);
        DFS(i, adj, visited, dist, parent, 0);

        cout << "\nDFS (tree) traversal from node " << i << ":\n";
        cout << "Node\tDistance\tParent\n";
        for (int j = 0; j < V; j++) {
            cout << j << "\t" << dist[j] << "\t\t" << parent[j] << "\n";
        }
    }

    return 0;
}
