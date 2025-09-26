#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

vector<int> dijkstra(int V, vector<int> adj[], int S, vector<int>& cost) {
    vector<bool> Explored(V, 0);
    vector<int> dist(V, INT_MAX);
    dist[S] = cost[S];

    int count = V;
    while (count--) {
        int node = -1, value = INT_MAX;

        for (int i = 0; i < V; i++) {
            if (!Explored[i] && value > dist[i]) {
                node = i;
                value = dist[i];
            }
        }

        if (node == -1) break;
        Explored[node] = 1;

        for (int j = 0; j < adj[node].size(); j++) {
            int neighbour = adj[node][j];
            if (!Explored[neighbour]) {
                int newCost = gcd(dist[node], cost[neighbour]);
                if (newCost < dist[neighbour])
                    dist[neighbour] = newCost;
            }
        }
    }

    return dist;
}

int main() {
    int V, E, S;
    cin >> V >> E;

    vector<int> cost(V);
    for (int i = 0; i < V; i++) {
        cin >> cost[i];
    }

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v ;
        cin >> u >> v  ;
        adj[u].push_back(v);
        // adj[v].push_back(u); // Uncomment if graph is undirected
    }

    cin >> S;

    vector<int> shortestDistances = dijkstra(V, adj, S, cost);

    for (int dist : shortestDistances) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}
