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
        parent[pu] = pv;
    else if (rank[pu] > rank[pv])
        parent[pv] = pu;
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

    // Min-heap {wt,{u,v}}
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>
        pq;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int v = adj[i][j][0];
            int w = adj[i][j][1];
            if (i < v) // avoid duplicate edges
                pq.push({w, {i, v}});
        }
    }

    int cost = 0, edges = 0;

    cout << "Edges in MST:\n";

    while (!pq.empty() && edges < V - 1)
    {
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        if (FindParent(u, parent) != FindParent(v, parent))
        {
            cost += wt;
            UnionByRank(u, v, parent, rank);
            edges++;

            // print this edge
            cout << u << " - " << v << " (cost " << wt << ")\n";
        }
    }

    cout << "Minimum Cost = " << cost << endl;
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
/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7





*/