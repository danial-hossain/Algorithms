#include <bits/stdc++.h>
using namespace std;

bool BFSGraph(int i,int V, vector<int> adj[], vector<bool> &visited)
{
    queue<int> q;

    q.push(i);
    visited[i] = 1;

    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!visited[adj[node][j]])
            {
                visited[adj[node][j]] = 1;
                q.push(adj[node][j]);
            }
        }
    }
    return true;
}
int isConnected(int V, vector<int> adj[])
{
    int count = 0;
    vector<bool> visited(V, 0);

    // Visit all the unvisited nodes
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (BFSGraph(i,V, adj, visited))
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V]; // Adjacency list

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Uncomment for an undirected graph
    }

    int count = isConnected(V, adj);

    cout << count;

    return 0;
}
