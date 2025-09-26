#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ans) {
    visited[node] = 1;
    ans.push_back(node);

    for (int j = 0; j < adj[node].size(); j++) {
        if (!visited[adj[node][j]]) {
            DFS(adj[node][j], adj, visited, ans);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, 0);
    vector<int> ans;

    DFS(0, adj, visited, ans); // Start DFS from node 0

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

    vector<int> result = dfsOfGraph(V, adj);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
