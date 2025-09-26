#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<bool> Explored(V, 0);
    vector<int> dist(V, INT_MAX);
    vector<int> ways(V, 0); // Number of shortest paths

    dist[S] = 0;
    ways[S] = 1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({0, S});

    while (!p.empty())
    {
        int node = p.top().second;
        p.pop();

        if (Explored[node])
            continue;
        Explored[node] = 1;

        // Explicit j-loop instead of auto
        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j][0];
            int weight = adj[node][j][1];

            if (dist[node] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[node] + weight;
                ways[neighbour] = ways[node];
                p.push({dist[neighbour], neighbour});
            }
            else if (dist[node] + weight == dist[neighbour])
            {
                ways[neighbour] += ways[node];
            }
        }
    }

    return ways;
}

int main()
{
    int V, E, S;
    cin >> V >> E;

    vector<vector<int>> adj[V]; // Adjacency list

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }

    cin >> S;

    vector<int> pathCounts = dijkstra(V, adj, S);

    for (int count : pathCounts)
    {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
