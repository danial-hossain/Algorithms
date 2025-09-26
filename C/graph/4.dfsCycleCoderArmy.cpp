#include <bits/stdc++.h>
using namespace std;

bool CycleDetect(int node, int parent, vector<int> adj[], vector<bool> &visited) {
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++) {
        if (parent == adj[node][j])
            continue;

        if (visited[adj[node][j]] == 1)
            return 1;

        if (CycleDetect(adj[node][j], node, adj, visited))
            return 1;
    }

    return 0;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, 0);

    // Visit all the unvisited nodes
    for (int i = 0; i < V; i++) {
        if (!visited[i] && CycleDetect(i, -1, adj, visited)) {
            return 1;
        }
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
        adj[v].push_back(u); // Uncomment for an undirected graph
    }

    if (isCycle(V, adj))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}
