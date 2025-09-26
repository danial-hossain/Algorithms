#include <bits/stdc++.h>
using namespace std;

bool checkBipartiteComponent(int start, vector<int> &color, vector<int> adj[]) {
    queue<int> q;
    q.push(start);
    color[start] = 0; // Start coloring with 0

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int j = 0; j < adj[node].size(); j++) {
            int neighbor = adj[node][j];

            // If uncolored, assign opposite color
            if (color[neighbor] == -1) {
                color[neighbor] = (color[node] + 1) % 2;
                q.push(neighbor);
            }
            // If already colored and has the same color as the current node, not bipartite
            else if (color[node] == color[neighbor]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[]) {
    vector<int> color(V, -1); // -1 means uncolored

    // Check each component of the graph
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) { // If node is unvisited
            if (!checkBipartiteComponent(i, color, adj)) {
                return false;
            }
        }
    }
    return true;
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

    if (isBipartite(V, adj))
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is not Bipartite" << endl;

    return 0;
}
