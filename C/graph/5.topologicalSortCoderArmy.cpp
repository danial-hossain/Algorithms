#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited, stack<int> &s) {
    visited[node] = 1;

    // Look at its neighbors one by one
    for (int j = 0; j < adj[node].size(); j++) {
        if (!visited[adj[node][j]])
            DFS(adj[node][j], adj, visited, s);
    }

    s.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool> visited(V, 0);
    stack<int> s;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            DFS(i, adj, visited, s);
    }

    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
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
    }

    vector<int> result = topoSort(V, adj);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
