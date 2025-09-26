#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int N, int M, int src, int dest) {
    // Write your code here

    vector<int> adj[N];

    for(int i = 0; i < M; i++)
    {
        adj[edges[i].first - 1].push_back(edges[i].second - 1);
        adj[edges[i].second - 1].push_back(edges[i].first - 1);
    }

    src--;
    dest--;

    // array dist
    vector<int> dist(N, -1);
    vector<bool> visited(N, 0);

    queue<int> q;
    q.push(src);
    dist[src] = 0;
    visited[src] = 1;
    vector<int> parent(N, -1);

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
            parent[adj[node][j]] = node;
        }
    }

    vector<int> path;
    while(dest != -1)
    {
        path.push_back(dest + 1);
        dest = parent[dest];
        //6=parent[8]
        //4=parent[6]
        //-1=parent[4]
    }

    reverse(path.begin(), path.end());

    return path;
}
int main() {
    int N = 8; // number of nodes
    int M = 9; // number of edges

    vector<pair<int, int>> edges = {
        {1, 2}, {1, 4}, {2, 3}, {4, 5}, {5, 6},
        {3, 7}, {6, 7}, {7, 8}, {7, 9}
    };

    int src = 1, dest = 9;

    vector<int> path = shortestPath(edges, 9, edges.size(), src, dest);

    cout << "Shortest path from " << src << " to " << dest << ": ";
    for(int node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}