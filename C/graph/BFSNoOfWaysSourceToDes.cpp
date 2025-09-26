#include <bits/stdc++.h>
using namespace std;

int countWaysBFS(int V, vector<int> adj[], int src, int dest) {
    vector<int> dist(V, -1);     // Distance from source
    vector<int> ways(V, 0);      // Ways to reach each node
    queue<int> q;

    dist[src] = 0;
    ways[src] = 1;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                // First time visiting neighbor
                dist[neighbor] = dist[node] + 1;
                ways[neighbor] = ways[node];
                q.push(neighbor);
            } else if (dist[neighbor] == dist[node] + 1) {
                // Found another shortest path
                ways[neighbor] += ways[node];
            }
        }
    }

    return ways[dest];
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

    int src, dest;
    cin >> src >> dest;

    int numWays = countWaysBFS(V, adj, src, dest);
    cout << "Number of shortest paths from " << src << " to " << dest << ": " << numWays << endl;

    return 0;
}
