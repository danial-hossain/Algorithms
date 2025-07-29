#include <bits/stdc++.h>
using namespace std;
bool BellMan(vector<vector<int>> adj, int V, int E, vector<int> &distance, vector<int> &parent)
{
    bool flag = false;
    distance[0] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = adj[j][0];
            int v = adj[j][1];
            int w = adj[j][2];
            if (distance[u] != INT_MAX && distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                parent[v] = u;
            }
        }
    }
    for (int j = 0; j < E; j++)
    {
        int u = adj[j][0];
        int v = adj[j][1];
        int w = adj[j][2];
        if (distance[u] != INT_MAX && distance[v] > distance[u] + w)
        {
            
            flag = true;
        }
    }
    return flag;
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({u, v, w});
    }
    vector<int> distance(V, INT_MAX);
    vector<int> parent(V, -1);
    bool flag = BellMan(adj, V, E, distance, parent);

    for (auto i : distance)
    {
        // cout<<i<<" ";
    }
    if (flag)
    {
        cout << "Negative Cycle Detected";
    }
    else
    {
        cout << "No Negative Cycle";
    }
    int des;
    cout << endl;
    cout << "Enter Destination : ";
    cin >> des;
    vector<int> cycle;
    cycle.push_back(1);
   do
    {
        cycle.push_back(des);
        des = parent[des];
    } while (des != 1);
    cycle.push_back(1);
    reverse(cycle.begin(),cycle.end());
    for (auto i : cycle)
    {
        cout << i << " ";
    }
}