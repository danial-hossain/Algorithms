
#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<int>adj[], int N, int src){



    vector<int> dist(N, INT_MAX);
    vector<bool> visited(N, 0);
    queue<int> q;
    
    q.push(src);
    dist[src] = 0;
    visited[src] = 1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();


        for(int j = 0; j < adj[node].size(); j++)
        {
            if(visited[adj[node][j]])
                continue;

            visited[adj[node][j]] = 1;
            q.push(adj[node][j]);
            dist[adj[node][j]] = dist[node] + 1;
        }
    }

    return dist;
}
 
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V]; // Adjacency list

    cout << "Enter " << E << " edges (as pairs of vertices):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    for(int i = 0; i < V; i++) {
        vector<int> distance = shortestPath(adj, V, i);
        cout << "Shortest distances from node " << i << ": ";
        for(int j = 0; j < distance.size(); j++) {
            cout << distance[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
