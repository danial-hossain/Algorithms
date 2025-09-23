#include <bits/stdc++.h>
using namespace std;//
void BFSShortestUndirected(vector<int> adj[], int V, vector<int> &distance, vector<int> &parent)
{
    vector<bool> visited(V, 0);
    queue<int> q;
    visited[0] = 1;
    q.push(0);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
            {
                visited[adj[node][i]] = 1;
                distance[adj[node][i]] = distance[node] + 1;
                parent[adj[node][i]] = node;
                q.push(adj[node][i]);
            }
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
    vector<int> distance(V, 0);
    vector<int> parent(V, -1);
    BFSShortestUndirected(adj, V, distance, parent);
    for (auto i : distance)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Enter Destination : ";
    int des;
    cin >> des;
    vector<int> path;
 
    while (parent[des] != -1)
    {
        path.push_back(des);
        des = parent[des];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    for (auto i : path)
    {
        cout << i<< " ";
    }
}
