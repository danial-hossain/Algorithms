#include <bits/stdc++.h>
using namespace std;

// Function to return list containing vertices in Topological order
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> InDeg(V, 0); // store the indegree of every node

    for (int i = 0; i < V; i++)
        for (int j = 0; j < adj[i].size(); j++)
            InDeg[adj[i][j]]++;

    // Push all the nodes of zero indegree into queue
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (!InDeg[i])
            q.push(i);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // Neighbour, unki indegree ko decrease karna hai
        for (int j = 0; j < adj[node].size(); j++) {
            InDeg[adj[node][j]]--;
            if (InDeg[adj[node][j]] == 0)
                q.push(adj[node][j]);
        }
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
        // adj[v].push_back(u); // Uncomment for an undirected graph
    }

    vector<int> result = topoSort(V, adj);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
