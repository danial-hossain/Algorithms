
#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<int> adj[], vector<int> &parent, int N, int src)
{

    vector<int> dist(N, 0);
    vector<bool> visited(N, 0);
    queue<int> q;

    q.push(src);
    dist[src] = 0;
    visited[src] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int j = 0; j < adj[node].size(); j++)
        {
            if (visited[adj[node][j]])
                continue;

            visited[adj[node][j]] = 1;
            q.push(adj[node][j]);
            dist[adj[node][j]] = dist[node] + 1;
            parent[adj[node][j]] = node;
        }
    }

    return dist;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V]; // Adjacency list
    vector<int> parent(V, -1);
    cout << "Enter " << E << " edges (as pairs of vertices):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    for (int i = 0; i < V; i++)
    {
        vector<int> parent(V, -1); // reset for each source
        vector<int> distance = shortestPath(adj, parent, V, i);

        cout << "\nShortest paths from node " << i << ":\n";
        cout << "Node\tDistance\tParent\n";
        for (int j = 0; j < V; j++)
        {
            cout << j << "\t" << distance[j] << "\t\t" << parent[j] << "\n";
        }
    }

    return 0;
}
