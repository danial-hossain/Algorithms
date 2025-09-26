#include <bits/stdc++.h>
using namespace std;

bool BFS(vector<int> adj[], vector<bool> &visited) {
    queue<pair<int, int>> q;
    visited[0] = 1;
    q.push(make_pair(0, -1)); // node, parent

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int j = 0; j < adj[node].size(); j++) {
            if (parent == adj[node][j])
                continue;
            if (visited[adj[node][j]])
                return 1;

            visited[adj[node][j]] = 1;
            q.push(make_pair(adj[node][j], node));
        }
    }
    return 0;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, 0);

    // Visit all the unvisited nodes
    for (int i = 0; i < V; i++) {
        if (!visited[i] && BFS(adj, visited)) {
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
