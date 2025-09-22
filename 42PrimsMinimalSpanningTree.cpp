#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<pair<int, int>>> &adj)
{
    // Priority queue -> {weight, {node, parent}}
    priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>
        pq;
        //for one pair-->got get --> top.first()
        //for pair inside pair -->top.second.first
        //structure{Weight,Node,Parent}

    vector<bool> IsMST(V, 0);
    vector<int> parent(V, -1);

    int cost = 0;
    pq.push({0, {0, -1}}); // {weight, {node, parent}}

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();

        if (!IsMST[node])
        {
            IsMST[node] = 1;
            cost += wt;
            parent[node] = par;

            for (int j = 0; j < adj[node].size(); j++)
            {
                int adjNode = adj[node][j].first;
                int edgeWt = adj[node][j].second;

                if (!IsMST[adjNode])
                {
                    pq.push({edgeWt, {adjNode, node}});
                }
            }
        }
    }

    return cost;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);

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
