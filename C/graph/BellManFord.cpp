#include <bits/stdc++.h>
using namespace std;


vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    int e = edges.size();

    for (int i = 0; i < V - 1; i++)
    {
        bool flag = 0;
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] == 1e8)
                continue;

            if (dist[u] + wt < dist[v])
            {
                flag = 1;
                dist[v] = dist[u] + wt;
            }
        }

        if (!flag)
            break;
    }

    // 🔴 Final check for negative cycle
    for (int j = 0; j < e; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] == 1e8)
            continue;

        if (dist[u] + wt < dist[v])
        {
            // Cycle detected
            vector<int> ans;
            ans.push_back(-1);
            return ans;
        }
    }

    return dist;
}


int main()
{
    int V, E, S;
    cin >> V >> E;

    vector<vector<int>> edges; // Edge list for Bellman-Ford

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        // edges.push_back({v, u, w}); // For undirected graph (optional)
    }

    cin >> S; // Source vertex

    vector<int> shortestDistances = bellman_ford(V, edges, S);

    // Handle negative cycle case
    if (shortestDistances.size() == 1 && shortestDistances[0] == -1)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    for (int dist : shortestDistances)
    {
        if (dist == 1e8)
            cout << "INF ";
        else
            cout << dist << " ";
    }
    cout << endl;

    return 0;
}
