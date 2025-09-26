#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<bool> Explored(V, 0);
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;

    // Select a node which is not explored yet and its dist

    int count = V;
    while (count--)
    {
        int node = -1, value = INT_MAX;

        for (int i = 0; i < V; i++)
        {
            if (!Explored[i] && value > dist[i])
            {
                node = i;
                value = dist[i];
            }
        }

        Explored[node] = 1;

        // Relax the edges6 

        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j][0];
            int weight = adj[node][j][1];
            if (!Explored[neighbour] && (dist[node] + weight < dist[neighbour]))
                dist[neighbour] = dist[node] + weight;
        }
    }

    return dist;
}
int main() {
    int V, E, S;
    cin >> V >> E;

    vector<vector<int>> adj[V]; // Adjacency list for weighted graph

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Uncomment for an undirected graph
    }

    cin >> S; // Source vertex for Dijkstra's algorithm

    vector<int> shortestDistances = dijkstra(V, adj, S);

    for (int dist : shortestDistances) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}
