#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, INT_MAX), parent(V, -1);
    dist[S] = 0;
    int x = -1;
    int e = edges.size();

    for (int i = 0; i < V; i++) // V iterations for cycle detection
    {
        x = -1;
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] == INT_MAX) continue;

            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1)
        return dist; // No negative cycle

    // Negative cycle detected: reconstruct path
    for (int i = 0; i < V; i++)
        x = parent[x]; // Move into the cycle

    vector<int> cycle;
    int curr = x;
    cycle.push_back(curr);
    curr = parent[curr];

    while (curr != x)
    {
        cycle.push_back(curr);
        curr = parent[curr];
    }
    cycle.push_back(x);
    reverse(cycle.begin(), cycle.end());

    cout << "Negative Cycle Detected: ";
    for (int node : cycle)
        cout << node << " ";
    cout << endl;

    return { -1 };
}

int main()
{
    int V, E, S;
    cin >> V >> E;

    vector<vector<int>> edges;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    cin >> S; // Source vertex

    vector<int> shortestDistances = bellman_ford(V, edges, S);

    // If a negative cycle was found, stop
    if (shortestDistances.size() == 1 && shortestDistances[0] == -1)
    {
        return 0;
    }

    // Print distances
    for (int dist : shortestDistances)
    {
        if (dist == INT_MAX)
            cout << "INF ";
        else
            cout << dist << " ";
    }
    cout << endl;

    return 0;
}
