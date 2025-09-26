#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int V, int m, vector<vector<int>> &edges)
{
    // adjacency list create
    // neighbour, weight
    vector<pair<int, int>> adj[V + 1];
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    vector<bool> Explored(V + 1, 0);
    vector<int> dist(V + 1, INT_MAX);
    vector<int> parent(V + 1, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({0, 1});
    dist[1] = 0;

    while (!p.empty())
    {
        int node = p.top().second;
        p.pop();
        if (Explored[node])
            continue;

        Explored[node] = 1;

        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j].first;
            int weight = adj[node][j].second;
            if (!Explored[neighbour] && dist[node] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[node] + weight;
                p.push({dist[neighbour], neighbour});
                parent[neighbour] = node; // line added
            }
        }
    }

    vector<int> path;

    // I can't reach my destination
    if (parent[V] == -1)
    {
        path.push_back(-1);
        return path;
    }

    // I will reach my destination
    int dest = V;
    while (dest != -1)
    {
        path.push_back(dest);
        dest = parent[dest];
    }

    path.push_back(dist[V]);
    reverse(path.begin(), path.end());

    return path;
}

int main()
{
    int V, m;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> m;

    vector<vector<int>> edges;
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<int> result = shortestPath(V, m, edges);

    if (result.size() == 1 && result[0] == -1)
    {
        cout << "No path found from 1 to " << V << endl;
    }
    else
    {
        cout << "Shortest path from 1 to " << V << " is: ";
        for (int i = 0; i < result.size() - 1; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\nTotal cost: " << result.back() << endl;
    }

    return 0;
}