#include <bits/stdc++.h>
using namespace std;

int FindParent(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;

    return parent[u] = FindParent(parent[u], parent);
}

void UnionByRank(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int pu = FindParent(u, parent);
    int pv = FindParent(v, parent);

    if (rank[pu] < rank[pv])
    {
        parent[pu] = pv;
    }
    else if (rank[pu] > rank[pv])
    {
        parent[pv] = pu;
    }
    else
    {
        parent[pv] = pu;
        rank[pu]++;
    }
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Priority queue: {wt,{u,v}}
    vector<pair<int, pair<int, int>>> temp;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq(temp.begin(), temp.end());

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            pq.push({adj[i][j][1], {i, adj[i][j][0]}});
        }
    }

    int cost = 0;
    int edges = 0;

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        // check if they are in different set
        if (FindParent(u, parent) != FindParent(v, parent))
        {
            cost += wt;
            UnionByRank(u, v, parent, rank);
            edges++;
        }
        if (edges == V - 1)
        {
            break; // V-1 edges should be part of Kruskal's Algo
        }
    }

    return cost;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << spanningTree(V, adj) << endl;
    return 0;
}
