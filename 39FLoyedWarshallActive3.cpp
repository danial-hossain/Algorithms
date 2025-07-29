#include <bits/stdc++.h>
using namespace std;
void FloyedWarshall(vector<vector<int>> &adj, int V, vector<vector<int>> &path, vector<int> skip,vector<vector<int>>&parent)
{
    for (int k = 0; k < V; k++)
    {
        bool flag = false;
        for (int x = 0; x < skip.size(); x++)
        {
            if (k == skip[x])
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            continue;
        }

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
                    parent[i][j]=parent[k][j];
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
    vector<vector<int>> parent(V, vector<int>(V, -1));
    vector<int> skip;
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
         parent[u][v] = u;
    }
    cout << "How many nodes you want to skip : ";
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        skip.push_back(x);
    }

    FloyedWarshall(adj, V, path, skip,parent);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == INT_MAX)
            {
                cout << "INF"<< " ";
            }
            else
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout<<"Enter Destination :";
    int des;
    cin>>des;
    int src=0;
    vector<int>rasta;
    while(des!=src)
    {
        rasta.push_back(des);
        des=parent[src][des];
    }
     rasta.push_back(0);
    reverse(rasta.begin(), rasta.end());
    for(auto i: rasta)
    {
        cout<< i<< " ";
    }

}