#include <bits/stdc++.h>
using namespace std;
bool BFSCycleUndirected(vector<pair<int, int>> adj[], int V)
{

    vector<bool> visited(V, 0);
    queue<pair<int, int>> q;
    q.push(make_pair(0, -1));
    visited[0] = 1;
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (adj[node][i].first == parent)
            {
                continue;
            }
            if (visited[adj[node][i].first])
            {
                return true;
            }
            if (!visited[adj[node][i].first])
            {
                q.push(make_pair(adj[node][i].first, node));
                visited[adj[node][i].first] = 1;
            }
        }
    }
    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(make_pair(v,u));
        adj[v].push_back(make_pair(u,v));
    }
    bool flag = BFSCycleUndirected(adj, V);
    cout<<flag;
}