#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> InDeg(V, 0);

    // Calculate in-degree of each node
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            InDeg[adj[i][j]]++;
        }
    }

    queue<int> q;
    // Push nodes with in-degree 0 into the queue
    for (int i = 0; i < V; i++) {
        if (InDeg[i] == 0)
            q.push(i);
    }

    vector<int> ans;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int j = 0; j < adj[node].size(); j++) {
            InDeg[adj[node][j]]--;
            if (InDeg[adj[node][j]] == 0) {
                q.push(adj[node][j]);
            }
        }
    }

    int count = ans.size();
    return count != V; // If topological sort size is not V, cycle exists
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

    if (isCyclic(V, adj)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}
