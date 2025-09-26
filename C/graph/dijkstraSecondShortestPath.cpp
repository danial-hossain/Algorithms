#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<bool> Explored(V, 0);
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    vector<int> parent(V, -1);
    // Select a node which is not explored yet and its dist
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({0, S});

    while (!p.empty())
    {
        int node = p.top().second;
        // first one was distance
        // second one was node
        p.pop();
        if (Explored[node] == 1)
            continue;
        Explored[node] = 1;

        // Relax the edges

        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j][0];
            int weight = adj[node][j][1];
            if (!Explored[neighbour] && (dist[node] + weight < dist[neighbour]))
            {
                dist[neighbour] = dist[node] + weight;
                p.push({dist[neighbour], neighbour});
                parent[neighbour] = node;
            }
        }
    }

    return parent;
}
int main()
{
    int V, E, S;
    cin >> V >> E;

    vector<vector<int>> adj[V]; // Adjacency list for weighted graph

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Uncomment for an undirected graph
    }

    cin >> S; // Source vertex for Dijkstra's algorithm

    vector<int> result = dijkstra(V, adj, S);

       int src;
    cout<<"Enter the Source : ";
    cin>>src;
   
    cout << "Enter the Destination Node : ";
    int destination;
    cin >> destination;

    cout << "Shortest Path from node "<<src<<" to node " << destination << " :" << endl;
    vector<int> path;
    while (destination != -1)
    {
        path.push_back(destination);
        destination = result[destination];
    }
    reverse(path.begin(), path.end());
    for (int node : path)
    {
        cout << node << " ";
    }

    return 0;
}
