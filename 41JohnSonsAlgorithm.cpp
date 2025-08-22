#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void BellmanFord(vector<vector<int>> adj, int V, int E, vector<int> &distance, bool &flag) {
    distance[V-1] = 0;  //V-> 6 ekhante,V-1 -> 6-1 =5 as source;
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = adj[j][0];
            int v = adj[j][1];
            int w = adj[j][2];
            if (distance[u] != INF && distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
            }
        }
    }

    flag = false;
    for (int j = 0; j < E; j++) {
        int u = adj[j][0];
        int v = adj[j][1];
        int w = adj[j][2];
        if (distance[u] != INF && distance[v] > distance[u] + w) {
            flag = true; 
        }
    }
}


void Dijkstra(vector<pair<int,int>> adj[], int V, int src, vector<int> &distance) {
    vector<int> visited(V, 0);
    vector<int> parent(V, -1);

    distance.assign(V, INF);
    distance[src] = 0;

    int count = V;
    while (count > 0) {
        int node = -1;
        int dist = INT_MAX;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && distance[i] < dist) {
                dist = distance[i];
                node = i;
            }
        }

        if (node == -1) break;
        visited[node] = 1;

        for (int j = 0; j < adj[node].size(); j++) {
            int neighbour = adj[node][j].first;
            int weight = adj[node][j].second;
            if (distance[neighbour] > distance[node] + weight) {
                distance[neighbour] = distance[node] + weight;
                parent[neighbour] = node;
            }
        }
        count--;
    }
}


void Johnson(int V, int E, vector<vector<int>> &edges) {
   
    for (int i = 0; i < V; i++) {
        edges.push_back({V, i, 0});// V=5,i=1 to 4,weight 0.
    }

    
    vector<int> h(V+1, INF);
    bool flag;
    BellmanFord(edges, V+1, E+V, h, flag);

    if (flag) {
        cout << "Graph has a negative cycle!\n";
        return;
    }


    vector<pair<int,int>> adj[V]; //adjency list for having weights
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if (u == V) continue; // u=5,V already 5,new dhora vergices ,edge gula skip
        int w_new = w + h[u] - h[v];
        adj[u].push_back(make_pair(v, w_new));
    }


    vector<vector<int>> distAll(V, vector<int>(V, INF));
    for (int u = 0; u < V; u++) {
        vector<int> dist;
        Dijkstra(adj, V, u, dist);//u -->source of dijkstra,all vertices
        for (int v = 0; v < V; v++) {
            if (dist[v] < INF) {
                distAll[u][v] = dist[v] + h[v] - h[u];
            }
        }
    }

   
    cout << "All-pairs shortest paths:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (distAll[i][j] == INF) cout << "INF ";
            else cout << distAll[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    Johnson(V, E, edges);
}
