#include <bits/stdc++.h>
using namespace std;
vector<int> BFS(vector<int> adj[], int V)
{

    vector<bool> visited(V, 0);
    vector<int> ans;
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();

        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
            {
                visited[adj[node][i]] = 1;
                q.push(adj[node][i]);
            }
        }
    }
    return ans;
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
    BFS(adj, V);
}