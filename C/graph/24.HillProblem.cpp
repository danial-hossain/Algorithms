#include <bits/stdc++.h>
using namespace std;

vector<double> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<bool> Explored(V, 0);
    vector<double> dist(V, 0.0); // Probability
    dist[S] = 1.0;

    int count = V;
    while (count--)
    {
        int node = -1;
        double value = -1.0;

        for (int i = 0; i < V; i++)
        {
            if (!Explored[i] && value < dist[i])
            {
                node = i;
                value = dist[i];
            }
        }

        if (node == -1) break;
        Explored[node] = 1;

        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j][0];
            double weight = (double)adj[node][j][1]; // Cast to double

            if (!Explored[neighbour] && dist[node] * weight > dist[neighbour])
            {
                dist[neighbour] = dist[node] * weight;
            }
        }
    }

    return dist;
}

int main() {
    int V, E, S;
    cin >> V >> E;

    vector<vector<int>> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        double w;
        cin >> u >> v >> w; // Input as double for probabilities
        adj[u].push_back({v, (int)(w * 1000000)}); // Store as int to preserve structure
        adj[v].push_back({u, (int)(w * 1000000)}); // Optional: for undirected
    }

    cin >> S;

    vector<double> prob = dijkstra(V, adj, S);

    for (double p : prob) {
        cout << fixed << setprecision(6) << p << " ";
    }
    cout << endl;

    return 0;
}
