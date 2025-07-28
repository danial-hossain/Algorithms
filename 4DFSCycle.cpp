#include <bits/stdc++.h>
using namespace std;
bool DFSCycleUndirected(vector<int> adj[], int V, vector<bool> &visited, int src, int parent)
{

    for (int i = 0; i < adj[src].size(); i++)
    {
        if (adj[src][i] == parent)
        {
            continue;
        }
        if (visited[adj[src][i]])
        {
            return true;
        }
        if (!visited[adj[src][i]])
        {
            visited[adj[src][i]] = 1;
            DFSCycleUndirected(adj, V, visited,adj[src][i], src);
        }
    }
    return false;
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(V, 0);
    bool flag = DFSCycleUndirected(adj, V, visited, 0, -1);
    cout << flag;
}