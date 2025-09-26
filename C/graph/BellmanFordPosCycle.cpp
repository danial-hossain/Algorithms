#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
     const int INF = 1e9;
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);
    dist[S] = 0;
    int x = -1;
    vector<int> cycle;
    int e = edges.size();

    for (int i = 0; i < V - 1; i++)
    {
        bool flag = 0;
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] == INF)
                continue;

            if (dist[u] + wt < dist[v])
            {
                flag = 1;
                dist[v] = dist[u] + wt;
                parent[v] = u;
                x = v;
            }
        }

        if (!flag)
            break;
    }
    bool c = true;

    for (int j = 0; j < e; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] == INF)
            continue;

        if (dist[u] + wt < dist[v])
        {
            break;
        }
        else
        {
            c = false;
            for (int i = 0; i < V; i++)
                x = parent[x]; // Move into the cycle

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
        }
    }
    if (c)
    {
        vector<int> ans;
        ans.push_back(-1);
        return ans;
    }
    return cycle;
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

    cin >> S;

    vector<int> shortestDistances = bellman_ford(V, edges, S);

    if (shortestDistances.size() == 1 && shortestDistances[0] == -1)
    {
        cout << "No Positive Cycle ";
    }
    else
    {
        for (int dist : shortestDistances)
        {
            cout << dist;
        }
    }
    cout << endl;

    return 0;
}
