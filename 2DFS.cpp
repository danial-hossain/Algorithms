#include <bits/stdc++.h>
using namespace std;
vector<int> DFS(vector<int> adj[], int V,vector<int>&ans,vector<int>&visited,int node)
{
    ans.push_back(node);
    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
        {
            DFS(adj, V,ans,visited,adj[node][i]);
        }
    }
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
    vector<int> ans(V);
    vector<int>visited(V,0);
    DFS(adj, V,ans,visited,0);
}