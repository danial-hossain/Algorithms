#include <bits/stdc++.h>
using namespace std;

void floyedwarshall(vector<vector<int>> &adj, int V, int E)
{
  



    for (int k = 0; k < V; k++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int i = 0; i < V; i++)
            {
                if(adj[i][k]==INT_MAX || adj[k][j]==INT_MAX)
                continue;
                if(adj[i][j]>adj[i][k]+adj[k][j])
                {
                    adj[i][j]=adj[i][k]+adj[k][j];
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

    for (int i = 0; i < V; i++)
    {
        adj[i][i] = 0;
    }
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }
    floyedwarshall(adj, V, E);
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(adj[i][j]==INT_MAX)
            {
                cout<<"INF";
            }
            cout<< adj[i][j]<< " ";
            
        }
        cout<<endl;
    }
}