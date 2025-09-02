#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cout<<"Enter the number of nodes: ";
    cin>> n;
    cout<<"Enter the number of edges: ";
    cin>> e;

    vector<pair<int, int>> adj[n+1];

    cout<<endl<<"Enter source and destination with edge weights: "<<endl;
    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        cin>> u>> v>> w;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));

    }
    cout<<endl;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j<adj[i].size(); j++)
        {
            cout<<i<<"-->"<<adj[i][j].first<<" Weight: "<<adj[i][j].second<<"   ";
        }
        cout<<endl;
    }

    /*for (int i = 1; i <=n ; i++)
    {
        cout << "Node " << i << " makes an edge with \n";
        for (auto it = adj[i].begin(); it!=adj[i].end(); it++)
        {
            cout << "\tNode " << it->first << " with edge weight ="<< it->second << "\n";
        }
        cout << "\n";
    }*/

    return 0;
}