#include <bits/stdc++.h>
using namespace std;
void FloyedWarshall(vector<vector<int>>&adj, int V, vector<vector<int>> &path)
{
    for (int k = 0; k < V; k++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int i = 0; i < V; i++)
            {
                if (adj[i][k] == INT_MAX || adj[k][j] == INT_MAX)
                    continue;

                if (adj[i][j] > adj[i][k] + adj[k][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    path[i][j] = path[i][k] * path[k][j];
                }
                else if (adj[i][j] == adj[i][k] + adj[k][j] && i != j)
                {
                    path[i][j] += path[i][k] * path[k][j];
                }
            }
        }
    }
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V, vector<int>(V, INT_MAX));
    vector<vector<int>> path(V, vector<int>(V, 0));
    for (int i = 0; i < V; i++)
    {

        {
            adj[i][i] = 0;
        }
    }
    for (int i = 0; i < E; i++)

    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        path[u][v] += 1;
    }
    FloyedWarshall(adj, V, path);
    for (int i = 0; i < V; i++)
    {

        if (adj[i][i] <0)
        {
            cout << "Has a negative cycle ";
        }
        else
        {
            cout << "Doest Have a negative cycle ";
        }
        cout << endl;
    }
}