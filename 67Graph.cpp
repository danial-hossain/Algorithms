#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; // number of nodes and edges
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // adjacency list (vector of vectors)
    vector<vector<pair<int,int>>> adj(n + 1);

    cout << "Enter edges (u v [w]):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        string type;
        cout << "Edge " << i+1 << " type (unweighted/weighted): ";
        cin >> type;

        if (type == "unweighted") {
            cin >> u >> v;
            adj[u].push_back({v, -1000});  // store dummy weight -1000
        } else {
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }
    }

    // Print adjacency list
    cout << "\nAdjacency List:\n";
    for (int u = 1; u <= n; u++) {
        cout << u << " -> ";
        for (auto &p : adj[u]) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << "\n";
    }

    // Calculate out-degree of each node
    map<int,int> outDegree;
    for (int u = 1; u <= n; u++) {
        outDegree[u] = adj[u].size();
    }

    cout << "\nOut-degrees:\n";
    for (auto &p : outDegree) {
        cout << "Node " << p.first << " -> " << p.second << "\n";
    }

    // Example: delete degree of a specific node
    int delNode;
    cout << "\nEnter a node to delete its degree: ";
    cin >> delNode;
    outDegree.erase(delNode);

    cout << "\nUpdated Out-degrees:\n";
    for (auto &p : outDegree) {
        cout << "Node " << p.first << " -> " << p.second << "\n";
    }

    // Finally, print capacity (size) per node
    cout << "\nCapacity per node:\n";
    for (int u = 1; u <= n; u++) {
        cout << "Node " << u << " capacity = " << adj[u].capacity() << "\n";
    }

    return 0;
}
