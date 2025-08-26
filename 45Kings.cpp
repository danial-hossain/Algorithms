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

    // Min-heap: {wt,{u,v}}
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>
        pq;

    // Push all edges into priority queue
    vector<pair<int, pair<int, int>>> allEdges;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int v = adj[i][j][0];
            int w = adj[i][j][1];
            if (i < v) // avoid duplicate undirected edges
            {
                pq.push({w, {i, v}});
                allEdges.push_back({w, {i, v}});
            }
        }
    }

    int cost = 0, edges = 0;
    vector<pair<int, pair<int, int>>> mstEdges;
    vector<pair<int, pair<int, int>>> removed;

    // Kruskal’s loop
    while (!pq.empty() && edges < V - 1)
    {
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        if (FindParent(u, parent) != FindParent(v, parent))
        {
            cost += wt;
            mstEdges.push_back({wt, {u, v}});
            UnionByRank(u, v, parent, rank);
            edges++;
        }
        else
        {
            removed.push_back({wt, {u, v}});
        }
    }

    // Any leftover edges in pq are also "removed"
    while (!pq.empty())
    {
        removed.push_back(pq.top());
        pq.pop();
    }

    // Output
    cout << "Minimum Cost = " << cost << endl;

    cout << "Roads to KEEP (MST):\n";
    for (auto &e : mstEdges)
        cout << e.second.first << " - " << e.second.second
             << " (cost " << e.first << ")\n";

    cout << "Roads to REMOVE:\n";
    for (auto &e : removed)
        cout << e.second.first << " - " << e.second.second
             << " (cost " << e.first << ")\n";

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

    spanningTree(V, adj);
    return 0;
}
