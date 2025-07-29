#include <bits/stdc++.h>
using namespace std;
void DFS(vector<int> adj[], int V, vector<int> &visited, vector<int> &length, int src)
{
    visited[src] = 1;

    for (int i = 0; i < adj[src].size(); i++)
    {

        {
            length[adj[src][i]] = max(length[adj[src][i]], length[src] + 1);
            DFS(adj, V, visited, length, adj[src][i]);
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
    }
    vector<int> visited(V, 0);
    vector<int> length(V, 0);

    DFS(adj, V, visited, length, 0);

    for (auto i : length)
    {
        cout << i << " ";
    }
    cout<<endl;
    cout<<"Enter the vertices ";
    int u,v;
    cin >>u >>v;
    cout<<length[v];
}