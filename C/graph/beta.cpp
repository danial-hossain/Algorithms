#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    const int INF = 1e9;
    vector<int> dist(V, INF);
    vector<int> dist2(V, INF);
    dist[S] = 0;
    dist2[S] = INF;  // second shortest dist to source is INF, no second path yet

    vector<int> parent(V, -1);
    // No Explored array because nodes must be revisited for 2nd shortest

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({0, S});

    while (!p.empty())
    {
        int node = p.top().second;
        int d = p.top().first;
        p.pop();

        // Ignore if this distance is worse than current second shortest distance
        if (d > dist2[node]) continue;

        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j][0];
            int weight = adj[node][j][1];
            int nd = d + weight;

            if (nd < dist[neighbour])
            {
                dist2[neighbour] = dist[neighbour];
                dist[neighbour] = nd;
                parent[neighbour] = node;
                p.push({nd, neighbour});
            }
            else if (nd > dist[neighbour] && nd < dist2[neighbour])
            {
                dist2[neighbour] = nd;
                p.push({nd, neighbour});
            }
        }
    }

    return parent; // Still returning parent array for shortest path
}

int main()
{
    int V, E, S;
    cin >> V >> E;

    vector<vector<int>> adj[V]; // Adjacency list for weighted graph

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Uncomment for undirected graph
    }

    cin >> S; // Source vertex for Dijkstra's algorithm

    vector<int> result = dijkstra(V, adj, S);

    int src;
    cout << "Enter the Source : ";
    cin >> src;

    cout << "Enter the Destination Node : ";
    int destination;
    cin >> destination;

    cout << "Shortest Path from node " << src << " to node " << destination << " :" << endl;
    vector<int> path;
    while (destination != -1)
    {
        path.push_back(destination);
        destination = result[destination];
    }
    reverse(path.begin(), path.end());
    for (int node : path)
    {
        cout << node << " ";
    }

    return 0;
}
