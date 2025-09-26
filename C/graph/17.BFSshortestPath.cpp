#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src){
    // adjacency list create karna
    vector<int> adj[N];

    for(int i = 0; i < M; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

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

        // Look at all the neighbours
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
    vector<vector<int>> edges = {
        {0,1}, {0,3}, {1,2}, {3,4}, {4,5}, {2,6}, {5,6}, {6,7}, {6,8}, {7,8}
    };
    int N = 9; // Number of nodes
    int M = edges.size(); // Number of edges
    int src = 0;

    vector<int> result = shortestPath(edges, N, M, src);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}